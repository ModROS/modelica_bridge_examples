cmake_minimum_required(VERSION 2.8.3)
project(modelica_bridge_examples)
add_compile_options(-std=c++11)

set(CATKIN_DEPS joy roscpp std_msgs modelica_bridge)
find_package(catkin REQUIRED COMPONENTS message_generation ${CATKIN_DEPS})
include_directories(${catkin_INCLUDE_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime ${CATKIN_DEPS})

### Trials using joystick input to control values in Modelica model

## Example of using modelica_bridge with a basic two spring-damper system
# Subscribes to additional node to recieve scaled joystick node values, to use as setpoint for proportional control.
# Uses ModComm.msg for passing values to relay node
add_executable(controller_spring src/spring_example/controller_spring.cpp)
target_link_libraries(controller_spring ${catkin_LIBRARIES})
add_dependencies(controller_spring ${catkin_EXPORTED_TARGETS})

# Recieves values from Joy node, scales values, and assigns desired axes values to the values within ModComm.msg
add_executable(teleop_spring src/spring_example/teleop_spring.cpp)
target_link_libraries(teleop_spring ${catkin_LIBRARIES})
add_dependencies(teleop_spring ${catkin_EXPORTED_TARGETS})