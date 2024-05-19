//#include <string>
//#include <iostream>
//
//class Human
//{
//public:
//    // общие вещи для всех людей
//    std::string m_name;
//    int m_age;
//
//    Human(std::string name = "", int age = 0)
//        : m_name(name), m_age(age)
//    {
//    }
//
//    std::string getName() const { return m_name; }
//    int getAge() const { return m_age; }
//
//};
//
//class BasketballPlayer
//{
//public:
//    double m_gameAverage;
//    int m_points;
//    std::string m_name;
//
//    BasketballPlayer(double gameAverage = 0.0, int points = 0)
//       : m_gameAverage(gameAverage), m_points(points)
//    {
//    }
//
//    std::string getName() const { return m_name; }
//};
//
////// BasketballPlayer открыто наследует Human
////class BasketballPlayer : public Human
////{
////public:
////    double m_gameAverage;
////    int m_points;
////
////    BasketballPlayer(double gameAverage = 0.0, int points = 0)
////        : m_gameAverage(gameAverage), m_points(points)
////    {
////    }
////};
//
//int main()
//{
//    // Создаем нового Баскетболиста
//    BasketballPlayer anton;
//    // Присваиваем ему имя (мы можем делать это напрямую, так как m_name является public)
//    anton.m_name = "Anton";
//    // Выводим имя Баскетболиста
//    std::cout << anton.getName() << '\n'; // используем метод getName(), который мы унаследовали от класса Human
//
//    return 0;
//}







//------------------------------------------------------------------------------------------
//#include <iostream>
//#include <string>
//
//class Human
//{
//protected:
//    std::string m_name;
//    int m_age;
//
//    std::string getName() const { return m_name; }
//    int getAge() const { return m_age; }
//
//    Human(std::string name = "", int age = 0)
//        : m_name(name), m_age(age)
//    {
//    }
//};
//
//// Employee открыто наследует Human
//class Employee : public Human
//{
//public:
//    int m_wage;
//    long m_employeeID;
//
//    Employee(int wage = 0, long employeeID = 0)
//        : m_wage(wage), m_employeeID(employeeID)
//    {
//    }
//
//    void printNameAndWage() const
//    {
//        std::cout << m_name << ": " << m_wage << '\n';
//    }
//};
//
//class Supervisor : public Employee
//{
//public:
//    // Этот Супервайзер может наблюдать максимум за 5-тью Работниками
//    long m_nOverseesIDs[5];
//
//    Supervisor()
//    {
//    }
//
//};
//
//int main()
//{
//    Employee ivan(350, 787);
//    ivan.m_name = "Ivan"; // мы можем это сделать, так как m_name является public
//
//    ivan.printNameAndWage();
//
//    return 0;
//}






//------------------------------------------------------------------------------------
//построение наследуемых объектов

//#include <iostream>
//
//class A
//{
//public:
//    int y;
//    A()
//    {
//        std::cout << "A\n";
//    }
//};
//
//class B : public A
//{
//public:
//    B()
//    {
//        y = 0;
//        std::cout << "B\n";
//    }
//};
//
//class C : public B
//{
//public:
//    C()
//    {
//        std::cout << "C\n";
//    }
//};
//
//class D : public C
//{
//public:
//    D()
//    {
//        std::cout << "D\n";
//    }
//};
//
//int main()
//{
//    std::cout << "Constructing A: \n";
//    A cA;
//
//    std::cout << "Constructing B: \n";
//    B cB;
//
//    std::cout << "Constructing C: \n";
//    C cC;
//
//    std::cout << "Constructing D: \n";
//    D cD;
//}





// инициализация переменных базового класса

//#include <iostream>
//
//class Parent
//{
//public:
//    int m_id;
//    int m_tt;
//
//    Parent() {}
//    Parent(string){}
//    Parent(string, int id = 0)
//        : m_id(id), m_tt{ 0 }
//    {
//    }
//
//    int getId() const { return m_id; }
//};
//
//class Child : public Parent
//{
//public:
//    double m_value;
//
//    Child(double value = 0.0)
//        : Parent{}
//    {}
//    Child(double value = 0.0, int id = 0)
//        : Parent{}, m_value(value)
//    {
//
//    }
//
//    Child(int value = 0.0, int id = 0)
//        : Parent{}
//    {
//
//    }
//
//
//    double getValue() const { return m_value; }
//};
//
//int main()
//{
//    Child child(1.5, 7); // вызывается конструктор Child(double, int)
//    std::cout << "ID: " << child.getId() << '\n';
//    std::cout << "Value: " << child.getValue() << '\n';
//
//    return 0;
//}




//вызов деструкторов
//#include <iostream>
//
//class A
//{
//public:
//    A(int a)
//    {
//        std::cout << "A: " << a << '\n';
//    }
//    ~A()
//    {
//        std::cout << " destructor A: " << '\n';
//    }
//};
//
//class B : public A
//{
//public:
//    B(int a, double b)
//        : A(a)
//    {
//        b1();
//        std::cout << "B: " << b << '\n';
//    }
//private:
//    void b1() {}
//    ~B()
//    {
//        std::cout << "destructor B: " << '\n';
//    }
//};
//
//class C : public B
//{
//public:
//    C(int a, double b, char c)
//        : B(a,b)
//    {
//        b1();
//        std::cout << "C: " << c << '\n';
//    }
//    ~C()
//    {
//        std::cout << "destructor C: " << '\n';
//    }
//};
//
//int main()
//{
//    C c(7, 5.4, 'D');
//    B b(5,5);
//    b.b1();
//
//    return 0;
//}



// модификаторы доступа
//class Parent
//{
//public:
//    int m_public; // доступ к этому члену открыт для всех объектов
//private:
//    int m_private; // доступ к этому члену открыт только для других членов класса Parent и для дружественных классов/функций (но не для дочерних классов)
//protected:
//    int m_protected; // доступ к этому члену открыт для других членов класса Parent, дружественных классов/функций, дочерних классов
//};
//
//class Child : public Parent
//{
//public:
//    Child()
//    {
//        m_public = 1; // разрешено: доступ к открытым членам родительского класса из дочернего класса
//        m_private = 2; // запрещено: доступ к закрытым членам родительского класса из дочернего класса
//        m_protected = 3; // разрешено: доступ к защищенным членам родительского класса из дочернего класса
//    }
//};
//
//int main()
//{
//    Parent parent;
//    parent.m_public = 1; // разрешено: доступ к открытым членам класса извне
//    parent.m_private = 2; // запрещено: доступ к закрытым членам класса извне
//    parent.m_protected = 3; // запрещено: доступ к защищенным членам класса извне
//
//    Child c;
//    c.m_public;
//    c.m_private;
//    c.m_protected;
//
//}



// типы наследования
//class Parent
//{
//public:
//    int m_public;
//private:
//    int m_private;
//protected:
//    int m_protected;
//};
//           /*public*/
//class Priv : protected Parent // закрытое наследование
//{
//    // Закрытое наследование означает, что:
//    // - public-члены становятся private (m_public теперь private) в дочернем классе;
//    // - protected-члены становятся private (m_protected теперь private) в дочернем классе;
//    // - private-члены остаются недоступными (m_private недоступен) в дочернем классе.
//public:
//    Priv()
//    {
//        m_public = 1; // разрешено: m_public теперь private в Priv
//        m_private = 2; // запрещено: дочерние классы не имеют доступ к закрытым членам родительского класса
//        m_protected = 3; // разрешено: m_protected теперь private в Priv
//    }
//};
//
//int main()
//{
//    Parent parent;
//    parent.m_public = 1; // разрешено: m_public доступен извне через родительский класс
//    parent.m_private = 2; // запрещено: m_private недоступен извне через родительский класс
//    parent.m_protected = 3; // запрещено: m_protected недоступен извне через родительский класс
//
//    Priv priv;
//    priv.m_public = 1; // запрещено: m_public недоступен извне через дочерний класс
//    priv.m_private = 2; // запрещено: m_private недоступен извне через дочерний класс
//    priv.m_protected = 3; // запрещено: m_protected недоступен извне через дочерний класс
//}



//-------------------------------------------------------------------------------
// переопределние методов класса
//#include <iostream>
//
//class Parent
//{
//protected:
//    int m_value;
//
//public:
//    Parent(int value)
//        : m_value(value)
//    {
//    }
//
//    void identify() { std::cout << "I am a Parent!\n"; }
//};
//
//class Child : public Parent
//{
//public:
//    Child(int value)
//        : Parent(value)
//    {
//    }
//
//    int GetValue() { return m_value; }
//
//    void identify()
//    {
//        Parent::identify(); // сначала выполняется вызов Parent::identify() 
//        std::cout << "I am a Child!\n"; // затем уже вывод этого текста
//    }
//};
//
//int main()
//{
//    Parent parent(6);
//    parent.identify();
//
//    Child child(8);
//    child.identify();
//
//    return 0;
//}





//изменение модификатора доступа в дочернем классе
//#include <iostream>
//
//class Parent
//{
//private:
//    int m_value;
//
//public:
//    Parent(int value)
//        : m_value(value)
//    {
//    }
//
//public:
//    void printValue() { std::cout << m_value; }
//};
//
//class Child : public Parent
//{
//public:
//    Child(int value)
//        : Parent(value)
//    {
//        m_value;
//    }
//
//    // Parent::printValue является protected, поэтому доступ к нему не является открытым для всех объектов.
//    // Но мы можем это исправить с помощью "using-объявления"
//    //using Parent::printValue; // обратите внимание, нет никаких скобок
//
//public:
//    void printValue() = delete;
//};
//
//int main()
//{
//    Child child(9);
//
//    // Метод printValue() является public в классе Child, поэтому всё хорошо
//    child.printValue(); // выведется 9
//    return 0;
//}







//----------------------------------------------------------------------------------
//множественное наследование
//#include <string>
//
//class Human
//{
//private:
//    std::string m_name;
//    int m_age;
//
//public:
//    Human(std::string name, int age)
//        : m_name(name), m_age(age)
//    {
//    }
//
//    std::string getName() { return m_name; }
//    int getAge() { return m_age; }
//};
//
//class Employee
//{
//private:
//    std::string m_employer;
//    double m_wage;
//
//public:
//    Employee(std::string employer, double wage)
//        : m_employer(employer), m_wage(wage)
//    {
//    }
//
//    std::string getEmployer() { return m_employer; }
//    double getWage() { return m_wage; }
//};
//
//// Класс Teacher открыто наследует свойства классов Human и Employee
//class Teacher : public Human, public Employee
//{
//private:
//    int m_teachesGrade;
//
//public:
//    Teacher(std::string name, int age, std::string employer, double wage, int teachesGrade)
//        : Human(name, age), Employee(employer, wage), m_teachesGrade(teachesGrade)
//    {
//    }
//};









//// ромбовидное наследование
//#include <iostream>
//
//class Base {
//public:
//    Base() { std::cout << "cons\n"; }
//
//    void show() { std::cout << "Base\n"; }
//};
//
//class Base1 {
//public:
//    Base1() { std::cout << "cons1\n"; }
//
//    void show() { std::cout << "Base1\n"; }
//};
//
//class Derived1 : public Base {};
//class Derived2 : public Base1 {};
//
//class MultipleDerived : public Derived1, public Derived2{};
//
//int main() {
//    MultipleDerived obj;
//    obj.show(); // Это сработает, потому что виртуальное наследование позволяет доступ к одному экземпляру Base
//    return 0;
//}






//------------------------------------------------------------------------------------------------------------------
// виртуальные функции
// указатели и ссылки на родительские классы
//#include <iostream> 
//#include <string>
//
//class Animal
//{
//protected:
//    std::string m_name;
//
//    // Мы делаем этот конструктор protected так как не хотим, чтобы пользователи создавали объекты класса Animal напрямую,
//    // но хотим, чтобы у дочерних классов доступ был открыт
//    Animal(std::string name)
//        : m_name(name)
//    {
//    }
//
//public:
//    std::string getName() { return m_name; }
//    /*virtual*/ 
//    virtual const char* speak() { return "???"; }
//};
//
//class Cat : public Animal
//{
//public:
//    Cat(std::string name)
//        : Animal(name)
//    {
//    }
//
//    const char* speak() { return "Meow"; }
//};
//
//class Dog : public Animal
//{
//public:
//    Dog(std::string name)
//        : Animal(name)
//    {
//    }
//
//    const char* speak() { return "Woof"; }
//};
//
//
//void report(Animal& rAnimal)
//{
//    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
//}
//
//int main()
//{
//    Cat cat("Matros");
//    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';
//
//    Dog dog("Barsik");
//    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';
//
//
//
//
//
//    Animal* pAnimal1 = new Cat{ "Matros" };
//    std::cout << "pAnimal is named " << pAnimal1->getName() << ", and it says " << pAnimal1->speak() << '\n';
//
//    Animal* pAnimal2 = &dog;
//    std::cout << "pAnimal is named " << pAnimal2->getName() << ", and it says " << pAnimal2->speak() << '\n';
//
//    ////
//    report(*pAnimal1);
//    report(*pAnimal2);
//
//    return 0;
//}







// виртуальные функции
//#include <iostream>
//
//class A
//{
//public:
//    virtual const char* getName() { return "A"; }
//};
//
//class B : public A
//{
//public:
//    virtual const char* getName() { return "B"; }
//};
//
//class C : public B
//{
//public:
//    virtual const char* getName() { return "C"; }
//};
//
//class D : public C
//{
//public:
//    virtual const char* getName() { return "D"; }
//};
//
//int main()
//{
//    C c;
//    B b;
//    A& rParent = b;
//    std::cout << "rParent is a " << rParent.getName() << '\n';
//
//    return 0;
//}





// override
//#include <iostream>
//
//class A
//{
//public:
//	virtual const char* getName1(int x) { return "A"; }
//	virtual const char* getName2(int x) { return "A"; }
//	virtual const char* getName3(int x) { return "A"; }
//};
//
//class B : public A
//{
//public:
//	virtual const char* getName1(short int x) override { return "B"; }   // ошибка компиляции, метод не является переопределением
//	virtual const char* getName2(int x) const override { return "B"; }  // ошибка компиляции, метод не является переопределением
//	virtual const char* getName3(int x) override { return "B"; }  // всё хорошо, метод является переопределением A::getName3(int)
//
//};
//
//int main()
//{
//	A *rParent = new B;
//	std::cout << rParent->getName1(1) << '\n';
//	std::cout << rParent->getName2(2) << '\n';
//	return 0;
//}






// final
class A
{
public:
	virtual const char* getName() { return "A"; }
};

class B : public A
{
public:
	virtual const char* getName() override  { return "B"; } // всё хорошо, переопределение A::getName()
};

class C : public B
{
public:
	virtual const char* getName() override { return "C"; } // ошибка компиляции: переопределение метода B::getName(), который является final
};






//виртуальный деструктор
//#include <iostream>
//
//class Parent
//{
//public:
//    /*virtual*/ ~Parent() // примечание: Деструктор виртуальный
//    {
//        std::cout << "Calling ~Parent()" << std::endl;
//    }
//};
//
//class Child : public Parent
//{
//private:
//    int* m_array;
//
//public:
//    Child(int length)
//    {
//        m_array = new int[length];
//    }
//
//    /*virtual*/ ~Child() // примечание: Деструктор виртуальный
//    {
//        std::cout << "Calling ~Child()" << std::endl;
//        delete[] m_array;
//    }
//};
//
//int main()
//{
//    Child* child = new Child(7);
//    Parent* parent = child;
//    delete parent;
//
//    return 0;
//}
//




//чистая виртуальная функция
//#include <iostream>
//#include <string>
//
//class Animal // это абстрактный родительский класс
//{
//protected:
//    std::string m_name;
//
//public:
//    Animal(std::string name)
//        : m_name(name)
//    {
//    }
//
//    std::string getName() { return m_name; }
//    virtual const char* speak() = 0; // обратите внимание, speak() является чистой виртуальной функцией
//};
//
//const char* Animal::speak()
//{
//    return "buzz"; // реализация по умолчанию
//}
//
//class Dragonfly : public Animal
//{
//
//public:
//    Dragonfly(std::string name)
//        : Animal(name)
//    {
//    }
//
//    virtual const char* speak() // этот класс уже не является абстрактным, так как мы переопределили функцию speak()
//    {
//        return Animal::speak(); // используется реализация по умолчанию класса Animal
//    }
//};
//
//int main()
//{
//    Dragonfly dfly("Barbara");
//    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';
//}