#pragma once

#include<chrono>

class Timer
{
public:
	Timer();

	int GetTimer() const;

	void ResetTimer();

private:
	std::chrono::time_point<std::chrono::steady_clock> mStartTime;
};