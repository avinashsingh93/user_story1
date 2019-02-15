#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "subscriber.h"


void Subscriber::filterVelocityCallback(const geometry_msgs::Twist& msg){
     	ROS_INFO_STREAM("Subscriber velocities: linear.x is ="<<msg.linear.x<<" and angular z is : "<<msg.angular.z);
}

void Subscriber::subscribe(){
	sub=nh.subscribe("turtle1/cmd_vel",MSG_QUEUE_SIZE,&Subscriber::filterVelocityCallback,this);
	ros::Rate rate(FREQUENCY);
	ros::spin();
}
