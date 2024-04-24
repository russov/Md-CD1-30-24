


// Передача параметра по значению

//#include <iostream>
//
//int add(int a, int b)
//{
//	return a + b;
//}
//
//int multiply(int c, int d)
//{
//	return c * d;
//}
//
//int main()
//{
//	std::cout << add(7, 8) << std::endl; // внутри функции add(): a = 7, b = 8, значит a + b = 15
//	std::cout << multiply(4, 5) << std::endl; // внутри функции multiply(): c = 4, d = 5, значит c * d = 20
//
//	// Мы можем передавать целые выражения в качестве аргументов
//	std::cout << add(2 + 3, 4 * 5) << std::endl; // внутри функции add(): a = 5, b = 20, значит a + b = 25
//
//	// Мы можем передавать переменные в качестве аргументов
//	int x = 4;
//	std::cout << add(x, x) << std::endl; // будет 4 + 4
//
//	std::cout << add(1, multiply(2, 3)) << std::endl; // будет 1 + (2 * 3)
//	std::cout << add(1, add(2, 3)) << std::endl; // будет 1 + (2 + 3)
//
//	return 0;
//}

// передача параметра по ссылкке
//#include <iostream>
//
//void addOne(int& x) // x - это переменная-ссылка
//{
//    x = x + 1;
//} // x уничтожается здесь
//
//int main()
//{
//    int a = 7;
//    std::cout << "a = " << a << '\n';
//    addOne(a);
//    std::cout << "a = " << a << '\n';
//    return 0;
//}



//#include <iostream>
//#include <math.h> // для sin() и cos()
//
//void getSinCos(double degrees, double& sinOut, double& cosOut)
//{
//    // sin() и cos() принимают радианы, а не градусы, поэтому необходима конвертация
//    const double pi = 3.14159265358979323846; // значение Пи
//    double radians = degrees * pi / 180.0;
//    sinOut = sin(radians);
//    cosOut = cos(radians);
//}
//
//int main()
//{
//    double sin(0.0);
//    double cos(0.0);
//
//    // Функция getSinCos() возвратит sin и cos в переменные sin и cos
//    getSinCos(30.0, sin, cos);
//
//    std::cout << "The sin is " << sin << '\n';
//    std::cout << "The cos is " << cos << '\n';
//    return 0;
//}


//передача по указателю

// что здесь выведется на экран?
//#include <iostream>
//
//void setToNull(int* tempPtr)
//{
//    
//    tempPtr = nullptr; 
//
//    
//}
//
//int main()
//{
//    // Сначала мы присваиваем ptr адрес six, т.е. *ptr = 6
//    int six = 6;
//    int* ptr = &six;
//
//    // Здесь выведется 6
//    std::cout << *ptr << "\n";
//
//    // tempPtr получит копию ptr
//    setToNull(ptr);
//
//    // Здесь выведется 6
//    if (ptr)
//        std::cout << *ptr << "\n";
//    else
//        std::cout << " ptr is null";
//
//    return 0;
//}

//------------------------------------------------------------------------------------------
// параметры по умолчанию

//#include <iostream>
//
//// Функция с параметрами по умолчанию
//void greet(std::string name = "World", int times = 1) {
//    for (int i = 0; i < times; ++i) {
//        std::cout << "Hello, " << name << "!" << std::endl;
//    }
//}
//
//int main() {
//    // Вызов функции без передачи аргументов (будут использованы значения по умолчанию)
//    greet();  // Выведет: Hello, World!
//
//    // Вызов функции с передачей только одного аргумента
//    greet("Alice");  // Выведет: Hello, Alice!
//
//    // Вызов функции с передачей обоих аргументов
//    greet("Bob", 3);  // Выведет:
//    // Hello, Bob!
//    // Hello, Bob!
//    // Hello, Bob!
//
//    return 0;
//}

//---------------------------------------------------------------------------------------------
// Перегрузка функций

//#include <iostream>
//
//void print(int x) {
//    std::cout << "Integer: " << x << std::endl;
//}
//
//void print(double x) {
//    std::cout << "Double: " << x << std::endl;
//}
//
//int main() {
//    int a = 5;
//    double b = 3.14;
//
//    print(a); 
//    print(b); 
//
//    return 0;
//}



// что тут не так
//void print(unsigned int value){};
//void print(float value) {};
//
//void main() {
//	print('b');
//	print(0);
//	print(3.14159);
//}