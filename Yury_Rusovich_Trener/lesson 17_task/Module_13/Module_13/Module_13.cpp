// ------------------------------------------------------------------------------------------------
// functor

//#include <iostream>
//
//class Print
//{
//public:
//    void operator()(const std::string& message) const
//    {
//        std::cout << message << std::endl;
//    }
//};
//
//int main()
//{
//    Print print;    // создание объекта
//    print("Hello"); // вызов функтора (как функцию)
//    print("World"); // вызов функтора (как функцию)
//}

// ------------------------------------------------------------------------------------------------

//#include <iostream>
//
//class Id
//{
//public:
//    unsigned operator()()
//    {
//        return ++id;
//    }
//private:
//    unsigned id{};
//};
//
//int main()
//{
//    Id id;
//    std::cout << id() << std::endl;
//    std::cout << id() << std::endl;
//    std::cout << id() << std::endl;
//}

// ------------------------------------------------------------------------------------------------

//#include <iostream>
//
//int main()
//{
//    []() {std::cout << "Hello world" << std::endl; }; // ();
//}

// ------------------------------------------------------------------------------------------------

//#include <iostream>
//
//int main()
//{
//    auto hello{ []() {std::cout << "Hello world" << std::endl; } };
//
//    hello();
//}

// ------------------------------------------------------------------------------------------------

//#include <iostream>
//
//int main()
//{
//    auto print{ [](const std::string& text) {std::cout << text << std::endl; } };
//
//    print("Hello World!");
//}

// ------------------------------------------------------------------------------------------------

//#include <iostream>
//
//int main()
//{
//    auto sum{ [](int a, int b) -> double {return a + b; } };
//
//    std::cout << sum(10, 23) << std::endl;
//}

// ------------------------------------------------------------------------------------------------
// Лямбда - выражения как параметры функций

//#include <iostream>
//
//void function(int a, int b, int (*op)(int, int))
//{
//    std::cout << op(a, b) << std::endl;
//}
//
//int main()
//{
//    auto sum{ [](int a, int b) {return a + b; } };
//    //auto sum = [](int a, int b) {return a + b; };
//
//    function(4, 4, sum);
//}

// ------------------------------------------------------------------------------------------------
// generic lambda

//#include <iostream>
//
//int main()
//{
//    auto add = [](auto a, auto b) {return a + b; };
//    auto print = [](const auto& value) {std::cout << value << std::endl; };
//
//    std::cout << add(2, 3) << std::endl;
//
//    std::string hello{ "hello " };
//    std::string world{ "world" };
//    print( add(hello, world) ); 
//}






//#include <algorithm>
//#include <array>
//#include <iostream>
//#include <string_view>
//
//int main()
//{
//    std::array months{
//      "January",
//      "February",
//      "March",
//      "April",
//      "May",
//      "June",
//      "July",
//      "August",
//      "September",
//      "October",
//      "November",
//      "December"
//    };
//
//    // Поиск двух последовательных месяцев, которые начинаются с одинаковой буквы
//    auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
//                                        [](const auto& a, const auto& b) {
//                                          return (a[0] == b[0]);
//                                        }) };
//
//    // Убеждаемся, что эти два месяца были найдены
//    if (sameLetter != months.end())
//    {
//        std::cout << *sameLetter << " and " << *std::next(sameLetter)
//            << " start with the same letter\n";
//    }
//
//    return 0;
//}




// generic lambda и статические переменные

//#include <algorithm>
//#include <array>
//#include <iostream>
//#include <string_view>
//
//int main()
//{
//    // Выводим значение и подсчитываем, сколько раз будет вызван print
//    auto print{
//      [](auto value) {
//        static int callCount{ 0 };
//        std::cout << callCount++ << ": " << value << '\n';
//      }
//    };
//
//    print("hello"); // 0: hello
//    print("world"); // 1: world
//
//    print(1); // 0: 1
//    print(2); // 1: 2
//
//    print("ding dong"); // 2: ding dong
//
//    return 0;
//}




// возвращаемый тип auto

//#include <iostream>
//
//int main()
//{
//    auto divide{ [](int x, int y, bool bInteger) /*-> double*/ { // примечание: Не указан тип возвращаемого значения
//      if (bInteger)
//        return x / y;
//      else
//        return static_cast<double>(x) / y; // ОШИБКА: 
//    } };
//
//    std::cout << divide(3, 2, true) << '\n';
//    std::cout << divide(3, 2, false) << '\n';
//
//    return 0;
//}

// ------------------------------------------------------------------------------------------------
// лямбда-захват
// все внешние переменные

//#include <iostream>
//
//int main()
//{
//    int i{ 10 };
//    int y{ 5 };
//
//    auto lambda{ [= /*&*/](int x) /*mutable*/ { std::cout << x + i + y << std::endl; }};
//    
//    lambda(4);
//}

// ------------------------------------------------------------------------------------------------
// лямбда-захват
// mutable

//#include <iostream>
//
//int main()
//{
//    int n{ 10 };
//    auto increment = [=]() mutable {
//        n++;
//        std::cout << "n inside lambda: " << n << std::endl;
//        };
//    increment();
//    std::cout << "n outside lambda: " << n << std::endl;
//}




//#include <algorithm>
//#include <array>
//#include <iostream>
//#include <string>
//
//struct Car
//{
//    std::string make{};
//    std::string model{};
//};
//
//int main()
//{
//    std::array<Car, 3> cars{ { { "Volkswagen", "Golf" },
//                               { "Toyota", "Corolla" },
//                               { "Honda", "Civic" } } };
//
//    int comparisons{ 0 };
//
//    std::sort(cars.begin(), cars.end(),
//        // Захват переменной comparisons по ссылке
//        [&comparisons](const auto& a, const auto& b) {
//            // Мы захватили переменную comparisons по ссылке, а это означает, что мы можем изменять её без использования спецификатора mutable
//            ++comparisons;
//
//            // Сортировка машин по марке
//            return (a.make < b.make);
//        });
//
//    std::cout << "Comparisons: " << comparisons << '\n';
//
//    for (const auto& car : cars)
//    {
//        std::cout << car.make << ' ' << car.model << '\n';
//    }
//
//    return 0;
//}




//Определение новых переменных в лямбда-захвате
//#include <array>
//#include <iostream>
//
//int main()
//{
//    std::array areas{ 100, 25, 121, 40, 56 };
//
//    int width{};
//    int height{};
//
//    std::cout << "Enter width and height: ";
//    std::cin >> width >> height;
//
//    // Мы храним переменную areas, но пользователь ввел width и height.
//    // Прежде, чем выполнить операцию поиска, мы должны вычислить значение площади (area)
//    auto found{ std::find_if(areas.begin(), areas.end(),
//        // Объявляем новую переменную, которая видима только для лямбды.
//        // Тип переменной userArea автоматически выведен как тип int
//        [userArea{ width * height }](int knownArea) {
//          return (userArea == knownArea);
//        }) };
//
//    if (found == areas.end())
//    {
//        std::cout << "I don't know this area :(\n";
//    }
//    else
//    {
//        std::cout << "Area found :)\n";
//    }
//
//    return 0;
//}





// ------------------------------------------------------------------------------------------------
// лямбда-захват
// захват членов класса

//#include <iostream>
//
//class MyClass {
//public:
//    MyClass(int value) : member(value) {}
//
//    void printMember() {
//        // Лямбда-выражение, которое захватывает переменную-член класса
//        auto lambda = [this]() {
//            // Обращение к переменной-члену класса внутри лямбда-выражения
//            std::cout << "Member value: " << member << std::endl;
//            };
//
//        // Вызов лямбда-выражения
//        lambda();
//    }
//
//private:
//    int member;
//};
//
//int main() {
//    MyClass obj(42);
//    obj.printMember(); // Выводит "Member value: 42"
//
//    return 0;
//}



//копирование лямбд
//#include <iostream>
//
//int main()
//{
//    int i{ 0 };
//
//    // Создаем новую лямбду с именем count
//    auto count{ [i]() mutable {
//      std::cout << ++i << '\n';
//    } };
//
//    count(); // обращаемся к count
//
//    auto otherCount{ count }; // создаем копию count
//
//    // Обращаемся к count и к копии count
//    count();
//    otherCount();
//
//    return 0;
//}



//решение проблемы с копированием лямбд
//#include <iostream>
//#include <functional>
//
//void invoke(const std::function<void(void)>& fn)
//{
//    fn();
//}
//
//int main()
//{
//    int i{ 0 };
//
//    // Выполняем инкремент и выводим на экран локальную копию переменной i
//    auto count{ [i]() mutable {
//      std::cout << ++i << '\n';
//    } };
//
//    // std::ref(count) гарантирует, что count рассматривается, как ссылка.
//    // Таким образом, всё, что пытается скопировать count, фактически является ссылкой,
//    // гарантируя тем самым существование только одного объекта count
//    invoke(std::ref(count));
//    invoke(std::ref(count));
//    invoke(std::ref(count));
//
//    return 0;
//}



// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// сравнение функтора и лямбды
// функтор

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// Функтор для сравнения строк по длине
//struct LengthComparator {
//    bool operator()(const std::string& a, const std::string& b) const {
//        return a.length() < b.length(); // Сортировка по возрастанию длины строки
//    }
//};
//
//int main() {
//    std::vector<std::string> words = { "apple", "banana", "orange", "grape", "kiwi" };
//
//    // Сортировка вектора строк по их длине, используя функтор
//    std::sort(words.begin(), words.end(), LengthComparator());
//
//    // Вывод отсортированного вектора строк
//    for (const auto& word : words) {
//        std::cout << word << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

// ------------------------------------------------------------------------------------------------
// сравнение функтора и лямбды
// лямбда


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main() {
//    std::vector<std::string> words = { "apple", "banana", "orange", "grape", "kiwi" };
//
//    // Сортировка вектора строк по их длине, используя лямбда-выражение
//    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
//        return a.length() < b.length(); // Сортировка по возрастанию длины строки
//        });
//
//    // Вывод отсортированного вектора строк
//    for (const auto& word : words) {
//        std::cout << word << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}

// ------------------------------------------------------------------------------------------------
// example

//#include <iostream>
//#include <string>
//
//int main()
//{
//    std::string favoriteFruit{ "grapes" };
//
//    auto printFavoriteFruit{
//      [=]() {
//        std::cout << "I like " << favoriteFruit << '\n';
//      }
//    };
//
//    favoriteFruit = "bananas with chocolate";
//
//    printFavoriteFruit();
//
//    return 0;
//}





//-----------------------------------------------------------------------------------------------------------------------------------
//Исключения
//#include <iostream>
//#include <string>
//
//int main()
//{ 
//    try
//    {
//        // Здесь мы пишем стейтменты, которые будут генерировать следующее исключение
//        throw "- 1.0" ; // типичный стейтмент throw
//    }
//    catch (int a)
//    {
//        // Любые исключения типа int, сгенерированные в блоке try, приведенном выше, обрабатываются здесь
//        std::cerr << "We caught an int exception with value: " << a << '\n';
//    }
//    catch (double) // мы не указываем имя переменной, так как в этом нет надобности (мы её нигде в блоке не используем)
//    {
//        // Любые исключения типа double, сгенерированные в блоке try, приведенном выше, обрабатываются здесь
//        std::cerr << "We caught an exception of type double" << '\n';
//    }
//    catch (const char* str) // ловим исключения по константной ссылке
//    {
//        // Любые исключения типа std::string, сгенерированные внутри блока try, приведенном выше, обрабатываются здесь
//        std::cerr << "We caught an exception of type std::string" << '\n';
//    }
//
//    std::cout << "Continuing our way!\n";
//
//    return 0;
//}






//// пример: исключения выполняются немедленно
//#include <iostream>
//
//int main()
//{
//    try
//    {
//        throw 7.4; // выбрасывается исключение типа double
//        std::cout << "This never prints\n";
//    }
//    catch (double a) // обрабатывается исключение типа double
//    {
//        std::cerr << "We caught a double of value: " << a << '\n';
//    }
//
//    return 0;
//}




//раскручивание стека
//#include <iostream>
//
//void last() // вызывается функцией three()
//{
//    std::cout << "Start last\n";
//    std::cout << "last throwing int exception\n";
//    throw - 1;
//    std::cout << "End last\n";
//
//}
//
//void three() // вызывается функцией two()
//{
//    std::cout << "Start three\n";
//    last();
//    std::cout << "End three\n";
//}
//
//void two() // вызывается функцией one()
//{
//    std::cout << "Start two\n";
//    try
//    {
//        three();
//    }
//    catch (double)
//    {
//        std::cerr << "two caught double exception\n";
//    }
//    std::cout << "End two\n";
//}
//
//void one() // вызывается функцией main()
//{
//    std::cout << "Start one\n";
//    try
//    {
//        two();
//    }
//    catch (int)
//    {
//        std::cerr << "one caught int exception\n";
//    }
//    catch (double)
//    {
//        std::cerr << "one caught double exception\n";
//    }
//    std::cout << "End one\n";
//}
//
//int main()
//{
//    std::cout << "Start main\n";
//    try
//    {
//        one();
//    }
//    catch (int)
//    {
//        std::cerr << "main caught int exception\n";
//    }
//    std::cout << "End main\n";
//
//    return 0;
//}
//
//



// обработка любого исключения
//#include <iostream>
//
//int main()
//{
//	try
//	{
//		throw 7; // выбрасывается исключение типа int
//	}
//	catch (double a)
//	{
//		std::cout << "We caught an exception of type double: " << a << '\n';
//	}
//	catch (...) // обработчик catch-all
//	{
//		std::cout << "We caught an exception of an undetermined type!\n";
//	}
//}






//классыиисключения
//#include <iostream>
//#include <string>
//#include <array>
//
//class ArrayException
//{
//private:
//	std::string m_error;
//
//public:
//	ArrayException(std::string error)
//		: m_error(error)
//	{
//	}
//
//	const char* getError() { return m_error.c_str(); }
//};
//
//class ArrayInt
//{
//private:
//
//	int m_data[4]; // ради сохранения простоты примера укажем значение 4 в качестве длины массива
//public:
//	ArrayInt() {}
//
//	int getLength() { return 4; }
//
//	int& operator[](const int index)
//	{
//		if (index < 0 || index >= getLength())
//			throw ArrayException("Invalid index");
//
//		return m_data[index];
//	}
//
//};
//
//int main()
//{
//	std::array array{ 3 };
//
//	try
//	{
//		int value = array[7];
//	}
//	catch (std::exception& exception)
//	{
//		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
//	}
//}





//стандартное исключение
//#include <iostream>
//#include <exception> // для std::exception
//#include <string> // для этого примера
//
//int main()
//{
//	try
//	{
//		// Здесь должен находиться код, использующий Стандартную библиотеку С++.
//		// Сейчас мы намеренно спровоцируем генерацию одного из исключений
//		std::string s;
//		s.resize(-1); // генерируется исключение std::bad_alloc
//	}
//	// Этот обработчик ловит std::exception и все дочерние ему классы-исключения
//	catch (std::exception& exception)
//	{
//		std::cerr << "Standard exception: " << exception.what() << '\n';
//	}
//
//	return 0;
//}




//использование стандартного исключения
//#include <iostream>
//#include <stdexcept>
//
//int main()
//{
//	try
//	{
//		throw std::runtime_error("Bad things happened");
//	}
//	// Этот обработчик ловит std::exception и все дочерние ему классы-исключения
//	catch (std::exception& exception)
//	{
//		std::cerr << "Standard exception: " << exception.what() << '\n';
//	}
//
//	return 0;
//}






//собственные классы исключения дочерние от стандартных
#include <iostream>
#include <string>
#include <exception> // для std::exception

class ArrayException : public std::exception
{
private:
	std::string m_error;

public:
	ArrayException(std::string error)
		: m_error(error)
	{
	}


	const char* what() const noexcept { return m_error.c_str(); }
};

class ArrayInt
{
private:

	int m_data[4]; // чтобы не усложнять, укажем значение 4 в качестве длины массива
public:
	ArrayInt() {}

	int getLength() { return 4; }

	int& operator[](const int index)
	{
		if (index < 0 || index >= getLength())
			throw ArrayException("Invalid index");

		return m_data[index];
	}

};

int main()
{
	ArrayInt array;

	try
	{
		int value = array[7];
	}
	catch (ArrayException& exception) // сначала ловим исключения дочернего класса-исключения
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
	catch (std::exception& exception)
	{
		std::cerr << "Some other std::exception occurred (" << exception.what() << ")\n";
	}
}

