#include <iostream>

void PrintArray(int arr[][10]) {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			std::cout << arr[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

int main() {
	srand(time(0));
	setlocale(0, "");
	std::cout << "Введите интервал (2 числа): ";
	int a, b;
	std::cin >> a >> b;
	int arr[10][10];
	int imin{0};
	int min{b + 1};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			arr[i][j] = rand() % (b - a + 1) + a;
			if (min > arr[i][j]) {
				imin = i;
				min = arr[i][j];
			}
		}
	}
	PrintArray(arr);
	std::cout << "\nномер строки с минимальным элементом - " << imin + 1 << "\nминимальный элемент - " << min << "\n\n\t\t\tМассив после перестановки:\n";
	std::swap(arr[0], arr[imin]);
	PrintArray(arr);
}