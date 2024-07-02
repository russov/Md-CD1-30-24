#ifndef R_FILE_H
#define R_FILE_H
#include <vector>
#include "create_file.h"

int readReverse(){
std::ifstream file("numbersFile.txt");
if(!(file.is_open()))
{
    std::cout<<"Read file error\n";
    return 1;
}
std::vector<std::string> lines;
std::string line;

while (std::getline(file, line)){
    lines.push_back(line);
}
 std::cout<<""<<'\n';
 std::cout<<"Reverse:"<<'\n';
for (auto i = lines.rbegin(); i != lines.rend(); i ++){
    int inInt = std::stoi(*i);
    std::cout<<*i<<'\n';
}
file.close();
return 1;
}

#endif 