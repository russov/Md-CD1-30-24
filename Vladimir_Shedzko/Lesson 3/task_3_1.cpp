#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME "numbers.txt"

void readBackwards(){
    std::cout << "Reversed file contents: " << std::endl;
    std::ifstream inNums(FILE_NAME, std::ifstream::ate | std::ifstream::binary);
    std::string num;
    char curchar;
    int pos = inNums.tellg();
    // откат в конец файла и побитовое чтение
    inNums.seekg(-1, std::ios::end);
    for (int i=0; i < pos; i++) {
        inNums.get(curchar);
        inNums.seekg(-2, std::ios::cur);
        if (curchar != '\n' && curchar != '\r') {
            num.insert (0, 1, curchar);
            continue;
        }
        if (num.length()) {
            std::cout << num << std::endl;
            num.clear();
        }
    }
    // вывод первого числа
    if (num.length())
        std::cout << num << std::endl;
    inNums.close();
}

void getSum(){
    int sum = 0;
    std::ifstream inNums(FILE_NAME, std::ios::beg);
    int a;
    while (inNums >> a)
        sum += a;
    inNums.close();
    std::cout << "Sum of numbers in file: " << sum << std::endl;
}

void getAvg(){
    int sum = 0;
    int count = 0;
    std::ifstream inNums(FILE_NAME, std::ios::beg);
    int a;
    while (inNums >> a){
        sum += a;
        count++;
    }
    inNums.close();
    std::cout << "Average of numbers in file: " << (float)sum/count << std::endl;
}

int main(){
    std::ofstream outNums(FILE_NAME, std::ios::app); 
    std::cout << "Enter numbers here" << std::endl;
    std::string line;
    bool isNumeric;
    // читаем значения до ввода пустой строки
    while (std::getline(std::cin, line)) {
        if (line.length() == 0)
            break;
        isNumeric = true;
        for (int i = 0; i < line.length(); i++)
            if (!isdigit(line[i])) {
                std::cout << "Line " << line << " is not numeric!" << std::endl;
                isNumeric = false;
                break;
            }
        if (isNumeric)
            outNums << line << std::endl;
    }
    outNums.close();
    readBackwards();
    getSum();
    getAvg();
}