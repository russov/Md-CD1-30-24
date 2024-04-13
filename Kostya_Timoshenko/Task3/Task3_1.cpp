#include <iostream>
#include <ctime>

const int SIZE = 10;

void swap_s(int arr[SIZE][SIZE], int str1, int str2) //Function for changing rows of an array
{
	for (int i = 0; i < SIZE; i++)
	{
		int temp = arr[str1][i];
		arr[str1][i] = arr[str2][i];
		arr[str2][i] = temp;
	}
}

int random(int a, int b) //Random function
{
	return a + rand() % b;
}

void good_array(int g_array, int j) //Array beauty function
{
	if (g_array < 10)
	{
		std::cout << " " << g_array;
	}
	else
	{
		std::cout << g_array;
	}
	if (j != SIZE - 1)
	{
		std::cout << "|";
	}
}

int main()
{
	int arr[SIZE][SIZE];
	int i, j, imin, jmin;
	srand(time(0));

	for (int i = 0; i < SIZE; i++) //Filling the array
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = random(1, 99);
			good_array(arr[i][j], j);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	int min = 0;
	min = arr[0][0];
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
				imin = ++i;
				jmin = ++j;
				std::cout << "Min:" << min << " String:" << imin << " Column:" << jmin << std::endl;
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