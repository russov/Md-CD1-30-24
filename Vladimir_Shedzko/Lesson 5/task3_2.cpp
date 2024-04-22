#include <iostream>
#include <string>
#include <fstream>

const char* g_ifname = "input.c";
const char* g_ofname = "output.txt";

int main() {
    std::ifstream inp(g_ifname);
    char c;
    int count = 0;
    // std::string content(std::istreambuf_iterator<char>{inp}, {});
    while(inp >> c){
        if (c == '{')
            count++;
        if (c == '}'){
            count--;
            if (count < 0)
                break;
        }
    }
    inp.close();

    std::ofstream out(g_ofname);
    if (count != 0)
        out << "File is incorrect";
    else
        out << "File is correct";
    out.close();
    return 0;
}