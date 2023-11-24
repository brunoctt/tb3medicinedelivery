import os
import json
try:
    from turtlebot3_controller.utils import Coordinates, Coordinate
except ModuleNotFoundError:
    from utils import Coordinates, Coordinate


class Graph:
    """
    Undirected weighted graph
    """
    def __init__(self) -> None:
        self.__edges = {}
        
        # Defining path planning algorithm
        self.routing_algorithm = self.multi_destination_dijkstra
        
        self.__stored_distances_path = os.path.join(os.getcwd(), "src", "turtlebot3_controller", "turtlebot3_controller", "path_planning", "stored_distances.json")
        self.__stored_graph_path = os.path.join(os.getcwd(), "src", "turtlebot3_controller", "turtlebot3_controller", "path_planning", "stored_graph.json")
        
        self.__all_distances = self.__get_stored_distances()
        
    def __get_stored_distances(self) -> dict:
        """Gets stored json file with already mapped distances or creates dict if none are available

        Returns:
            dict: Distances dict from all sources
        """
        if not os.path.exists(self.__stored_distances_path):
            return {}
        
        with open(self.__stored_distances_path, "r") as f:
            return json.load(f)
        
    def __get_distances_from_source(self, source: str) -> dict:
        """Returns specific distances for a source node.

        Args:
            source (str): Source node

        Returns:
            dict: Distances from source node
        """
        if source not in self.__all_distances:
            return {vertex: {'distance': float('inf'), 'path': []} for vertex in self.__edges}
            
        return self.__all_distances[source]
    
    def __save_stored_distances(self, distances: dict, source: str) -> None:
        """
        Saves calculated node distances in json file
        
        Args:
            distances (dict): Calculated distances for a source node, from graph
        """
        self.__all_distances.update({source: distances})
        
        try:
            with open(self.__stored_distances_path, "w+") as f:
                json.dump(self.__all_distances, f, indent=4)
        except FileNotFoundError:
            debug_path = os.path.join(os.getcwd(), "turtlebot3_ws", "src", "turtlebot3_controller", "turtlebot3_controller", "path_planning", "stored_distances.json")
            with open(debug_path, "w+") as f:
                json.dump(self.__all_distances, f, indent=4)
        

    def save_graph(self):
        """
        Saves graph in json file
        """
        def non_serializable_object_encoder(obj):
            try:
                return obj.__json__()
            except AttributeError:
                raise AttributeError(f"Object {obj} is not JSON serializable")
        
        with open(self.__stored_graph_path, "w+") as f:
            json.dump(self.__edges, f, indent=4, default=non_serializable_object_encoder)
            
    def load_graph(self):
        """
        Loads graph from json file
        """
        try:
            with open(self.__stored_graph_path, "r") as f:
                data = json.load(f)
        except FileNotFoundError:
            debug_path = os.path.join(os.getcwd(), "turtlebot3_ws", "src", "turtlebot3_controller", "turtlebot3_controller", "path_planning", "stored_graph.json")
            with open(debug_path, "r") as f:
                data = json.load(f)
        
        for destinations in data.values():
            for destination_data in destinations.values():
                destination_data["coordinates"] = Coordinates([Coordinate(value['coordinate']) for value in destination_data["coordinates"]])

        self.__edges = data
    
    def __add_vertex(self, vertex: str) -> None:
        """Adds vertex to graph

        Args:
            vertex (str): Vertex name
        """
        if vertex in self.__edges:
            return

        self.__edges[vertex] = {}
    
    def add_edge(self, source: str, destination: str, weight: float, direction_to_destination: str) -> None:
        """Adds edge to graph, from source to destination. Information added is weight and direction.

        Args:
            source (str): Source vertex
            destination (str): Destination vertex
            weight (float): Weight of edge, undirected
            direction_to_destination (str): Direction from source to destination
        """
        self.__add_vertex(source)
        self.__add_vertex(destination)
        coordinates = Coordinates(direction_to_destination)
        self.__edges[source][destination] = {'weight': weight, 'coordinates': coordinates}
        self.__edges[destination][source] = {'weight': weight, 'coordinates': coordinates.invert_coordinates()}
        
    @staticmethod
    def find_best_distance_vertex(distances, visited: dict) -> str | None:
        """Finds vertex with smallest weight from mapped distances.

        Args:
            distances (dict): Distances dict, from source
            visited (dict): Visited nodes

        Returns:
            str | None: Closest vertex, if found, else None
        """
        best_distance = float('inf')
        best_vertex = None
        for vertex in distances:
            # Ignores vertexes with bigger distance than best or already visited
            if distances[vertex]['distance'] >= best_distance or visited[vertex]:
                continue
            best_distance = distances[vertex]['distance']
            best_vertex = vertex
        return best_vertex
        
    def dijkstra(self, source: str, destinations: list[str]) -> str:
        """Finds best path from source to all nodes using Dijkstra's algorithm.

        Args:
            source (str): Source node
            destinations (list[str]): List of possible destinations

        Returns:
            str: Destination contained in possible destinations with smallest weight
        """
        distances = self.__get_distances_from_source(source)
        distances[source]['distance'] = 0
        visited = {vertice: False for vertice in distances}
        best_destination = None
        best_distance = float('inf')
        
        # While there are neighbour nodes to search
        while (vertex := self.find_best_distance_vertex(distances, visited)) is not None:
            visited[vertex] = True

            for neighbour, weight in self.__edges[vertex].items():
                if distances[vertex]['distance'] + weight['weight'] < distances[neighbour]['distance']:
                    distances[neighbour]['distance'] = distances[vertex]['distance'] + weight['weight']
                    distances[neighbour]['path'] = distances[vertex]['path'] + [vertex]
                if neighbour in destinations and distances[neighbour]['distance'] < best_distance:
                    best_destination = neighbour
                    best_distance = distances[neighbour]['distance']
                
        self.__save_stored_distances(distances, source)
        
        return best_destination

    def multi_destination_dijkstra(self, source: str, destinations: list[str]) -> list[tuple[Coordinates, str]]:
        """
        Path plannig for multiple destinations utilizing conventional dijkstra.
        Args:
            source (str): Source node
            destinations (list[str]): Desired destinations list

        Returns:
            list[tuple[Coordinates, str]]: Coordinates with path to visit all desired destinations, with optimized weight (not exactly best)
        """
        path = []
        old_source = source
        while len(destinations) > 0:
            new_source = self.dijkstra(old_source, destinations)
            path += self.__all_distances[old_source][new_source]['path']
            old_source = new_source
            destinations.remove(old_source)

        path += [old_source]

        result = []
        for i in range(len(path) - 1):
            result.append((self.__edges[path[i]][path[i+1]]['coordinates'], path[i+1]))

        return result
