#include <string> 
#include "module_21_task.h"

int main() {
    const std::string filename = "numbers.txt";

    writeNumbersToFile(filename);

    auto numbers = readNumbersFromFile(filename);

    printVectorReverse(numbers);

    auto sum = calculateSum(numbers);
    std::cout << "Sum of numbers: " << sum << std::endl;

    auto average = calculateAverage(numbers);
    std::cout << "Average of numbers: " << std::fixed << std::setprecision(2) << average << std::endl;

    return 0;
}