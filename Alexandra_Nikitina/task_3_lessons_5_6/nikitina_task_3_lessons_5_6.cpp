#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <stack>

void ArrayManipulation();

void CheckBracketInFile();

bool IsCorrect (std::string &s);

  
int main(){

    std::cout << "1) We begin to work with arrays \n";
    ArrayManipulation();

    std::cout << "2) We begin checking the file for the number of opening and closing brackets \n";
    CheckBracketInFile();

    return 0;
}

void ArrayManipulation(){

    srand(time(nullptr));
    int a = 0;
    int b = 0;
    std::cout << "Enter the numbers of the interval [a;b]:\n" << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    
    const int MaxSize = 10;
    int arr[10][10];
    for(int i=0; i<MaxSize; ++i){
        for(int j=0; j<MaxSize; ++j){
            arr[i][j] = a + rand()%(b-a+1);
        }                
    }
    std::cout << "Array: \n";
    for (int i = 0; i < MaxSize; ++i) {
        for (int j = 0; j < MaxSize; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

     int min = arr[0][0];
     int index = 0;
     for(int i=0; i<MaxSize; ++i){
        for(int j=0; j<MaxSize; ++j){
            if(min > arr[i][j]){
                min = arr[i][j];
                index = i;
            }
        }
     }
    
    std::cout << "Minimum value in this array: " << min << " \nLine number with minimum value: " << index+1 << "\n";

    if(index == 0){
        std::cout << "We don't swap rows because the element with the minimum value is found on the first row \n";
    }
    else {
        std::cout << "Replacing the first line with the line where the minimum value is found: \n";

        int changer = 0;
        for(int j=0; j<MaxSize; ++j){
            changer = arr[index][j];
            arr[index][j] = arr[0][j];
            arr[0][j] = changer;
        }
        for(int i=0; i<MaxSize; ++i){
            for(int j=0; j<MaxSize; ++j){
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }

        return;
    }
}


void CheckBracketInFile(){

    std::ifstream file("for_check.txt");
        if(!file){
            std::cout << "File can't be opened/n";
        }

        std::string s;
        getline(file, s, '\0');
        int counter = 0;

    file.close();

    std::ofstream outf("out.txt", std::ios::app);
    if(!outf){
        std::cout << "File can't be opened/n";
    }
    
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now); 
    std::tm* local_now = std::localtime(&now_time);


   if (IsCorrect(s)){
        outf << "All brackets were open and closed. " << "Date and time of file check: " << (local_now->tm_year + 1900) << '-'
                                                                                         << (local_now->tm_mon + 1) << '-'
                                                                                         << local_now->tm_mday << ' '
                                                                                         << local_now->tm_hour << ':'
                                                                                         << local_now->tm_min << ':'
                                                                                         << local_now->tm_sec << std::endl;
        std::cout << "All brackets were open and closed. " << "Date and time of file check: " << (local_now->tm_year + 1900) << '-'
                                                                                              << (local_now->tm_mon + 1) << '-'
                                                                                              << local_now->tm_mday << ' '
                                                                                              << local_now->tm_hour << ':'
                                                                                              << local_now->tm_min << ':'
                                                                                              << local_now->tm_sec << std::endl;
    }
    else {
        outf << "Error. Not all brackets are placed correctly. " << "Date and time of file check: " << (local_now->tm_year + 1900) << '-'
                                                                                                             << (local_now->tm_mon + 1) << '-'
                                                                                                             << local_now->tm_mday << ' '
                                                                                                             << local_now->tm_hour << ':'
                                                                                                             << local_now->tm_min << ':'
                                                                                                             << local_now->tm_sec << std::endl;;
        std::cerr << "Error. Not all brackets are placed correctly. " << "Date and time of file check: " << (local_now->tm_year + 1900) << '-'
                                                                                                                  << (local_now->tm_mon + 1) << '-'
                                                                                                                  << local_now->tm_mday << ' '
                                                                                                                  << local_now->tm_hour << ':'
                                                                                                                  << local_now->tm_min << ':'
                                                                                                                  << local_now->tm_sec << std::endl;
    }

    outf.close();
    
    return;
}


bool IsCorrect (std::string &s){
    
    std::stack<char> container;

    for (char bracket : s) {
        if (bracket == '{') {
            container.push(bracket); 
        }
    
        else if(bracket == '}') {
            if (container.empty()){
                return false;
            }
            container.pop();
        }
    }

    return container.empty();
}