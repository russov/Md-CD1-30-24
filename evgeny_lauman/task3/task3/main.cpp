#include <iostream>
#include <fstream>


void genArray(int** arr, int N)
{
	int a(0), b(0); // интервал значений массива
	std::cout << "Введите a\n";
	std::cin >> a;
	std::cout << "Введите b\n";
	std::cin >> b;
	while (b < a || !std::cin)
	{
		std::cout << "Допускается ввод только целых чисел, где a<b !!!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите a\n";
		std::cin >> a;
		std::cout << "Введите b\n";
		std::cin >> b;
	}

	srand(time(NULL)); //инициализация счетчика случайных чисел
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
			arr[i][j] = rand() % (b - a + 1) + a;
	}
}

void printArray(int** arr, int N)
{
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << arr[i][j] << "\t";
		std::cout << std::endl;
	}
}

int findRowWithMinElem(int** arr, int N)
{
	int row_num = 0;
	int min = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (min > arr[i][j])
			{
				min = arr[i][j];
				row_num = i;
			}
	}
	return row_num;
}

void replaceArrRows(int** arr, int num_replacement_row, int num_row_to_replace = 0)
{
	int* buf_arr = arr[num_row_to_replace];
	arr[num_row_to_replace] = arr[num_replacement_row];
	arr[num_replacement_row] = buf_arr;
}

void checkScopesInCppFile(std::string filename)
{
	std::ifstream fin;
	int left_counter = 0;
	int right_counter = 0;
	fin.open(filename, std::ios::in);
	if (fin.is_open())
	{
		char c = ' ';
		while (fin.get(c))
		{
			if (c == '{')
				++left_counter;
			else if (c == '}')
				++right_counter;
		}
		fin.close();
	}
	else
		std::cout << "Ошибка открытия файла " << filename << std::endl;
	std::ofstream fout;
	fout.open("out.txt", std::ios::out);
	if (fout.is_open())
	{
		if (left_counter == right_counter)
		{
			fout << "Количество открывающихся и закрывающихся скобок в файле "<<filename<<" СООТВЕТСТВУЕТ" << std::endl;
			std::cout << "Количество открывающихся и закрывающихся скобок в файле " << filename << " СООТВЕТСТВУЕТ" << std::endl;
		}
		else
		{
			fout << "Количество открывающихся и закрывающихся скобок в файле " << filename << " НЕ СООТВЕТСТВУЕТ!!!" << std::endl;
			std::cout << "Количество открывающихся и закрывающихся скобок в файле " << filename << " НЕ СООТВЕТСТВУЕТ!!!" << std::endl;
		}
		fout.close();
	}
	else
		std::cout << "Ошибка открытия файла out.txt\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	const int N(10); //размерность массива N*N
	int** arr = new int*[N];
	genArray(arr, N);
	printArray(arr, N);
	replaceArrRows(arr, findRowWithMinElem(arr, N));
	printArray(arr, N);

	checkScopesInCppFile("file.cpp");
	return 0;
}