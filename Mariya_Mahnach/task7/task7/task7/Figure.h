#include <iostream>
#pragma once

class Figure
{
protected:
	std::string name;
public:
	Figure(std::string name) : name(name) {}
	virtual const std::string GetName() = 0;
	virtual const double GetVolume() = 0;
	const void Print();
	virtual ~Figure() {}
};

