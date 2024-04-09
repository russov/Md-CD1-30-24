#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int getOutRevNumb() {

	ifstream fin;
	fin.open("numbers.txt");

	if (!fin.is_open()) {
		cout << "Error opening file!!!" << endl;
		return 1;
	}

	vector<string>vector;

	cout << endl << "Numbers from file:" << endl;

	while (fin) {
		string x;
		getline(fin, x);

		vector.push_back(x);
	}

	fin.close();

	int sum = 0;
	int sizeVector = vector.size();
	double sra = 0;

	for (int i = sizeVector - 2; i >= 0; --i) {
		sum += stoi(vector[i]);
		cout << vector[i] << endl;
	}

	cout << endl << "Sum of numbers = " << sum << endl;

	sra = (sum * 1.0)  / (sizeVector - 1);

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
}


