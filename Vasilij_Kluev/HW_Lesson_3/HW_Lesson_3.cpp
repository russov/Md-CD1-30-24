// Project1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы. 
// 

#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    int SIZE;
    int SIZE2 = 0;
    cout << "Введите количество чисел, которое хотите записать" << endl;
    while (!(cin >> SIZE))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Неверный ввод. Повторите." << endl;
        cout << "Введите число " << endl;
    }
    int* Arr = new int[SIZE];
    for (int i = 0; i < SIZE; ++i)
    {
        int buffer;
        cout << "Введите число " << endl;
        while (!(cin >> buffer))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Неверный ввод. Повторите." << endl;
            cout << "Введите число " << endl;
        }
        Arr[i] = buffer;
    }
    cout << "Gроверяем запись вашего массива" << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        cout << Arr[i] << endl;
    }

    ofstream Lesson_3;
    //string path = "D:\git_(trashbucket)\lesson_3\read.txt"; 
    string path = "read.txt";
    Lesson_3.open(path);
    if (!Lesson_3.is_open())
    {
        cout << "Ошибка!";
    }
    else
    {
        //cout << "Введенные вами числа:\n"; 
        for (int i = 0; i < SIZE; ++i)
        {
            Lesson_3 << Arr[i] << "\n";
        }
    }
    Lesson_3.close();
    delete[] Arr;



    ifstream Lesson_3_read;
    Lesson_3_read.open(path);
    int* NewArr = new int[SIZE];
    if (!Lesson_3_read.is_open())
    {
        cout << "Ошибка!" << endl;
    }
    else
    {
        cout << "фаил открыт!" << endl;
        string str;
        if (!Lesson_3_read.eof())
        {

            for (int i = 0; i < SIZE; ++i)
            {
                Lesson_3_read >> str;
                NewArr[i] = stoi(str);
            }
        }
        cout << "____________________________________" << endl;
        for (int i = SIZE - 1; i >= 0; i--)
        {
            cout << NewArr[i] << endl;
        }
    }
    Lesson_3_read.close();
    delete[] NewArr;

    cout << "Новый массив!" << endl;


    ifstream Lesson_3_SUM;
    Lesson_3_SUM.open(path);
    int* Arr_SUM = new int[SIZE];
    string c;
    int SUM = 0;
    if (!Lesson_3_SUM.is_open())
    {
        cout << "Ошибка" << endl;
    }
    else
    {
        for (int i = 0; i < SIZE; ++i)
        {
            Lesson_3_SUM >> c;
            Arr_SUM[i] = stoi(c);
            SUM = SUM + Arr_SUM[i];
        }
        Lesson_3_SUM.close();
        cout << "Сумма чисел введенных вами равна:" << SUM << endl;
    }
    delete[] Arr_SUM;



    ifstream Lesson_3_arithmetic;
    Lesson_3_arithmetic.open(path);
    int* Arr_arithmetic = new int[SIZE];
    float SUM1 = 0;
    float arithmetic = 0;
    string b;
    if (!Lesson_3_arithmetic.is_open())
    {
        cout << "Ошибка" << endl;
    }
    else
    {
        for (int i = 0; i < SIZE; ++i)
        {
            Lesson_3_arithmetic >> (b);
            Arr_arithmetic[i] = stoi(b);
            SUM1 = SUM1 + Arr_arithmetic[i];
        }
        arithmetic = SUM1 / SIZE;
        cout << "Среднеарифмитическое равно:" << arithmetic << endl;
    }
    delete[] Arr_arithmetic;
    ofstream Lesson_3_New_number;
    Lesson_3_New_number.open(path, ofstream::app);
    if (!Lesson_3_New_number.is_open())
    {
        cout << "Ошибка" << endl;
    }
    else
    {
        cout << "Xотите добавить еще одно число?" << endl;
        cout << "y/n" << endl;
        string resalt;
        cin >> resalt;
        bool is_quel = true;
        if (resalt == "Y" || resalt == "y")
        {
            while (is_quel)
            {
                cout << "Введите число" << endl;
                int new_value;
                while (!(cin >> new_value))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Неверный ввод. Повторите." << endl;
                    cout << "Введите число " << endl;
                }
                ++SIZE2;
                Lesson_3_New_number << new_value << "\n";
                cout << "Xотите добавить еще одно число?" << endl;
                cout << "y/n" << endl;
                cin >> resalt;
                if (resalt == "Y" || resalt == "y")
                {
                    is_quel = true;
                }
                else
                {
                    is_quel = false;
                    cout << "конец программы" << endl;
                }
            }


        }
        else if (resalt == "N" || resalt == "n")
        {
            cout << "конец программы" << endl;

        }
        else
        {
            cout << "Вы ввели не коректное значение" << endl;
        }
        Lesson_3_New_number.close();
    }


    cout << "Вычсляем  сумму и среднее значение из нового списка;" << endl;

    ifstream new_read;
    new_read.open(path);
    int newSIZE = SIZE + SIZE2, newSUM = 0;
    float newArithmetic = 0;
    int* New_Arrr_of_Numbers = new int[newSIZE];
    string new_number_read;
    if (!new_read.is_open())
    {
        cout << "ОШИБКА!" << endl;
    }
    else
    {
        for (int i = 0; i < newSIZE; ++i)
        {
            new_read >> new_number_read;
            New_Arrr_of_Numbers[i] = stoi(new_number_read); 
            newSUM += New_Arrr_of_Numbers[i];

        }
        cout << "новая сумма равна:" << newSUM << endl;
        float newSIZE2 = newSIZE;
        newArithmetic = newSUM / newSIZE2;
        cout << "новое среднеарифметическое:" << newArithmetic << endl;
    }
    delete New_Arrr_of_Numbers;
    new_read.close();

    return 0;
}