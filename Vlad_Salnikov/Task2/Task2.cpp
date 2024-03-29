#include <iostream>
#include <vector>
#include "numCheck.h"
#include "task_2.h"
#include "file.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int choise{ 1000 };
	std::vector<int> numbers;

	std::cout << "Menu:\n" << "1) Create file\n" << "2) Fill file\n" << "3) Read file\n";
	std::cout << "4) Edit file\n" << "5) Task2\n" << "6) Exit" << std::endl;
	while (choise != 0)
	{
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			createFile();
			break;
		case 2:
			fillFile(numbers);
			break;
		case 3:
			readFile(numbers);
			break;
		case 4:
			editFile();
			break;
		case 5:
			readFile(numbers);
			task2(numbers);
			break;
		case 6:
			choise = 0;
			break;
		default:
			choise = 1000;
			break;
		}

	}
	return 0;
}