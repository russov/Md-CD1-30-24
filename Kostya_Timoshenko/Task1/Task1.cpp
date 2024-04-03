#include <iostream>
#include <fstream>
#include <string>

bool isInteger(const std::string& s) {
	if (s.empty()) {
		return false;
	}
	size_t st = 0;
	if (s[0] == '-') {
		if (s.length() == 1) {
			return false;
		}
		st = 1;
	}
	for (size_t i = st; i < s.length(); i++) {
		if (!std::isdigit(s[i])) {
			return false;
		}
	}
	return true;
}

int main() {
	char ofile;
	int count = 0;
	int a;
	int sum = 0;
	double ave;

	do { // Цикл что бы узнать перезаписываем ли мы файл
		std::cout << "Overwrite the file? (Y/N): ";
		std::cin >> ofile;
	} while (ofile != 'Y' && ofile != 'y' && ofile != 'N' && ofile != 'n');

	if (ofile == 'y' || ofile == 'Y') { // Если перезаписать
		std::ofstream outf("numbers.txt");
		if (!outf) {
			std::cerr << "Uh oh, file could not be opened for writing!" << std::endl;
			exit(1);
		}
		std::cin.ignore();
		std::cout << "If you want to stop entering values, write stop." << "\n";
		while (true) {  // Цикл на ввод данных
			std::cout << "Please number: ";
			std::string input;
			std::getline(std::cin, input);
			if (input == "stop")
				break;
			else if (isInteger(input)) {
				outf << input << "\n";
			}
			else {
				std::cout << "Please enter only whole numbers." << "\n";
			}
		}
		outf.close();
	}

	else if (ofile == 'n' || ofile == 'N') { // Если не перезаписывать
		std::ofstream outp("numbers.txt", std::ios::app);
		if (!outp) {
			std::cerr << "Uh oh, file could not be opened for writing!" << std::endl;
			exit(1);
		}
		std::cin.ignore();
		std::cout << "If you want to stop entering values, write stop." << "\n";
		while (true) {  // Цикл на ввод данных
			std::cout << "Please number: ";
			std::string input;
			std::getline(std::cin, input);
			if (input == "stop")
				break;
			else if (isInteger(input)) {
				outp << input << "\n";
			}
			else {
				std::cout << "Please enter only whole numbers." << "\n";
			}
		}
		outp.close();
	}

	std::ifstream inf("numbers.txt");
	if (!inf) {
		std::cerr << "Uh oh, file could not be opened for reading!" << std::endl;
		exit(1);
	}
	while (inf >> a)
	{
		count++;
	}
	inf.clear();
	inf.seekg(0);
	int* mas = new int[count];
	for (int i = 0; i < count; i++)
		inf >> mas[i];

	for (int i = count - 1; i != -1; i--) // Обратный порядок
		std::cout << mas[i] << " ";

	for (int i = 0; i < count; i++) // Сумма чисел
		sum = sum + mas[i];

	std::cout << "\n" << "Sum of all numbers: " << sum << std::endl;
	ave = (double)sum / count; // Средне арифметическое всех чисел
	std::cout << "The arithmetic mean of all numbers: " << ave << std::endl;
	inf.close(); //Закрыть файл
	return 0;
}
