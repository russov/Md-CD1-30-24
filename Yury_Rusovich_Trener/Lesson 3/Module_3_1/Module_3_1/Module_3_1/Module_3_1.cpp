// Module_3_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <clocale>
//#include <Windows.h>
//
//int main()
//{
//    std::cout << "bool:\t\t" << sizeof(bool) << " bytes" << std::endl;
//    std::cout << "char:\t\t" << sizeof(char) << " bytes" << std::endl;
//    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << std::endl;
//    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << std::endl;
//    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << std::endl;
//    std::cout << "short:\t\t" << sizeof(short) << " bytes" << std::endl;
//    std::cout << "int:\t\t" << sizeof(int) << " bytes" << std::endl;
//    std::cout << "long:\t\t" << sizeof(long) << " bytes" << std::endl;
//    std::cout << "long long:\t" << sizeof(long long) << " bytes" << std::endl;
//    std::cout << "float:\t\t" << sizeof(float) << " bytes" << std::endl;
//    std::cout << "double:\t\t" << sizeof(double) << " bytes" << std::endl;
//    return 0;
//}



//-------------------------------------------------------------------------------------
// char

//#include <iostream>
//#include <cstdint>
//
//int main()
//{
//    char c = 128;
//    char c2 = '\t';
//    std::cout << c << std::endl;
//    std::cout << (int)c2 << std::endl;  
//    
//    std::int8_t h;
//    char16_t g{5};
//
//    // как вывести 65?
//
//    return 0;
//}


//-------------------------------------------------------------------------------------
// переполнение

//#include <iostream>
//
// void doSomething(unsigned int x)
// {
//     std::cout << x;
// }
 
// int main()
// {
//     {
//         unsigned short x = 65535;
//         std::cout << "x was: " << x << std::endl;
//         x = x + 1;
//         std::cout << "x is now: " << x << std::endl;
//     }
//     {
//         unsigned short x = 0;
//         std::cout << "x was: " << x << std::endl;
//         x = x - 1;
//         std::cout << "x is now: " << x << std::endl;
//     }
//
//     int8_t f;
//
//     // что будет выведено на экран?
//     doSomething(-1);
//
//    return 0;
//}


//-------------------------------------------------------------------------------------
// doble

//#include <iostream>
//#include <iomanip>
//
//int main()
//{
//    std::cout << std::setprecision(16);
//    float f = 3.33333333333333333333333333333333333333f;
//    std::cout << f << std::endl;
//    double d = 3.3333333333333333333333333333333333333;
//    std::cout << d << std::endl;
//    return 0;
//}

// какие могут быть проблемы с double?

//#include <iostream>
//#include <iomanip>
//
//int main()
//{
//    double d(0.1);
//    std::cout << d << std::endl; // используем точность cout по умолчанию (6 цифр)
//    std::cout << std::setprecision(17);
//    std::cout << d << std::endl;
//    return 0;
//}

//#include <iostream>
//#include <cmath> // Для функции fabs (absolute value)
//#include <iomanip>
//
//int main() {
//    double a = 0.1 + 0.2;
//    double b = 0.3;
//
//    std::cout << std::setprecision(17);
//
//    // Сравнение с погрешностью
//    if (fabs(a - b) < std::numeric_limits<double>::epsilon()) {
//        std::cout << "a= " << a << " and b= " << b << " is equal" << std::endl;
//    }
//    else {
//        std::cout << "a and b is not equal" << std::endl;
//    }
//
//    return 0;
//}

//-------------------------------------------------------------------------------------
// bool


//#include <iostream>
//
//int main()
//{
//	const int x{ 5 };
//	const bool b{ true };
//    int y = !x;
//
//    //if (x == 0) 
//    //if (b)
//    //if (x)
//    if (!x)
//        std::cout << "true" << std::endl;
//    else
//        std::cout << "false" << std::endl;
//
//    return 0;
//}

//------------------------------------------------------------------------------------
// циклы

//while
//#include <iostream>
//
//int main()
//{
//    int count = 0; // счетчик циклов
//    while (count < 10)
//    {
//        std::cout << count << " ";
//        ++count;
//    }
//    std::cout << "done!";
//
//    return 0;
//}

//#include <iostream>
//
//int main()
//{
//    int count = 1;
//    while (count <= 50)
//    {
//        // Выводим числа до 10 (перед каждым числом добавляем 0)
//        if (count < 10)
//            std::cout << "0" << count << " ";
//        else
//            std::cout << count << " "; // выводим остальные числа 
//
//        // Если счетчик цикла делится на 10 без остатка, то тогда вставляем символ новой строки
//        if (count % 10 == 0)
//            std::cout << "\n";
//
//        // Увеличиваем значение счетчика цикла на единицу 
//        ++count;
//    }
//
//    return 0;
//}

// do while
//#include <iostream>
//
//int main()
//{
//    // Переменная choice должна быть объявлена вне цикла do while 
//    int choice;
//
//    do
//    {
//        std::cout << "Please make a selection: \n";
//        std::cout << "1) Addition\n";
//        std::cout << "2) Subtraction\n";
//        std::cout << "3) Multiplication\n";
//        std::cout << "4) Division\n";
//        std::cin >> choice;
//    } while (choice != 1 && choice != 2 &&
//        choice != 3 && choice != 4);
//
//    // Что-то делаем с переменной choice, например, используем оператор switch
//
//    std::cout << "You selected option #" << choice << "\n";
//
//    return 0;
//}

 //цикл for
//#include <iostream>
//
//int main()
//{
//
//   // int i = 0;
//   //// auto ii = ++i;
//   // auto ii = i++;
//   // std::cout << "i = " << i << " ii = " << ii << std::endl;
//
//    //size_t
//    ////
//    //    for (size_t i = 0; i < length; i++)
//    //    {
//
//    //    }
//
//    int count(0);
//
//    for (count = 0; count < 10; count++) {
//        std::cout << count << " ";
//
//    }
//
//    for (count = 0; count < 10; count++) {
//        std::cout << count << " ";
//
//    }
//
//
//    return 0;
//}


//#include <iostream>
//
//int main()
//{
//	for (int count = 8; count >= 0; --count)
//		std::cout << count << " ";
//
//	return 0;
//}

//#include <iostream>
//
//int main()
//{
//	int count = 0;
//	for (; count < 10; )
//	{
//		std::cout << count << " ";
//		++count;
//	}
//
//	return 0;
//}

//#include <iostream>
//
//int main()
//{
//	int aaa, bbb;
//	for (aaa = 0, bbb = 9; aaa < 10 && bbb>10; ++aaa, --bbb)
//		std::cout << aaa << " " << bbb << std::endl;
//
//	return 0;
//}

//#include <iostream>
//
//int main()
//{
//	for (char c = 'a'; c <= 'e'; ++c) // внешний цикл по буквам
//	{
//		std::cout << c; // сначала выводим букву
//
//		for (int i = 0; i < 3; ++i) // внутренний цикл по числам
//			std::cout << i;
//
//		std::cout << '\n';
//	}
//
//	return 0;
//}

////foreach
//#include <iostream>
//
//int main()
//{
//    const int numStudents = 7;
//    int scores[numStudents] = { 45, 87, 55, 68, 80, 90, 58 };
//    int maxScore = 0; // отслеживаем индекс наибольшего score (значения)
//    for (const auto& score : scores) // итерация по массиву, присваиваем каждое значение массива поочередно переменной score
//        if (score > maxScore)
//            maxScore = score;
//
//    std::cout << "The best score was " << maxScore << '\n';
//
//    return 0;
//}


//#include <vector>
//#include <iostream>
//
//int main()
//{
//    std::vector<int> math = { 0, 1, 4, 5, 7, 8, 10, 12, 15, 17, 30, 41 };
//    for (const auto& number : math)
//        std::cout << number << ' ';
//
//    return 0;
//}

//break, return, continue
//#include <iostream>
//
//int breakOrReturn()
//{
//    while (true) // бесконечный цикл
//    {
//        std::cout << "Enter 'b' to break or 'r' to return: ";
//        char sm;
//        std::cin >> sm;
//
//        if (sm == 'b')
//            break; // выполнение кода продолжится с первого стейтмента после цикла
//
//        if (sm == 'r')
//            return 1; // выполнение return приведет к тому, что управление сразу возвратится в caller (в этом случае, в функцию main())
//    }
//
//    // Использование оператора break приведет к тому, что выполнение цикла продолжится здесь
//
//    std::cout << "We broke out of the loop\n";
//
//    return 0;
//}
//
//int main()
//{
//    int returnValue = breakOrReturn();
//    std::cout << "Function breakOrContinue returned " << returnValue << '\n';
//
//    return 0;
//}


//#include <iostream>
//
//int main()
//{
//	for (int count = 0; count < 20; ++count)
//	{
//		// Если число делится нацело на 4, то пропускаем весь код в этой итерации после continue 
//		if ((count % 4) == 0)
//			continue; // пропускаем всё и переходим в конец тела цикла 
//
//		// Если число не делится нацело на 4, то выполнение кода продолжается
//		std::cout << count << std::endl;
//
//		// Точка выполнения после оператора continue перемещается сюда 
//	}
//
//	return 0;
//}


//------------------------------------------------------------------------------------
// Арифметические операторы

 //унарный оператор
//#include <iostream>
//
//int main() {
//    int x = 10;
//    int result = -x; // унарный оператор "-", меняющий знак числа
//    std::cout << "Result: " << result << std::endl; // Вывод: Result: -10
//    return 0;
//}

// бинарные операторы
//#include <iostream>
//
//int main() {
//    int a = 10, b = 5;
//
//    // Сложение
//    int sum = a + b;
//    std::cout << "Sum: " << sum << std::endl;
//
//    // Вычитание
//    int difference = a - b;
//    std::cout << "Difference: " << difference << std::endl;
//
//    // Умножение
//    int product = a * b;
//    std::cout << "Product: " << product << std::endl;
//
//    // Деление
//    int quotient = a / b; // Результатом будет целочисленное деление
//    std::cout << "Quotient: " << quotient << std::endl;
//
//    // Остаток от деления
//    int remainder = a % b;
//    std::cout << "Remainder: " << remainder << std::endl;
//
//    return 0;
//}

//оператор присваивания
//#include <iostream>
//
//int main() {
//    int a = 10, b = 5;
//
//    // Оператор присваивания
//    int c = a;
//    std::cout << "c after assignment: " << c << std::endl;
//
//    // Оператор присваивания суммы
//    c += b;
//    std::cout << "c after addition: " << c << std::endl;
//
//    // Оператор присваивания разности
//    c -= b;
//    std::cout << "c after subtraction: " << c << std::endl;
//
//    // Оператор присваивания произведения
//    c *= b;
//    std::cout << "c after multiplication: " << c << std::endl;
//
//    // Оператор присваивания частного
//    c /= b;
//    std::cout << "c after division: " << c << std::endl;
//
//    // Оператор присваивания остатка от деления
//    c %= b;
//    std::cout << "c after modulus: " << c << std::endl;
//
//    return 0;
//}

//возведение в степень
//#include <iostream>
////#include <cmath>
//
//int main() {
//    double base = 2.0;
//    int exponent = 3;
//
//    double result = std::pow(base, exponent);
//
//    std::cout << base << " в степени " << exponent << " равно " << result << std::endl;
//
//    return 0;
//}

//-------------------------------------------------------------------------------------
// приоритет операций

//#include <iostream>
//
//int main() {
//    int a = 5, b = 3, c = 2;
//
//    // Арифметические операции
//    int result1 = a + b * c;  // Приоритет у умножения
//    int result2 = (a + b) * c;  // Использование скобок для изменения порядка операций
//
//    std::cout << "Результат 1: " << result1 << std::endl; // Вывод 11
//    std::cout << "Результат 2: " << result2 << std::endl; // Вывод 16
//
//    // Операции сравнения
//    bool is_greater = a > b && b > c;  // Приоритет у сравнения
//    bool is_equal = a == b || b == c;  // Использование логических операций
//
//    std::cout << "Больше: " << std::boolalpha << is_greater << std::endl; // Вывод true
//    std::cout << "Равны: " << std::boolalpha << is_equal << std::endl; // Вывод false
//
//    // Операции присваивания
//    int x = 10;
//    x += 5 * 2;  // Приоритет у умножения, затем сложение
//
//    std::cout << "x = " << x << std::endl; // Вывод 20
//
//
//    // Пример с тернарным оператором
//    int g = 10, h = 5;
//    int max = g > h ? g : h;
//    std::cout << "Max (ternary): " << max << std::endl;
//
//    return 0;
//}




//#include <iostream>
//#include <string>
//
//void main() {
//	int i = 5.0;
//	double d = 5.0;
//	std::string s = "e";
//
//	//std::t
//
//	if (i == std::stoi(s))
//		std::cout << "true";
//
//
//}