#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#define VK_DOWN 72
#define VK_UP 80
void menu();
void fileWrite(std::ofstream& outf);
void sumAndAver();
void printReversed();
int getSum(std::vector<int> numbers);
void getNumbers(std::vector<int>& numbers);
std::string printCenter(const std::string str, const int width);
void printCenterCC(const std::string str, const int width, const int lineNumber, const int nchoose);

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
std::string filename = "Numbers.txt";
int CenterWidth = 110;

int main()
{
	setlocale(0, "");
	menu();
}



void menu() {
	int choose = 0;
	while (1)
	{
		int lineNumber = 0;
		system("cls");
		std::cout << "\n\n" << printCenter("[Main menu]", CenterWidth) << "\n\n";
		printCenterCC("Перезаписать файл", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		printCenterCC("Дописать в конец файла", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		printCenterCC("Вывод в обратном порядке", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		printCenterCC("Вывод суммы и среднего знечения", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		printCenterCC("завершить программу (escape)", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		std::cout << "\n\n\n\n" << "\n\n" << printCenter("|Управление стрелочками|", CenterWidth);
		switch (_getch()) {

		case VK_UP:choose = (choose + 1) % lineNumber;
			break;

		case VK_DOWN: {
			if (choose == 0)choose = lineNumber - 1;
			else choose--;
			break; }

		case VK_ESCAPE:
			exit(0); break;

		case VK_RETURN:
			switch (choose) {
			case 0: {
				system("cls");
				std::ofstream outf("Numbers.txt");
				fileWrite(outf);
				outf.close();
				break; }

			case 1: {
				system("cls");
				std::ofstream outf("Numbers.txt", std::ios_base::app);
				fileWrite(outf);
				outf.close();
				break; }

			case 2: printReversed();  break;

			case 3: sumAndAver(); break;

			case 4: exit(0); break;

			} break;

		}
	}
}


void fileWrite(std::ofstream& outf) {
	std::cout << "Для выхода напишите back\n" << printCenter("Введите числа:\n", CenterWidth);
	std::string strnumber;
	long long number;
	do
	{
		std::cin >> strnumber;
		if (strnumber != "back") {
			try
			{
				number = std::stoll(strnumber);
				outf << number << '\n';
			}
			catch (const std::exception&)
			{
				std::cout << "Допущена ошибка при вводе\n";
			}
		}
	} while (strnumber != "back");
}


void getNumbers(std::vector<int>& numbers) {
	int a;
	std::ifstream fin(filename);
	if (fin.is_open()) {
		while (fin >> a) {
			numbers.push_back(a);
		}
	}
	fin.close();
}


void printReversed() {
	system("cls");
	std::cout << printCenter("Назад в меню - escape\n", CenterWidth);
	std::vector<int> numbers;
	getNumbers(numbers);
	int numbers_amount = size(numbers);
	for (int i = numbers_amount - 1; i >= 0; --i) {
		std::cout << numbers[i] << " ";
	}
	while (_getch() != VK_ESCAPE) { Sleep(10); }
}


int getSum(std::vector<int> numbers) {
	int sum = 0;
	for (const int a : numbers) {
		sum += a;
	}
	return sum;
}


void sumAndAver() {
	system("cls");
	std::cout << printCenter("Назад в меню - escape\n", CenterWidth);
	std::vector<int> numbers;
	getNumbers(numbers);
	int sum = getSum(numbers);
	std::cout << "\tсумма: " << sum;
	double aver = static_cast<double>(sum) / size(numbers);
	std::cout << "\n\tсреднее значение : " << aver;
	while (_getch() != VK_ESCAPE) { Sleep(10); }
}


std::string printCenter(const std::string str, const int width) {
	int space;
	space = (width - size(str)) / 2;
	std::string res(space, ' ');
	res += str;
	return res;
}


void printCenterCC(const std::string str, const int width, const int lineNumber, const int nchoose) {
	if (lineNumber == nchoose)
		SetConsoleTextAttribute(hConsole, 5);
	std::cout << printCenter(str, width);
	SetConsoleTextAttribute(hConsole, 7);
}