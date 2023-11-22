import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from image_interfaces.srv import Movement
from turtlebot3_controller.line_following import track_line


class ImageProcessor(Node):

    def __init__(self):
        super().__init__('image_processor')
        self.get_logger().info("Image processing node started")
        
        self.image_sub = self.create_subscription(Image, '/camera/image_raw', self.__image_callback, 10)
        self.image_service = self.create_service(Movement, 'find_centroid', self.__find_centroid_callback)
                
        self.__cv_image = None
        self.__bridge = CvBridge()
        
        
    def __find_centroid_callback(self, request, response: Movement.Response):
        self.get_logger().info("Request received")
        if self.__cv_image is not None:
            response.relative_centroid, response.intersection = track_line(self.__cv_image.shape[:2], self.__cv_image)
        return response

    def __image_callback(self, msg: Image):
        try:
            self.__cv_image = self.__bridge.imgmsg_to_cv2(msg, "bgr8")
        except CvBridgeError:
            self.get_logger().warning("Error loading image")
        

def main(args=None):
    rclpy.init(args=args)
    minimal_subscriber = ImageProcessor()
    rclpy.spin(minimal_subscriber)
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
