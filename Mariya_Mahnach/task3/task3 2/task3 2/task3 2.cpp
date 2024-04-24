#include <iostream>
#include <fstream>
#include <string>

int CharNum(const std::string &s, const char c)
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
    if (s[n - 1] == c) k++;
    return k;
}


int main()
{
    int open = 0, close = 0,k=0;
    std::ifstream infile("task2.cpp");
    if (!infile.is_open()) { std::cout << "Failed to open input file"; return 0; }
    while (!infile.eof())
    {
        k++;
        std::string str;
        getline(infile, str, '\n');
        if(k==1) str.erase(0,3);
        str.push_back(' ');
        open += CharNum(str, '{');
        close += CharNum(str, '}');
    }
    infile.close();
    std::ofstream outfile("out.txt");
    if (!outfile.is_open()) { std::cout << "Failed to open output file"; return 0; }
    if (open == close)
    {
        std::cout << "The parentheses are fine";
        outfile << "The parentheses are fine";
    }
    else if (open > close)
    {
        std::cout << "Missing '}' or extra '{'";
        outfile << "Missing '}' or extra '{'";
    }
    else
    {
        std::cout << "Missing '{' or extra '}'";
        outfile << "Missing '{' or extra '}'";
    }
    outfile.close();
}
