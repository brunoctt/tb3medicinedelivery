#! /usr/bin/env python3

import rclpy
from time import sleep
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from image_interfaces.srv import Movement
from math import atan2, asin, pi
try:
    from turtlebot3_controller.utils import Coordinate, Turn
except ModuleNotFoundError:
    from utils import Coordinate, Turn


class _TB3Controller(Node):
    def __init__(self):
        super().__init__("turtle_bot_3_controller")
        
        self.get_logger().info("Turtle Bot 3 Controller started")
        self.__cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        
    def send_vel_cmd(self, msg: Twist):
        self.__cmd_vel_pub.publish(msg)
         

class _TB3OdomSubs(Node):
    def __init__(self):
        super().__init__("tb3_odometry_subscriber")
        
        self.get_logger().info("TB3 Odometry Subscriber started")
        self.__odom_sub = self.create_subscription(Odometry, '/odom', self.__odometry_callback, 10)
        self.orientation = None
        
    def __odometry_callback(self, msg: Odometry):
        ori = msg.pose.pose.orientation
        self.orientation = round(self.__euler_from_quaternion(ori.x, ori.y, ori.z, ori.w)[-1], 2)
        
    @staticmethod
    def __euler_from_quaternion(x, y, z, w):
        """
        Convert a quaternion into euler angles (roll, pitch, yaw)
        roll is rotation around x in radians (counterclockwise)
        pitch is rotation around y in radians (counterclockwise)
        yaw is rotation around z in radians (counterclockwise)
        From: https://automaticaddison.com/how-to-convert-a-quaternion-into-euler-angles-in-python/
        """
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll_x = atan2(t0, t1)
    
        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = asin(t2)
    
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = atan2(t3, t4)
    
        return roll_x, pitch_y, yaw_z # in radians
     
        
class _TB3Client(Node):
    def __init__(self):
        super().__init__("image_client")
        
        self.get_logger().info("Image client started")
        self.__camera_client = self.create_client(Movement, 'find_centroid')

        while not self.__camera_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for camera service...')
        
        self.cv_image = None
        
        self.resp = None
        
    def request_image(self):
        req = Movement.Request()
        future = self.__camera_client.call_async(req)
        # future.add_done_callback(self.response_callback)
        return future
        
        
class TurtleBot3Controller:
    
    MAX_LINEAR_SPEED = 0.5
    MAX_ANGULAR_SPEED = 1.0
    CURVE_DURATION = 2
    ACTION_DURATION = 1
    
    def __init__(self, graph, current_node: str = 'A') -> None:
        rclpy.init()
        self.__robot = _TB3Controller()
        self.__image_client = _TB3Client()
        self.__odometry = _TB3OdomSubs()
        self.__graph = graph
        self.__current_node = current_node
        self.__current_direction = Coordinate(0)
       
    @property
    def node(self):
        return self.__robot
    
    @property
    def orientation(self):
        rclpy.spin_once(self.__odometry)
        return self.__odometry.orientation
    
    def log(self, msg: str):
        self.__robot.get_logger().info(msg)
        
    def __move_robot(self, linear=0.0, angular=0.0):
        cmd = Twist()
        cmd.linear.x = linear
        cmd.angular.z = angular
        self.__robot.send_vel_cmd(cmd)
        
    def request_image(self):
        return self.__image_client.request_image()
        
    def stop(self):
        self.__move_robot()
        
    def move_straight(self):
        self.__move_robot(self.MAX_LINEAR_SPEED)
        
    def turn(self, angle):    
        while self.orientation is None:
            pass    
        initial_ori = self.orientation
        k = 1
        diff = 0
        self.log("Begin turn")
        while diff < pi/2 - 0.1:
            self.__move_robot(angular=k * (abs(angle) - diff) * (angle//abs(angle)))
            sleep(0.1)
            diff = min(abs(self.orientation - initial_ori), (self.orientation - initial_ori)%pi)
        self.stop()
        
    def turn_right(self):
        # self.__move_robot(angular=-self.MAX_ANGULAR_SPEED)
        # sleep(self.CURVE_DURATION)
        self.turn(-pi/2)

    def turn_left(self):
        # self.__move_robot(angular=self.MAX_ANGULAR_SPEED)
        # sleep(self.CURVE_DURATION)
        self.turn(pi/2)
        
    def turn_back(self):
        self.turn_left()
        self.turn_left()
        
    def move_past_intersection(self):
        self.__move_robot(self.MAX_LINEAR_SPEED)
        sleep(self.ACTION_DURATION)
        self.stop()
        
    def follow_line(self):
        """
        Calculates robot motors speeds based on input image, so it keeps following line until finds intersection
        """
        robot_image = self.__return_response()
        while not robot_image.intersection:
            self.__move_robot(
                linear=self.MAX_LINEAR_SPEED, 
                angular=-self.MAX_ANGULAR_SPEED*robot_image.relative_centroid
            )
            robot_image = self.__return_response()
            # sleep(0.1)
            
        self.move_past_intersection()
        
    # def move_to_intersection(self):
    #     original_position = self.get_robot_position()
    #     self.set_motors_speed(self.__max_speed * 0.8, self.__max_speed * 0.8)
    #     while abs(sum(original_position - self.get_robot_position())) < 0.15:
    #         pass
    #     self.set_motors_speed(0, 0)
        
    def decision(self, turn):
        if turn == Turn.STRAIGHT:
            self.move_past_intersection()
        elif turn == Turn.RIGHT:
            self.turn_right()
        elif turn == Turn.LEFT:
            self.turn_left()
        elif turn == Turn.BACK:
            self.turn_back()
    
    def move_to_nodes(self, nodes: list[str]):
        """
        Move to a given node, from current one
        Args:
            nodes (list[str]): Destination nodes
        """
        path = self.find_path_to_nodes(nodes)
        for turns, node in path:
            self.follow_path(turns)
            self.__current_node = node

    def find_path_to_nodes(self, nodes: list[str]) -> list:
        turns = self.__graph.multi_destination_dijkstra(self.__current_node, nodes)
        return turns
    
    def follow_path(self, path):
        """
        Makes robot follow line, main method
        """
        for coordinate in path:
            self.stop()
            turn = coordinate.convert_to_turn(self.__current_direction)
            self.__current_direction = coordinate
            self.log(str(turn))

            self.decision(turn)
            self.follow_line()

        self.stop()

    def __return_response(self) -> Movement.Response:
        res = self.request_image()
        rclpy.spin_until_future_complete(self.__image_client, res)
        try:
            return res.result()
        except Exception as e:
            self.log(str(e))
