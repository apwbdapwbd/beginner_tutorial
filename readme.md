

## Overview

branch:Week10_HW

This is a ROS package that shows a node publishing message to a topic and a node subscribing message from that topic. In addition, the a service was added to the publisher node to change the published message.

## Installation of package

In your catkin workspace directory (or create a new one)
```
git clone --recursive https://github.com/michael081906/beginner_tutorial.git
cd ./beginner_tutorial
git checkout Week10_HW
```

## Build the package

At catkin workspace 
```
cd ~/catkin_ws
catkin_make 
```

## Run
 
First, open a terminal and type: 
```
roscore
```
which runs a ros master. Second, open a new terminal and type:
```
rosrun beginner_tutorials talker
``` 
which runs a talker node. Lastly, open a new terminal and type:
```
rosrun beginner_tutorials listener
```
which runs a listener node. 

## Run ros launch

```
roslaunch beginner_tutorials beginner_tutorial.launch freq:=15
```
where freq is a argument of publisher frequency

## Service

Make sure the talker has been launch, then enter either
```
rosservice call /ChangeString "num: 1"
```
or
```
rosservice call /ChangeString "num: 2"
```
to change the message published by talker.

## RosTest

At catkin workspace 
```
cd ~/catkin_ws
catkin_make run_tests
rostest beginner_tutorials beginner_tutorialTest.launch
```
If the test fail with no reason, try to re-run the test after several seconds. 

## TF

Open a new terminal
```
roslaunch beginner_tutorials beginner_tutorial.launch freq:=15
```
Open another terminal 
```
rosrun tf tf_echo world talker
```
to verify the tf frame information send by talker. Moreover, you can use
```
rosrun tf view_frames
```
to see the relation between two frames.

## Rosbag

At terminal 
```
roslaunch beginner_tutorials beginner_tutorial.launch freq:=15 rosbag:=1
```
where "rosbag:=1" indicates whether using rosbag to record. If you don't want to record, simply use "rosbag:=0" instead. After launching nodes, open a new terminal
```
rosservice call /ChangeString "num: 1"
```
Now terminate the process and open three new terminals

```
roscore
```

```
rosrun beginner_tutorials listener 
```

```
rosbag play ../.ros/2017-11-14-06-32-01.bag
```
Notice that name of the bag file could be different. Next,switch back to the terminal of listener node, verifying the result. At first, the listener receives nothing, but after the service is called, the listener will receive "Michael" string. In addition, you may use
```
rosbag info ../.ros/2017-11-14-06-32-01.bag
```.
to view the bag file summary.


## Dependencis

ROS kinetic

