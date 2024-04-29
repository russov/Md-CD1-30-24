
// friend
//class Anything
//{
//private:
//    int m_value;
//public:
//    Anything() { m_value = 0; }
//    void add(int value) { m_value += value; }
//
//    // Делаем функцию reset() дружественной классу Anything
//    friend void reset(Anything& anything);
//};
//
//// Функция reset() теперь является другом класса Anything
//void reset(Anything& anything) // нужно передать объект класса
//{
//    // И мы имеем доступ к закрытым членам объектов класса Anything
//    anything.m_value = 0;
//}
//
//int main()
//{
//    Anything one;
//    one.add(4); // добавляем 4 к m_value
//    reset(one); // сбрасываем m_value в 0
//
//    return 0;
//}

// пример friend
//class Something
//{
//private:
//    int m_value;
//public:
//    Something(int value) { m_value = value; }
//    friend bool isEqual(const Something& value1, const Something& value2);
//};
//
//bool isEqual(const Something& value1, const Something& value2)
//{
//    return (value1.m_value == value2.m_value);
//}


// friend и классы
//#include <iostream>
//
//class Humidity;
//
//class Temperature
//{
//private:
//    int m_temp;
//public:
//    Temperature(int temp = 0) { m_temp = temp; }
//
//    friend void outWeather(const Temperature& temperature, const Humidity& humidity);
//};
//
//class Humidity
//{
//private:
//    int m_humidity;
//public:
//    Humidity(int humidity = 0) { m_humidity = humidity; }
//
//    friend void outWeather(const Temperature& temperature, const Humidity& humidity);
//};
//
//void outWeather(const Temperature& temperature, const Humidity& humidity)
//{
//    std::cout << "The temperature is " << temperature.m_temp <<
//        " and the humidity is " << humidity.m_humidity << '\n';
//}
//
//int main()
//{
//    Temperature temp(15);
//    Humidity hum(11);
//
//    outWeather(temp, hum);
//
//    return 0;
//}



// friend классы
//#include <iostream>
//
//class Values
//{
//private:
//    int m_intValue;
//    double m_dValue;
//public:
//    Values(int intValue, double dValue)
//    {
//        m_intValue = intValue;
//        m_dValue = dValue;
//    }
//
//    // Делаем класс Display другом класса Values
//    friend class Display;
//};
//
//class Display
//{
//private:
//    bool m_displayIntFirst;
//
//public:
//    Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
//
//    void displayItem(Values& value)
//    {
//        if (m_displayIntFirst)
//            std::cout << value.m_intValue << " " << value.m_dValue << '\n';
//        else // или сначала выводим double
//            std::cout << value.m_dValue << " " << value.m_intValue << '\n';
//    }
//};
//
//int main()
//{
//    Values value(7, 8.4);
//    Display display(false);
//
//    display.displayItem(value);
//
//    return 0;
//}


//#include <iostream>
//
//class Values; // предварительное объявление класса Values
//
//class Display
//{
//private:
//	bool m_displayIntFirst;
//
//public:
//	Display(bool displayIntFirst) { m_displayIntFirst = displayIntFirst; }
//
//	void displayItem(Values& value); // предварительное объявление, приведенное выше, требуется для этой строки
//};
//
//class Values // полное определение класса Values
//{
//private:
//	int m_intValue;
//	double m_dValue;
//public:
//	Values(int intValue, double dValue)
//	{
//		m_intValue = intValue;
//		m_dValue = dValue;
//	}
//
//	// Делаем метод Display::displayItem() другом класса Values
//	friend void Display::displayItem(Values& value);
//};
//
//// Теперь мы можем определить метод Display::displayItem(), которому требуется увидеть полное определение класса Values
//void Display::displayItem(Values& value)
//{
//	if (m_displayIntFirst)
//		std::cout << value.m_intValue << " " << value.m_dValue << '\n';
//	else // или выводим сначала double
//		std::cout << value.m_dValue << " " << value.m_intValue << '\n';
//}
//
//int main()
//{
//	Values value(7, 8.4);
//	Display display(false);
//
//	display.displayItem(value);
//
//	return 0;
//}

//-----------------------------------------------------------------------------------------------
// перегрузка операторов
// перегрузка через дружественные операторы

//#include <iostream>
//
//class Dollars
//{
//private:
//	int m_dollars;
//
//public:
//	Dollars(int dollars) { m_dollars = dollars; }
//
//	// Выполняем Dollars + Dollars через дружественную функцию
//	friend Dollars operator+(const Dollars& d1, const Dollars& d2);
//
//	int getDollars() const { return m_dollars; }
//};
//
//// Примечание: Эта функция не является методом класса!
//Dollars operator+(const Dollars& d1, const Dollars& d2)
//{
//	// Используем конструктор Dollars и operator+(int, int).
//	// Мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
//	return Dollars(d1.m_dollars + d2.m_dollars);
//}
//
//int main()
//{
//	Dollars dollars1(7);
//	Dollars dollars2(9);
//	Dollars dollarsSum = dollars1 + dollars2;
//	std::cout << "I have " << dollarsSum.getDollars() << " dollars." << std::endl;
//
//	return 0;
//}



// перегрузка операторов с разными типами

//#include <iostream>
//
//class Dollars
//{
//private:
//	int m_dollars;
//
//public:
//	Dollars(int dollars) { m_dollars = dollars; }
//
//	// Выполняем Dollars + int через дружественную функцию
//	friend Dollars operator+(const Dollars& d1, int value);
//
//	// Выполняем int + Dollars через дружественную функцию
//	friend Dollars operator+(int value, const Dollars& d1);
//
//
//	int getDollars() { return m_dollars; }
//};
//
//// Примечание: Эта функция не является методом класса!
//Dollars operator+(const Dollars& d1, int value)
//{
//	// Используем конструктор Dollars и operator+(int, int).
//	// Мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
//	return Dollars(d1.m_dollars + value);
//}
//
//// Примечание: Эта функция не является методом класса!
//Dollars operator+(int value, const Dollars& d1)
//{
//	// Используем конструктор Dollars и operator+(int, int).
//	// Мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
//	return Dollars(d1.m_dollars + value);
//}
//
//int main()
//{
//	Dollars d1 = Dollars(5) + 5;
//	Dollars d2 = 5 + Dollars(5);
//
//	std::cout << "I have " << d1.getDollars() << " dollars." << std::endl;
//	std::cout << "I have " << d2.getDollars() << " dollars." << std::endl;
//
//	return 0;
//}


// перегрузка через функции
//#include <iostream>
//
//class Dollars
//{
//private:
//	int m_dollars;
//
//public:
//	Dollars(int dollars) { m_dollars = dollars; }
//
//	int getDollars() const { return m_dollars; }
//};
//
//// Примечание: Эта функция не является ни методом класса, ни дружественной классу Dollars!
//Dollars operator+(const Dollars& d1, const Dollars& d2)
//{
//	// Используем конструктор Dollars и operator+(int, int).
//	// Здесь нам не нужен прямой доступ к закрытым членам класса Dollars
//	return Dollars(d1.getDollars() + d2.getDollars());
//}
//
//int main()
//{
//	Dollars dollars1(7);
//	Dollars dollars2(9);
//	Dollars dollarsSum = dollars1 + dollars2;
//	std::cout << "I have " << dollarsSum.getDollars() << " dollars." << std::endl;
//
//	return 0;
//}


// Перегрузка операторов через методы классов
//#include <iostream>
// 
//class Dollars
//{
//private:
//    int m_dollars;
// 
//public:
//    Dollars(int dollars) { m_dollars = dollars; }
// 
//    // Выполняем Dollars + int
//    Dollars operator+(int value);
//
//    Dollars operator+(const Dollars& other) const
//    {
//        return Dollars(m_dollars + other.m_dollars);
//    }
// 
//    int getDollars() { return m_dollars; }
//};
// 
//// Примечание: Эта функция является методом класса!
//// Вместо параметра dollars в перегрузке через дружественную функцию здесь неявный параметр, на который указывает указатель *this
//Dollars Dollars::operator+(int value)
//{
//    return Dollars(m_dollars + value);
//}
// 
//int main()
//{
//	Dollars dollars1(7);
//	Dollars dollars2 = dollars1 + 3;
//    auto dollars3 = dollars1 + dollars2;
//	std::cout << "I have " << dollars2.getDollars() << " dollars.\n";
//    std::cout << "I have " << dollars3.getDollars() << " dollars.\n";
// 
//	return 0;
//}

// перегрузка оператора сравнения
//#include <iostream>
//#include <string>
//
//class Car
//{
//private:
//    std::string m_company;
//    std::string m_model;
//
//public:
//    Car(std::string company, std::string model)
//        : m_company(company), m_model(model)
//    {
//    }
//
//    friend bool operator== (const Car& c1, const Car& c2);
//    friend bool operator!= (const Car& c1, const Car& c2);
//};
//
//bool operator== (const Car& c1, const Car& c2)
//{
//    return (c1.m_company == c2.m_company &&
//        c1.m_model == c2.m_model);
//}
//
//bool operator!= (const Car& c1, const Car& c2)
//{
//    return !(c1 == c2);
//}
//
//int main()
//{
//    Car mustang("Ford", "Mustang");
//    Car logan("Renault", "Logan");
//
//    if (mustang == logan)
//        std::cout << "Mustang and Logan are the same.\n";
//
//    if (mustang != logan)
//        std::cout << "Mustang and Logan are not the same.\n";
//
//    return 0;
//}


//перегрузка operator()
//#include <iostream>
//#include <cassert> // для assert()
//
//class Matrix
//{
//private:
//    double data[5][5];
//public:
//    Matrix()
//    {
//        // Присваиваем всем элементам массива значение 0.0
//        for (int row = 0; row < 5; ++row)
//            for (int col = 0; col < 5; ++col)
//                data[row][col] = 0.0;
//    }
//
//    double& operator()(int row, int col);
//    const double& operator()(int row, int col) const;
//    void operator()();
//};
//
//double& Matrix::operator()(int row, int col)
//{
//    assert(col >= 0 && col < 5);
//    assert(row >= 0 && row < 5);
//
//    return data[row][col];
//}
//
//const double& Matrix::operator()(int row, int col) const
//{
//    assert(col >= 0 && col < 5);
//    assert(row >= 0 && row < 5);
//
//    return data[row][col];
//}
//
//void Matrix::operator()()
//{
//    // Сбрасываем значения всех элементов массива на 0.0
//    for (int row = 0; row < 5; ++row)
//        for (int col = 0; col < 5; ++col)
//            data[row][col] = 0.0;
//}
//
//int main()
//{
//    Matrix matrix;
//    matrix(2, 3) = 3.6;
//    matrix(); // выполняем сброс
//    std::cout << matrix(2, 3);
//
//    return 0;
//}



// функтор
//#include <iostream>
//
//class Accumulator
//{
//private:
//    int m_counter = 0;
//
//public:
//    Accumulator()
//    {
//    }
//
//    int operator() (int i) { return (m_counter += i); }
//};
//
//int main()
//{
//    Accumulator accum;
//    std::cout << accum(30) << std::endl; // выведется 30
//    std::cout << accum(40) << std::endl; // выведется 70
//
//    return 0;
//}


//----------------------------------------------------------------------------------------------------
// КОНСТРУКТОР КОПИРОВАНИЯ
//#include <iostream> 
//#include <cassert>
//
//class Drob
//{
//private:
//    int m_numerator;
//    int m_denominator;
//
//public:
//    // Конструктор по умолчанию
//    Drob(int numerator = 0, int denominator = 1) :
//        m_numerator(numerator), m_denominator(denominator)
//    {
//        assert(denominator != 0);
//    }
//
//    // Конструктор копирования
//    //Drob(const Drob& drob) :
//    //    m_numerator(drob.m_numerator), m_denominator(drob.m_denominator)
//    //    // Примечание: Мы имеем прямой доступ к членам объекта drob, поскольку мы сейчас находимся внутри класса Drob
//    //{
//    //    // Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществляется в конструкторе класса Drob
//    //    std::cout << "Copy constructor worked here!\n"; // просто, чтобы показать, что это работает
//    //}
//
//    friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
//};
//
//std::ostream& operator<<(std::ostream& out, const Drob& d1)
//{
//    out << d1.m_numerator << "/" << d1.m_denominator;
//    return out;
//}
//
//int main()
//{
//    Drob sixSeven(6, 7); // прямая инициализация объекта класса Drob, вызывается конструктор Drob(int, int)
//    Drob dCopy(sixSeven); // прямая инициализация, вызывается конструктор копирования класса Drob
//    std::cout << dCopy << '\n';
//}





// перегрузка оператора присваивания
//#include <iostream> 
//#include <cassert>
//
//class Drob
//{
//private:
//    int m_numerator;
//    int m_denominator;
//
//public:
//    // Конструктор по умолчанию
//    Drob(int numerator = 0, int denominator = 1) :
//        m_numerator(numerator), m_denominator(denominator)
//    {
//        assert(denominator != 0);
//    }
//
//    // Конструктор копирования
//    Drob(const Drob& copy) :
//        m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
//    {
//        // Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществлена в конструкторе по умолчанию
//        std::cout << "Copy constructor worked here!\n"; // просто, чтобы показать, что это работает
//    }
//
//    // Перегрузка оператора присваивания
//    Drob& operator= (const Drob& drob)
//    {
//        // Выполняем копирование значений
//        m_numerator = drob.m_numerator;
//        m_denominator = drob.m_denominator;
//
//        // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
//        return *this;
//    }
//
//    friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
//
//};
//
//std::ostream& operator<<(std::ostream& out, const Drob& d1)
//{
//    out << d1.m_numerator << "/" << d1.m_denominator;
//    return out;
//}
//
//int main()
//{
//    Drob sixSeven(6, 7);
//    Drob d;
//    d = sixSeven; // вызывается перегруженный оператор присваивания
//    std::cout << d;
//
//    return 0;
//}