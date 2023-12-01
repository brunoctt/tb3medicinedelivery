# TurtleBot3 control with ROS2

Medicine delivery simulation. Developed as Final Paper of _Residência em Robótica e Inteligência Artificial - Projeto CIn-Softex_ at CIn-UFPE.

## Dependencies
- Ubuntu 22.04
- ROS Humble
- Python 3.10

## Steps to use
1. Clone repository
2. Delete build and install folders in the `turtlebot3_ws` directory
3. Follow instructions for PC Setup in the Quick Start Guide in the [TurtleBot3 install guide](https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/#pc-setup)
4. Follow instructions for Simulation - Gazebo Simulation in the [TurtleBot3 install guide](https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/#gazebo-simulation)
5. Copy the files from `custom_entities` at the root to their respective folders in `turtlebot3_ws/src/turtlebot3_simulations/turtlebot3_gazebo` (models and worlds)
6. Run `colcon build --symlink-install` in the `turtlebot3_ws` directory (if an error occurs, try running it again)
7. In three terminals, from `turtlebot3_ws`, run (Remember that every terminal that tries to run a file has to first `source .../turtlebot3_ws/install/setup.bash`!):
   1. `cd launch && ros2 launch hospital_world_launch.py`
   2. `ros2 run turtlebot3_controller image_node`
   3. `ros2 run turtlebot3_controller main_node`

Be careful! When the guide refers to `catkin_ws`, remember you're using `turtlebot3_ws`.

`hospital_world_launch` launches the hospital world. Alternatively, `test_world_launch` can be used, just be careful to change the graph in `main.py` at `.../src/turtlebot3_controller/turtlebot3_controller/`
`image_node` will start the service that returns momentums from image captured by the robot.
`main_node` will run the `main.py` file, that has the graph to be used and robot controller, with the command of which nodes to move to.
