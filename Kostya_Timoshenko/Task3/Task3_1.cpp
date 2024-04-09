#include <iostream>
#include <ctime>

void swap_s(int arr[10][10], int str1, int str2) //Функция для смены строк массива
{
	for (int i = 0; i < 10; i++)
	{
		int temp = arr[str1][i];
		arr[str1][i] = arr[str2][i];
		arr[str2][i] = temp;
	}
}

int random(int a, int b) //Функция рандома
{
	return a + rand() % b;
}

int main()
{
	int mass[10][10];
	int i, j, imin, jmin;
	srand(time(0));

	for (int i = 0; i < 10; i++) //Заполняем массив
	{
		for (int j = 0; j < 10; j++)
		{
			mass[i][j] = random(1, 99);
			if (mass[i][j] < 10)
			{
				std::cout << " " << mass[i][j];
			}
			else
			{
				std::cout << mass[i][j];
			}
			if (j != 9)
			{
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	int min = 0;
	min = mass[0][0];
	for (int i = 0; i < 10; i++) //Поиск минимального значения
	{
		for (int j = 0; j < 10; j++)
		{
			if (min > mass[i][j])
			{
				min = mass[i][j];
			}
		}
	}
	for (int i = 0; i < 10; i++) //Ищем был ли min элемент единственный или нет, выводим их, так же меняем строки в массиве
	{
		for (int j = 0; j < 10; j++)
		{
			if (min == mass[i][j])
			{
				swap_s(mass, 0, i);
				imin = ++i;
				jmin = ++j;
				std::cout << "Min:" << min << " String:" << imin << " Column:" << jmin << std::endl;
			}
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++) //Выводим новый массив после смены строк
	{
		for (int j = 0; j < 10; j++)
		{
			if (mass[i][j] < 10)
			{
				std::cout << " " << mass[i][j];
			}
			else
			{
				std::cout << mass[i][j];
			}
			if (j != 9)
			{
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}