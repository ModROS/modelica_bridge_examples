cmake_minimum_required(VERSION 2.8.3)
project(modelica_bridge_examples)
add_compile_options(-std=c++11)

set(CATKIN_DEPS joy roscpp std_msgs modelica_bridge)
find_package(catkin REQUIRED COMPONENTS message_generation ${CATKIN_DEPS})
include_directories(${catkin_INCLUDE_DIRS})

catkin_package(CATKIN_DEPENDS message_runtime ${CATKIN_DEPS})

add_executable(two_springs_modbridgex_controller src/two_springs_example/controller.cpp)
target_link_libraries(two_springs_modbridgex_controller ${catkin_LIBRARIES})
add_dependencies(two_springs_modbridgex_controller ${catkin_EXPORTED_TARGETS})

add_executable(two_springs_modbridgex_teleop src/two_springs_example/teleop.cpp)
target_link_libraries(two_springs_modbridgex_teleop ${catkin_LIBRARIES})
add_dependencies(two_springs_modbridgex_teleop ${catkin_EXPORTED_TARGETS})

install(TARGETS two_springs_modbridgex_controller two_springs_modbridgex_teleop
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch/
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch)