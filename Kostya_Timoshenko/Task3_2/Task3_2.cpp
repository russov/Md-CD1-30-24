#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void read_file(int& count, int& count2) //������� ������ �����
{
	std::string a;
	std::ifstream readf("c.txt"); //�������� ����� ��� ������
	if (!readf) {
		std::cerr << "Uh oh, file could not be opened for reading!" << std::endl;
		exit(1);
	}
	while (getline(readf, a)) { //������� � ������� { � }
		for (char c : a) {
			if (c == '{') {
				count++;
			}
			else if (c == '}') {
				count2++;
			}
		}
	}
	readf.close(); //������� ����
}

int main()
{
	int diff = 0;
	int count = 0;
	int count2 = 0;
	read_file(count, count2);

	time_t now = time(0);
	tm* now_local_time = localtime(&now);
	int year = 1900 + now_local_time->tm_year;
	int month = 1 + now_local_time->tm_mon;
	int day = now_local_time->tm_mday;
	int hour = now_local_time->tm_hour;
	int minutes = now_local_time->tm_min;
	int seconds = now_local_time->tm_sec;

	std::ofstream openf("result.txt", std::ios::app); //�������� ����� �� ������
	if (!openf) {
		std::cerr << "Uh oh, file could not be opened for writing!" << std::endl;
		exit(1);
	}

	if (count == count2) { //������� �� �����
		openf << "Its fine!" << "  " << "Check was in: " << hour << ":" << minutes << "|" << day << "." << month << "." << year << std::endl;
		std::cout << "Its fine! " << "\n" << "Check was in: " << hour << ":" << minutes << "|" << day << "." << month << "." << year << std::endl;
	}
	else if (count < count2) {
		diff = count2 - count;
		openf << "Missing opening curly braces: " << diff << "  " << "Check was in: " << hour << ":" << minutes << "|" << day << "." << month << "." << year << std::endl;
		std::cout << "Missing opening curly braces: " << diff << "\n" << "Check was in: " << hour << ":" << minutes << "|" << day << "." << month << "." << year << std::endl;
	}
	else if (count > count2) {
		diff = count - count2;
		openf << "Missing closing curly braces: " << diff << "  " << "Check was in: " << hour << ":" << minutes << "|" << day << "." << month << "." << year << std::endl;
		std::cout << "Missing closing curly braces: " << diff << "\n" << "Check was in: " << hour << ":" << minutes << "|" << day << "." << month << "." << year << std::endl;
	}
	openf.close();
	system("pause");
	return 0;
}