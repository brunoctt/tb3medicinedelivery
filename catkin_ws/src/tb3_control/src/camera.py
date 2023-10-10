#!/usr/bin/env python

import rospy
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from tb3_control.srv import CameraRes, CameraResResponse

class myCamera():

    def __init__(self):
        print('init camera')
        # Bridge to convert ROS message to openCV
        self.bridge = CvBridge()

        # Subscriber to the camera image
        self.image_sub = rospy.Subscriber("/camera/rgb/image_raw", Image,self.callback_camera_subscriber)

        # Server Service camera
        self.service = rospy.Service('camera_result_service', CameraRes, self.callback_camera_service)
        
        self.cv_image = None
        
    def callback_camera_service(self, request):
        return self.cv_image

    def callback_camera_subscriber(self, msg):
        # print('callback camera')
        try:
            self.cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except CvBridgeError as e:
            print(e)
            

if __name__ == '__main__':

    rospy.init_node('maze_camera')

    cam = myCamera()

    rospy.spin()