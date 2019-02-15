#include <ros/ros.h>
#include "subscriber.h"

int main(int argc, char**argv){
ros::init(argc,argv, "filter_velocity");
Subscriber sub;
sub.subscribe();
}
