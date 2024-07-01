#pragma once
#include <chrono>
#include <thread>

class Timer
{
public:
	Timer();
	Timer(int time) :breakTime(time) {};

	template<typename Function, typename... Args>
	void stop(Function&& func, Args&&... args)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(breakTime));
		std::invoke(std::forward<Function>(func), std::forward<Args>(args)...);
	}

private:
	int breakTime{0};
};

