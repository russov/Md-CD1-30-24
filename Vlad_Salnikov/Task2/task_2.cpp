#include "task_2.h"
#include <iostream>
#include <vector>

void task2(std::vector<int>& numbers)
{
	int sum{ 0 };
	
	std::cout << "Task 2\n";
	std::cout << "�������� �������, ������� ��������� ����� �� ����� numbers.txt � ������� �� �� ����� � �������� �������.\n";
	for (int i = numbers.size(); i > 0; --i)
	{
		std::cout << numbers[i - 1] << ' ';
	}
	std::cout << "\n��������� ���������,����� ��� ��������� ����� �� ����� numbers.txt � �������� �� �����.";
	std::cout << "����� ������ ���������� �� �����.\n";
	for (int i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];
	}
	std::cout << "Sum of numbers = " << sum << '\n';
	std::cout << "�������� �������, ������� ��������� ����� �� ����� numbers.txt � ������� ������� �������������� ���� �����.";
	std::cout << "��������� ������ ���� ������� �� �����.\n";
	std::cout << "Average is " << (double)sum / 2 << '\n';
	std::cout << "Back to memu\n";
}