#ifndef _EMERGENCY_STOP_HPP_
#define _EMERGENCY_STOP_HPP_

#include <ros/ros.h>
#include "std_msgs/Bool.h"

namespace emergencystop_ns
{

    class EmergencyStop
    {
        public:
            EmergencyStop();
            ~EmergencyStop();

            bool getEmergencystop();

            ros::Subscriber estop_cmd_sub_;
        
        private:
            ros::NodeHandle nh_;
            const double LOOP_RATE_ {20.0};
            
            bool emergency_stop_state_;
            void emergencystopCB(const std_msgs::BoolConstPtr& msg);
    };
    
}

#endif