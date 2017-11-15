// "Copyright [2017] <Michael Kam>"
/** @file ChangeString.cpp
 *  @brief ChangeString.cpp is a node that serves as a client to request a ChangeString service.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 *
 *  This file is part of beginner_tutorials.
 *
 *  ChangeString is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  ChangeString is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with ChangeString.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <cstdlib>
#include "ros/ros.h"
#include "beginner_tutorials/ChangeString.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "ChangeString");
  if (argc != 2) {
    ROS_ERROR("usage: changeString X");
    return 1;
  }
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::ChangeString>(
      "ChangeString");
  beginner_tutorials::ChangeString srv;
  srv.request.num = atoll(argv[1]);
  if (client.call(srv)) {
    ROS_INFO("%s", srv.response.what.c_str());
  } else {
    ROS_FATAL("Failed to call service ChangeString");
    return 1;
  }
  return 0;
}
