// Module_6_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// const
//#include <iostream>
//
//// Пример использования const с переменными
//void constVariables() {
//    const int x = 5; // Константа
//    int y = 10;
//
//    const int* ptr1 = &x; // Константный указатель на данные
//    int* const ptr2 = &y; // Указатель на константу
//    const int* const ptr3 = &x; // Константный указатель на константу
//
//    // x = 7; // Ошибка: попытка изменить значение константы
//    // *ptr1 = 7; // Ошибка: попытка изменить данные, на которые указывает указатель
//    // ptr2 = &x; // Ошибка: попытка изменить сам указатель
//    //*ptr2 = 7; // Верно: изменяем данные, на которые указывает указатель
//}
//
//// Пример использования const с параметрами функций
//void constFunctionParams(const int x, int const y) {
//     //x = 7; // Ошибка: попытка изменить значение константного параметра
//     //y = 7; // Ошибка: попытка изменить значение константного параметра
//}
//
//// Пример использования const с методами класса
//class MyClass {
//public:
//    int getValue() const { // Константный метод: не изменяет состояние объекта
//         
//        int d = 6;
//        d++;
//        
//        //value = 10; // Ошибка: попытка изменить член-данные внутри константного метода
//        return d;
//    }
//
//private:
//    int value = 5;
//};
//
//int main() {
//    constVariables();
//    constFunctionParams(3, 4);
//
//    const MyClass obj;
//    std::cout << "Value: " << obj.getValue() << std::endl;
//
//    return 0;
//}

//constexp



//указатели
//#include <iostream>
//
//int main()
//{
//    int a = 7;
//
//    int *i = &a;
//
//    std::cout << a << '\n'; // выводим значение переменной a
//    std::cout << &a << '\n'; // выводим адрес памяти переменной a
//    std::cout << *i << '\n'; /// выводим значение ячейки памяти переменной a
//
//    return 0;
//}


//#include <iostream>
//
//int main()
//{
//    int value = 5;
//    int* ptr = &value; // инициализируем ptr адресом значения переменной
//
//    std::cout << &value << '\n'; // выводим адрес значения переменной value
//    std::cout << ptr << '\n'; // выводим адрес, который хранит ptr
//
//    return 0;
//}

// 
#include <iostream>
int main()
{

    char* chPtr = new char(); // тип char занимает 1 байт
    int* iPtr = new int(); // тип int занимает 4 байта

    struct Something
    {
        int nX, nY, nZ;
    };
    
    Something* somethingPtr = new Something();

    std::cout << sizeof(chPtr) << " " << chPtr << '\n'; // выведется 4
    std::cout << sizeof(iPtr) << " " << iPtr << '\n'; // выведется 4
    std::cout << sizeof(somethingPtr) << " " << somethingPtr << '\n'; // выведется 4
}


//------------------------------------------------------------------------------
//new / delete
//#include <iostream>
//
//int main() {
//    // Выделение памяти для одного целочисленного элемента
//    int* ptr = new int;
//
//    // Проверка, удалось ли выделить память
//    if (ptr != nullptr) {
//        // Инициализация значения
//        *ptr = 42;
//
//        // Использование выделенной памяти
//        std::cout << "Value stored at ptr: " << *ptr << std::endl;
//
//        // Освобождение выделенной памяти
//        delete ptr; 
//
//        //std::cout << " " << *ptr << std::endl;
//
//        ptr = nullptr;
//    }
//    else {
//        std::cout << "Memory allocation failed!" << std::endl;
//    }
//
//    return 0;
//}

//------------------------------------------------------------------------------------------------
//массивы
//#include <iostream>
//
//int main()
//{
//    int array[5]; // массив из пяти чисел
//    
//    array[0] = 3; // индекс первого элемента - 0 (нулевой элемент)
//    array[1] = 2;
//    array[2] = 4;
//    array[3] = 8;
//    array[4] = 12; // индекс последнего элемента - 4 
//
//    std::cout << array[3];
//
//
//    double array[3]; // выделяем 3 переменные типа double
//    array[0] = 3.5;
//    array[1] = 2.4;
//    array[2] = 3.4;
//
//
//
//    //// Используем литерал 
//    //int array[7]; // хорошо
//
//    //// Используем макрос-объект с текст_замена в качестве символьной константы
//    //#define ARRAY_WIDTH 4
//    //int array[ARRAY_WIDTH]; // синтаксически хорошо, но не делайте этого
//
//    //// Используем символьную константу
//    //const int arrayWidth = 7;
//    //int array[arrayWidth]; // хорошо
//
//    //// Используем перечислитель
//    //enum ArrayElements
//    //{
//    //    MIN_ARRAY_WIDTH = 3
//    //};
//    //int array[MIN_ARRAY_WIDTH]; // хорошо
//
//    //// Используем неконстантную переменную
//    //int width;
//    //std::cin >> width;
//    //int array[width]; // плохо: width должна быть константой типа compile-time!
//
//    //// Используем константную переменную типа runtime
//    //int temp = 8;
//    //const int width = temp;
//    //int array[width]; // плохо: здесь width является константой типа runtime, но должна быть константой типа compile-time!
//
//
//
//    return 0;
//}

// массивы и перечисления
//enum StudentNames
//{
//    SMITH, // 0
//    ANDREW, // 1
//    IVAN, // 2
//    JOHN, // 3
//    ANTON, // 4
//    MAX_STUDENTS // 5
//};
//
//int main()
//{
//    int testScores[MAX_STUDENTS]; // всего 5 студентов
//    testScores[JOHN] = 65;
//
//    return 0;
//}



//#include <iostream>
//#include <array>
//
//void passValue(int value) // здесь value - это копия аргумента
//{
//    value = 87; // изменения value здесь не повлияют на фактическую переменную value
//}
//
//void passArray(/*const*/ int array[]) // здесь array - это фактический массив
//{
//    //auto s = std::size(array);
//    //auto s = sizeof(array) / sizeof(array[0]);
//
//   // *(array + 0) = 10;
//   // *(array + 1) = 8;
//    array[0] = 10; // изменения array здесь изменят исходный массив array
//    array[1] = 8;
//    array[2] = 6;
//    array[3] = 4;
//    array[4] = 1;
//    //array[100] = 1;
//
//    int arr[] = { 1, 2, 4, 5 };
//
//    //auto s = sizeof(arr) / sizeof(arr[0]);
//    std::cout << "Size of arr: " << std::size(arr) << std::endl;
//
//}
//
//int main()
//{
//    int value = 1;
//    std::cout << "before passValue: " << value << "\n";
//    passValue(value);
//    std::cout << "after passValue: " << value << "\n";
//
//    int array[5] = { 1, 4, 6, 8, 10 };
//    std::cout << "before passArray: " << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << "\n";
//    passArray(array);
//    std::cout << "after passArray: " << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << "\n";
//
//    return 0;
//}

// массивы и циклы

//#include <iostream>
//#include <algorithm>
//
//int main() {
//    int arr[] = { 1, 2, 3, 4, 5 };
//
//    // Проход по массиву с помощью цикла for
//    for (int i = 0; i < 5; ++i) {
//        std::cout << arr[i] << " ";
//    }
//
//    for (int* ptr = arr; ptr < arr + 5; ++ptr) {
//        std::cout << *ptr << " ";
//    }
//
//    for (int elem : arr) {
//        std::cout << elem << " ";
//    }
//
//    std::for_each(std::begin(arr), std::end(arr), 
//        [](const auto elem) {
//            std::cout << elem << " "; 
//        });
//
//    return 0;
//}

//----------------------------------------------------------------
//двумерные массивы

//#include <iostream>
//
//int main()
//{
//    // Объявляем массив 10x10 
//    const int numRows = 10;
//    const int numCols = 10;
//    int product[numRows][numCols] = { 0 };
//
//    // Создаем таблицу умножения
//    for (int row = 0; row < numRows; ++row)
//        for (int col = 0; col < numCols; ++col)
//            product[row][col] = row * col;
//
//    // Выводим таблицу умножения
//    for (int row = 1; row < numRows; ++row)
//    {
//        for (int col = 1; col < numCols; ++col)
//            std::cout << product[row][col] << "\t";
//
//        std::cout << '\n';
//    }
//
//    return 0;
//}
// 



// динамический массив 
//#include <iostream>
//
//int main()
//{
//    std::cout << "Enter a positive integer: ";
//    int length;
//    std::cin >> length;
//
//    int* array = new int[length]; // используем оператор new[] для выделения массива. Обратите внимание, переменная length не обязательно должна быть константой!
//
//    std::cout << "I just allocated an array of integers of length " << length << '\n';
//
//    array[0] = 7; // присваиваем элементу под индексом 0 значение 7
//
//    delete[] array; // используем оператор delete[] для освобождения выделенной массиву памяти
//    array = 0; // используйте nullptr вместо 0 в C++11
//
//    return 0;
//}

//---------------------------------------------------------------------------
// ссыдка
//#include <iostream>
//
//int main()
//{
//	int value = 7; // обычная переменная
//	int &ref = value; // ссылка на переменную value
//
//	value = 8; // value теперь 8
//	ref = 9; // value теперь 9
//
//	std::cout << value << std::endl; // выведется 9
//	++ref;
//	std::cout << value << std::endl; // выведется 10
//
//	std::cout << &value << std::endl;
//	std::cout << &ref << std::endl;;
//
//
//	return 0;
//}

//--------------------------------------------------------------------------
//С-style строки
//#include <iostream>
//
//int main()
//{
//    char mystring[] = "string";
//
//    mystring[4] = 'u';
//
//    std::cout << mystring << " has " << sizeof(mystring) << " characters.\n";
//    for (int index = 0; index < sizeof(mystring); ++index)
//        std::cout << mystring[index] << " ";
//    for (int index = 0; index < sizeof(mystring); ++index)
//        std::cout << static_cast<int>(mystring[index]) << " ";
//
//    return 0;
//}


//// ---
//#include <iostream>
//
//int main()
//{
//    char name[255]; // объявляем достаточно большой массив (для хранения 255 символов)
//    std::cout << "Enter your name: ";
//    std::cin >> name;
//    std::cout << "You entered: " << name << '\n';
//
//    return 0;
//}
//
//#include <iostream>
//
//int main()
//{
//    char name[255]; // объявляем достаточно большой массив (для хранения 255 символов)
//    std::cout << "Enter your name: ";
//    std::cin.getline(name, 255);
//    std::cout << "You entered: " << name << '\n';
//
//    return 0;
//}
//-----

//#include <iostream>
//#include <cstring>
//
//int main()
//{
//    char text[] = "Print this!";
//    char dest[50];
//    strcpy_s(dest, text);
//    std::cout << dest; // выводим "Print this!"
//
//    return 0;
//}

//#include <iostream>
//#include <cstring>
//
//int main()
//{
//    // Просим пользователя ввести строку
//    char buffer[255];
//    std::cout << "Enter a string: ";
//    std::cin.getline(buffer, 255);
//
//    int spacesFound = 0;
//    // Перебираем каждый символ, который ввел пользователь
//    for (int index = 0; index < strlen(buffer); ++index)
//    {
//        // Подсчитываем количество пробелов
//        if (buffer[index] == ' ')
//            spacesFound++;
//    }
//
//    std::cout << "You typed " << spacesFound << " spaces!\n";
//
//    return 0;
//}

//-----------------------------------------------------------------------------
//array

//#include <iostream>
//#include <array>
//
//int main()
//{
//	std::array<double, 4> myarray{ 8.0, 6.4, 4.3, 1.9 };
//	std::cout << "length: " << myarray.size();
//
//	return 0;
//}


//#include <iostream>
//#include <array>
//
//void printLength(const std::array<double, 4>& myarray)
//{
//    std::cout << "length: " << myarray.size();
//}
//
//int main()
//{
//    std::array<double, 4> myarray{ 8.0, 6.4, 4.3, 1.9 };
//
//    printLength(myarray);
//
//    return 0;
//}



//#include <iostream>
//#include <array>
//#include <algorithm> // для std::sort
//
//int main()
//{
//    std::array<int, 5> myarray{ 8, 4, 2, 7, 1 };
//    std::sort(myarray.begin(), myarray.end()); // сортировка массива по возрастанию
//    //    std::sort(myarray.rbegin(), myarray.rend()); // сортировка массива по убыванию
//
//    for (const auto& element : myarray)
//        std::cout << element << ' ';
//
//    return 0;
//}


//-------------------------------------------------------------------------------------
//vector
//#include <vector>
//#include <iostream>
//
//int main()
//{
//    std::vector<int> array{ 0, 1, 2 };
//    array.resize(7); // изменяем длину array на 7
//
//    std::cout << "The length is: " << array.size() << '\n';
//
//    for (auto const& element : array)
//        std::cout << element << ' ';
//
//    return 0;
//}

// что не так с кодом?
            //#include <iostream>

            //int main()
            //{
            //    int array[6]{ 0, 2, 4, 7, 9 };
            //    for (int count = 0; count <= 6; ++count)
            //        std::cout << array[count] << " ";

            //    return 0;
            //}

            //#include <iostream>

            //int main()
            //{
            //    int a = 4;
            //    int b = 6;

            //    const int* ptr = &a;
            //    std::cout << *ptr;
            //    *ptr = 7;
            //    std::cout << *ptr;
            //    ptr = &b;
            //    std::cout << *ptr;

            //    return 0;
            //}

            //#include <iostream>

            //void printArray(int array[])
            //{
            //    for (const int& element : array)
            //        std::cout << element << ' ';
            //}


            //int main()
            //{
            //    int array[]{ 8, 6, 4, 2, 0 };
            //    printArray(array);

            //    return 0;
            //}

            //#include <iostream>

            //int main()
            //{
            //    double d(4.7);
            //    int* ptr = &d;
            //    std::cout << ptr;

            //    return 0;
            //}

