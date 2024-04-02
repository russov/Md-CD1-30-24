#include <iostream>
#include <fstream>

void reverse_output();
void sum_avg_numbers();

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ofstream numbers("numbers.txt", std::ios_base::app);                 // �������� � �������� ����� ��� ������ � ����� �����
    std::cout << "������� ����� ��� ����� ������� ��� ������: " << std::endl;

    while (true)                                                              // ������ ������ � ���������� � ���� � ����� ������
    {
          
        int n;
    
        std::cin >> n;
        if(!n) break;
        numbers << n << std::endl;

    }

    numbers.close();

    reverse_output();                                                          // ����� ��������� �����
    sum_avg_numbers();                                                         // ������� ����� � �������� ��������������� �����

    return 0;
}

void reverse_output()
{   
    int in;
    std::ifstream file("numbers.txt");
    std::cout << "������ ����� � �������� �������: " << std::endl;

    while(file >> in)
    {
        std:: cout << in;
    }

    return;
}

void sum_avg_numbers()
{

    int a, count = 0, sum = 0;
    double avg;

    std::ifstream file("numbers.txt");
    
    while(file >> a) 
    {
        sum += a;
        count++;
    }

    file.close();

    avg = (double)sum/(double)count;

    std::cout << "����� ��������� �����: " << std::endl;
    std::cout << sum;
    std::cout << std::endl;
    std::cout << "���-�� ����� = " << count << std::endl;
    std::cout << "������� �������������� ��������� �����: " << std::endl;
    std::cout << avg;

    return;
}