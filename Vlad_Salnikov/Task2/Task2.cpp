#include <iostream>
#include <fstream>
#include <vector>
#include "numCheck.h"
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int choise{ 1000 };
	int num{ 0 };
	int sum{ 0 };
	int count{ 0 };
	string file_in{ "" };
	vector<int> numbers;
	vector<string> numbers_str;
	string file_name = "";
	fstream file;

	cout << "Menu:\n" << "1) Create file\n" << "2) Fill file\n" << "3) Read file\n" << "4) Edit file\n" << "5) Exit" << endl;
	while (choise != 0)
	{
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "Enter file name\n";
			cin >> file_name;
			file.open(file_name + ".txt");
			file.close();
			cout << "File created\n";
			break;
		case 2:
			cout << "Enter file name\n";
			cin >> file_name;
			file.open(file_name + ".txt", ios::out);
			if (!file.is_open())
			{
				cout << "Incorrect name. Back to menu\n";
				break;
			}
			cout << "Enter count of numbers\n";
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				cout << "Enter " << i + 1 << " number\n";
				cin >>num;
				num = numCheck(num);
				numbers.push_back(num);
			}
			for (int i = 0; i < count; i++)
			{
				file << numbers[i] << '\n';
			}
			file.close();
			numbers.clear();
			cout << "Fill complete. Back to menu\n";
			break;
		case 3:
			cout << "Enter the name of the file you want to open\n";
			cin >> file_name;
			file.open(file_name + ".txt");
			if (!file.is_open())
			{
				cout << "Incorrect name. Back to menu\n";
				break;
			}
			while (!file.eof())
			{
				getline(file, file_in);
				numbers_str.push_back(file_in);
			}
			file.close();
			for (int i = 0; i < numbers_str.size()-1; i++)
			{
				numbers.push_back(stoi(numbers_str[i]));
			}
			numbers_str.clear();
			cout << "Task 2\n";
			cout << "Добавьте функцию, которая считывает числа из файла numbers.txt и выводит их на экран в обратном порядке.\n";
			for (int i = numbers.size(); i > 0; --i)
			{
				cout << numbers[i-1] << ' ';
			}
			cout << "\nРасширьте программу,чтобы она считывала числа из файла numbers.txt и находила их сумму.";
			cout << "Сумма должна выводиться на экран.\n";
			for (int i = 0; i < numbers.size(); i++)
			{
				sum += numbers[i];
			}
			cout << "Sum of numbers = " << sum << '\n';
			cout << "Напишите функцию, которая считывает числа из файла numbers.txt и находит среднее арифметическое всех чисел.";
			cout << "Результат должен быть выведен на экран.\n";
			cout << "Average is " << (double)sum / 2 << '\n';
			cout << "Back to memu\n";
			break;
		case 4:
			cout << "Enter file name that you want edit\n";
			cin >> file_name;
			file.open(file_name + ".txt", ios::app);
			if (!file.is_open())
			{
				cout << "Incorrect name. Back to menu\n";
				break;
			}
			cout << "Enter count of numbers that you want to add\n";
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				cout << "Enter " << i + 1 << '\n';
				cin >> num;
				num = numCheck(num);
				file << num << '\n';
			}
			file.close();
			cout << "Back to menu\n";
			break;

		case 5:
			choise = 0;
			break;
		default:
			choise = 1000;
			break;
		}

	}
	return 0;
}