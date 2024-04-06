#include <iostream>
#include <string>

const int g_arr_size = 10;

void printArr(const int arr[g_arr_size][g_arr_size]){
    for (int i=0; i< g_arr_size; i++){
        for (int j=0; j < g_arr_size; j++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
}
int main() {
    int a, b, minRow, minEl;
    int arr[g_arr_size][g_arr_size];
    std::cout << "Enter the boundaries for the segment [a, b]" << std::endl;
    std::cin >> a >> b;
    if (a > b){
        std::swap(a, b);
    }
    minEl = b + 1;
    for (int i = 0; i < g_arr_size; i++)
        for (int j = 0; j < g_arr_size; j++){
            arr[i][j] = a + rand()%(b - a + 1);
            if (arr[i][j] < minEl){
                minEl = arr[i][j];
                minRow = i;
            }
        }

    std::cout << "Generated array:" << std::endl;
    printArr(arr);

    std::cout << "Minimum row is " << minRow<< " with element " << minEl << std::endl;

    std::swap(arr[0], arr[minRow]);
    std::cout << "Processed array:" << std::endl;
    printArr(arr);
    return 0;
}