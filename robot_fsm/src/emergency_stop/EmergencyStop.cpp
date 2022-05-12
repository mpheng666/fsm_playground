#include "EmergencyStop.hpp"

using namespace emergencystop_ns;

EmergencyStop::EmergencyStop():
estop_cmd_sub_(nh_.subscribe<std_msgs::Bool>("emergency_button_status", 10, &EmergencyStop::emergencystopCB, this))
{

}

EmergencyStop::~EmergencyStop()
{

}

bool EmergencyStop::getEmergencystop()
{
    return emergency_stop_state_;
}
    
void EmergencyStop::emergencystopCB(const std_msgs::BoolConstPtr& msg)
{
    emergency_stop_state_ = msg->data;
}
