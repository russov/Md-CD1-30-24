//// task 3.1
//#include <iostream>
//#include <random>
//
//using namespace std;
//
//const int ROWS = 10;
//const int COLS = 10;
//
//
//int getRandomNumberInRange(int min, int max) {
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<> dis(min, max);
//
//	return dis(gen);
//}
//
//void getOutArr(int arr[][COLS]) {
//	for (int i = 0; i < ROWS; i++)
//	{
//		for (int y = 0; y < COLS; y++)
//		{
//			cout << arr[i][y] << "\t";
//		}
//		cout << endl;
//	}
//}
//
//int isCheckNumber(char x) {
//
//	bool checkNumber = false;
//	int value{ 0 };
//
//	while (checkNumber == false) {
//		cout << x << ": ";
//		cin >> value;
//
//		if (!cin.fail() && value == int(value)) {
//			checkNumber = true;
//			break;
//		}
//		else {
//			cout << "Error is number!" << endl;
//			cin.clear();
//			cin.ignore(10000000, '\n');
//		}
//	}
//
//	return value;
//
//}
//
//void main() {
//
//	int arr[ROWS][COLS]{};
//
//	int minElementArr{0};
//	int minElementArrRows{0};
//
//	int a{ 0 };
//	int b{ 0 };
//
//	cout << "Enter interval [a;b]" << endl;
//
//	a = isCheckNumber('a');
//	b = isCheckNumber('b');
//	cout << endl;
//
//	for (int i = 0; i < ROWS; i++)
//	{
//		for (int y = 0; y < COLS; y++)
//		{
//			arr[i][y] = getRandomNumberInRange(a, b);			
//		}
//	}
//
//	getOutArr(arr);
//
//	minElementArr = arr[0][0];
//
//	for (int i = 0; i < ROWS; i++)
//	{
//		for (int y = 0; y < COLS; y++)
//		{
//			if (arr[i][y] <= minElementArr) {
//
//				minElementArr = arr[i][y];
//				minElementArrRows = i;
//			}
//		}
//	}
//
//	cout <<endl<< "Minimal element: "<< minElementArr<< "\nRow: " << minElementArrRows + 1<< endl<< endl;
//
//	for (int col = 0; col < COLS; ++col) {
//		swap(arr[0][col], arr[minElementArrRows][col]);
//	}
//
//	getOutArr(arr);
//}




////task 3.2 
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//void main() {
//
//	int countOpening{ 0 };
//	int countClosing{ 0 };
//
//	char ch;
//
//	ifstream inf("code.cpp");
//
//	if (!inf)
//	{
//		cerr << "Uh oh, file could not be opened for reading!" << endl;
//		exit(1);
//	}
//
//	while (inf.get(ch))
//	{
//		if (ch == '{') ++countOpening;
//		if (ch == '}') ++countClosing;
//	}
//
//	inf.close();
//
//	ofstream outf("out.txt", ios::out);
//
//	if (countOpening == countClosing) {
//		string x = "File is ok!";
//		cout << x;
//		outf << x;
//	}
//
//	if (countOpening > countClosing) {
//		string x = "The File is missing : " + to_string(countOpening - countClosing) + " }";
//		cout << x;
//		outf << x;
//	}
//
//	if (countClosing > countOpening) {
//		string x = "The File is missing : " + to_string(countClosing - countOpening) + " {";
//		cout << x;
//		outf << x;
//	}
//
//	inf.close();
//}
