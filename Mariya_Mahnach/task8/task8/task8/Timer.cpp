#include "Timer.h"
void Timer::wait()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}