#pragma once
#include <iostream>

inline int numCheck(int num)
{
	while (!num)
	{
		std::cout << "Incorrect type\n";
		std::cin.clear();
		std::cin.ignore(100000000, '\n');
		std::cin >> num;
	}
	return num;
}