

## Overview

This is a small ROS project that demos a node publishing message to a topic and a node subscribe message from that topic. 

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


## Dependencis

ROS kinetic

