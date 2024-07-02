#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>

namespace Data_storage { // Data storage structure
    std::queue<char> buffer; // Buffer for characters, using queue (works on the principle FIFO)
    std::mutex mutexBuffer; // Mutex for buffer synchronization
    std::condition_variable bufferNotEmpty; // Condition variable to notify thread
    bool stopRead = false; // Flag to end the thread
    size_t charactersRead = 0; // Number of characters read
    size_t charactersWrite = 0; // Number of characters recorded
};

class Timer { // Timer class for setting delay
public:
    static void delay(int value) {
        std::this_thread::sleep_for(std::chrono::milliseconds{ value });
    }
};

void read_from_file(const std::string& filename, int delay_value) { // Function for reading characters from a file and writing to a buffer
    char symbol = '\0';
    const size_t buffer_max = 5; // Buffer size
    std::ifstream inf(filename);
    if (!inf.is_open()) {
        std::cerr << "Uh oh, file could not be opened for reading!" << std::endl;
        return;
    }
    while (inf.get(symbol)) {
        {
            std::lock_guard<std::mutex> lock(Data_storage::mutexBuffer); // Using lock_guard
            if (symbol == '.') { // If this is a period, then we delete all characters from the buffer              
                while (!Data_storage::buffer.empty()) {
                    Data_storage::buffer.pop();
                }
            }
            else if (Data_storage::buffer.size() < buffer_max) { // If the buffer is not full, add the character to the buffer             
                Data_storage::buffer.push(symbol);               
            }
            Data_storage::charactersRead++; // Increase the counter
            Data_storage::bufferNotEmpty.notify_one();
        }
        Timer::delay(delay_value);
    }
    Data_storage::stopRead = true;
    Data_storage::bufferNotEmpty.notify_one(); // Notify thread author when reading is complete
    inf.close();
}

void write_to_buffer(const std::string& output_filename, int delay_value) { // Function for reading characters from a buffer and writing to a file
    std::ofstream outf(output_filename);
    if (!outf.is_open()) {
        std::cerr << "If you want to stop entering values, write stop." << std::endl;
        return;
    }
    while (true) {
        char symbol = '\0';
        {
            std::unique_lock<std::mutex> lock(Data_storage::mutexBuffer); // Lock blocks access to the buffer. Synchronization between threads
            Data_storage::bufferNotEmpty.wait(lock, [&] { return !Data_storage::buffer.empty() || Data_storage::stopRead; }); // Waiting until the buffer is non-empty or the flag is true. This helps the writer thread continue working as long as there is data to write to the file.
            if (Data_storage::buffer.empty()) { // Is the buffer empty?
                if (Data_storage::stopRead) // Checking the flag that no more characters will be received
                    break;
            }
            else {
                symbol = Data_storage::buffer.front(); // Retrieving a character from the front of the buffer
                Data_storage::buffer.pop(); // Removing a character from the buffer
                Data_storage::charactersWrite++; // Increase by one
            }
        }
        outf.put(symbol); // Writing a symbol to a file
        Timer::delay(delay_value);
    }
    outf.close();
}

int main() {
    const std::string input_filename = "input.txt";
    const std::string output_filename = "output.txt";

    std::thread reader_thread(read_from_file, input_filename, 100); // Stream with delay 100 мс
    std::thread writer_thread(write_to_buffer, output_filename, 150); // Stream with delay 150 мс

    reader_thread.join(); // Block the main thread until this thread is executed
    writer_thread.join(); // Block the main thread until this thread is executed

    std::cout << "Total characters read: " << Data_storage::charactersRead << std::endl;
    std::cout << "Total characters written: " << Data_storage::charactersWrite << std::endl;

    return 0;
}