#include <iostream>
#include <fstream>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <stdarg.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

const int maxSize = 5;
const int varCount = 3;
const char extChar = '\0';

class Timer
{
public:
    static void start(int waitMsec, std::function<bool(
        std::fstream*, std::queue<char>*, std::mutex*, int*
    )> func, std::fstream* stream, std::queue<char>*cont, std::mutex* mutex, int* counter) 
    {      
        if (stream == nullptr || !stream->is_open()) {
            std:: cout << "input file stream is empty" << std::endl;
            return;
        }
            if (cont == nullptr) {
            std:: cout << "container is null" << std::endl;
            return;
        }
        if (mutex == nullptr) {
            std:: cout << "mutex is null" << std::endl;
            return;
        }
        while (func(stream, cont, mutex, counter)){
            std::this_thread::sleep_for(std::chrono::milliseconds(waitMsec));
        }
    }
};

bool readChar(std::fstream* reader, std::queue<char>*cont, std::mutex* mutex, int* counter)
{
    char inChar;
    
    if ((*reader) >> std::noskipws >> inChar) 
    {
        (*counter) ++;
        if (inChar == '.') {
            mutex->lock();
            while (!cont->empty())
                cont->pop();
            mutex->unlock();
        }
        else if (cont->size() < maxSize) {
            mutex->lock();
            cont->push(inChar);
            mutex->unlock();
        }        
        return true;
    }
    
    mutex->lock();
    cont->push('\0');
    mutex->unlock();
    return false;
}

bool writeChar(std::fstream* writer, std::queue<char>*cont, std::mutex* mutex, int* counter) 
{   
    mutex->lock();
    if (!cont->empty())
    {
        if (cont->front() == '\0')
            return false;
        *writer << std::noskipws << cont->front();
        (*counter) ++;
        cont->pop();
    }
    mutex->unlock();
    return true;
}

int main() 
{
    auto fileReader = std::fstream{INPUT_FILE, std::ios::in};
    auto fileWriter = std::fstream{OUTPUT_FILE, std::ios::out | std::ios::trunc};

    const int read_delay {100};
    const int write_delay {150};

    int read_count {0};
    int write_count {0};

    std::mutex mutex;

    auto container = std::queue<char>{};
    // Timer::start(read_delay, &read_count, readChar, &fileReader, &container, &mutex);
    std::thread thread1([&](){
        Timer::start(read_delay, readChar, &fileReader, &container, &mutex, &read_count);
    });
    std::thread thread2 ([&](){
        Timer::start(read_delay, writeChar, &fileWriter, &container, &mutex, &write_count);
    });
    

    thread1.join();
    thread2.join();

    fileReader.close();
    fileWriter.close();

    std::cout << "Total chars read " << read_count << std::endl;
    std::cout << "Total chars writen " << write_count << std::endl;

    return 0;
}