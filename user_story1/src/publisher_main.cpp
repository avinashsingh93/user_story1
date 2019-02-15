#include <ros/ros.h>
#include "publisher.h"


int main(int argc, char**argv){
	ros::init(argc, argv, "publish_velocity");
	TurtlePublish t1;
	t1.make_circle();
	t1.draw_random();
	}
