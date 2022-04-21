#include <ros/ros.h>

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "finite_state_design_pattern_node");
    ros::NodeHandle nh;
    ros::Rate r(1);
    std::cout << "Hello finite state design pattern node \n";

    while(ros::ok())
    {
        r.sleep();
        ros::spinOnce();
    }

    return 0;
}