//алгоритмы STl

//#include <iostream>
//#include <list>
//#include <algorithm> 
//
//int main()
//{
//    std::list<int> li;
//    for (int nCount = 0; nCount < 5; ++nCount)
//        li.push_back(nCount);
//
//    std::list<int>::const_iterator it; // объявляем итератор
//    it = min_element(li.begin(), li.end());
//    std::cout << *it << ' ';
//    it = max_element(li.begin(), li.end());
//    std::cout << *it << ' ';
//
//    std::cout << '\n';
//}




//#include <iostream>
//#include <list>
//#include <algorithm>
//
//int main()
//{
//    std::list<int> li;
//    for (int nCount = 0; nCount < 5; ++nCount)
//        li.push_back(nCount);
//
//    std::list<int>::iterator it = li.begin(); // объявляем итератор
//    it = find(li.begin(), li.end(), 2); // ищем в списке число 2
//    li.insert(it, 7); // используем алгоритм list::insert() для добавления числа 7 перед числом 2
//
//    for (it = li.begin(); it != li.end(); ++it) // выводим с помощью цикла и итератора элементы списка
//        std::cout << *it << ' ';
//
//    std::cout << '\n';
//}









//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//
//    std::vector<int> vect;
//    vect.push_back(4);
//    vect.push_back(8);
//    vect.push_back(-3);
//    vect.push_back(3);
//    vect.push_back(-8);
//    vect.push_back(12);
//    vect.push_back(5);
//
//    std::sort(vect.begin(), vect.end()); // выполняем сортировку элементов вектора
//
//    std::vector<int>::const_iterator it; // объявляем итератор
//    for (it = vect.begin(); it != vect.end(); ++it) // выводим с помощью цикла и итератора элементы вектора
//        std::cout << *it << ' ';
//
//    std::cout << '\n';
//
//    std::reverse(vect.begin(), vect.end()); // записываем элементы вектора в обратном порядке
//
//    for (it = vect.begin(); it != vect.end(); ++it) // выводим с помощью цикла и итератора элементы вектора
//        std::cout << *it << ' ';
//
//    std::cout << '\n';
//}





// functor vs lambda
#include <iostream>
#include <vector>
#include <algorithm>


class Compare {
public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};


int main() {
    std::vector<int> vec1 = { 5, 2, 8, 1, 3 };

    //1
    std::sort(
        vec1.begin(), 
        vec1.end(), 
        [](int a, int b) {
            return a > b;
        });

    //2
    std::sort(vec1.begin(), vec1.end(), Compare());


    //3
    //std::sort(vec1.begin(), vec1.end(), std::greater<int>());


    std::cout << "Sorted with lambda: ";
    for (int num : vec1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}