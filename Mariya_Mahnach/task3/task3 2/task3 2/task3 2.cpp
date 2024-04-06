#include <iostream>
#include <fstream>
#include <string>


int CharNum(std::string s, char c)
{
    static bool gIscom = false;
    int n = s.size(), k = 0;
    bool iscom = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '/' && s[i + 1] == '/' && !gIscom) { iscom = true; break; }
        if (s[i] == '/' && s[i + 1] == '*' && !iscom) { gIscom = true; }
        if (s[i] == '*' && s[i + 1] == '/' && !iscom) { gIscom = false; }
        if (!iscom && !gIscom && s[i] == c) k++;
    }
    return k;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int open = 0, close = 0,k=0;
    std::ifstream infile("task2.cpp");
    if (!infile.is_open()) { std::cout << "Не удалось открыть файл ввода"; return 0; }
    while (!infile.eof())
    {
        k++;
        std::string str;
        getline(infile, str, '\n');
        if(k==1) str.erase(0,3);
        //std::cout<<str<<"\n";
        open += CharNum(str, '{');
        close += CharNum(str, '}');
    }
    infile.close();
    std::ofstream outfile("out.txt");
    if (!outfile.is_open()) { std::cout << "Не удалось открыть файл вывода"; return 0; }
    if (open == close)
    {
        std::cout << "Со скобками всё в порядке";
        outfile << "Со скобками всё в порядке";
    }
    else if (open > close)
    {
        std::cout << "Не хватает '}' или есть лишние '{'";
        outfile << "Не хватает '}' или есть лишние '{'";
    }
    else
    {
        std::cout << "Не хватает '{' или есть лишние '}'";
        outfile << "Не хватает '{' или есть лишние '}'";
    }
    outfile.close();
}
