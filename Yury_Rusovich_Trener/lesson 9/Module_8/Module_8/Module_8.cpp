//#include <iostream>
//
//class DateClass
//{
//public:
//    int m_day;
//    int m_month;
//    int m_year;
//
//    void print()
//    {
//        std::cout << m_day << "/" << m_month << "/" << m_year;
//    }
//};
//
//int main()
//{
//    DateClass today{ 12, 11, 2018 };
//
//    today.m_day = 18; // используем оператор выбора членов для выбора переменной-члена m_day объекта today класса DateClass
//    today.print(); // используем оператор выбора членов для вызова метода print() объекта today класса DateClass
//
//    return 0;
//}




//#include <iostream>
//#include <string>
//
//class Employee
//{
//public:
//    std::string m_name;
//    int m_id;
//    double m_wage;
//
//    // Метод вывода информации о работнике на экран
//    void print()
//    {
//        std::cout << "Name: " << m_name <<
//            "\nId: " << m_id <<
//            "\nWage: $" << m_wage << '\n';
//    }
//};
//
//int main()
//{
//    // Определяем двух работников
//    Employee john{ "John", 5, 30.00 };
//    Employee max{ "Max", 6, 32.75 };
//
//    // Выводим информацию о работниках на экран
//    john.print();
//    std::cout << std::endl;
//    max.print();
//
//    return 0;
//}

// пример классов
//#include <string>
//#include <array>
//#include <vector>
//#include <iostream>
//
//int main()
//{
//    std::string s{ "Hello, world!" }; // создаем экземпляр класса string
//    std::array<int, 3> a{ 7, 8, 9 }; // создаем экземпляр класса array
//    std::vector<double> v{ 1.5, 2.6, 3.7 }; // создаем экземпляр класса vector
//
//    std::cout << "length: " << s.length() << '\n'; // вызываем метод 
//
//    return 0;
//}

// модификаторы доступа

//class DateClass // члены класса являются закрытыми по умолчанию
//{
//// public:
//    int m_day; // закрыто по умолчанию, доступ имеют только другие члены класса
//    int m_month; // закрыто по умолчанию, доступ имеют только другие члены класса
//    int m_year; // закрыто по умолчанию, доступ имеют только другие члены класса
//};
//
//int main()
//{
//    DateClass date;
//    date.m_day = 12; // ошибка
//    date.m_month = 11; // ошибка
//    date.m_year = 2018; // ошибка
//
//    return 0;
//}


//--------------------------------------------------------------------------------------------------
//Инкапсуляция
//сеттеры
//геттеры

//class Date
//{
//private:
//    int m_day;
//    int m_month;
//    int m_year;
//
//public:
//    int getDay() { return m_day; } // геттер для day
//    void setDay(int day) { m_day = day; } // сеттер для day
//
//    int getMonth() { return m_month; } // геттер для month
//    void setMonth(int month) { m_month = month; } // сеттер для month
//
//    int getYear() { return m_year; } // геттер для year
//    void setYear(int year) { m_year = year; } // сеттер для year
//};



//------------------------------------------------------------------------------------------------
// клнструкторы
//#include <iostream>
//#include <string>
//#include <vector>
//#include <utility>
//
//// Класс, представляющий товар
//class Product {
//private:
//    std::string name_;
//    double price_;
//public:
//    // Конструктор по умолчанию
//    Product() : name_(""), price_(0.0) {}
//
//    // Конструктор с параметрами
//    Product(const std::string& name, double price) : name_(name), price_(price) {}
//
//    // Конструктор копирования
//    Product(const Product& other) : name_(other.name_), price_(other.price_) {}
//
//    // Конструктор перемещения
//    Product(Product&& other) noexcept : name_(std::move(other.name_)), price_(other.price_) {}
//
//    // Метод получения имени товара
//    std::string getName() const { return name_; }
//
//    // Метод получения цены товара
//    double getPrice() const { return price_; }
//};
//
//// Класс, представляющий склад
//class Warehouse {
//private:
//    std::vector<Product> products_;
//public:
//    // Конструктор по умолчанию
//    Warehouse() {}
//
//    // Конструктор с параметром - начальное заполнение склада товарами
//    Warehouse(const std::vector<Product>& products) : products_(products) {}
//
//    // Конструктор копирования
//    Warehouse(const Warehouse& other) : products_(other.products_) {}
//
//    // Конструктор перемещения
//    Warehouse(Warehouse&& other) noexcept : products_(std::move(other.products_)) {}
//
//    // Метод добавления товара на склад
//    void addProduct(const Product& product) {
//        products_.push_back(product);
//    }
//
//    // Метод получения списка товаров на складе
//    std::vector<Product> getProducts() const {
//        return products_;
//    }
//};
//
//int main() {
//    // Создаем несколько товаров
//    Product p1{"item 1", 100.0};
//    Product p2{"item 2", 200.0};
//
//    // Создаем склад и добавляем товары на склад
//    Warehouse warehouse;
//    warehouse.addProduct(p1);
//    warehouse.addProduct(p2);
//
//    // Копируем склад
//    //Warehouse copiedWarehouse{ warehouse };
//    Warehouse copiedWarehouse = warehouse;
//
//    // Перемещаем склад
//    Warehouse movedWarehouse = std::move(warehouse);
//
//    // Выводим список товаров на копии склада
//    std::cout << "Items in warehouse (copy):" << std::endl;
//    for (const auto& product : copiedWarehouse.getProducts()) {
//        std::cout << "Name: " << product.getName() << ", Cost: " << product.getPrice() << std::endl;
//    }
//
//    // Выводим список товаров на перемещенном складе
//    std::cout << "\nItems in warehouse (move)" << std::endl;
//    for (const auto& product : movedWarehouse.getProducts()) {
//        std::cout << "Name: " << product.getName() << ", Cost: " << product.getPrice() << std::endl;
//    }
//
//    return 0;
//}


//---------------------------------------------------------------------------------------------------------
//деструктор

//#include <iostream>
//#include <cassert>
//
//class Massiv
//{
//private:
//	int* m_array;
//	int m_length;
//
//public:
//	Massiv(int length) // конструктор
//	{
//		assert(length > 0);
//
//		m_array = new int[length];
//		m_length = length;
//	}
//
//	~Massiv() // деструктор
//	{
//		// Динамически удаляем массив, который выделили ранее
//		delete[] m_array;
//	}
//
//	void setValue(int index, int value) { m_array[index] = value; }
//	int getValue(int index) { return m_array[index]; }
//
//	int getLength() { return m_length; }
//};
//
//int main()
//{
//	Massiv arr(15); // выделяем 15 целочисленных значений
//	for (int count = 0; count < 15; ++count)
//		arr.setValue(count, count + 1);
//
//	std::cout << "The value of element 7 is " << arr.getValue(7);
//
//	return 0;
//}



//----------------------------------------------------------------------------------------------
//статические переменный класса
#include <iostream>

class Anything
{
public:
    static int s_value; // объявляем статическую переменную-член
    //static const int s_value = 5;
    //static constexpr double s_value = 3.4;
};

int Anything::s_value = 3; // определяем статическую переменную-член

int main()
{
    // Примечание: Мы не создаем здесь никаких объектов класса Anything

    Anything::s_value = 4;
    std::cout << Anything::s_value << '\n';
    return 0;
}





//использование статических переменных класса
//#include <iostream>
//
//class Anything
//{
//private:
//    static int s_idGenerator;
//    int m_id;
//
//public:
//    Anything() { m_id = s_idGenerator++; } // увеличиваем значение идентификатора для следующего объекта
//
//    int getID() const { return m_id; }
//};
//
//// Мы определяем и инициализируем s_idGenerator несмотря на то, что он объявлен как private.
//// Это нормально, поскольку определение не подпадает под действия спецификаторов доступа
//int Anything::s_idGenerator = 1; // начинаем наш ID-генератор со значения 1
//
//int main()
//{
//    Anything first;
//    Anything second;
//    Anything third;
//
//    std::cout << first.getID() << '\n';
//    std::cout << second.getID() << '\n';
//    std::cout << third.getID() << '\n';
//    return 0;
//}





// статический метод
//#include <iostream>
//class Anything
//{
//private:
//    static int s_value;
//public:
//    static int getValue() { return s_value; } // статический метод
//};
//
//int Anything::s_value = 3; // определение статической переменной-члена класса
//
//int main()
//{
//    std::cout << Anything::getValue() << '\n';
//}





//-----------------------------------------------------------------------------------------------------------
//Константные методы классов
//class Anything
//{
//public:
//    int m_value;
//
//    Anything() : m_value(0) { }
//
//    void setValue(int value) { m_value = value; }
//    int getValue() { return m_value; }
//};
//
//int main()
//{
//    const Anything anything; // вызываем конструктор по умолчанию
//
//    anything.m_value = 7; // ошибка компиляции: нарушение const
//    anything.setValue(7); // ошибка компиляции: нарушение const
//
//    //anything.getValue();
//
//
//    return 0;
//}

//передача объекта по константной ссылке
//#include <iostream>
//
//class Date
//{
//private:
//    int m_day;
//    int m_month;
//    int m_year;
//
//public:
//    Date(int day, int month, int year)
//    {
//        setDate(day, month, year);
//    }
//
//    void setDate(int day, int month, int year)
//    {
//        m_day = day;
//        m_month = month;
//        m_year = year;
//    }
//
//    int getDay() { return m_day; }
//    int getMonth() { return m_month; }
//    int getYear() { return m_year; }
//};
//
//// Примечание: Мы передаем объект date по константной ссылке, дабы избежать создания копии объекта date
//void printDate(const Date& date)
//{
//    std::cout << date.getDay() << "." << date.getMonth() << "." << date.getYear() << '\n';
//}
//
//int main()
//{
//    Date date(12, 11, 2018);
//    printDate(date);
//
//    return 0;
//}