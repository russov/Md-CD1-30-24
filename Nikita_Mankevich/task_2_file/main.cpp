#include <iostream>
#include <fstream>

void reverse_output();
void sum_avg_numbers();

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ofstream numbers("numbers.txt", std::ios_base::app);                 // создание и открытие файла для записи в конец файла
    std::cout << "Введите число или любую клавишу для выхода: " << std::endl;

    while (true)                                                              // вводим данные и записываем в файл с новой строки
    {
          
        int n;
    
        std::cin >> n;
        if(!n) break;
        numbers << n << std::endl;

    }

    numbers.close();

    reverse_output();                                                          // вывод введенных чисел
    sum_avg_numbers();                                                         // подсчёт суммы и среднего арифметического чисел

    return 0;
}

void reverse_output()
{   
    int in;
    std::ifstream file("numbers.txt");
    std::cout << "Список чисел в обратном порядке: " << std::endl;

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

    std::cout << "Сумма введенных чисел: " << std::endl;
    std::cout << sum;
    std::cout << std::endl;
    std::cout << "Кол-во чисел = " << count << std::endl;
    std::cout << "Среднее арифметическое введенных чисел: " << std::endl;
    std::cout << avg;

    return;
}