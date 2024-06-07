#include <iostream>
#include <list>
#include <future>
#include <condition_variable>
#include <fstream>


#define MAX_BUFFER_SIZE 5
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"


bool readingFile{ true };
std::list<char> buffer;
std::mutex buffer_mutex;

int readFile()
{
	int count{ 0 };
	std::ifstream fromFile(INPUT_FILE);
	if (!fromFile)
	{
		std::cerr << "ERROR! Failed to open input file!!!" << std::endl;
	}
	else {
		const std::chrono::milliseconds delay{ 100 };
		char readSymbol;
		while (fromFile >> readSymbol)
		{
			++count;
			buffer_mutex.lock();
			if (readSymbol == '.')
			{
				buffer.clear();
			}
			else if (buffer.size() < MAX_BUFFER_SIZE)
			{
				buffer.push_back(readSymbol);
			}
			buffer_mutex.unlock();
			std::this_thread::sleep_for(delay);
		}
	}
	readingFile = false;
	return count;
}


int writeToFile()
{
	int count{ 0 };
	std::ofstream toFile(OUTPUT_FILE);
	const std::chrono::milliseconds delay{ 150 };
	while (readingFile || !buffer.empty())
	{
		buffer_mutex.lock();
		if (!buffer.empty())
		{
			toFile << buffer.front();
			buffer.pop_front();
			++count;
		}
		buffer_mutex.unlock();
		std::this_thread::sleep_for(delay);
	}
	return count;
}


int main()
{
	std::future<int> readCount = std::async(std::launch::async, readFile);
	std::future<int> writeCount = std::async(std::launch::async, writeToFile);
	std::cout << "readCount - " << readCount.get() << std::endl;
	std::cout << "writeCount - " << writeCount.get() << std::endl;
}