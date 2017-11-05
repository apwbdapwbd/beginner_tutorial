// "Copyright [2017] <Michael Kam>"
/** @file talker.cpp
 *  @brief talker.cpp is a node that publish string message to chatter topic.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 */
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeString.h"

std::stringstream ss;

bool change(beginner_tutorials::ChangeString::Request  &req,
            beginner_tutorials::ChangeString::Response &res)
{
  ss.str(" ");
  if(req.num==1)
    {res.what="Now change to: Michael";
     ss<< " Michael ";}
  else
    {res.what="Now change to: Michael Kam";
     ss<< " Michael Kam ";}
  return true;
}


int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::ServiceServer service = n.advertiseService("ChangeString", change);
  ros::Rate loop_rate(10);
  int count = 0;
  while (ros::ok()) {
    std_msgs::String msg;    
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  //ros::spin();
  return 0;
}
