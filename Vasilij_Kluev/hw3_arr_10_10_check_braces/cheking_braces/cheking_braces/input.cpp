#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int min_Value, max_Value;
	cout << "put minimal value of random number \n";
	cin >> min_Value;
	cout << "put maximal value of random number \n";
	cin >> max_Value;
	if (min_Value == max_Value || min_Value > max_Value || max_Value == 0 )
	{
		cout << " ERROR!";
		return 1;
	}
	cout << endl << "___________________________________________________________________ \n";
	//srand(time(0));
	int arr[10][10];
	int random_Value;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			random_Value = rand() % (max_Value - min_Value) + min_Value;
			arr[i][j] = random_Value;
			cout << arr[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}


	int first_Nunber_of_arr = arr[0][0];
	int buffer = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (first_Nunber_of_arr >= arr[i][j]) 
			{
				first_Nunber_of_arr = arr[i][j];
				buffer = i;

			}

		}
	}
	cout <<"min number of Array:" << first_Nunber_of_arr << "\n";
	cout << "min string of Array:" << buffer << "\n";
	int temp;
	for (int i = 0; i < 10; ++i)
	{
		temp = arr[0][i];
		arr[0][i] = arr[buffer][i];
		arr[buffer][i] = temp;
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n" << "\n";
	}

}