// Module_4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// if
//#include <iostream>
////
//int main() {
//    int x;
//    std::cin >> x;
//    if (x <= 0) {
//        std::cout << "zero or negative\n";
//    }
//    else if (x == 1) {
//        std::cout << "one\n";
//    }
//    else if (x == 2) {
//        std::cout << "two\n";
//    }
//    else {
//        std::cout << "many\n";
//    }
//}

//#include <iostream>
//
//int main() {
//    int a, b, x;
//    /* Тут должна быть логика заполнения объявленных переменных */
//
//    if (a <= x && x <= b) {
//        // точка x лежит на отрезке [a; b]
//    }
//    else {
//        // точка x лежит вне отрезка [a; b]
//    }
//
//    // то же самое можно было бы проверить так:
//    if (!(x < a || x > b)) {  // отрицание
//        // точка x лежит на отрезке [a; b]
//    }
//    else {
//        // точка x лежит вне отрезка [a; b]
//    }
//}



//#include <iostream>
//
//int main()
//{
//    std::cout << "Enter a number: ";
//    int value;
//    std::cin >> value;
//
//    if (value > 10 && value < 20)
//        std::cout << "Your value is between 10 and 20" << std::endl;
//    else
//        std::cout << "Your value is not between 10 and 20" << std::endl;
//
//    return 0;
//}

//switch

//#include <cstdint>
//#include <iostream>
//
//int main() {
//    int64_t a, b;
//    char operation;
//    std::cin >> a >> operation >> b;
//
//    int64_t result = 0;
//    if (operation == '+') {
//        result = a + b;
//    }
//    else if (operation == '-') {
//        result = a - b;
//    }
//    else if (operation == '*') {
//        result = a * b;
//    }
//    else if (operation == '/' || operation == ':') {
//        result = a / b;
//    }
//    else if (operation == '%') {  // остаток от деления
//        result = a % b;
//    }
//
//    std::cout << result << "\n";
//}


//#include <cstdint>
//#include <iostream>
//
//int main() {
//    int64_t a, b;
//    char operation;
//    std::cin >> a >> operation >> b;
//
//    int64_t result;
//    switch (operation) {
//    case '+':
//        result = a + b;
//        break;  // если не написать этот break, программа просто пойдёт дальше в код следующего блока case
//    case '-':
//        result = a - b;
//        break;
//    case '*':
//        result = a * b;
//        break;
//    case '/':
//    case ':':
//        result = a / b;
//        break;
//    case '%':
//        result = a % b;
//        break;
//    default:  // здесь обрабатывается случай, когда ни один case не сработал.
//        result = 0;
//    }
//
//    std::cout << result << "\n";
//}

//#include <iostream>
//
//int main()
//{
//	int x = 5;
//	int y = 7;
//
//	if (!x == y)
//		std::cout << "x does not equal y";
//	else
//		std::cout << "x equals y";
//
//	return 0;
//}





// задача

//#include <iostream>
//
//int main() {
//    int array[] = { 10, 5, 45, 20, 15, 30 };
//    int maxElement = array[0]; // Предполагаем, что первый элемент массива - максимальный
//
//    // Проходим по всем элементам массива, начиная со второго
//    for (int i = 1; i < sizeof(array) / sizeof(array[0]); ++i) {
//        if (array[i] > maxElement) {
//            maxElement = array[i]; // Обновляем максимальный элемент, если находим больший
//        }
//    }
//
//    std::cout << "Максимальный элемент массива: " << maxElement << std::endl;
//
//    return 0;
//}
