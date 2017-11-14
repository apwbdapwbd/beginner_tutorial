
#include <gtest/gtest.h>
#include <ros/console.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/ChangeString.h"

TEST(TestSuite, testXYZ)
{
ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient < beginner_tutorials::ChangeString
      > ("ChangeString");
  beginner_tutorials::ChangeString srv;
  srv.request.num = 1;
  client.call(srv);
  std::string m;
  m="Now change to: Michael";
  EXPECT_STREQ(m.c_str(),srv.response.what.c_str());
  //EXPECT_NEAR(1, 1,0.01);
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "testnode");
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
