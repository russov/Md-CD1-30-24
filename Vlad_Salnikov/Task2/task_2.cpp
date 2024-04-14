#include "task_2.h"
#include <iostream>
#include <vector>

void task2(std::vector<int>& numbers)
{
	int sum{ 0 };
	
	std::cout << "Task 2\n";
	std::cout << "Добавьте функцию, которая считывает числа из файла numbers.txt и выводит их на экран в обратном порядке.\n";
	for (int i = numbers.size(); i > 0; --i)
	{
		std::cout << numbers[i - 1] << ' ';
	}
	std::cout << "\nРасширьте программу,чтобы она считывала числа из файла numbers.txt и находила их сумму.";
	std::cout << "Сумма должна выводиться на экран.\n";
	for (int i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];
	}
	std::cout << "Сумма чисал = " << sum << '\n';
	std::cout << "Напишите функцию, которая считывает числа из файла numbers.txt и находит среднее арифметическое всех чисел.";
	std::cout << "Результат должен быть выведен на экран.\n";
	std::cout << "Average is " << (double)sum / 2 << '\n';
	std::cout << "Возврат в меню\n";
}