#include <geometry_msgs/Twist.h>

class Subscriber{
private:
		ros::NodeHandle nh;
		ros::Subscriber sub;
		const int MSG_QUEUE_SIZE=1000;
		const int FREQUENCY=1;
		void filterVelocityCallback(const geometry_msgs::Twist& msg);

public:
		void subscribe();
};
