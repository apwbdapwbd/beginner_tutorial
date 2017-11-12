// "Copyright [2017] <Michael Kam>"
/** @file listener.cpp
 *  @brief listener.cpp is a node that subscribe string message from chatter topic.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
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
