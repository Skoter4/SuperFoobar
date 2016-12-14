#pragma once
#include "Timer.h"

class Score
{
public:
	Score() = default;
	~Score() = default;
	void increase_score(float);
	float get_score();
	void time_to_score(Timer);
private:
	float score{0.0f};
};