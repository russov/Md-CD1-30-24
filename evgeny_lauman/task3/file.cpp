#include <iostream>
#include <fstream>
#include <string>
#include <vector>


bool isStrNumber(std::string str)
{
	if (!str.size())
		return false;
	for (int i = 0; i < str.size(); i++)
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			return false;
	}
	return true;
}

void writeNumbersToFile(std::ios_base::openmode mode)
{
	std::string filename = "numbers.txt";
	std::ofstream fout;
	fout.open(filename, mode);
	if (fout.is_open())
	{
		std::string num_row = "";
		std::cout << "Введите последовательность чисел через пробел\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //очистка буфера ввода
		std::getline(std::cin, num_row);

		int pos = 0;
		for (int i = 0; i < num_row.size(); i++)
		{
			if (num_row[i] == ' ')
			{
				if (isStrNumber(num_row.substr(pos, i - pos)))
					fout << num_row.substr(pos, i - pos) << "\n";
				pos = i + 1;
			}
			else if (i == num_row.size() - 1)
			{
				if (isStrNumber(num_row.substr(pos)))
					fout << num_row.substr(pos) << "\n";
			}
		}
		fout.close();
	}
	else
		std::cout << "Ошибка открытия файла numbers.txt\n";
	return;
}

void readNumbersFromFile(std::vector<int>& num_arr)
{
	std::string filename = "numbers.txt";
	std::ifstream fin;
	num_arr.clear();
	int num = 0;
	fin.open(filename, std::ios::in);
	if (fin.is_open())
	{
		std::string line = "";
		while (std::getline(fin, line))
		{
			if (line != "\n" && isStrNumber(line))
			{
				num_arr.push_back(stoi(line));
				line = "";
			}
		}
		fin.close();
	}
	else
		std::cout << "Ошибка открытия файла numbers.txt\n";
}


int main()
{
	setlocale(LC_ALL, "rus");
	char choice = 0;
	std::vector<int> num_arr;
	while (true)
	{
		std::cout << "Выберите задание:\n"
			<< "1. Ввод целых чисел с клавиатуры через пробел и запись их в файл\n"
			<< "2. Считывание чисел из файла и вывод в обратном порядке\n"
			<< "3. Считывание чисел из файла и вывод их суммы\n"
			<< "4. Считывание чисел из файла и вывод их среднего арифметического \n"
			<< "5. Запись чисел в конец файла\n"
			<< "x. Для завершения программы"
			<< std::endl;
		std::cin >> choice;
		std::cout << "Введено: " << choice << "\n";
		switch (choice)
		{
		case '1':
		{
			writeNumbersToFile(std::ios::out);
			break;
		}
		case '2':
		{
			readNumbersFromFile(num_arr);
			std::reverse(num_arr.begin(), num_arr.end());
			for (int num : num_arr)
			{
				std::cout << num << "\n";
			}
			break;
		}
		case '3':
		{
			readNumbersFromFile(num_arr);
			int sum = 0;
			for (int num : num_arr)
			{
				sum += num;
			}
			std::cout << "Сумма чисел из файла = " << sum << "\n";
			break;
		}
		case '4':
		{
			readNumbersFromFile(num_arr);
			int sum = 0;
			for (int num : num_arr)
			{
				sum += num;
			}
			std::cout << "Среднее арифметическое чисел из файла = " << (float)sum / (num_arr.size()) << "\n";
			break;
		}
		case '5':
		{
			writeNumbersToFile(std::ios::app);
			break;
		}
		case 'x':
		{
			return 0;
		}
		default:
			break;
		}
	}
}
