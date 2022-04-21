
#include <ros/ros.h>
#include "light/Light.hpp"

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "state_transition_table_node");
    ros::NodeHandle nh;
    ros::Rate r(1);
    Light lightfsm;
    std::cout << "Hello FSM \n";

    while(ros::ok())
    {
        r.sleep();
        ros::spinOnce();
        lightfsm.toggle();
    }

    return 0;
}