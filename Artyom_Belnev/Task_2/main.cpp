#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void getOutRevNumb() {

	ifstream fin;
	fin.open("numbers.txt");

	if (!fin.is_open()) {
		cout << "Error opening file!!!" << endl;
		exit(1);
	}

	vector<string>numbersIsFile;

	cout << endl << "Numbers from file:" << endl;

	while (fin) {
		string x;
		getline(fin, x);

		numbersIsFile.push_back(x);
	}

	fin.close();

	int sum = 0;
	int sizeVector = numbersIsFile.size();
	double sra = 0;

	for (int i = sizeVector - 2; i >= 0; --i) {
		sum += stoi(numbersIsFile[i]);
		cout << numbersIsFile[i] << endl;
	}

	cout << endl << "Sum of numbers = " << sum << endl;

	sra = (sum * 1.0) / (sizeVector - 1);

	cout << "Arithmetic mean = " << sra << endl;
}




int main()
{
	int numb = 0;
	int count = 0;
	bool countCheck = false;

	ofstream fout;
	fout.open("numbers.txt", ios::app);

	if (!fout.is_open())
	{
		cout << "Error opening file!" << endl;
		return 1;
	}

	cout << "Enter the number of numbers:" << endl;

	while (countCheck == false) {
		double x;
		cin >> x;

		if (!cin.fail() && x == int(x)) {
			count = x;
			countCheck = true;
			break;
		}
		else {
			cout << "Number error!" << endl;
			cin.clear();
			cin.ignore(10000000, '\n');
		}
	}

	cout << "Enter integers:" << endl;

	for (int i = 0; i < count;)
	{
		double x;
		cin >> x;

		if (!cin.fail() && x == int(x)) {
			numb = x;
			fout << numb << "\n";
			i++;
		}
		else {
			cout << "Number error!" << endl;
			cin.clear();
			cin.ignore(10000000, '\n');
		}
	}

	fout.close();
	getOutRevNumb();

	return 0;
}


