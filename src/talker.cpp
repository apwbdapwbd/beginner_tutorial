// "Copyright [2017] <Michael Kam>"
/** @file talker.cpp
 *  @brief talker.cpp is a node that publish string message to chatter topic.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 */
#include <ros/console.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeString.h"

std::stringstream ss;
int feqRate = 10;

/**@brief This function is a callback function to change the output string.
 * @param[in] &req is the ROS service request.
 * @param[out] &res is a ROS service response.
 * @return bool
 */
bool change(beginner_tutorials::ChangeString::Request &req,
            beginner_tutorials::ChangeString::Response &res) {
  ss.str(" ");
  if (req.num == 1) {
    res.what = "Now change to: Michael";
    ss << " Michael ";
  }
else{
  if (req.num == 2) {
    res.what = "Now change to: Michael Kam";
    ss << " Michael Kam ";
  }
  else{
    ROS_ERROR("usage only 1 or 2");
  }
}
  return true;
}


int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::NodeHandle home("~");
  home.getParam("feq", feqRate);
  ros::Publisher chatter_pub = n.advertise < std_msgs::String
      > ("chatter", 1000);
  ros::ServiceServer service = n.advertiseService("ChangeString", change);
  ros::Rate loop_rate(feqRate);
  ROS_WARN("If the feq didn't assigned, it will use default 10 Hz as feq");
  int count = 0;
  if (ros::ok()) {
    while (ros::ok()) {
      std_msgs::String msg;
      msg.data = ss.str();
      ROS_INFO("%s", msg.data.c_str());
      ROS_DEBUG("Publishing msgs");
      chatter_pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
      ++count;
    }
  } else {
    ROS_FATAL("Failed to initialize talker");
  }
  return 0;
}

