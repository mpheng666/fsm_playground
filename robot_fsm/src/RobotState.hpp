#ifndef _ROBOT_STATE_HPP_
#define _ROBOT_STATE_HPP_

#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Bool.h"
#include "geometry_msgs/PoseStamped.h"

#include "blinker/Blinker.hpp"
#include "mission_state/MissionState.hpp"
#include "mrccc_mission_executor2/MissionStatus.h"

namespace robotstate_ns
{
    class RobotState
    {
        public:
            RobotState();
            RobotState(MissionState MissionIdle, geometry_msgs::PoseStamped current_pose);
            ~RobotState();

            geometry_msgs::Pose getPose();
            bool setPose(geometry_msgs::Pose);

            MissionState getMissionState();
            void setState(MissionState);

        private:
            ros::NodeHandle nh_;
            const double LOOP_RATE {20.0};

            ros::Publisher set_pose_pub_;
            ros::Publisher i2r_util_mission_pub_;

            ros::Subscriber mrccc_mission_sub_;
            ros::Subscriber amcl_pose_sub_;
            ros::Subscriber battery_voltage_sub_;
            ros::Subscriber emergency_stop_sub_;

            geometry_msgs::PoseStamped curr_pose_;
            
            MissionState fsm_state_;
            mrccc_mission_executor2::MissionStatus mission_status_;
            std_msgs::Int32 curr_mission_;
            std_msgs::Int32 prev_mission_;
            
            blinker_ns::BlinkerState blinker_state_;
            std_msgs::Bool door_present_;

            // std_msgs::Bool emergency_stop_;
            // std_msgs::Float64 battery_level_;

            bool emergency_stop_state_;
            double battery_voltage_;

            void emergencystopCB(const std_msgs::BoolConstPtr& msg);
            void batteryvoltageCB(const std_msgs::Float64ConstPtr& msg);

            void updateState();
    };

} // robotstate_ns
#endif