#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "publisher.h"

TurtlePublish::TurtlePublish(){
		speed=2;
		radius=1.1;
		pub=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", MSG_QUEUE_SIZE);
		count_to_break_loop=0;
	}


void TurtlePublish::make_circle(){
	ros::Rate rate(2);
	while(ros::ok()){
		msg.linear.x = speed;
		msg.angular.z=(speed/radius);
		publish();
		if(count_to_break_loop==COUNT_TO_MAKE_CIRCLE)
			break;
		count_to_break_loop++;
		ROS_INFO_STREAM(" linear x ="<<msg.linear.x <<"and angular z : "<<msg.angular.z);
		rate.sleep();
		}
	ROS_INFO_STREAM("Circular path");
	}

void TurtlePublish::draw_random(){
	ros::Rate rate(FREQUENCY);
	while(ros::ok()){
		msg.linear.x = double(rand())/double(RAND_MAX);
		msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;
		publish();
		ROS_INFO_STREAM("linear x is : "<<msg.linear.x<<"and angular z is : "<<msg.angular.z);
		rate.sleep();
	}
	ROS_INFO_STREAM("Random path");
	}

	void TurtlePublish::publish(){
		pub.publish(msg);
	}

