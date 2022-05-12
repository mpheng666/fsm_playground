#ifndef _BLINKER_HPP_
#define _BLINKER_HPP_

#include <ros/ros.h>
#include "std_msgs/Int32.h"

namespace blinker_ns
{
    enum class BlinkerState
    {
        Red_ON = 5,
        Red_OFF = 6,
        Yellow_ON = 7,
        Yellow_OFF = 8,
        Green_ON = 9,
        Green_OFF = 10,
        Yellow_BLINK = 17
    };

    class Blinker
    {
        public:
            Blinker();
            ~Blinker();

            void setBlinker(BlinkerState state);
            BlinkerState getBlinkerState();

            ros::Publisher blinker_cmd_pub_;
        
        private:
            ros::NodeHandle nh_;
            const double LOOP_RATE_ {20.0};
            
            BlinkerState blinker_state_;
    };
    
}

#endif