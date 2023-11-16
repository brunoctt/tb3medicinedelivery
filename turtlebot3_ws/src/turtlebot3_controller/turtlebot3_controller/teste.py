#! /usr/bin/env python3


from turtlebot3_controller.turtlebot3_controller import TurtleBot3Controller
import rclpy
from time import sleep


def main(args=None):
    control = TurtleBot3Controller()
    # rate = control.node.create_rate(1)
    # while rclpy.ok():
    control.turn_right()    
    sleep(1)
    control.stop()
    sleep(1)
    control.turn_left()
    # rate.sleep()
    sleep(1)
    control.stop()
    
    rclpy.shutdown()


if __name__ == "__main__":
    main()
