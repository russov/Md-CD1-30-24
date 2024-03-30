#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME "numbers.txt"

void readBackwards(){
    std::ifstream inNums(FILE_NAME, std::ios::ate);
    std::string num;
    int count = 0;
    char curchar;
    int pos = inNums.tellg();
    inNums.seekg(-1, std::ios::end);
    for (int i=0; i < pos; i++){
        curchar = inNums.get();
        count -= 1;
        std::cout << inNums.cur << std::endl;
        std::cout << curchar << std::endl;
        if (curchar != '\n'){
            num.insert (0, 1, curchar);
            continue;
        }
        inNums.seekg(-2, std::ios::cur);
        
        
        std::cout << num << std::endl;
        num.clear();

        // num = inNums + 
    }
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

int main(){
    std::ofstream outNums(FILE_NAME, std::ios::app); 
    std::cout << "Enter numbers here" << std::endl;
    int num;
    while (std::cin){
        std::cin >> num;
        outNums << num << std::endl;
    }
    outNums.close();
    getSum();
    readBackwards();
}