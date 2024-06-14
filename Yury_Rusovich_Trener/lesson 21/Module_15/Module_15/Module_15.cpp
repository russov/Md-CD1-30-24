//#include <iostream>
//
//// сортировка пузырьком
//using namespace std;
//
//int main()
//{
//    int arr[] = {1,2,3,4,5,6,7,8,9,0}; // указатель для выделения памяти под массив
//    const int size = std::size(arr);
//    int temp; // временная переменная для обмена элементов местами
//
//    // Сортировка массива пузырьком
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = 0; j < size - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                // меняем элементы местами
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//
//    // Вывод отсортированного массива на экран
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}


//быстрая сортировка
#include <iostream>

void sort(int[], size_t, size_t);

int main()
{
    int nums[]{ 3, 0, 6, -2, -6, 11, 3, 5, -7 };
    sort(nums, 0, std::size(nums) - 1);
    for (auto num : nums)
    {
        std::cout << num << "\t";
    }
    std::cout << std::endl;
}

void sort(int numbers[], size_t start, size_t end)
{
    // начальный индекс должен быть меньше конечного индекса для массива из 2 и более элементов
    if (start >= end)
        return;
    // проверяем все элементы относительно элемента с индексом start
    size_t current{ start };
    for (size_t i{ start + 1 }; i <= end; i++)
    {
        // если i-ый элемент меньше начального
        if (numbers[i] < numbers[start])
        {
            std::swap(numbers[++current], numbers[i]); // меняем его с левым
        }
    }
    std::swap(numbers[start], numbers[current]); // Меняем выбранный (start) и последний обмененный элементы
    if (current > start)
    {
        sort(numbers, start, current - 1); // Сортируем элементы слева
    }
    if (end > current + 1)
    {
        sort(numbers, current + 1, end); // Сортируем элементы справа
    }
}

