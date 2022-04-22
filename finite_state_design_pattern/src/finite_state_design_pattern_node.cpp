#include <ros/ros.h>
#include "ConcreteLightStates.hpp"

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "finite_state_design_pattern_node");
    ros::NodeHandle nh;
    ros::Rate r(1);
    std::cout << "Hello finite state design pattern node \n";

    Light lightfsm_2;

    while(ros::ok())
    {
        // ROS_INFO("ROS SPINNING");
        lightfsm_2.toggle();
        auto cs = lightfsm_2.getCurrentState();
        r.sleep();
        ros::spinOnce();
    }

    return 0;
}