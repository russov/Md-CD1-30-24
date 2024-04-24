#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

void writeNumbersToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for writing." << std::endl;
        return;
    }

    std::cout << "Enter numbers (type 'done' to finish):\n";
    std::string input{};
    while (true) {
        std::cin >> input;
        if (input == "done") break;
        std::istringstream iss(input);
        int num;
        if (!(iss >> num)) {
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        file << num << std::endl;
    }
    file.close();
    std::cout << "Numbers have been written to the file." << std::endl;
}

std::vector<int> readNumbersFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file for reading." << std::endl;
        return {};
    }

    std::vector<int> numbers{};
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    file.close();
    return numbers;
}

void printVectorReverse(const std::vector<int>& numbers) {
    std::cout << "Numbers in reverse order:\n";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}

int calculateSum(const std::vector<int>& numbers) {
    auto sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum;
}

double calculateAverage(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        std::cerr << "No numbers found in the vector." << std::endl;
        return 0.0;
    }

    double sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum / numbers.size();
}

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