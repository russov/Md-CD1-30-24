#include <iostream>
#include <random>

int main() {
	setlocale(LC_ALL, "rus");
	int array[10][10];
	int a{ 0 };
	int b{ 0 };

	std::cout << "Введите интервал чисел: ";
	std::cin >> a >> b;

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(a, b);

	for (int i = 0; i < 10; i++)
		for (int k = 0; k < 10; k++)
		{
			array[i][k] = distribution(generator);
		}

	int numMIN{array[0][0]};
	int str{0};
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (array[i][k] < numMIN)
			{
				str = i;
				numMIN = array[i][k];
			}
		}
	}

	if (str !=0)
	{
		for (int i = 0; i < 10; ++i) 
		{
			int num = array[0][i];
			array[0][i] = array[str][i];
			array[str][i] = num;
		}
		
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << '\n';
		for (int k = 0; k < 10; k++)
		{
			std::cout << array[i][k] << ' ';
			
		}
	}

	return 0;
}