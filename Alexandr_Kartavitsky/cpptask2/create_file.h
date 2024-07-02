#ifndef CREATE_FILE_H
#define CREATE_FILE_H
#include<fstream>
#include<iostream>
int makeFileNumbers(){
    

    std::cout << "input quantity of input values: " << '\n';
    int numOfValues;
    std::cin >> numOfValues;
    std::ofstream file("numbersFile.txt");
    if (!(file.is_open())) {
        std::cout << "Open file error\n";
        return 1;
    }
    std::cout << "input your values:" << '\n';
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
    file.close();
    return 0;
}


#endif

