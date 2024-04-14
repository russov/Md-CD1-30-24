#include "numCheck.h"
#include <iostream>

 int checkingAndCorrectingInputErrors(int num)
{
	while (std::cin.fail())
	{
		std::cout << "Неверный тип\n";
		std::cin.clear();
		std::cin.ignore(100000000, '\n');
		std::cin >> num;
	}
	return num;
}