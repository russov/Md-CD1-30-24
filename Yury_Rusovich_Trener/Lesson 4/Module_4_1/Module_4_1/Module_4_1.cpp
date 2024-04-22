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

//Побитовые операторы
//
//#include <iostream>
//
//int main() {
//    // Исходные числа для демонстрации операций
//    unsigned int a = 12; // 1100 в двоичном формате
//    unsigned int b = 10; // 1010 в двоичном формате
//
//    // Побитовое И (AND)
//    unsigned int result_and = a & b; // 1100 & 1010 = 1000
//    std::cout << "a & b = " << result_and << std::endl;
//
//    // Побитовое ИЛИ (OR)
//    unsigned int result_or = a | b; // 1100 | 1010 = 1110
//    std::cout << "a | b = " << result_or << std::endl;
//
//    // Побитовое исключающее ИЛИ (XOR)
//    unsigned int result_xor = a ^ b; // 1100 ^ 1010 = 0110
//    std::cout << "a ^ b = " << result_xor << std::endl;
//
//    // Побитовый сдвиг влево
//    unsigned int result_left_shift = a << 2; // 1100 << 2 = 110000
//    std::cout << "a << 2 = " << result_left_shift << std::endl;
//
//    // Побитовый сдвиг вправо
//    unsigned int result_right_shift = b >> 1; // 1010 >> 1 = 0101
//    std::cout << "b >> 1 = " << result_right_shift << std::endl;
//
//    // Побитовое НЕ (NOT)
//    unsigned int result_not_a = ~a; // ~1100 = 0011
//    std::cout << "~a = " << result_not_a << std::endl;
//
//    return 0;
//}