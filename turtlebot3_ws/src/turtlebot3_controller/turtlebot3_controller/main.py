#! /usr/bin/env python3

try:
    from turtlebot3_controller.turtlebot3_controller import TurtleBot3Controller
    from turtlebot3_controller.path_planning.path_planner import Graph
except ModuleNotFoundError:
    from turtlebot3_controller import TurtleBot3Controller
    from path_planning.path_planner import Graph
import rclpy
import threading


def main(args=None):
    
    graph = Graph() 
    graph.load_graph()
    
    control = TurtleBot3Controller(graph)
    
    executor = rclpy.executors.MultiThreadedExecutor()
    for node in control.nodes:
        executor.add_node(node)
    
    
    executor_thread = threading.Thread(target=executor.spin, daemon=True)
    executor_thread.start()
    
    control.move_to_nodes(['C', 'B'])
    # rclpy.spin(control.node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
