#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>

int input(int num)
{
	std::cin >> num;
	while (std::cin.fail())
	{
		std::cout << "Неверный тип\n";
		std::cin.clear();
		std::cin.ignore(100000000, '\n');
		std::cin >> num;
	}
	return num;
}
void creatingFile()
{
	std::string file_name{ "" };
	std::ofstream file;

	std::cout << "Введите имя файла\n";
	std::cin >> file_name;
	file.open(file_name + ".txt");
	std::cout << "Файл создан.\n";
	file.close();
}
void fileFilling()
{
	std::string file_name;
	std::ofstream file;
	std::ifstream fileExistence;
	int count{ 0 };
	int num{ 0 };

	std::cout << "Введите имя файла\n";
	std::cin >> file_name;
	fileExistence.open(file_name + ".txt", std::ios::ate);
	if (!fileExistence.is_open())
	{
		std::cout << "Такого файла не существует. Возврат в меню\n";
		return;
	}
	fileExistence.close();


	file.open(file_name + ".txt", std::ios::out);
	file.close();
	file.open(file_name + ".txt", std::ios::out | std::ios::_Nocreate);
	std::cout << "Введите количиство чисел\n";
	count = input(count);
	for (int i = 0; i < count; i++)
	{
		std::cout << "Введите " << i + 1 << " число\n";
		num = input(num);
		file << num << '\n';
	}

	file.close();
	std::cout << "Заполнение закончено\n";
}
void fillingVectorFromFile(std::vector<int>& numbers)
{
	std::string file_name;
	std::ifstream file;
	std::cout << "Введи имя файла для заполнения вектора.\n";
	std::cin >> file_name;

	file.open(file_name + ".txt");
	if (!file.is_open())
	{
		std::cout << "Такого файла не существует. Возврат в меню\n";
		return;
	}

	while (!file.eof())
	{
		std::string buffer{ "" };
		file >> buffer;
		if (!buffer.empty())
		{
			numbers.push_back(stoi(buffer));
		}

	}
	std::cout << "Вектор заполнен.\n";
	file.close();
}
void addNumberToFile()
{
	std::string file_name;
	std::cout << "Введите имя файла для добавления числа\n";
	std::cin >> file_name;
	std::ofstream file;
	file.open(file_name + ".txt", std::ios::ate | std::ios::_Nocreate);
	if (!file.is_open())
	{
		std::cout << "Такого файла не существует. Возврат в меню\n";
		return;
	}

	int count{ 0 };
	int num{ 0 };
	std::cout << "Введите количество символов, которое вы хотите добавить\n";
	count = input(count);
	while (count < 0)
	{
		std::cout << "Количество не может быть меньше 0\n";
		count = input(count);
	}
	for (int i = 0; i < count; i++)
	{
		std::cout << "Введите " << i + 1 << " число" << '\n';
		num = input(num);
		file << num << '\n';
	}

	file.close();
	std::cout << "Число(а) было(и) добавлено(ы). Возврат в меню\n";
}
void reversVector(std::vector<int>& numbers)
{
	for (int i = numbers.size() - 1; i >= 0; --i)
	{
		std::cout << numbers[i] << ' ';
	}
	std::cout << std::endl;
}
void menu()
{
	std::cout << "Меню:\n" << "1) Создать файл\n" << "2) Заполнить файл\n";
	std::cout << "3) Добаление числа(чисел) в файл\n" << "4) Числа из файла в обратном порядке\n" << "5) Сумма чисел вектора\n";
	std::cout << "6) Среднее арифметическое вектора\n" << "7) Очистить терминал\n" << "0) Выход" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int choice{ 0 };
	std::vector<int> numbers;
	menu();

	while (true)
	{
		choice = input(choice);
		switch (choice)
		{
		case 1:
			creatingFile();
			break;
		case 2:
			fileFilling();
			break;
		case 3:
			addNumberToFile();
			break;
		case 4:
			fillingVectorFromFile(numbers);
			reversVector(numbers);
			numbers.clear();
			break;
		case 5:
			fillingVectorFromFile(numbers);
			std::cout << std::accumulate(numbers.begin(), numbers.end(), 0) << std::endl;
			numbers.clear();
			break;
		case 6:
			fillingVectorFromFile(numbers);
			std::cout << std::accumulate(numbers.begin(), numbers.end(), 0) / 2.0 << std::endl;
			numbers.clear();
			break;
		case 7:
			system("cls");
			menu();
			break;
		case 0:
			return 0;
		}
	}
}