// "Copyright [2017] <Michael Kam>"
/** @file talkerTest.cpp
 *  @brief talkerTest.cpp is a test node that tests the talker node's service.
 *
 *  @author Michael Kam (michael081906)
 *  @bug No known bugs.
 *  @copyright GNU Public License.
 */
#include <gtest/gtest.h>
#include <ros/console.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeString.h"

/** @brief TEST(TalkerTest, ChangeString) will
 * test the ChangeString service of the talker node*/
TEST(TalkerTest, ChangeString) {
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::ChangeString>(
      "ChangeString");
  beginner_tutorials::ChangeString srv;
  srv.request.num = 1;
  client.call(srv);
  std::string m;
  m = "Now change to: Michael";
  EXPECT_STREQ(m.c_str(), srv.response.what.c_str());
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "testnode");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
