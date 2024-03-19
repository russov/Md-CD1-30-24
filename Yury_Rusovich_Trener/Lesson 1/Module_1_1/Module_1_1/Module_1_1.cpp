// Module_1_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}



//#include <iostream>
// 
//int main() {
//    int number;
//    std::cout << "Enter a number: ";
//    std::cin >> number;
//    std::cout << "You entered: " << number << std::endl;
//    return 0;
//}



//#include <iostream>
//
//int main() {
//    int a = 10, b = 5;
//    std::cout << "a + b = " << (a + b) << std::endl;
//    std::cout << "a - b = " << (a - b) << std::endl;
//    std::cout << "a * b = " << (a * b) << std::endl;
//    std::cout << "a / b = " << (a / b) << std::endl;
//    std::cout << "a % b = " << (a % b) << std::endl;
//    return 0;
//}


#include <iostream>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}
int main() {
    int x = 5, y = 10;
    int sum = add(x, y);
    std::cout << "Sum of " << x << " and " << y << " is " << sum << std::endl;
    return 0;
}
