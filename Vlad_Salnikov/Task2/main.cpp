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

	std::cout << "Меню:\n" << "1) Создать файл\n" << "2) Заполнить файл\n" << "3) Заполнение из внешнего файла\n";
	std::cout << "4) Редактировать файл\n" << "5) Задание 2\n" << "0) Выход" << std::endl;
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