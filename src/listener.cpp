#include "ros/ros.h"
#include "std_msgs/String.h"

void talkCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"listener");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("talk",1000,talkCallback);
	ros::spin();
	return 0;
}