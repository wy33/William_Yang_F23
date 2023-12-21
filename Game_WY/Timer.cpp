#include "Timer.h"

Timer::Timer() :
	mStartTime{ std::chrono::steady_clock::now() }
{
}

int Timer::GetTimer() const
{
	return static_cast<int>(
		std::chrono::duration_cast<std::chrono::seconds>
		(std::chrono::steady_clock::now() - mStartTime).count()
		);
}

void Timer::ResetTimer()
{
	mStartTime = std::chrono::steady_clock::now();
}