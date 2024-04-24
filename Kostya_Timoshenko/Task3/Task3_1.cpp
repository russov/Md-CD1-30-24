#include <iostream>
#include <ctime>

const int SIZE = 10;
const int MaxRand = 99;
const int MinRand = 1;

void swap_s(int arr[SIZE][SIZE], int str1, int str2) //Function for changing rows of an array
{
	for (int i = 0; i < SIZE; i++)
	{
		int temp = arr[str1][i];
		arr[str1][i] = arr[str2][i];
		arr[str2][i] = temp;
	}
}

void good_array(int g_array, int j) //Array beauty function
{
	if (g_array < SIZE)
	{
		std::cout << " " << g_array;
	}
	else
	{
		std::cout << g_array;
	}
	if (j != SIZE - MinRand)
	{
		std::cout << "|";
	}
}

int main()
{
	int arr[SIZE][SIZE];
	srand(time(0));

	for (int i = 0; i < SIZE; i++) //Filling the array
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = MinRand + rand() % MaxRand;
			good_array(arr[i][j], j);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	int min = arr[0][0];
	for (int i = 0; i < SIZE; i++) //Finding the minimum value
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
			}
		}
	}
	for (int i = 0; i < SIZE; i++) //We look for whether the min element was the only one or not, display them, and also change the lines in the array
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (min == arr[i][j])
			{
				swap_s(arr, 0, i);
				std::cout << "Min:" << min << " String:" << i + 1 << " Column:" << j + 1 << std::endl;
			}
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < SIZE; i++) //Outputting a new array after changing lines
	{
		for (int j = 0; j < SIZE; j++)
		{
			good_array(arr[i][j], j);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}