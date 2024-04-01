#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int getOutRevNumb() {

	ifstream fin;
	fin.open("numbers.txt");

	if (!fin.is_open()) {
		cout << "Ошибка открытия файла!!!" << endl;
		return 1;
	}

	vector<string>myVector;

	cout << endl << "Числа из файла:" << endl;

	while (fin) {
		string x;
		getline(fin, x);

		myVector.push_back(x);
	}

	fin.close();

	double sum = 0, sizeVector = myVector.size(), sra = 0;

	for (int i = sizeVector - 2; i >= 0; --i) {
		sum += stoi(myVector[i]);
		cout << myVector[i] << endl;
	}

	cout << endl << "Cумма всех чисел = " << sum << endl;

	sra = sum / (sizeVector - 1);

	cout << "Cреднее арифметическое = " << sra << endl;
}




int main()
{
	setlocale(LC_ALL, "Russian");

	double numb = 0;
	int count = 0;
	bool countCheck = false;

	ofstream fout;
	fout.open("numbers.txt", ios::app);

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}

	cout << "Введите количество чисел:" << endl;

	while (countCheck == false) {

		cin >> count;

		if (!cin.fail() && count == int(count)) {
			countCheck = true;
			break;
		}
		else {
			cout << "Ошибка ввода числа!" << endl;
			cin.clear();
			cin.ignore(10000000, '\n');
		}
	}

	cout << "Введите целые числа:" << endl;

	for (int i = 0; i < count;)
	{
		cin >> numb;

		if (!cin.fail() && numb == int(numb)) {
			fout << numb << "\n";
			i++;
		}
		else {
			cout << "Ошибка ввода числа!" << endl;
			cin.clear();
			cin.ignore(10000000, '\n');
		}
	}


	fout.close();
	getOutRevNumb();
}


