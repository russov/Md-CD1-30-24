
#include <iostream> 
#include <fstream> 
#include <string> 

using namespace std;



int main()
{
    setlocale(LC_ALL, "ru");
    int size;
    int size2 = 0;
    cout << "Enter how many number you wont to enter" << endl;
    while (!(cin >> size))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Incorrect. Plise try again." << endl;
        cout << "Enter number " << endl;
    }
    size = fabs(size);
    int* Arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        int buffer;
        cout << "Enter number " << endl;
        while (!(cin >> buffer))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Incorrect. Plise try again." << endl;
            cout << "Enter number" << endl;
        }
        Arr[i] = buffer;
    }
    cout << "Check your array" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << Arr[i] << endl;
    }

    ofstream Lesson_3;
    string path = "read.txt";
    Lesson_3.open(path);
    if (!Lesson_3.is_open())
    {
        cout << "Error!";
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            Lesson_3 << Arr[i] << "\n";
        }
    }
    Lesson_3.close();
    delete[] Arr;



    ifstream Lesson_3_read;
    Lesson_3_read.open(path);
    int* NewArr = new int[size];
    if (!Lesson_3_read.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        string str;
        if (!Lesson_3_read.eof())
        {

            for (int i = 0; i < size; ++i)
            {
                Lesson_3_read >> str;
                NewArr[i] = stoi(str);
            }
        }
        cout << "____________________________________" << endl;
        for (int i = size - 1; i >= 0; i--)
        {
            cout << NewArr[i] << endl;
        }
    }
    Lesson_3_read.close();
    delete[] NewArr;

    cout << "Your new array!" << endl;


    ifstream Lesson_3_SUM;
    Lesson_3_SUM.open(path);
    int* Arr_SUM = new int[size];
    string c;
    int sum = 0;
    if (!Lesson_3_SUM.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            Lesson_3_SUM >> c;
            Arr_SUM[i] = stoi(c);
            sum = sum + Arr_SUM[i];
        }
        Lesson_3_SUM.close();
        cout << "Sum is:" << sum << endl;
    }
    delete[] Arr_SUM;



    ifstream Lesson_3_arithmetic;
    Lesson_3_arithmetic.open(path);
    int* Arr_arithmetic = new int[size];
    float sum1 = 0;
    float arithmetic = 0;
    string b;
    if (!Lesson_3_arithmetic.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            Lesson_3_arithmetic >> (b);
            Arr_arithmetic[i] = stoi(b);
            sum1 = sum1 + Arr_arithmetic[i];
        }
        arithmetic = sum1 / size;
        cout << "Arithmetic mean" << arithmetic << endl;
    }
    delete[] Arr_arithmetic;
    ofstream Lesson_3_New_number;
    Lesson_3_New_number.open(path, ofstream::app);
    if (!Lesson_3_New_number.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        cout << "Do you whant to enter new number?" << endl;
        cout << "y/n" << endl;
        string resalt;
        cin >> resalt;
        bool is_quel = true;
        if (resalt == "Y" || resalt == "y")
        {
            while (is_quel)
            {
                cout << "Enter the number" << endl;
                int new_value;
                while (!(cin >> new_value))
                {
                    cin.clear();
                    while (cin.get() != '\n');
                    cout << "Incorrect. Plise try again." << endl;
                    cout << "Enter the number " << endl;
                }
                ++size2;
                Lesson_3_New_number << new_value << "\n";
                cout << "Do you whant to enter new number?" << endl;
                cout << "y/n" << endl;
                cin >> resalt;
                if (resalt == "Y" || resalt == "y")
                {
                    is_quel = true;
                }
                else
                {
                    is_quel = false;
                    cout << "The End" << endl;
                }
            }


        }
        else if (resalt == "N" || resalt == "n")
        {
            cout << "The End" << endl;

        }
        else
        {
            cout << "Incorrect." << endl;
        }
        Lesson_3_New_number.close();
    }


    cout << "Count SUM and arithmetic mean at new array:" << endl;

    ifstream new_read;
    new_read.open(path);
    int newSize = size + size2, newSUM = 0;
    float newArithmetic = 0;
    int* New_Arrr_of_Numbers = new int[newSize];
    string new_number_read;
    if (!new_read.is_open())
    {
        cout << "Error!" << endl;
    }
    else
    {
        for (int i = 0; i < newSize; ++i)
        {
            new_read >> new_number_read;
            New_Arrr_of_Numbers[i] = stoi(new_number_read);
            newSUM += New_Arrr_of_Numbers[i];

        }
        cout << "New SUM:" << newSUM << endl;
        float newSize2 = newSize;
        newArithmetic = newSUM / newSize2;
        cout << "New arithmetic mean:" << newArithmetic << endl;
    }
    delete[] New_Arrr_of_Numbers;
    new_read.close();

    return 0;
}
