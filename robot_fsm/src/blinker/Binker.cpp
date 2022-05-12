#include "Blinker.hpp"

using namespace blinker_ns;

Blinker::Blinker():
blinker_cmd_pub_(nh_.advertise<std_msgs::Int32>("blinker_cmd", 1))
{

}

Blinker::~Blinker()
{

}

void Blinker::setBlinker(BlinkerState state)
{
    blinker_cmd_pub_.publish(state);
    blinker_state_ = state;
}

BlinkerState Blinker::getBlinkerState()
{
    return blinker_state_;
}
    