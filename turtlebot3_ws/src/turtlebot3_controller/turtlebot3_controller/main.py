#! /usr/bin/env python3

try:
    from turtlebot3_controller.turtlebot3_controller import TurtleBot3Controller
    from turtlebot3_controller.path_planning.path_planner import Graph
except ModuleNotFoundError:
    from turtlebot3_controller import TurtleBot3Controller
    from path_planning.path_planner import Graph
import rclpy


def main(args=None):
    
    graph = Graph()
    graph.load_graph()
    
    control = TurtleBot3Controller(graph)
    
    control.move_to_nodes(['D', 'B'])
    
    rclpy.spin(control.node)
    
    # while rclpy.ok():
    #     img = control.node.get_image()
    
    # plt.imshow(img)
    # plt.show()    
    
    
    # while rclpy.ok():
    #     rclpy.spin_once(control.node)
    #     if control.node.future.done():
    #         try:
    #             response = control.node.future.result()
    #         except Exception as e:
    #             control.node.get_logger().info(
    #                 'Service call failed %r' % (e,))
    #     else:
    #         control.node.get_logger().info(str(response.sum))
    #         break
    
    
    
    # control.turn_right()    
    # sleep(1)
    # control.stop()
    # sleep(1)
    # control.turn_left()
    # # rate.sleep()
    # sleep(10000000)
    # control.stop()
    
    rclpy.shutdown()


if __name__ == "__main__":
    main()
