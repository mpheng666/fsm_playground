#include "Light.hpp"

Light::Light()
{
	currentState_ = LightState::Off;
	prevState_ = LightState::High;
}

void Light::toggle()
{
	int currentState_int = static_cast<int>(currentState_);
	int prevState_int = static_cast<int>(prevState_);
	prevState_ = currentState_;
	currentState_ = lightTransitions_[currentState_];
	std::cout << "Toggle from prev: " << prevState_int << " to current: " << currentState_int << "\n";
}
