#include <iostream>
#include <fstream>
#include <vector>
#include <future>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

class Timer {
    public:
        Timer(int delay) : m_delay(delay) {}

        void sleep() {
            std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
        }

        void start() {
            m_future = std::async(std::launch::async, [&](){
                sleep();
            });
        }

        void wait() {
            if (m_future.valid()) {
                m_future.wait();
            }
        }

    private:
        int m_delay;
        std::future<void> m_future;
};

class Buffer {
    public:
        bool push(char c) {
            std::lock_guard<std::mutex> lock(m_mutex);
            const int max_buffer_size = 5;
            if (m_buffer.size() < max_buffer_size) {
                m_buffer.push_back(c);
                return true;
            }
            return false;
        }

        std::vector<char> PopAll() {
            std::lock_guard<std::mutex> lock(m_mutex);
            std::vector<char> data(m_buffer.begin(), m_buffer.end());
            m_buffer.clear();
            return data;
        }

    private:
        std::vector<char> m_buffer;
        std::mutex m_mutex;
};

int ReadFromFile(const std::string& filename, Buffer& buffer, Timer& read_timer) {
    std::ifstream input_file(filename);
    if(!input_file){
        std::cout << "File can't be opened";
    }
    int count = 0;
    char c;
    bool finished = false;
    while (!finished && input_file >> std::noskipws >> c) {
        read_timer.start();
        if (c == '.') {
            buffer.PopAll(); 
        } else {
            if (buffer.push(c)) {
                count++;
            }
        }
        read_timer.wait();

        if (input_file.peek() == EOF) {
            finished = true;
        }

    }
    return count;
}

int WriteToFile(const std::string& filename, Buffer& buffer, Timer& write_timer) {
    std::ofstream output_file(filename);
    if(!output_file){
        std::cout << "File can't be opened";
    }
    int count = 0;
    while (true) {
        write_timer.start();
        std::vector<char> data = buffer.PopAll();
        if (data.empty()) {
            break;
        }
        for (char c : data) {
            output_file << c;
            count++;
        }
        write_timer.wait();
    }
    return count;
}

int main() {
    Buffer buffer;
    Timer read_timer(100);
    Timer write_timer(150);

    std::string input_filename = "example.txt";
    std::string output_filename = "output.txt";

    std::future<int> read_result = std::async(std::launch::async, ReadFromFile, input_filename, std::ref(buffer), std::ref(read_timer));
    std::future<int> write_result = std::async(std::launch::async, WriteToFile, output_filename, std::ref(buffer), std::ref(write_timer));

    if (read_result.valid()) {
        int count_read = read_result.get();
        std::cout << "Successfully read characters: " << count_read << std::endl;
    }

    if (write_result.valid()) {
        int count_written = write_result.get();
        std::cout << "Successfully written characters: " << count_written << std::endl;
    }

    return 0;
}