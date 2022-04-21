#include <iostream>
#include <map>

enum class LightState {
	Off,
	Low,
	Medium,
	High
};

class Light
{
public:
	Light();
	void toggle();
	inline LightState getCurrentState() const { return currentState_; }

private:
	LightState currentState_;
	LightState prevState_;

	std::map<LightState, LightState> lightTransitions_
	{
		{LightState::Off, LightState::Low},
		{LightState::Low, LightState::Medium},
		{LightState::Medium, LightState::High},
		{LightState::High, LightState::Off}
	};
};
