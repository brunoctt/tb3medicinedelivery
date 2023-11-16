#! /usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class _TB3Controller(Node):
    def __init__(self):
        super().__init__("turtle_bot_3_controller")
        
        self.get_logger().info("Turtle Bot 3 Controller started")
        self.__cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        
    def send_vel_cmd(self, msg: Twist):
        self.__cmd_vel_pub.publish(msg)
        
        
class TurtleBot3Controller:
    
    MAX_SPEED = 1.0
    
    def __init__(self) -> None:
        rclpy.init()
        self.__robot = _TB3Controller()
       
    # @property
    # def node(self):
    #     return self.__robot
        
    def __move_robot(self, linear=0.0, angular=0.0):
        cmd = Twist()
        cmd.linear.x = linear
        cmd.angular.z = angular
        self.__robot.send_vel_cmd(cmd)
        
    def stop(self):
        self.__move_robot()
        
    def move_straight(self):
        self.__move_robot(self.MAX_SPEED)
        
    def turn_right(self):
        self.__move_robot(angular=-2.0)

    def turn_left(self):
        self.__move_robot(angular=2.0)