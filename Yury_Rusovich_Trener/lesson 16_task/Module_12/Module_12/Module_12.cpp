// Module_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// простой пример шаблона функции
//#include <iostream>
//
//template <typename T>
//const T& max(const T& a, const T& b)
//{
//    return (a > b) ? a : b;
//}
//
//int main()
//{
//    int i = max(4, 8);
//    std::cout << i << '\n';
//
//    double d = max(7.56, 21.434);
//    std::cout << d << '\n';
//
//    char ch = max('b', '9');
//    std::cout << ch << '\n';
//
//    return 0;
//}



//шаблоны пользовательского типа
//перегрузка оператора
//template <typename T> // объявление параметра шаблона функции
//const T& max(const T& a, const T& b)
//{
//    return (a > b) ? a : b;
//}
//
//class Dollars
//{
//private:
//    int m_dollars;
//public:
//    Dollars(int dollars)
//        : m_dollars(dollars)
//    {
//    }
//
//    //friend bool operator>(const Dollars& d1, const Dollars& d2)
//    //{
//    //    return (d1.m_dollars > d2.m_dollars);
//    //}
//};
//
//int main()
//{
//    Dollars seven(7);
//    Dollars twelve(12);
//
//    Dollars bigger = max(seven, twelve);
//
//    return 0;
//}






//#include <iostream>
//
//         /*typename*/
//template <class T, class F>
//F average(T* array, int length)
//{
//    F sum = 0;
//    for (int count = 0; count < length; ++count)
//        sum += array[count];
//
//    sum /= length;
//    return sum;
//}
//
//class Dollars
//{
//private:
//    int m_dollars;
//public:
//    Dollars(int dollars)
//        : m_dollars(dollars)
//    {
//    }
//
//    friend bool operator>(const Dollars& d1, const Dollars& d2)
//    {
//        return (d1.m_dollars > d2.m_dollars);
//    }
//
//    friend std::ostream& operator<< (std::ostream& out, const Dollars& dollars)
//    {
//        out << dollars.m_dollars << " dollars ";
//        return out;
//    }
//
//    Dollars& operator+=(Dollars dollars)
//    {
//        m_dollars += dollars.m_dollars;
//        return *this;
//    }
//
//    Dollars& operator/=(int value)
//    {
//        m_dollars /= value;
//        return *this;
//    }
//};
//
//int main()
//{
//    int array1[] = { 6, 4, 1, 3, 7 };
//    std::cout << average<int, double>(array1, 5) << '\n';
//
//    double array2[] = { 4.25, 5.37, 8.44, 9.25 };
//    std::cout << average<double, double>(array2, 4) << '\n';
//
//    Dollars array3[] = { Dollars(7), Dollars(12), Dollars(18), Dollars(15) };
//    std::cout << average<Dollars, Dollars>(array3, 4) << '\n';
//
//    return 0;
//}




//шаблонный класс
//#ifndef ARRAY_H
//#define ARRAY_H
//
//#include <assert.h> // для assert()
//
//template <class T> // это шаблон класса с T вместо фактического (передаваемого) типа данных
//class Array
//{
//private:
//    int m_length;
//    T* m_data;
//
//public:
//    Array()
//    {
//        m_length = 0;
//        m_data = nullptr;
//    }
//
//    Array(int length)
//    {
//        m_data = new T[length];
//        m_length = length;
//    }
//
//    ~Array()
//    {
//        delete[] m_data;
//    }
//
//    void Erase()
//    {
//        delete[] m_data;
//        // Присваиваем значение nullptr для m_data, чтобы на выходе не получить висячий указатель!
//        m_data = nullptr;
//        m_length = 0;
//    }
//
//
//    T& operator[](int index)
//    {
//        assert(index >= 0 && index < m_length);
//        return m_data[index];
//    }
//
//    // Длина массива всегда является целочисленным значением, она не зависит от типа элементов массива
//    int getLength(); // определяем метод и шаблон метода getLength() ниже
//};
//
//
////!!!
//template <typename T> // метод, определенный вне тела класса, нуждается в собственном определении шаблона метода
//int Array<T>::getLength() { return m_length; } // обратите внимание, имя класса - Array<T>, а не просто Array
//
//#endif
//
//
//#include <iostream>
//
//int main()
//{
//    Array<int> intArray(10);
//    Array<double> doubleArray(10);
//
//    for (int count = 0; count < intArray.getLength(); ++count)
//    {
//        intArray[count] = count;
//        doubleArray[count] = count + 0.5;
//    }
//
//    for (int count = intArray.getLength() - 1; count >= 0; --count)
//        std::cout << intArray[count] << "\t" << doubleArray[count] << '\n';
//
//    return 0;
//}






//Параметр non-type
//#include <iostream>
//
//template <class T, int size> // size является параметром non-type в шаблоне класса
//class StaticArray
//{
//private:
//    // Параметр non-type в шаблоне класса отвечает за размер выделяемого массива
//    T m_array[size];
//
//public:
//    T* getArray();
//
//    T& operator[](int index)
//    {
//        return m_array[index];
//    }
//};
//
//// Синтаксис определения шаблона метода и самого метода вне тела класса с параметром non-type
//template <class T, int size>
//T* StaticArray<T, size>::getArray()
//{
//    return m_array;
//}
//
//int main()
//{
//    // Объявляем целочисленный массив из 10 элементов
//    StaticArray<int, 10> intArray;
//
//    // Заполняем массив значениями
//    for (int count = 0; count < 10; ++count)
//        intArray[count] = count;                  //здесь статический массив
//
//    // Выводим элементы массива в обратном порядке 
//    for (int count = 9; count >= 0; --count)
//        std::cout << intArray[count] << " ";
//    std::cout << '\n';
//
//    // Объявляем массив типа double из 5 элементов
//    StaticArray<double, 5> doubleArray;
//
//    // Заполняем массив значениями
//    for (int count = 0; count < 5; ++count)
//        doubleArray[count] = 5.5 + 0.1 * count;
//
//    // Выводим элементы массива 
//    for (int count = 0; count < 5; ++count)
//        std::cout << doubleArray[count] << ' ';
//
//    return 0;
//}





//специализация функции
//#include <iostream>
//
//template <class T>
//class Repository
//{
//private:
//    T m_value;
//public:
//    Repository(T value)
//    {
//        m_value = value;
//    }
//
//    ~Repository()
//    {
//    }
//
//    void print()
//    {
//        std::cout << m_value << '\n';
//    }
//};
//
//template <>
//void Repository<double>::print()
//{
//    std::cout << std::scientific << m_value << '\n';
//}
//
//template <>
//Repository<char*>::Repository(char* value)
//{
//    // Определяем длину value
//    int length = 0;
//    while (value[length] != '\0')
//        ++length;
//    ++length; // +1, учитывая нуль-терминатор
//
//    // Выделяем память для хранения значения value
//    m_value = new char[length];
//
//    // Копируем фактическое значение value в m_value
//    for (int count = 0; count < length; ++count)
//        m_value[count] = value[count];
//}
//
//template <>
//Repository<char*>::~Repository()
//{
//    delete[] m_value;
//}
//
//int main()
//{
//    // Инициализируем объекты класса
//    Repository<int> nValue(7);
//    Repository<double> dValue(8.4);
//
//    // Выводим значения объектов класса
//    nValue.print();
//    dValue.print();
//
//
//
//    // Динамически выделяем временную строку
//    char* string = new char[40];
//
//    // Просим пользователя ввести свое имя
//    std::cout << "Enter your name: ";
//    std::cin >> string;
//
//    // Сохраняем то, что ввел пользователь
//    Repository<char*> repository(string);
//
//    // Удаляем временную строку
//    delete[] string;
//
//    // Пытаемся вывести то, что ввел пользователь
//    repository.print(); // получаем мусор
//}






//специализация класса
//#include <iostream>
//
//template <class T>
//class Repository8
//{
//private:
//    T m_array[8];
//
//public:
//    void set(int index, const T& value)
//    {
//        m_array[index] = value;
//    }
//
//    const T& get(int index)
//    {
//        return m_array[index];
//    }
//};
//
//template <>
//class Repository8<bool> // специализируем шаблон класса Repository8 для работы с типом bool
//{
//    // Реализация класса
//private:
//    unsigned char m_data;
//
//public:
//    Repository8() : m_data(0)
//    {
//    }
//
//    void set(int index, bool value)
//    {
//        // Выбираем оперируемый бит
//        unsigned char mask = 1 << index;
//
//        if (value) // если на входе у нас true, то бит нужно "включить"
//            m_data |= mask; // используем побитовое ИЛИ, чтобы "включить" бит
//        else // если на входе у нас false, то бит нужно "выключить" 
//            m_data &= ~mask; // используем побитовое И, чтобы "выключить" бит
//    }
//
//    bool get(int index)
//    {
//        // Выбираем бит
//        unsigned char mask = 1 << index;
//        // Используем побитовое И для получения значения бита, а затем выполняется его неявное преобразование в тип bool
//        return (m_data & mask) != 0;
//    }
//};
//
//int main()
//{
//    // Объявляем целочисленный объект-массив
//    Repository8<int> intRepository;
//
//    for (int count = 0; count < 8; ++count)
//        intRepository.set(count, count);
//
//    for (int count = 0; count < 8; ++count)
//        std::cout << intRepository.get(count) << '\n';
//
//    // Объявляем объект-массив типа bool
//    Repository8<bool> boolRepository;
//
//    for (int count = 0; count < 8; ++count)
//        boolRepository.set(count, count % 5);
//
//    for (int count = 0; count < 8; ++count)
//        std::cout << (boolRepository.get(count) ? "true" : "false") << '\n';
//
//    return 0;
//}





//частичная специализация
//#include <iostream>
//#include <cstring>
//
//template <class T, int size> // size является non-type параметром шаблона
//class StaticArray
//{
//private:
//	// Параметр size отвечает за длину массива
//	T m_array[size];
//
//public:
//	T* getArray() { return m_array; }
//
//	T& operator[](int index)
//	{
//		return m_array[index];
//	}
//};
//
//template <typename T, int size>
//void print(StaticArray<T, size>& array)
//{
//	for (int count = 0; count < size; ++count)
//		std::cout << array[count] << ' ';
//}
//
//// Шаблон функции print() с частично специализированным шаблоном класса StaticArray<char, size> в качестве параметра
//template <int size>
//void print(StaticArray<char, size>& array)  // !!!входной параметр шаблон класса!!!
//{
//	for (int count = 0; count < size; ++count)
//		std::cout << array[count];
//}
//
//////test
////template <class T>
////void print(StaticArray<T, 14>& array)
////{
////	int y = 0;
////}
//
//
//int main()
//{
//	// Объявляем массив типа char длиной 14
//	StaticArray<char, 14> char14;
//
//	strcpy_s(char14.getArray(), 14, "Hello, world!");
//
//	// Выводим элементы массива
//	print(char14);
//
//	// Теперь объявляем массив типа char длиной 12
//	StaticArray<char, 12> char12;
//
//	strcpy_s(char12.getArray(), 12, "Hello, dad!");
//
//	// Выводим элементы массива
//	print(char12);
//
//	return 0;
//}





//частичная специализация метода
//обходной путь

//#include <iostream>
//
//template <class T, int size> // size является non-type параметром шаблона
//class StaticArray
//{
//private:
//	// Параметр size отвечает за длину массива
//	T m_array[size];
//
//public:
//	T* getArray() { return m_array; }
//
//	T& operator[](int index)
//	{
//		return m_array[index];
//	}
//	void print()
//	{
//		for (int i = 0; i < size; i++)
//			std::cout << m_array[i] << ' ';
//		std::cout << "\n";
//	}
//};
//
//template <int size> // size является non-type параметром шаблона
//class StaticArray<double, size>
//{
//private:
//	// Параметр size отвечает за длину массива
//	double m_array[size];
//
//public:
//	double* getArray() { return m_array; }
//
//	double& operator[](int index)
//	{
//		return m_array[index];
//	}
//	void print()
//	{
//		for (int i = 0; i < size; i++)
//			std::cout << std::scientific << m_array[i] << ' ';
//		std::cout << "\n";
//	}
//};
//
////улучшение с наследованием
//	//template <class T, int size> // size является non-type параметром шаблона
//	//class StaticArray_Base
//	//{
//	//protected:
//	//	// Параметр size отвечает за длину массива
//	//	T m_array[size];
//	//
//	//public:
//	//	T* getArray() { return m_array; }
//	//
//	//	T& operator[](int index)
//	//	{
//	//		return m_array[index];
//	//	}
//	//	virtual void print()
//	//	{
//	//		for (int i = 0; i < size; i++)
//	//			std::cout << m_array[i] << ' ';
//	//		std::cout << "\n";
//	//	}
//	//};
//	//
//	//template <class T, int size> // size является non-type параметром шаблона
//	//class StaticArray : public StaticArray_Base<T, size>
//	//{
//	//public:
//	//	StaticArray()
//	//	{
//	//
//	//	}
//	//};
//	//
//	//template <int size> // size является non-type параметром шаблона
//	//class StaticArray<double, size> : public StaticArray_Base<double, size>
//	//{
//	//public:
//	//
//	//	virtual void print() override
//	//	{
//	//		for (int i = 0; i < size; i++)
//	//			std::cout << std::scientific << this->m_array[i] << " ";
//	//		std::cout << "\n";
//	//	}
//	//};
//
//int main()
//{
//	// Объявляем целочисленный массив длиной 5
//	StaticArray<int, 5> intArray;
//
//	// Заполняем его, а затем выводим
//	for (int count = 0; count < 5; ++count)
//		intArray[count] = count;
//	intArray.print();
//
//	// Объявляем массив типа double длиной 4
//	StaticArray<double, 4> doubleArray;
//
//	// Заполняем его, а затем выводим
//	for (int count = 0; count < 4; ++count)
//		doubleArray[count] = (4. + 0.1 * count);
//	doubleArray.print();
//
//	return 0;
//}


//variadic templates
#include <iostream>
#include <string>

// Функция для объединения произвольного числа строк
template <typename... Args>
std::string concatenate(const Args&... args) {
    // Создаем массив строк из аргументов
    std::string arr[sizeof...(Args)] = { std::string(args)... };

    // Объединяем строки из массива
    std::string result;
    for (const auto& str : arr) {
        result += str;
    }
    return result;
}

int main() {
    std::string result = concatenate("Hello", ", ", "world", "!");
    std::cout << result << std::endl; // Вывод: Hello, world!

    return 0;
}




//// вычисление функции на этапе компиляции
//#include <iostream>
//
//template <int N>
//struct Factorial {
//    static const int value = N * Factorial<N - 1>::value;
//};
//
//template <>
//struct Factorial<0> {
//    static const int value = 1;
//};
// 
//int main() {
//    constexpr int result = Factorial<5>::value; // Факториал числа 5 вычисляется на этапе компиляции
//    std::cout << "Factorial of 5 is: " << result << std::endl;
//     
//    return 0;
//}