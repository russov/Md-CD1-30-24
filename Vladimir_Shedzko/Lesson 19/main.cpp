#include <iostream>
#include <fstream>
#include <thread>
#include <deque>

#if defined(_WIN32)
    #include <windows.h>
#elif __has_include(<unistd.h>)
    #include <unistd.h>
#else
#  error Unknown platform
#endif

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

void readChar(std::ifstream reader, std::deque<char> cont)
{

}

void writeChar() 
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() 
{
    //std::mutex counter_mutex;
//
//void increment() {
//    for (int i = 0; i < 10000000; ++i) {
//        std::lock_guard<std::mutex> lock(counter_mutex);
//        ++counter;
//    }
//}
    auto fileReader = std::ifstream{INPUT_FILE};
    auto fileWriter = std::ofstream{INPUT_FILE};
    char inChar;
    char outChar;

    auto container = std::deque<char>{};

    auto f1 = [&fileReader, &container, &inChar]() {
        if (!fileReader.is_open()) 
        {
            container.push_back('\0');
            return;
        }
        while (fileReader >> inChar) 
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
        container.push_back('\0');
        fileReader.close();
    };

    auto f2 = [&fileWriter, &container, &outChar]() {
        
        while (true)
        {
            if (!container.empty())
            {

            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        fileWriter.close();
    };


    auto thread1 = std::thread{readChar, fileReader, };
    auto thread2 = std::thread{};

    thread1.join();
    thread2.join();

    

    return 0;
}