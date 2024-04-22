// Module_2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//void hello();
//
//int main()
//{
//    hello();
//    hello();
//}
//
//void hello()
//{
//    std::cout << "hello" << std::endl;
//}

//----------------------------------------------------------------------------------

//#include <iostream>
//#include "add.h"
//
//int main()
//{
//    std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
//    return 0;
//}


//-----------------------------------------------------------------------------------
// работа с файлами

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


#define SUM_5_5 5+5

int main()
{
	using namespace std;

	ofstream outf("file.txt"); // Класс ofstream используется для записи данных в файл.

	// Если мы не можем открыть этот файл для записи данных,
	if (!outf)
	{
		cerr << "Uh oh, file could not be opened for writing!" << endl;
		exit(1);
	}

	outf << "Hello World! Hello File!\n";
	outf << "Nice to meet you" << endl;

	outf.close();

	
	// чтение

	ifstream inf("file.txt"); // ifstream используется для чтения содержимого файла.

	// Если мы не можем открыть этот файл для чтения его содержимого,
	if (!inf)
	{
		cerr << "Uh oh, file could not be opened for reading!" << endl;
		exit(1);
	}

	// Пока есть данные, которые мы можем прочитать,
	while (inf)
	{
		// вывод на экран данных из файла
		string strInput;
		//inf >> strInput;
		getline(inf, strInput);
		cout << strInput << endl;
	}

	inf.close();




	outf.open("file.txt", ios::trunc);
	outf << "Additional information" << endl;
	outf.close();


	std::cout << "!!!!!!!!!!!!1 --- " << SUM_5_5 << std::endl;




	// debuging

	struct S {
		int y = 5;
		double f = 6.9;
		std::string s = "text";
		bool i = true;
	} str;

	int y = 5;
	double f = 6.9;
	std::string s = "text";
	bool i = true;




	return 0;
}