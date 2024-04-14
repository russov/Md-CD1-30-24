#include "file.h"
#include "numCheck.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void createFile()
{
	std::string file_name{""};
	std::ofstream file;

	std::cout << "Enter file name\n";
	std::cin >> file_name;
	file.open(file_name + ".txt");
	file.close();
	std::cout << "File created. Back to menu.\n";
}

void fillFile(std::vector<int>& numbers)
{
	std::string file_name;
	std::ifstream file;
	int count{ 0 };
	int num{ 0 };

	std::cout << "Enter file name\n";
	std::cin >> file_name;
	file.open(file_name + ".txt", std::ios::out);
	if (!file.is_open())
	{
		std::cout << "Incorrect name. Back to menu\n";
	}

	std::cout << "Enter count of numbers\n";
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		std::cout << "Enter " << i + 1 << " number\n";
		std::cin >> num;
		num = checkingAndCorrectingInputErrors(num);
		numbers.push_back(num);
	}

	for (int i = 0; i < count; i++)
	{
		file << numbers[i] << '\n';
	}
	file.close();
	numbers.clear();
	std::cout << "Fill complete. Back to menu\n";
}

void readFile(std::vector<int>& numbers)
{
	std::string file_name;
	std::string file_in;
	std::vector<std::string> numbers_str;
	std::ifstream file;
	std::cout << "Enter the name of the file you want to open\n";
	std::cin >> file_name;

	file.open(file_name + ".txt");
	if (!file.is_open())
	{
		std::cout << "Incorrect name. Back to menu\n";
	}

	while (!file.eof())
	{
		std::getline(file, file_in);
		numbers_str.push_back(file_in);
	}
	file.close();

	for (int i = 0; i < numbers_str.size() - 1; i++)
	{
		numbers.push_back(stoi(numbers_str[i]));
	}

	numbers_str.clear();
}

void editFile()
{
	std::string file_name;
	int count{ 0 };
	int num{ 0 };
	std::cout << "Введите имя файла который вы хотите отредактировать\n";
	std::cin >> file_name;
	std::ifstream file;
	file.open(file_name + ".txt", std::ios::app);
	if (!file.is_open())
	{
		std::cout << "Неверное имя! Возврат в меню\n";
	}

	std::cout << "Введите число символов, которое вы хотите добавить\n";
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		std::cout << "Введите " << i + 1 << '\n';
		std::cin >> num;
		num = checkingAndCorrectingInputErrors(num);
		file << num << '\n';
	}

	file.close();
	std::cout << "Возврат в меню\n";
}