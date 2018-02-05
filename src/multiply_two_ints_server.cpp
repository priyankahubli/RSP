#include "ros/ros.h"
#include "beginner_tutorials/MultiplyTwoInts.h"

bool multiply(beginner_tutorials::MultiplyTwoInts::Request &req,
	 beginner_tutorials::MultiplyTwoInts::Response &res)
{
	res.product = req.a * req.b;
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: [%ld]", (long int)res.product);
	return true;
}

int main (int argc, char **argv)
{
	ros::init(argc,argv,"multiply_two_ints_server");
	ros::NodeHandle n;
	ros::ServiceServer service = n.advertiseService("multiply_two_ints", multiply);
	ROS_INFO("Ready to multiply two integers");
	ros::spin();

	return 0;
}
