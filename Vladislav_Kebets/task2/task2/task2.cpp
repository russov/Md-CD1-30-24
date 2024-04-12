#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#define lineAmount 5
#define CenterWidth 110
void menu();
void file_Continue();
void file_FromBegin();
void SumAndAver();
void GetFromFile();
std::string PrintCenter(std::string str, int width);
void PrintCenterCC(std::string str, int width, int lineNumber, int nchoose);



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
		std::cout << "\n\n" << PrintCenter("[Main menu]", CenterWidth) << "\n\n";
		PrintCenterCC("Перезаписать файл", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		PrintCenterCC("Дописать в конец файла", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		PrintCenterCC("Вывод в обратном порядке", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		PrintCenterCC("Вывод суммы и среднего знечения", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		PrintCenterCC("завершить программу (escape)", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		std::cout << "\n\n\n\n" << "\n\n" << PrintCenter("|Управление стрелочками|", CenterWidth);
		switch (_getch())
		{
		case 80:choose = (choose + 1) % lineAmount;
			break;
		case 72:
			if (choose == 0)choose = lineAmount - 1;
			else choose--;
			break;
		case VK_ESCAPE:exit(0); break;
		case VK_RETURN:switch (choose)
		{
		case 0: file_FromBegin(); break;
		case 1: file_Continue(); break;
		case 2: GetFromFile();  break;
		case 3: SumAndAver(); break;
		case 4: exit(0); break;
		} break;
		}
	}
}

bool newline = 1;

void file_FromBegin() {
	system("cls");
	std::ofstream outf("Numbers.txt");
	std::cout << "Для выхода напишите back\n" << PrintCenter("Введите числа:\n", CenterWidth);
	std::string strnumber;
	long long number;
	do
	{
		std::cin >> strnumber;
		if (strnumber != "back")try
		{
			number = std::stoll(strnumber);
			if (newline) { outf << number; newline = 0; }
			else outf << '\n' << number;
		}
		catch (const std::exception&)
		{
			std::cout << "Допущена ошибка при вводе\n";
		}
	} while (strnumber != "back");
	outf.close();
}

void file_Continue() {
	system("cls");
	std::ofstream outf("Numbers.txt", std::ios::app);
	std::cout << "Для выхода напишите back\n" << PrintCenter("Введите числа:\n", CenterWidth);
	std::string strnumber;
	long long number;
	//bool sym{ 0 };
	do
	{
		//sym = 0;
		std::cin >> strnumber;
		try
		{
			/* В случае, когда мы вводим, например, 422f65, функция stoll возвращает только 422, а данный
			код не позволяет с такой строкой чтото делать, что мне нравиться больше, но тогда страдает оптимизация,
			поэтому я его закомментировал(можно сделать чтоб код просто убирал все символы, но оптимизация тогда будет еще хуже)
			for (int i = 0; i < size(strnumber); ++i) {
				if (strnumber[i] != '-' && strnumber[i] != '1' && strnumber[i] != '2' &&
					strnumber[i] != '3' && strnumber[i] != '4' && strnumber[i] != '5' &&
					strnumber[i] != '6' && strnumber[i] != '7' && strnumber[i] != '8' &&
					strnumber[i] != '9' && strnumber[i] != '0') {  sym = 1;  break;}
			}
			if (sym)std::cout << "Допущена ошибка при вводе\n";
			else {number = std::stoll(strnumber);
				if (newline) { outf << number; newline = 0; }
				else outf << '\n' << number;
			}*/
			number = std::stoll(strnumber);
			if (newline) { outf << number; newline = 0; }
			else outf << '\n' << number;
		}
		catch (const std::exception&)
		{
			std::cout << "Допущена ошибка при вводе\n";
		}
	} while (strnumber != "back");
	outf.close();
}

void GetFromFile() {
	system("cls");
	std::ifstream fin("Numbers.txt");
	if (!fin) {
		std::cout << PrintCenter("Ошибка при открытии файла!\n", CenterWidth);
		Sleep(3000);
	}
	else {
		std::cout << PrintCenter("Назад в меню - escape\n", CenterWidth);
		std::string a;
		int numbers_amount = 0;
		while (!fin.eof())
		{
			fin >> a;
			numbers_amount++;
		}
		fin.seekg(0);
		long long* numbers = new long long[numbers_amount];
		for (int i = 0; i < numbers_amount; i++) {
			fin >> numbers[i];
		}
		for (int i = 0; i < numbers_amount; i++) {
			std::cout << numbers[numbers_amount - i - 1] << " ";
		}
		while (_getch() != VK_ESCAPE) { Sleep(1); }
	}

}

void SumAndAver() {
	system("cls");
	std::ifstream fin("Numbers.txt");
	if (!fin) {
		std::cout << PrintCenter("Ошибка при открытии файла!\n", CenterWidth);
		Sleep(2500);
	}
	else {
		std::cout << PrintCenter("Назад в меню - escape\n", CenterWidth);
		std::string a;
		int numbers_amount = 0;
		long long sum = 0, number;
		while (fin >> number)
		{
			sum += number;
			numbers_amount++;
		}
		double average = static_cast<double>(sum) / numbers_amount;
		std::cout << PrintCenter("сумма: " + std::to_string(sum) + "\t\tсреднее значение:" + std::to_string(average), CenterWidth);

		while (_getch() != VK_ESCAPE) { Sleep(1); }
	}
}

std::string PrintCenter(std::string str, int width) {
	int space;
	space = (width - size(str)) / 2;
	std::string res(space, ' ');
	res += str;
	return res;
}

void PrintCenterCC(std::string str, int width, int lineNumber, int nchoose) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (lineNumber == nchoose) SetConsoleTextAttribute(hConsole, 5);
	std::cout << PrintCenter(str, width);
	SetConsoleTextAttribute(hConsole, 7);
}