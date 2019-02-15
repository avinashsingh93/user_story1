#include <geometry_msgs/Twist.h>

class TurtlePublish{

	private:
		ros::NodeHandle nh;
		ros::Publisher pub;
		int count_to_break_loop;
		double speed;
		double radius;
		geometry_msgs::Twist msg;
		const int COUNT_TO_MAKE_CIRCLE=8;
		const int MSG_QUEUE_SIZE=1000;
		const int FREQUENCY=2;

	public:

		TurtlePublish();
		void make_circle();
		void draw_random();
		void publish();
};
