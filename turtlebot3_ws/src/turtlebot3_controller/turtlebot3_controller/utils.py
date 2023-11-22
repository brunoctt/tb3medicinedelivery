from __future__ import annotations
from enum import Enum


class Turn(Enum):
    STRAIGHT = 0 
    LEFT = 1 
    BACK = 2 
    RIGHT = 3
    STOP_SIMULATION = 4 


class Coordinate(Enum):
    N = 0  # NORTH
    E = 1  # EAST
    S = 2  # SOUTH
    W = 3  # WEST
    
    def __json__(self):
        return {'coordinate': self.value}
  
    def invert(self):
        return Coordinate((self.value + 2) % 4)
    
    def convert_to_turn(self, robot_direction: Coordinate):
        return Turn((robot_direction.value - self.value) % 4)


class Coordinates:
    def __init__(self, coordinates: str | list[Coordinate]) -> None:
        if isinstance(coordinates, list):
            self.coordinates = coordinates
            return

        try:
            self.coordinates = [Coordinate[coord[0].upper()] for coord in coordinates]
        except KeyError:
            raise KeyError("Wrong values used. Only cardinal coordinates are valid (N, S, E, W)")
        
    def __json__(self):
        return self.coordinates
        
    def __str__(self) -> str:
        return f"Coordinates {''.join([c.name for c in self.coordinates])}"
    
    def __repr__(self) -> str:
        return self.__str__()

    def __add__(self, other):
        if not isinstance(other, Coordinates):
            raise TypeError("Coordinates object can only be added with another Coordinates")
        return Coordinates(self.coordinates + other.coordinates)

    def __iter__(self):
        return (coordinate for coordinate in self.coordinates)

    def invert_coordinates(self) -> Coordinates:
        new_coordinates = [coord.invert().name for coord in self.coordinates[::-1]]
        return Coordinates("".join(new_coordinates))