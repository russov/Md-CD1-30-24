#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int err() {
	if (!std::ifstream("test.txt")) {
		std::cout << "Не могу открыть файл.\n";
		return 1;
	}
	else {
		return 0;
	}
}

void menu() {
	std::cout << "Файл записан, можно заходить и читать!\n";
	std::cout << "Предлагаю следующие варианты: \n";
	std::cout << "1 - Вывести числа в обратном порядке. Результат вывести на экран.\n";
	std::cout << "2 - Найти сумму чисел. Результат вывести на экран.\n";
	std::cout << "3 - Найти среднее арифметическое всех чисел. Результат вывести на экран.\n";
	std::cout << "4 - Дописать новые числа в конец файла.\n";
}

int input2() {
	std::cout << "Введите цифру от '1' до '4': \n";
	int op;
	std::cin >> op;
	return op;
}

int summ() {
	int sum = 0;
	std::ifstream fin("test.txt");
	int number;
	while (fin >> number) {
		sum += number;
	}
	fin.close();
	return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int errVall = err();
	if (errVall == 1) { // если невозможно открыть файл, закрываем программу
		return 1;
	}

	std::ofstream fout("test.txt");
	int num;
	std::cout << "Введите количество чисел, которые Вы хотите ввести, через ENTER: ";
	std::cin >> num;

	for (int i = 0; i < num; ++i) {
		std::cout << "Введите число номер " << i + 1 << ": ";
		int number;
		std::cin >> number;
		fout << number << "\n";
	}
	fout.close();

	menu();
	int choice = input2();

	std::ifstream fin("test.txt");

	switch (choice) {
	case 1: {
		std::vector<int> numbers;
		int number;
		while (fin >> number) {
			numbers.push_back(number);
		}
		fin.close();

		std::cout << "Числа в обратном порядке: \n";
		for (int i = numbers.size() - 1; i >= 0; --i) {
			std::cout << numbers[i] << "\n"; // Отображение чисел в обратном порядке
		}
		break;
	}

	case 2: {
		std::cout << "Сумма значений: " << summ() << "\n";
		break;
	}
	case 3: {
		int totalNumbers = 0;
		fin.clear();
		fin.seekg(0, ios::beg);
		int number;
		while (fin >> number) {
			totalNumbers++;
		}
		fin.close();
		std::cout << "Среднее арифметическое значение: " << static_cast<double>(summ()) / totalNumbers << "\n";
		break;
	}
	case 4: {
		std::ofstream out("test.txt", std::ios::app);
		if (!err()) {
			std::cout << "Введите количество цифр, которые хотите добавить в файл: ";
			std::cin >> num;

			for (int i = 0; i < num; ++i) {
				std::cout << "Введите числа, которые необходимо добавить в файл, номер " << i + 1 << ": ";
				int number2;
				std::cin >> number2;
				out << number2 << std::endl;
			}
			out.close();
		}
		break;
	}

	default:
		std::cout << "Неправильный ввод, пожалуйста, введите число от 1 до 4.\n";
		break;
	}

	return 0;
}
