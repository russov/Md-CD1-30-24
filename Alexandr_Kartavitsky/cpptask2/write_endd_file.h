#ifndef WRITE_ENDD_FILE_H
#define WRITE_ENDD_FILE_H
#include "create_file.h"
#include <iostream>

int writeInTheFileEnd(){
    std::ofstream file("numbersFile.txt", std::ios::app);
   if(file.is_open())
{
     std::cout << "input quantity of input values: " << '\n';
    int numOfValues;
    std::cin >> numOfValues;
    std::cout << " " << '\n';
    std::cout << "input your add values:" <<std::endl;
    int value;
    for (int i = 0; i < numOfValues; i++) {
        std::cin >> value;

       if(std::cin.fail()){
            std::cerr<<"Incorrect input. Only digits"<<std::endl;
            return 1;
        }else{
        file << value << '\n';
    }
}
}else{
    std::cout<<"Open file error\n";
    return 1;
}

file.close();
return 1;
}

#endif