#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>

void ArrayManipulation();

void CheckBracketInFile();
  
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
    
    int arr[10][10];
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            arr[i][j] = a + rand()%(b-a+1);
        }                
    }
    std::cout << "Array: \n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

     int min = arr[0][0];
     int index = 0;
     for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
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
        for(int j=0; j<10; ++j){
            changer = arr[index][j];
            arr[index][j] = arr[0][j];
            arr[0][j] = changer;
        }
        for(int i=0; i<10; ++i){
            for(int j=0; j<10; ++j){
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
    return;

    }

}

void CheckBracketInFile(){

    std::ifstream file("numbers.cpp");
        if(!file){
            std::cout << "File can't be opened";
        }

    std::string s;
    getline(file, s, '\0');
    int counter = 0;
    int len = s.length();
    for(int i=0; i<len; ++i){
        if(s[i] == '{'){
            counter++;
        }
        else if(s[i] == '}') {
            counter--;
        }
   }

    std::ofstream outf("out.txt", std::ios::app);
    if(!outf){
        std::cout << "File can't be opened";
    }
    
    auto now = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(now); 

    if(counter == 0){
        outf << "All brackets were open and closed. " << "Date and time of file check: " << std::ctime(&end_time);
        std::cout << "All brackets were open and closed. " << "Date and time of file check: " << std::ctime(&end_time);
    }
    else if (counter < 0){
        outf << "There are more open '{' brackets than closed '}' ones. " << "Date and time of file check: " << std::ctime(&end_time);
        std::cout << "There are more open '{' brackets than closed '}' ones. " << "Date and time of file check: " << std::ctime(&end_time);
    }
    else {
        outf << "There are more closed '}' brackets than open '{' ones. " << "Date and time of file check: " << std::ctime(&end_time);
        std::cout << "There are more closed '}' brackets than open '{' ones. " << "Date and time of file check: " << std::ctime(&end_time);
    }
    outf.close();
    
    return;
}