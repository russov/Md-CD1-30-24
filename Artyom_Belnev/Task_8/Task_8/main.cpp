#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <list>

using namespace std;

const int BUFFER_SIZE = 5;

class Timer {
private:
    mutex mtx;
    condition_variable c_v;
    bool isDone = false;

public:
    void sleepFor(const chrono::milliseconds& duration) {
        unique_lock<mutex> lock(mtx);
        c_v.wait_for(lock, duration, [this] { return isDone; });
    }
};

class Buffer {
private:
    std::list<char> buffer;
    std::mutex mtx;

public:
    Buffer() {}

    void push(char c) {
        lock_guard<mutex> lock(mtx);
        if (c == '.') buffer.clear();
        buffer.push_back(c);
    }

    char pop() {
        lock_guard<mutex> lock(mtx);
        if (!buffer.empty()) {
            char result = buffer.front();
            buffer.pop_front();
            return result;
        }
        return '\0';
    }
};

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) return 1; 

    ofstream outputFile("output.txt"); 
    if (!outputFile.is_open()) return 1;

    Buffer sharedBuffer;

    Timer timer;

    int readerCount = 0;
    int writerCount = 0;
    bool stopReader = false;

  
    thread readerThread([&]() {
        char c;
        while (file.get(c)) {

            timer.sleepFor(std::chrono::milliseconds(100));
            sharedBuffer.push(c);
            readerCount++;
        }
        stopReader = true;
    });

   
    thread writerThread([&]() {
        char c;
        while (stopReader == false) {
            timer.sleepFor(std::chrono::milliseconds(150));
            c = sharedBuffer.pop();
            if (c != '\0') {
                outputFile << c;
                writerCount++;
            }
        }
     });

    readerThread.join(); 
    writerThread.join(); 

    cout << "Read chars = " << readerCount << endl;
    cout << "Write chars = "<< writerCount << endl;


    file.close();
    outputFile.close();

    return 0;
}