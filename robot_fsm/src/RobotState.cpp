#include "RobotState.hpp"

using namespace robotstate_ns;

RobotState::RobotState() :
set_pose_pub_(nh_.advertise<geometry_msgs::PoseStamped>("/initialpose", 10)),
i2r_util_mission_pub_(nh_.advertise<std_msgs::Int32>("/i2r_util_manual_mission/manual_trigger", 10)),
emergency_stop_sub_(nh_.subscribe<std_msgs::Bool>("/emergency_button_status", 10, &RobotState::emergencystopCB, this)),
battery_voltage_sub_(nh_.subscribe<std_msgs::Float64>("/merlin/battery_voltage", 10, &RobotState::batteryvoltageCB, this))
{
    
}

RobotState::RobotState(MissionState MissionIdle, geometry_msgs::PoseStamped current_pose)
{

}

RobotState::~RobotState()
{
    
}

geometry_msgs::Pose robotstate_ns::RobotState::getPose()
{
    return curr_pose_.pose;
}

bool RobotState::setPose(geometry_msgs::Pose pose)
{
    geometry_msgs::PoseStamped new_pose;
    new_pose.header.frame_id = "base_link";
    new_pose.header.stamp = ros::Time::now();
    new_pose.pose = pose;
    set_pose_pub_.publish(new_pose);
}

void RobotState::updateState()
{
    switch(fsm_state_)
    {
        case MissionState::MissionIdle:
            {
                break;
            }
        case MissionState::MissionRunning:
            {
                break;
            }
        default:
    }
}

void RobotState::emergencystopCB(const std_msgs::BoolConstPtr& msg)
{
    emergency_stop_state_ = msg->data;
}

void RobotState::batteryvoltageCB(const std_msgs::Float64ConstPtr& msg)
{
    battery_voltage_ = msg->data;
}

