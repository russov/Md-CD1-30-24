#ifndef SUM_AVE_H
#define SUM_AVE_H
#include "create_file.h"
#include <iostream>
#include <vector>
int sumAverage(){
    std::ifstream file("numbersFile.txt");
    if(!(file.is_open())){
        std::cout<<"File open error"<<'\n';
        return 1;
    }
    std::vector<int> num;
    int value;
    while (file >> value)
    {
        num.push_back(value);
    }
    int sumElement = 0;
    for(int i = 0; i < num.size(); i++){
    sumElement += num[i];
    }
    int average = 0;
    std::cout<<""<<'\n';
    std::cout<<"Sum:"<<'\n';
    std::cout<<sumElement<<'\n';
    average = sumElement / num.size();
    
    std::cout<<"Average:"<<'\n';
    std::cout<<average<<'\n';
    std::cout<<""<<'\n';
    file.close();
    return 0;
}

#endif