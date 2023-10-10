#!/usr/bin/env python

import rospy
import cv2
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from tf.transformations import euler_from_quaternion
# from tb3_control.srv import CameraRes, CameraResResponse


class Robot:
    
    def __init__(self) -> None:
        self.odometry_subs = rospy.Subscriber("/odom", Odometry, self.callback_odometry, queue_size=1)
        self.orientation = None
        self.vel_publisher = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
        
        self.rate = rospy.Rate(20000)
        
    def callback_odometry(self, msg: Odometry):
        """Converts turtlebot's odometry to store its orientation

        Args:
            msg (Odometry): _description_
        """
        q = msg.pose.pose.orientation
        self.orientation = round(euler_from_quaternion([q.x, q.y, q.z, q.w])[-1], 2)
        
    # def get_image(self):
    #     rospy.wait_for_service('camera_result_service')
    #     try:
    #         # Connect to the server
    #         res = rospy.ServiceProxy('camera_result_service', CameraRes)

    #         # Call the service
    #         response: CameraResResponse = res()
    #         return response.res

    #     # If the connection fails (DEBUG)
    #     except rospy.ServiceException as e:
    #         print("Service call failed: %s"%e)
        
    # def show_image(self):
    #     cv2.imshow("Robot View", self.get_image())
    #     cv2.waitKey(0) 
    #     cv2.destroyAllWindows()


if __name__ == '__main__':
    rospy.init_node('control')
    robo = Robot()
    while (not rospy.is_shutdown()):
        print(robo.orientation)
        robo.rate.sleep()
