#pragma once
#include <thread>
class Timer
{
private:
	int time;
public:
	Timer(int millisec) : time(millisec) {}
	void wait();
};
