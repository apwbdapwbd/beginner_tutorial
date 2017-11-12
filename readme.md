

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

## Dependencis

ROS kinetic

