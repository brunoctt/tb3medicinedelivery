#! /usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from image_interfaces.srv import Movement
try:
    from turtlebot3_controller.utils import Coordinate, Turn
except ModuleNotFoundError:
    from utils import Coordinate, Turn


class _TB3Controller(Node):
    def __init__(self, decision_function):
        super().__init__("turtle_bot_3_controller")
        
        self.get_logger().info("Turtle Bot 3 Controller started")
        self.__cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        
        # self.__camera_client = self.create_client(Movement, 'find_centroid')
        
        # while not self.__camera_client.wait_for_service(timeout_sec=1.0):
        #     self.get_logger().info('Waiting for camera service...')
            
        self.decision_function = decision_function
        
    # def request_image(self):
    #     req = Movement.Request()
    #     future = self.__camera_client.call_async(req)
    #     # future.add_done_callback(self.response_callback)
    #     return future
        
    # def response_callback(self, future):
    #     response = future.result()
    #     self.decision_function(response)

    def send_vel_cmd(self, msg: Twist):
        self.__cmd_vel_pub.publish(msg)
        
        
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
    
    MAX_LINEAR_SPEED = 1.0
    MAX_ANGULAR_SPEED = 2.0
    
    def __init__(self, graph, current_node: str = 'A') -> None:
        rclpy.init()
        self.__robot = _TB3Controller(self.follow_path)
        self.__image_client = _TB3Client()
        self.__graph = graph
        self.__current_node = current_node
        self.__current_direction = Coordinate(0)
       
    @property
    def node(self):
        return self.__robot
    
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
        self.__move_robot(self.MAX_SPEED)
        
    def turn_right(self):
        self.__move_robot(angular=-self.MAX_ANGULAR_SPEED)

    def turn_left(self):
        self.__move_robot(angular=self.MAX_ANGULAR_SPEED)
        
    def turn_back(self):
        self.turn_left()
        self.turn_left()
        
    def move_past_intersection(self):
        self.__move_robot(self.MAX_LINEAR_SPEED)
        
    # async def follow_line(self):
    #     """
    #     Calculates robot motors speeds based on input image, so it keeps following line until finds intersection
    #     """
    #     robot_image = self.request_image()
    #     self.set_motors_speed()
    #     teste = self.__robot.request_image()
    #     resultado = await teste.result()
            

    #     self.move_past_intersection()
    
        
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
            turn = coordinate.convert_to_turn(self.__current_direction)
            self.__current_direction = coordinate
            self.log(str(turn))

            self.decision(turn)
            self.request_image()

        self.stop()

    def return_response(self):
        res = self.request_image()
        rclpy.spin_until_future_complete(self.__image_client, res)
        try:
            self.log(str(res.result()))
        except Exception as e:
            self.log(str(res) + str(e))
        
