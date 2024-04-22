// Module_5_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//-----------------------------------------------------------------------------------------------------------
// область видимости
//#include <iostream>
//// Параметр x можно использовать только внутри функции add()
//
//int add(int x, int y) // параметр x функции add() создается здесь
//{
//    return x + y;
//} // параметр x функции add() уничтожается здесь
//
//// Переменную x функции main() можно использовать только внутри функции main()
//int main()
//{
//    int x = 5; // переменная x функции main() создается здесь
//    int y = 6;
//    std::cout << add(x, y) << std::endl; // значение x функции main() копируется в переменную x функции add()
//    return 0;
//} // переменная x функции main() уничтожается здесь


//#include <iostream>
//
//int main()
//{ // начало внешнего блока 
//
//    int x(5);
//
//    { // начало вложенного блока 
//        int y(7);
//        // Мы можем использовать x и y здесь
//        std::cout << x << " + " << y << " = " << x + y;
//    } // переменная y уничтожается здесь
//
//    // Переменную y здесь нельзя использовать, поскольку она уже уничтожена!
//
//    return 0;
//} // переменная x уничтожается здесь


//#include <iostream>
//
//int oranges(2);
//
//int main()
//{ // внешний блок
//	int oranges(5); // внешняя переменная oranges
//
//	if (oranges >= 5) // относится к внешней oranges
//	{ // вложенный блок
//		int oranges; // скрывается внешняя переменная oranges
//
//		// Идентификатор oranges теперь относится к вложенной переменной oranges.
//		// Внешняя переменная oranges временно скрыта
//
//		oranges = 10; // здесь мы присваиваем значение 10 вложенной переменной oranges, не внешней!
//
//		std::cout << oranges << std::endl; // выводим значение вложенной переменной oranges
//		std::cout << ::oranges << std::endl;
//	} // вложенная переменная oranges уничтожается
//
//	// Идентификатор oranges опять относится к внешней переменной oranges
//
//	std::cout << oranges << std::endl; // выводим значение внешней переменной oranges
//
//	return 0;
//} // внешняя переменная oranges уничтожается


//#include <iostream>
//
//int main()
//{
//	int y(5); // мы объявляем переменную y здесь, потому что она нам будет нужна как во внутреннем, так и во внешнем блоке чуть позже
//
//	{
//		int x;
//		std::cin >> x;
//		// Если бы мы объявили y здесь, непосредственно перед её первым фактическим использованием,
//		if (x == 4)
//			y = 4;
//	} // то она бы уничтожилась здесь
//
//	std::cout << y; // а переменная y нам нужна еще здесь 
//
//	return 0;
//}

//// глобальные переменные
//#include <iostream>
//
//// Переменные, определенные вне блока, являются глобальными переменными 
//int g_x; // глобальная переменная g_x
//const int g_y(3); // константная глобальная переменная g_y
//
//void doSomething()
//{
//	// Глобальные переменные можно использовать в любом месте программы
//	g_x = 4;
//	std::cout << g_y << "\n";
//}
//
//int main()
//{
//	doSomething();
//
//	// Глобальные переменные можно использовать в любом месте программы
//	g_x = 7;
//	std::cout << g_y << "\n";
//
//	return 0;
//}

//// static 
//#include <iostream>
//
//extern int g_m; // предварительное объявление g_m. Теперь g_m можно использовать в любом месте этого файла  
///*extern*/ int add(int,int);
//
//extern const double g_y;
//
//int main()
//{
//	extern int g_n; // предварительное объявление g_n. Теперь g_n можно использовать только внутри main()
//
//	g_m = 4;
//	std::cout << g_n; // должно вывести 3
//
//	auto ui = add(3, 5);
//
//	auto hh = g_y;
//
//	return 0;
//}

//---------------------------------------------------------------------------------
//// статические переменные
//#include <iostream>
//
//void incrementAndPrint()
//{
//    int value = 1; // автоматическая продолжительность жизни (по умолчанию)
//    ++value;
//    std::cout << value << std::endl;
//} // переменная value уничтожается здесь
//
//int main()
//{
//    incrementAndPrint();
//    incrementAndPrint();
//    incrementAndPrint();
//}

//#include <iostream>
//
//void incrementAndPrint()
//{
//    static int s_value = 1; // переменная s_value является статической
//    ++s_value;
//    std::cout << s_value << std::endl;
//} // переменная s_value не уничтожается здесь, но становится недоступной
//
//int main()
//{
//    incrementAndPrint();
//    incrementAndPrint();
//    incrementAndPrint();
//}

// ------------------------------------------------------------------------------------
// пространство имен

//#include <iostream>
//#include "a.h"
//#include "b.h"
//
//int main()
//{
//    std::cout << doOperation(5, 4); // какая версия doOperation() выполнится здесь?
//    return 0;
//}


//#include <iostream>
//
//namespace Boo
//{
//    namespace Doo
//    {
//        const int g_x = 7;
//    }
//}
//
//int main()
//{
//    std::cout << Boo::Doo::g_x;
//    return 0;
//}

//#include <iostream>
//
//namespace Boo
//{
//	namespace Doo
//	{
//		const int g_x = 7;
//	}
//}
//
//namespace Foo = Boo::Doo; // Foo теперь считается как Boo::Doo
//
//int main()
//{
//	std::cout << Foo::g_x; // это, на самом деле, Boo::Doo::g_x
//	return 0;
//}


//-----------------------------------------------------------------------------------
//enum

//#include <iostream>
//
//enum Colors
//{
//	COLOR_YELLOW, // присваивается 0
//	COLOR_WHITE,  // присваивается 1
//	COLOR_ORANGE, // присваивается 2
//	COLOR_GREEN,  // присваивается 3
//	COLOR_RED,    // присваивается 4
//	COLOR_GRAY,   // присваивается 5
//	COLOR_PURPLE, // присваивается 6
//	COLOR_BROWN   // присваивается 7
//};
//
//int main()
//{
//	Colors paint(COLOR_RED);
//	std::cout << paint;
//
//	return 0;
//}

//#include <iostream>
//
//// Определяем новый перечисляемый тип Animals
//enum Animals
//{
//	ANIMAL_PIG = -4,
//	ANIMAL_LION, // присваивается -3
//	ANIMAL_CAT, // присваивается -2
//	ANIMAL_HORSE = 6,
//	ANIMAL_ZEBRA = 6, // имеет то же значение, что и ANIMAL_HORSE
//	ANIMAL_COW // присваивается 7
//};
//
//int main()
//{
//	int mypet = ANIMAL_PIG;
//	std::cout << ANIMAL_HORSE; // конвертируется в int, а затем выводится на экран
//
//	//Animals animal = 7; // приведет к ошибке компиляции
//	//Animals animal = static_cast<Animals>(5); // но делать так не рекомендуется
//
//	return 0;
//}


#include <iostream>
#include <string>

enum ItemType
{
    ITEMTYPE_GUN,
    ITEMTYPE_ARBALET,
    ITEMTYPE_SWORD
};

std::string getItemName(ItemType itemType)
{
    if (itemType == ITEMTYPE_GUN)
        return std::string("Gun");
    if (itemType == ITEMTYPE_ARBALET)
        return std::string("Arbalet");
    if (itemType == ITEMTYPE_SWORD)
        return std::string("Sword");
}

int main()
{
    // ItemType - это перечисляемый тип, который мы объявили выше.
    // itemType (с маленькой i) - это имя переменной, которую мы определяем ниже (типа ItemType).
    // ITEMTYPE_GUN - это значение перечислителя, которое мы присваиваем переменной itemType
    ItemType itemType(ITEMTYPE_GUN);

    std::cout << "You are carrying a " << getItemName(itemType) << "\n";

    return 0;
}

