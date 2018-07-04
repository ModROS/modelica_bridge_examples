/**
 * @brief Example teleop-based input for use with modbridge_node
 * @file teleop.cpp
 * 
 * Provides scaled joystick input to the two_springs_modbridgex_controller node.
 *
 * This file is part of the modelica_bridge_example package and subject to the license terms
 * in the top-level LICENSE file of the modelica_bridge_examples repository.
 * https://github.com/ModROS/modelica_bridge_examples/blob/master/LICENSE
 * 
 * Copyright 2018
 * @author Shashank Swaminathan <sh.swami235@gmail.com>
 */

#include <ros/ros.h>
#include "modelica_bridge/ModComm.h"
#include <sensor_msgs/Joy.h>

ros::Publisher pub; ///< publisher for teleop input values

/**
 * Scales joystick input, and publishes to topic /modbridge_joy
 * Reads from the /joy topic, of the joy_node
 * @param [in] joy Message for joystick input
 * @see pub()
 * @return none
 */
void joyCallback(const sensor_msgs::Joy::ConstPtr& joy) {
  modelica_bridge::ModComm springVal;
  for(int i = 0; i < 8; i++) {
    springVal.data.push_back((i+1)*joy->axes[i]);
  }
  springVal.size = springVal.data.size();
  pub.publish(springVal);
}

/**
 * Initializes node, publisher, and subscriber. Spins to keep node running.
 * @see pub()
 * @see joyCallback()
 * @return 0
 */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "two_springs_modbridgex_teleop");
    ros::NodeHandle n;
    
    pub = n.advertise<modelica_bridge::ModComm>("modbridge_joy", 1);
    ros::Subscriber joy_sub = n.subscribe<sensor_msgs::Joy>("joy", 10, joyCallback);

    ros::spin();

    return 0;
}