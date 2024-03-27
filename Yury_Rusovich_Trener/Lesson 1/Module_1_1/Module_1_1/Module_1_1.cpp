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
//#include <iomanip>
//
//int main()
//{
//    char buf[8];
//    std::cin >> std::setw(8) >> buf;
//    std::cout << "You entered: " << buf << std::endl;
//}


//#include <iostream>
//
//int main()
//{
//	char strBuf[100];
//	std::cin.getline(strBuf, 100);
//	std::cout << strBuf << std::endl;
//	std::cout << std::cin.gcount() << " characters were read" << std::endl;
//
//	return 0;
//}


//#include <iostream>     // std::cout, std::ios
//
//int main() {
//	std::cout.setf(std::ios::hex, std::ios::basefield);  // set hex as the basefield
//	std::cout.setf(std::ios::showbase);                  // activate showbase
//	std::cout << 100 << '\n';
//	std::cout.unsetf(std::ios::showbase);                // deactivate showbase
//	std::cout << 100 << '\n';
//	return 0;
//}


//#include <iostream>
//
//int main()
//{
//	std::cout << std::hex << 30 << '\n'; // выводим 30 в шестнадцатеричной системе счисления
//	std::cout << 31 << '\n'; // мы все еще находимся в шестнадцатеричной системе счисления
//	std::cout << std::dec << 32 << '\n'; // перемещаемся обратно в десятичную систему счисления
//}

//#include <iostream>
//
//int main()
//{
//	std::cout << true << " " << false << '\n';
//
//	std::cout.setf(std::ios::boolalpha);
//	std::cout << true << " " << false << '\n';
//
//	std::cout << std::noboolalpha << true << " " << false << '\n';
//
//	std::cout << std::boolalpha << true << " " << false << '\n';
//}


//#include <iostream>
//#include <iomanip> // для setprecision()
//
//int main()
//{
//	std::cout << std::fixed;
//	std::cout << std::setprecision(3) << 123.4567 << '\n';
//	std::cout << std::setprecision(4) << 123.45612 << '\n';
//	std::cout << std::setprecision(5) << 123.45634 << '\n';
//	std::cout << std::setprecision(6) << 123.45645 << '\n';
//	std::cout << std::setprecision(7) << 123.45645 << '\n';
//
//	std::cout << std::scientific << '\n';
//	std::cout << std::setprecision(3) << 123.456 << '\n';
//	std::cout << std::setprecision(4) << 123.456 << '\n';
//	std::cout << std::setprecision(5) << 123.456 << '\n';
//	std::cout << std::setprecision(6) << 123.456 << '\n';
//	std::cout << std::setprecision(7) << 123.456 << '\n';
//}


//#include <iostream>
//#include <iomanip> // для setw()
//
//int main()
//{
//	std::cout.fill('5');
//	std::cout << -12345 << '\n'; // выводим значение без использования ширины поля
//	std::cout << std::setw(10) << -12345 << '\n'; // выводим значение с использованием ширины поля
//	std::cout << std::setw(10) << std::left << -12345 << '\n'; // выравниваем по левому краю
//	std::cout << std::setw(10) << std::right << -12345 << '\n'; // выравниваем по правому краю
//	std::cout << std::setw(10) << std::internal << -12345 << '\n'; // знак значения выравнивается по левому краю, а само значение - по правому
//}


//----------------------------------------------------------------------------------------------------
// простые операции

//#include <iostream>

//void main() {
//    int a = 15, b = 5;
//    std::cout << "a + b = " << (a + b) << std::endl;
//    std::cout << "a - b = " << (a - b) << std::endl;
//    std::cout << "a * b = " << (a * b) << std::endl;
//    std::cout << "a / b = " << (a / b) << std::endl;
//    std::cout << "a % b = " << (a % b) << std::endl;
//    return;
//}


#include <iostream>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}


char add1(int a, int b) {


    return 'f';
}


void add2() {

    std::cout << "add2" << std::endl;
    return;
}

int main() {

    add2();
    int x = 5, y = 10;
    int sum = add(x, y);
    std::cout << "Sum of " << x << " and " << y << " is \n" << sum << std::endl;
    return 0;
}
