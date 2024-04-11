#include <iostream>
#include <fstream>
int main()
{
    std::string FileName;
    std::cout << "Enter file name(example: in.cpp): ";
    std::cin >> FileName;
    std::ifstream inf(FileName);
    if (!inf) {
        std::cout << "ERROR! FAILED TO OPEN FILE";
        exit(1);
    }
    char sym;
    int count{0};
    while (inf >> sym) {
            if (sym == '{')++count;
            else if (sym == '}')--count;
    }
    std::ofstream outf("out.txt");
    if (count == 0) {
        std::cout << "File is ok";
        outf << "File is ok";
    }
    else {
        std::cout << "File is NOT ok";
        outf << "File is NOT ok";
    }
}