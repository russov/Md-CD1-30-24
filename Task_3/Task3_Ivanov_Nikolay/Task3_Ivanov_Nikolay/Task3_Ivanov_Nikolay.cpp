#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void PrintReverse(const std::vector<int>& arr);
void ArithmeticMean(const std::vector<int>& arr);
void Sum(const std::vector<int>& arr);

int main() {
    std::ofstream outf("numbers.txt", std::ios::app);
    if (!outf) {
        std::cerr << "File can't be opened" << std::endl;
        return 1;
    }

    int amount;
    std::cout << "Enter amount of numbers: ";
    while (!(std::cin >> amount) || amount <= 0) {
        std::cout << "Incorrect type, try again\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter amount of numbers: ";
    }

    for (int i = 0; i < amount; ++i) {
        int num;
        std::cout << "num " << i + 1 << " = ";
        while (!(std::cin >> num)) {
            std::cout << "Incorrect type, try again\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "num " << i + 1 << " = ";
        }
        outf << num << "\n";
    }
    outf.close();

    std::ifstream iinf("numbers.txt");
    if (!iinf) {
        std::cerr << "File can't be opened" << std::endl;
        return 1;
    }

    std::vector<int> arr;
    int num;
    while (iinf >> num) {
        arr.push_back(num);
    }
    iinf.close();

    std::cout << "Number of digits in file: " << arr.size() << "\n";
    for (const auto& n : arr) {
        std::cout << n << "\n";
    }

    PrintReverse(arr);
    Sum(arr);
    ArithmeticMean(arr);

    return 0;
}

void PrintReverse(const std::vector<int>& arr) {
    std::cout << "In reverse order: \n";
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        std::cout << *it << std::endl;
    }
}

void ArithmeticMean(const std::vector<int>& arr) {
    if (arr.empty()) {
        std::cout << "Arithmetic mean = 0\n";
        return;
    }
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    float average = static_cast<float>(sum) / arr.size();
    std::cout << "Arithmetic mean = " << average << "\n";
}

void Sum(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    std::cout << "Sum = " << sum << "\n";
}
