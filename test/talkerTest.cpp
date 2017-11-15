// "Copyright [2017] <Michael Kam>"
/** @file talkerTest.cpp
 *  @brief talkerTest.cpp is a test node that tests the talker node's service.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 *
 *  This file is part of beginner_tutorials.
 *
 *  talkerTest is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  talkerTest is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with talkerTest.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <gtest/gtest.h>
#include <ros/console.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeString.h"

std::string m = "Now change to: Michael";

/** @brief TEST(TalkerTest, ChangeString) will
 * test the ChangeString service of the talker node*/
TEST(TalkerTest, ChangeString) {
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::ChangeString>(
      "ChangeString");
  bool exists(client.waitForExistence(ros::Duration(1)));
  EXPECT_TRUE(exists);
  beginner_tutorials::ChangeString srv;
  srv.request.num = 1;
  client.call(srv);
  EXPECT_STREQ(m.c_str(), srv.response.what.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "testnode");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
