#include <iostream>
#include <fstream>


int main() {
	setlocale(LC_ALL, "Russian");

	//создаем поток и сразу открываем файл
	std::ofstream fout("test.txt");

	//Проверка файла на открытие
	if (!fout) {
		std::cout << "Не могу открыть файл ";
		return 1;
	}

	long long num, aver;
	std::cout << "Введите количество чисел, которые Вы хотите ввести: ";
	std::cin >> num;
	long long summ = 0;

	for (int i = 0; i < num; ++i) {

		std::cout << " Введите число номер  " << i + 1 << ": ";
		long long number;
		std::cin >> number;
		fout << number << "\n";
		summ += number;


		//std::cout << summ;

	}


	fout.close();

	std::cout << "Файл записана, можно заходить и читать!\n";


	//system("cls");
	std::cout << "Предлагаю следующие варинаты: \n";
	std::cout << "1 - Вывести числа в обратном порядке.Результат вывести на экран: \n"; // Есть вопросы по реализации
	std::cout << "2 - Найти сумму чисел. Результат выести на экран: \n";
	std::cout << "3 - Найти среднее арифметическое всех числе. Результат вывести на экран: \n";
	std::cout << "4 - Дописать новые числа в конец файла: \n";



	std::cout << "Введите цифру  '1 - 4'  \n";
	int op;
	std::cin >> op;
	std::ifstream fin("test.txt");
	fin.unsetf(std::ios::skipws); //не пропускать пробелы


	switch (op) {

	case 1:

		if (!fin) {
			std::cout << "Не могу открыть файл для чтения! ";
			return 1;
		}

		char ch;
		//читаем файл посимвольно
		while (!fin.eof()) {

			fin >> ch;
			std::cout << ch;


		}
		std::cout << std::endl;
		fin.close();
		break;

	case 2:
		std::cout << "Сумма введенных чисел: " << summ << std::endl;
		break;

	case 3:

		aver = summ / num;
		std::cout << "Среднее арифметическое всех чисел: " << aver << std::endl;
		break;

	case 4:

		std::ofstream out("test.txt", std::ios::app);
		if (out.is_open())
		{
			std::cout << "Введите количество цифр, которое хотите добавить в файл: ";
			std::cin >> num;

			for (int i = 0; i < num; ++i) {

				std::cout << " Введите числа которые необходимо добавить в файл  " << i + 1 << ": ";
				long number2;
				std::cin >> number2;
				fout << number2 << "\n";
				

				out << number2 << std::endl;
							
			}
			break;
			
		}

	}


	return 0;
}
