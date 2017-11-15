// "Copyright [2017] <Michael Kam>"
/** @file talker.cpp
 *  @brief talker.cpp is a node that publish string message to chatter topic. In addition, this node
 *  will now send a tf transformation as well.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 *
 *  talker is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  talker is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with talker.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <ros/console.h>
#include <tf/transform_broadcaster.h>
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
  } else {
    if (req.num == 2) {
      res.what = "Now change to: Michael Kam";
      ss << " Michael Kam ";
    } else {
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
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::ServiceServer service = n.advertiseService("ChangeString", change);
  ros::Rate loop_rate(feqRate);
  ROS_WARN("If the feq didn't assigned, it will use default 10 Hz as feq");
  int count = 0;

  static tf::TransformBroadcaster br;
  tf::Transform transform;
  transform.setOrigin(tf::Vector3(1.0, 2.0, 3.0));
  tf::Quaternion q;
  q.setRPY(0, 0, 0.7);
  transform.setRotation(q);
  if (ros::ok()) {
    while (ros::ok()) {
      br.sendTransform(
          tf::StampedTransform(transform, ros::Time::now(), "world", "talker"));
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

