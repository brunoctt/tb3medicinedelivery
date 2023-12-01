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
    
    control = TurtleBot3Controller(graph, direction=3)
    
    executor = rclpy.executors.MultiThreadedExecutor()
    for node in control.nodes:
        executor.add_node(node)
    
    executor_thread = threading.Thread(target=executor.spin, daemon=True)
    executor_thread.start()
    
    control.move_to_nodes(['G', 'B', 'E'])

    rclpy.shutdown()
    
    
def add_graph_test_world():
    graph = Graph() 
    graph.add_edge("A", "G", 3, "N")
    graph.add_edge("G", "B", 2, "E")
    graph.add_edge("G", "F", 4, "W")
    graph.add_edge("G", "H", 2, "N")
    graph.add_edge("H", "E", 2, "W")
    graph.add_edge("H", "D", 1, "N")
    graph.add_edge("H", "C", 7, "ES")
    graph.save_graph()
    
    
def add_graph_hospital_world():
    graph = Graph() 
    graph.add_edge("A", "I", 4, "W")
    graph.add_edge("I", "H", 4, "W")
    graph.add_edge("I", "J", 3, "N")
    graph.add_edge("J", "G", 4, "W")
    graph.add_edge("J", "L", 3, "N")
    graph.add_edge("L", "D", 2, "N")
    graph.add_edge("L", "K", 2, "E")
    graph.add_edge("L", "M", 2, "W")
    graph.add_edge("K", "C", 2, "N")
    graph.add_edge("K", "B", 4, "EN")
    graph.add_edge("M", "E", 2, "N")
    graph.add_edge("M", "F", 4, "WN")
    graph.save_graph()


if __name__ == "__main__":
    main()
