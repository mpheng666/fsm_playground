#include "ConcreteLightStates.hpp"

void LightOff::toggle(Light* light)
{
	// Off -> Low
	printf("current state LOW \n"); 
	light->setState(LowIntensity::getInstance());
}

LightState& LightOff::getInstance()
{
	static LightOff singleton;
	printf("Return singleton \n"); 
	return singleton;
}

void LowIntensity::toggle(Light* light)
{
	// Low -> Medium
	printf("current state MEDIUM \n"); 
	light->setState(MediumIntensity::getInstance());
}

LightState& LowIntensity::getInstance()
{
	static LowIntensity singleton;
	printf("Return singleton \n"); 
	return singleton;
}

void MediumIntensity::toggle(Light* light)
{
	// Medium -> High
	printf("current state HIGH \n"); 
	light->setState(HighIntensity::getInstance());
}

LightState& MediumIntensity::getInstance()
{
	static MediumIntensity singleton;
	printf("Return singleton \n"); 
	return singleton;
}

void HighIntensity::toggle(Light* light)
{
	// High -> Off
	printf("current state OFF \n"); 
	light->setState(LightOff::getInstance());
}

LightState& HighIntensity::getInstance()
{
	static HighIntensity singleton;
	printf("Return singleton \n"); 
	return singleton;
}
