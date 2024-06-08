#pragma once
#include <chrono>
#include <thread>

class Timer
{
public:
	Timer();
	Timer(int time) :breakTime(time) {};

	void stop()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(breakTime));
	}

private:
	int breakTime{0};
};

