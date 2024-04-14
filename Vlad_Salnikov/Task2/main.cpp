#include <iostream>
#include <vector>
#include "numCheck.h"
#include "task_2.h"
#include "file.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int choice{ 1000 };
	std::vector<int> numbers;

	std::cout << "Menu:\n" << "1) Create file\n" << "2) Fill file\n" << "3) Read file\n";
	std::cout << "4) Edit file\n" << "5) Task2\n" << "0) Exit" << std::endl;
	while (choice != 0)
	{
		std::cin >> choice;
		choice = checkingAndCorrectingInputErrors(choice);
		switch (choice)
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
		case 0:
			choice = 0;
			break;
		}
	}
	return 0;
}