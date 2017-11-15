// "Copyright [2017] <Michael Kam>"
/** @file listener.cpp
 *  @brief listener.cpp is a node that subscribe string message from chatter topic.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 *
 *  This file is part of beginner_tutorials.
 *
 *  listener is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  listener is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with listener.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "ros/ros.h"
#include "std_msgs/String.h"

/**@brief This function is a callback function to output a msg content
 * @param[in] msg is a message type
 * @return none
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ROS_DEBUG("Start subscribe to topic chatter");
  ros::spin();
  return 0;
}
