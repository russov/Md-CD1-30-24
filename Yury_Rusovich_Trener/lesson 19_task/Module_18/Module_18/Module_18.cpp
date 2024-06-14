// семантика перемещения 

//#include <iostream>
//
//template<class T>
//class Auto_ptr2
//{
//	T* m_ptr;
//public:
//	Auto_ptr2(T* ptr = nullptr)
//		:m_ptr(ptr)
//	{
//	}
//
//	~Auto_ptr2()
//	{
//		delete m_ptr;
//	}
//
//	// Конструктор копирования, который реализовывает семантику перемещения
//	Auto_ptr2(Auto_ptr2& a) // примечание: Ссылка не является константной
//	{
//		m_ptr = a.m_ptr; // перемещаем наш глупый указатель от источника к нашему локальному объекту
//		a.m_ptr = nullptr; // подтверждаем, что источник больше не владеет указателем
//	}
//
//	// Оператор присваивания, который реализовывает семантику перемещения
//	Auto_ptr2& operator=(Auto_ptr2& a) // примечание: Ссылка не является константной
//	{
//		if (&a == this)
//			return *this;
//
//		delete m_ptr; // подтверждаем, что удалили любой указатель, который наш локальный объект имел до этого
//		m_ptr = a.m_ptr; // затем перемещаем наш глупый указатель из источника к нашему локальному объекту
//		a.m_ptr = nullptr; // подтверждаем, что источник больше не владеет указателем
//		return *this;
//	}
//
//	T& operator*() const { return *m_ptr; }
//	T* operator->() const { return m_ptr; }
//	bool isNull() const { return m_ptr == nullptr; }
//};
//
//class Item
//{
//public:
//	Item() { std::cout << "Item acquired\n"; }
//	~Item() { std::cout << "Item destroyed\n"; }
//};
//
//int main()
//{
//	Auto_ptr2<Item> item1(new Item);
//	Auto_ptr2<Item> item2; // начнем с nullptr
//
//	std::cout << "item1 is " << (item1.isNull() ? "null\n" : "not null\n");
//	std::cout << "item2 is " << (item2.isNull() ? "null\n" : "not null\n");
//
//	item2 = item1; // item2 теперь является "владельцем" значения item1, объекту item1 присваивается null
//
//	std::cout << "Ownership transferred\n";
//
//	std::cout << "item1 is " << (item1.isNull() ? "null\n" : "not null\n");
//	std::cout << "item2 is " << (item2.isNull() ? "null\n" : "not null\n");
//
//	return 0;
//}






//// rvalue ссылка
//#include <iostream>
//
//int main() {
//	int &&x = 1;
//    int& rref = x; // Создаётся временный объект со значением 7, и rref привязывается к нему
//
//    std::cout << "rref = " << rref << std::endl;
//
//    rref = 10; // Изменение значения временного объекта через r-value ссылку
//
//    std::cout << "rref = " << rref << std::endl;
//
//    return 0;
//}





// rvalue ссылка в качестве параметра функции
//#include <iostream>
//
//void fun(const int& lref) // перегрузка функции для работы с аргументами l-values
//{
//	std::cout << "l-value reference to const\n";
//}
//
//void fun(int&& rref) // перегрузка функции для работы с аргументами r-values
//{
//	std::cout << "r-value reference\n";
//}
//
//int main()
//{
//	int x = 7;
//	fun(x); // аргумент l-value вызывает функцию с ссылкой l-value
//	fun(7); // аргумент r-value вызывает функцию с ссылкой r-value
//
//	return 0;
//}






//------------------------------------------------------------------------------------------------------------
//конструктор перемещения
//#include <iostream>
//
//template<class T>
//class Auto_ptr4
//{
//	T* m_ptr;
//public:
//	Auto_ptr4(T* ptr = nullptr)
//		:m_ptr(ptr)
//	{
//	}
//
//	~Auto_ptr4()
//	{
//		delete m_ptr;
//	}
//
//	// Конструктор копирования, который выполняет глубокое копирование x.m_ptr в m_ptr
//	Auto_ptr4(const Auto_ptr4& x)
//	{
//		m_ptr = new T;
//		*m_ptr = *x.m_ptr;
//	}
//
//	// Конструктор перемещения, который передает право собственности на x.m_ptr в m_ptr
//	Auto_ptr4(Auto_ptr4&& x)
//		: m_ptr(x.m_ptr)
//	{
//		x.m_ptr = nullptr; // мы поговорим об этом чуть позже
//	}
//
//	// Оператор присваивания копированием, который выполняет глубокое копирование x.m_ptr в m_ptr
//	//Auto_ptr4& operator=(const Auto_ptr4& x)
//	//{
//	//	// Проверка на самоприсваивание
//	//	if (&x == this)
//	//		return *this;
//
//	//	// Удаляем всё, что к этому моменту может хранить указатель 
//	//	delete m_ptr;
//
//	//	// Копируем передаваемый объект
//	//	m_ptr = new T;
//	//	*m_ptr = *x.m_ptr;
//
//	//	return *this;
//	//}
//
//	// Оператор присваивания перемещением, который передает право собственности на x.m_ptr в m_ptr
//	Auto_ptr4& operator=(Auto_ptr4&& x)
//	{
//		// Проверка на самоприсваивание
//		if (&x == this)
//			return *this;
//
//		// Удаляем всё, что к этому моменту может хранить указатель 
//		delete m_ptr;
//
//		// Передаем право собственности на x.m_ptr в m_ptr
//		m_ptr = x.m_ptr;
//		x.m_ptr = nullptr; // мы поговорим об этом чуть позже
//
//		return *this;
//	}
//
//	T& operator*() const { return *m_ptr; }
//	T* operator->() const { return m_ptr; }
//	bool isNull() const { return m_ptr == nullptr; }
//};
//
//class Item
//{
//public:
//	Item() { std::cout << "Item acquired\n"; }
//	~Item() { std::cout << "Item destroyed\n"; }
//};
//
//Auto_ptr4<Item> generateItem()
//{
//	Auto_ptr4<Item> item(new Item);
//	return item; // это возвращаемое значение приведет к вызову конструктора перемещения
//}
//
//int main()
//{
//
//
//	auto i{ Auto_ptr4<Item>{ new Item } };
//	auto j{ i };
//
//	Auto_ptr4<Item> mainItem;
//	auto mainItem1{ Auto_ptr4<Item>{ new Item } };
//	mainItem = generateItem(); // эта операция присваивания приведет к вызову оператора присваивания перемещением
//
//
//	int ii = 8;
//
//
//	std::move
//
//
//	Auto_ptr4<Item> mainItem1{ mainItem };
//	Auto_ptr4<Item> mainItem2{ generateItem() };
//	return 0;
//}







//-------------------------------------------------------------------------------------------------------------------
//std::move
//#include <iostream>
//#include <string>
// 
//template<class T>
//void swap(T& x, T& y) 
//{ 
//  T tmp { x }; // вызывает конструктор копирования
// // x = y; // вызывает оператор присваивания копированием
// // y = tmp; // вызывает оператор присваивания копированием
//  x = std::move(y); // вызывает оператор присваивания перемещением
//  y = std::move(tmp); // вызывает оператор присваивания перемещением
//}
// 
//int main()
//{
//	std::string x{ "Anton" };
//	std::string y{ "Max" };
// 
//	std::cout << "x: " << x << '\n';
//	std::cout << "y: " << y << '\n';
// 
//	swap(x, y);
// 
//	std::cout << "x: " << x << '\n';
//	std::cout << "y: " << y << '\n';
// 
//	return 0;
//}



//std::move
//#include <iostream>
//#include <string>
//#include <utility>
//#include <vector>
//
//int main()
//{
//	std::vector<std::string> v;
//	std::string str = "Bye";
//
//	std::cout << "Copying str\n";
//	v.push_back(str); // вызывает версию l-value метода push_back(), которая копирует str в элемент массива
//
//	std::cout << "str: " << str << '\n';
//	std::cout << "vector: " << v[0] << '\n';
//
//	std::cout << "\nMoving str\n";
//
//	v.push_back(std::move(str)); // вызывает версию r-value метода push_back(), которая перемещает str в элемент массива
//
//	std::cout << "str: " << str << '\n';
//	std::cout << "vector: " << v[0] << ' ' << v[1] << '\n';
//
//	return 0;
//}






//-----------------------------------------------------------------------------------------------------------------
//deque
//#include <iostream>
//#include <deque>
//
//int main()
//{
//    std::deque<int> deq;
//    for (int count = 0; count < 4; ++count)
//    {
//        deq.push_back(count); // вставляем числа в конец массива
//        deq.push_front(10 - count); // вставляем числа в начало массива
//    }
//
//    for (int index = 0; index < deq.size(); ++index)
//        std::cout << deq[index] << ' ';
//
//    std::cout << '\n';
//
//
//
//}




//std::map
//#include <iostream>
//#include <map>
//
//int main() {
//    // Создание и инициализация map
//    std::map<int, std::string> myMap = {
//        {1, "one"},
//        {2, "two"},
//        {3, "three"}
//    };
//    auto i = new int{ 5 };
//    i->
//    *i.
//    auto j = *i
//    // Добавление элемента
//    myMap.insert({ 4, "four" });
//    std::pair<int, std::string>
//    // Поиск элемента по ключу
//    auto it = myMap.find(2);
//    if (it != myMap.end()) {
//        std::cout << "Key 2 found, value: " << it->second << std::endl;
//    }
//    else {
//        std::cout << "Key 2 not found" << std::endl;
//    }
//
//    // Удаление элемента по ключу
//    myMap.erase(3);
//
//    // Перебор всех элементов
//    std::cout << "All elements:" << std::endl;
//    for (const auto& pair : myMap) {
//        std::cout << pair.first << ": " << pair.second << std::endl;
//    }
//
//    return 0;
//}




//multimap
//#include <iostream>
//#include <map>
//
//int main() {
//    std::multimap<int, std::string> myMultimap;
//
//    // Добавляем пары ключ-значение
//    myMultimap.insert({ 1, "one" });
//    myMultimap.insert({ 2, "two" });
//    myMultimap.insert({ 2, "another two" });
//    myMultimap.insert({ 2, "another two2" });
//    myMultimap.insert({ 3, "three" });
//
//    // Получаем диапазон итераторов для всех значений с ключом 2
//    auto range = myMultimap.equal_range(2);
//
//    // Выводим все значения
//    std::cout << "Values with key 2:" << std::endl;
//    for (auto it = range.first; it != range.second; ++it) {
//        std::cout << it->second << std::endl;
//    }
//
//    return 0;
//}





//std::stack
//#include <iostream>
//#include <stack>
//#include <vector>
//
//int main() {
//    // Создание стека с std::vector в качестве базового контейнера
//    std::stack<int, std::vector<int>> myStack;
//
//    // Добавление элементов в стек
//    myStack.push(1);
//    myStack.push(2);
//    myStack.push(3);
//    myStack.push(4);
//    
//    // Печать верхнего элемента стека
//    std::cout << "Top element of the stack: " << myStack.top() << std::endl;
//
//    // Удаление верхнего элемента стека
//    myStack.pop();
//    auto u = myStack.top();
//
//    // Печать размера стека
//    std::cout << "Size of the stack: " << myStack.size() << std::endl;
//
//    return 0;
//}





//iterator
//#include <iostream>
//#include <vector>
//
//int main()
//{
//    std::vector<int> myVector;
//    for (int count = 0; count < 5; ++count)
//        myVector.push_back(count);
//
//
//
//
//    std::vector<int>::iterator it; // объявляем итератор только для чтения
//    it = myVector.begin(); // присваиваем ему начальный элемент вектора
//
//    for (const auto& ptr = myVector.begin(); ptr != myVector.end(); ++it)
//    {
//    }
//
//    while (it != myVector.end()) // пока итератор не достигнет последнего элемента
//    {
//        std::cout << *it << " "; // выводим значение элемента, на который указывает итератор
//        ++it; // и переходим к следующему элементу
//    }
//
//    std::cout << '\n';
//}





//#include <iostream>
//#include <forward_list>
//#include <vector>
//
//int main()
//{
//    std::forward_list<int> myList;
//    for (int count = 0; count < 5; ++count)
//        myList.push_front(count);
//
//    std::forward_list<int>::const_iterator it; // объявляем итератор
//    it = myList.begin(); // присваиваем ему начальный элемент списка
//    while (it != myList.end()) // пока итератор не достигнет последнего элемента
//    {
//        std::cout << *it << " "; // выводим значение элемента, на который указывает итератор
//        ++it; // и переходим к следующему элементу
//    }
//
//    std::cout << '\n';
//}







//#include <iostream>
//#include <set>
//
//int main()
//{
//    std::set<int> mySet;
//    mySet.insert(8);
//    mySet.insert(3);
//    mySet.insert(-4);
//    mySet.insert(9);
//    mySet.insert(2);
//
//    std::set<int>::iterator it; // объявляем итератор
//    it = mySet.begin(); // присваиваем ему начальный элемент set-а
//    while (it != mySet.end()) // пока итератор не достигнет последнего элемента
//    {
//        std::cout << *it << " "; // выводим значение элемента, на который указывает итератор
//        ++it; // и переходим к следующему элементу
//    }
//
//    std::cout << '\n';
//}







//#include <iostream>
//#include <map>
//#include <string>
//
//int main()
//{
//	std::map<int, std::string> myMap;
//	myMap.insert(std::make_pair(3, "cat"));
//	myMap.insert(std::make_pair(2, "dog"));
//	myMap.insert(std::make_pair(5, "chicken"));
//	myMap.insert(std::make_pair(4, "lion"));
//	myMap.insert(std::make_pair(1, "spider"));
//
//	std::map<int, std::string>::const_iterator it; // объявляем итератор
//	it = myMap.begin(); // присваиваем ему начальный элемент вектора
//	while (it != myMap.end()) // пока итератор не достигнет последнего элемента
//	{
//		std::cout << it->first << "=" << it->second << " "; // выводим значение элемента, на который указывает итератор
//		++it; // и переходим к следующему элементу
//	}
//
//	std::cout << '\n';
//}







//std::allocator
//#include <iostream>
//#include <vector>
//#include <memory> // для std::allocator
//
//int main() {
//    // Создание вектора с использованием std::allocator
//    std::vector<int, std::allocator<int>> myVector;
//
//    // Добавление элементов в вектор
//    myVector.push_back(1);
//    myVector.push_back(2);
//    myVector.push_back(3);
//
//    // Перебор всех элементов вектора и вывод их на экран
//    for (const auto& elem : myVector) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}






//самодельный аллокатор
//#include <iostream>
//#include <vector>
//#include <memory> // Для std::allocator
//
//#include <iostream>
//#include <memory>
//
//template<typename T>
//class CustomAllocator {
//public:
//    using value_type = T;
//
//    CustomAllocator() = default;
//    template<typename U>
//    CustomAllocator(const CustomAllocator<U>&) {}
//
//    T* allocate(std::size_t n) {
//        std::cout << "Allocating " << n * sizeof(T) << " bytes.\n";
//        return static_cast<T*>(::operator new(n * sizeof(T)));
//    }
//
//    void deallocate(T* p, std::size_t n) {
//        std::cout << "Deallocating " << n * sizeof(T) << " bytes.\n";
//        ::operator delete(p);
//    }
//
//    template<typename U, typename... Args>
//    void construct(U* p, Args&&... args) {
//        new (p) U(std::forward<Args>(args)...);
//    }
//
//    template<typename U>
//    void destroy(U* p) {
//        p->~U();
//    }
//};
//
//template<typename T, typename U>
//bool operator==(const CustomAllocator<T>&, const CustomAllocator<U>&) {
//    return true;
//}
//
//template<typename T, typename U>
//bool operator!=(const CustomAllocator<T>& a, const CustomAllocator<U>& b) {
//    return !(a == b);
//}
//
//int main() {
//
//    // Создание вектора с использованием MyAllocator<int>
//    std::vector<int, CustomAllocator<int>> myVector; // передача аллокатора через конструктор
//    myVector.push_back(1);
//    // Добавление элементов в вектор
//    for (int i = 0; i < 5; ++i) {
//        myVector.push_back(i * 10);
//    }
//
//    // Вывод элементов вектора
//    std::cout << "Vector elements: ";
//    for (const auto& elem : myVector) {
//        std::cout << elem << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}






//емкость строки
//#include <iostream>
//
//int main()
//{
//    std::string sString("0123456789");
//    std::cout << "Length: " << sString.length() << std::endl;
//    std::cout << "Capacity: " << sString.capacity() << std::endl;
//
//    return 0;
//}







//#include <iostream>
//
//int main()
//{
//	std::string sString("0123456789abcde");
//	std::cout << "Length: " << sString.length() << std::endl;
//	std::cout << "Capacity: " << sString.capacity() << std::endl;
//
//	// Добавляем новый символ
//	sString += "f";
//	std::cout << "Length: " << sString.length() << std::endl;
//	std::cout << "Capacity: " << sString.capacity() << std::endl;
//
//	return 0;
//}





//reserve
//#include <iostream>
//
//int main()
//{
//	std::string sString("0123456789");
//	std::cout << "Length: " << sString.length() << std::endl;
//	std::cout << "Capacity: " << sString.capacity() << std::endl;
//
//	sString.reserve(300);
//	std::cout << "Length: " << sString.length() << std::endl;
//	std::cout << "Capacity: " << sString.capacity() << std::endl;
//
//	//sString.reserve();
//	sString.shrink_to_fit();
//	std::cout << "Length: " << sString.length() << std::endl;
//	std::cout << "Capacity: " << sString.capacity() << std::endl;
//
//	return 0;
//}





//max_size
//#include <iostream>
//
//int main()
//{
//	std::string sString("MyString");
//	std::cout << sString.max_size() << std::endl;
//}





//c_str, data
//#include <iostream>
//#include <string>
//
//int main()
//{
//	std::string sSomething("abcdefg");
//	std::cout << strlen(sSomething.c_str());
//
//
//	const char* szString = "abcdefg";
//	// Функция memcmp() сравнивает две вышеприведенные строки C-style и возвращает 0, если они равны
//	if (memcmp(sSomething.data(), szString, sSomething.length()) == 0)
//		std::cout << "The strings are equal";
//	else
//		std::cout << "The strings are not equal";
//}






//convert numbers to string
//#include <iostream>
//#include <string>
//
//int main() {
//    int num = 42;
//    double pi = 3.14159;
//
//    std::string str_num = std::to_string(num);
//    std::string str_pi = std::to_string(pi);
//
//    std::cout << "Integer: " << str_num << std::endl;
//    std::cout << "Double: " << str_pi << std::endl;
//
//    return 0;
//}






//#include <iostream>
//#include <sstream>
//#include <string>
//
//int main() {
//    int num{ 42 };
//    double pi{ 3.14159 };
//
//    std::ostringstream oss;
//    oss << num;
//    std::string str_num{ oss.str() };
//
//    oss.str(""); // Сбросить содержимое потока
//    oss.clear(); // Сбросить состояние ошибок
//
//    oss << pi;
//    std::string str_pi{ oss.str() };
//
//    std::cout << "Integer: " << str_num << std::endl;
//    std::cout << "Double: " << str_pi << std::endl;
//
//    return 0;
//}




//string to number
//#include <iostream>
//#include <string>
//
//int main() {
//    std::string str_num = "QQ";
//    std::string str_long_num = "123123123";
//
//    int num = std::stoi(str_num);
//    long long_num = std::stol(str_long_num);
//
//    std::cout << "int: " << num << std::endl;
//    std::cout << "long: " << long_num << std::endl;
//
//    return 0;
//}





//#include <iostream>
//#include <sstream>
//#include <string>
//
//int main() {
//    std::string str_num = "0";
//    std::string str_float = "3.14";
//
//    int num;
//    float f;
//
//    std::istringstream(str_num) >> num;
//    std::istringstream(str_float) >> f;
//
//    std::cout << "int: " << num << std::endl;
//    std::cout << "float: " << f << std::endl;
//
//    return 0;
//}

