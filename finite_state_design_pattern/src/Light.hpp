#ifndef _LIGHT_HPP_
#define _LIGHT_HPP_

#include "LightState.hpp"

#include <iostream>

// Forward declaration to resolve circular dependency/include
class LightState;

class Light
{
public:
	Light();
	inline LightState* getCurrentState() const { return currentState; }
	void toggle();
	// This is where the magic happens
	void setState(LightState& newState);

private:
	LightState* currentState;
};

#endif
