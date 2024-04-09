#include <iostream>
#include <random>

void initArray(int arr);
void searchMinElemAndRow(int* arr);
const int COLUMN = 10;
const int ROW    = 10; 

int main()
{
    setlocale(LC_ALL, "Russian");
 
    int Array[ROW][COLUMN];
    int* ptr = &Array[0][0];

    initArray(*ptr);
    searchMinElemAndRow(ptr);

    return 0;
}

void initArray(int arr)
{
    //���� ������� ���������
    int start, end;
    
    std::cout << "������� ��������" << "\n";
    std::cout << "�� " << "\n";
    std::cin >> start;
    std::cout << "�� " << "\n";
    std::cin >> end;
    std::cout << "\n";

    //���������� � ����� �������
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
            int x;
            // x = rand() % (end - start + 1) + start;
            std::random_device rd;
            std::mt19937 generator(rd());
            std::uniform_int_distribution<int> distribution(start, end);
            x = distribution(generator);
            arr = x;
            std::cout << arr << ' ';
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

//����� ������������ �������� � ������
void searchMinElemAndRow(int* arr)
{
    int i_min = 0;
    int i, j;
    int minElem = arr[0];

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COLUMN; j++)
        {
            if (minElem > arr[i]) minElem = arr[i_min = i];
        }
    }
    std::cout << "����������� ������� [" << i_min << "][" << j << "]" <<  " = " << minElem << "\n";
    std::cout << "��������������� ������: \n";


    int temp = arr[0];
    arr[0] = arr[i_min];
    arr[i_min] = temp;
    
    std::cout << *arr;
}