

## Overview

branch:Week10_HW

This is a small ROS project that shows a node publishing message to a topic and a node subscribing message from that topic. In addition, the a service was added to the publisher node to change the published message.

## Installation

In your catkin workspace directory (or create a new one), checkout the repo (and submodules)
```
git clone --recursive https://github.com/michael081906/beginner_tutorial.git
git checkout Week10_HW
```

## Build

At catkin workspace 
```
catkin_make 
```
which build the project

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

## Service



## Dependencis

ROS kinetic

