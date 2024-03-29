#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#define lineAmount 5
void menu();
void file_Contnue();
void file_FromBegin();
void getnum();
void SumAndAver();
void GetFromFile();
std::string PrintCenter(std::string str, int width);
void PrintCenterCC(std::string str, int width, int lineNumber, int nchoose);


bool newline = 0;
bool go_to_menu=0;
int CenterWidth = 70;
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
		PrintCenterCC("Перезаписать файл", CenterWidth, lineNumber++,choose);
		std::cout << "\n";
		PrintCenterCC("Дописать в конец файла", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		PrintCenterCC("Вывод в обратном порядке", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		PrintCenterCC("Вывод суммы и среднего знечения", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		PrintCenterCC("завершить программу (escape)", CenterWidth, lineNumber++, choose);
		std::cout << "\n";
		std::cout << "\n\n\n\n"<< "\n\n" << PrintCenter("|Управление стрелочками|", CenterWidth);
		switch (_getch())
		{
		case 80:choose = (choose + 1) % lineAmount;
			break;
		case 72:
			if (choose == 0)choose = lineAmount-1;
			else choose--;
			break;
		case VK_ESCAPE:exit(0); break;
		case VK_RETURN:switch (choose)
		{
		case 0: file_FromBegin(); break;
		case 1: file_Contnue(); break;
		case 2: GetFromFile();  break;
		case 3: SumAndAver(); break;
		case 4: exit(0); break;
		} break;
		}
	}
}

int getnum(int num,bool cycle, bool firstcycle, bool minus) {
	cycle = 1;
		firstcycle = 1;
		minus = 0;
		num = 0;
	do {
		system("cls");
		std::cout << "Чтобы выйти нажмите escape\n" << PrintCenter("Введите число(а) через Enter", CenterWidth) << '\n';
		if (minus)std::cout << '-';
		if (num > 0)std::cout << num;
		switch (_getch())
		{
		case '-':if (firstcycle)minus = 1; break;
		case VK_ESCAPE: go_to_menu = 1; break;
		case '0':num = num * 10 + 0; firstcycle = 0; break;
		case '1':num = num * 10 + 1; firstcycle = 0; break;
		case '2':num = num * 10 + 2; firstcycle = 0; break;
		case '3':num = num * 10 + 3; firstcycle = 0; break;
		case '4':num = num * 10 + 4; firstcycle = 0; break;
		case '5':num = num * 10 + 5; firstcycle = 0; break;
		case '6':num = num * 10 + 6; firstcycle = 0; break;
		case '7':num = num * 10 + 7; firstcycle = 0; break;
		case '8':num = num * 10 + 8; firstcycle = 0; break;
		case '9':num = num * 10 + 9; firstcycle = 0; break;
		case VK_BACK:num /= 10;
			if (num == 0 && minus) { minus = 0; firstcycle = 1; }
			else if (num == 0 && !minus) { firstcycle = 1; }
			break;
		case VK_RETURN: cycle = 0; break;
		}
	} while (cycle && !go_to_menu);
	if (!cycle) {
		if (minus)num *= (-1);
		return num;
	}
	else return 0;
}

void file_FromBegin() {
	std::ofstream outf("Numbers.txt");
	int num = 0,res;
	bool cycle = 1, firstcycle = 1, minus = 0;
	do {
		res = getnum(num, cycle, firstcycle, minus);
		if (res != 0) { 
			if (!newline) { outf << res; newline = 1; }
			else outf << '\n' << res;
		}
	} while (!go_to_menu);
	go_to_menu = 0;
	outf.close();
	menu();
}

void file_Contnue() {
	std::ofstream outf("Numbers.txt",std::ios::app);
	int num = 0, res;
	bool cycle = 1, firstcycle = 1, minus = 0;
	do {
		res = getnum(num, cycle, firstcycle, minus);
		if (res != 0) {
			if (!newline) { outf << res; newline = 1; }
			else outf << '\n' << res;
		}
	} while (!go_to_menu);
	go_to_menu = 0;
	outf.close();
	menu();
}

std::string PrintCenter(std::string str, int width) {
	int space;
	std::string res{""};
	space = (width - size(str)) / 2;
	for (int i = 0; i < width; i++) {
		if (i < space) res+=" ";
		else {
			if (i > space + size(str)) break;
			else res +=str[i - space];
		}
	}
	return res;
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
		int sum = 0,number,numbers_amount=0;
		while (fin >> number)
		{
			sum += number;
			numbers_amount++;
		}
		double average = static_cast<double>(sum) / numbers_amount;
		std::cout << "сумма: " << sum <<"\nсреднее значение: " <<average;
		while (_getch() != VK_ESCAPE) {}
	}
}

void PrintCenterCC(std::string str, int width, int lineNumber,int nchoose) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (lineNumber==nchoose) SetConsoleTextAttribute(hConsole,5);
	std::cout << PrintCenter(str, width);
	SetConsoleTextAttribute(hConsole, 7);
}

void GetFromFile() {
	system("cls");
	std::ifstream fin("Numbers.txt");
	if (!fin) {
		std::cout << PrintCenter("Ошибка при открытии файла!\n",CenterWidth);
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
			int* numbers = new int[numbers_amount];
			for (int i = 0; i < numbers_amount; i++) {
				fin >> numbers[i];
			}
			for (int i = 0; i < numbers_amount; i++) {
				std::cout << numbers[numbers_amount - i - 1] << " ";
			}
			while (_getch() != VK_ESCAPE) {}
	}

}