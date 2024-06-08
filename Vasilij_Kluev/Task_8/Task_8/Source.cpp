
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>


const int BUFFER_SIZE = 5;
std::vector<char> buffer(BUFFER_SIZE);
std::mutex mtx;
std::condition_variable cv;
std::atomic<int> buffer_count(0);
std::atomic<bool> stop_reading(false);
std::atomic<bool> stop_writing(false);

class Timer {
public:
    template <typename Function>
    void setInterval(Function function, int interval) {
        std::thread([function, interval]() {
            while (true) {
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                function();
            }
            }).detach();
    }
};

int reader_thread(const std::string& input_file) {
    std::ifstream infile(input_file);
    if (!infile.is_open()) {
        std::cerr << "Error opening input file!" << std::endl;
        return 0;
    }
    char ch;
    int read_count = 0;
    Timer timer;
    timer.setInterval([&]() {
        if (infile.get(ch)) {
            std::unique_lock<std::mutex> lock(mtx);
            if (ch == '.') {
                buffer_count = 0;
                cv.notify_all();
                std::cout << "Buffer cleared due to '.'" << std::endl;
            }
            else if (buffer_count < BUFFER_SIZE) {
                buffer[buffer_count++] = ch;
                std::cout << "Read: " << ch << std::endl;
                read_count++;
                cv.notify_all();
            }
            else {
                std::cout << "Buffer overflow, character lost: " << ch << std::endl;
            }
        }
        else {
            stop_reading = true;
            cv.notify_all();
        }
        }, 100);
    while (!stop_reading) std::this_thread::sleep_for(std::chrono::milliseconds(10));
    infile.close();
    return read_count;
}

int writer_thread(const std::string& output_file) {
    std::ofstream outfile(output_file);
    if (!outfile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        return 0;
    }
    int write_count = 0;
    Timer timer;
    timer.setInterval([&]() {
        std::unique_lock<std::mutex> lock(mtx);
        if (buffer_count > 0) {
            outfile << buffer[--buffer_count];
            std::cout << "Written: " << buffer[buffer_count] << std::endl;
            write_count++;
        }
        cv.notify_all();
        }, 150);
    while (!stop_writing) std::this_thread::sleep_for(std::chrono::milliseconds(10));
    outfile.close();
    return write_count;
}

int main() {
    std::string input_file = "file_1.txt";
    std::string output_file = "file_2.txt";

    std::thread reader([&input_file]() { return reader_thread(input_file); });
    std::thread writer([&output_file]() { return writer_thread(output_file); });

    reader.join();
    stop_writing = true;
    writer.join();

    std::cout << "Reading finished." << std::endl;
    std::cout << "Writing finished." << std::endl;

    return 0;
}