#include <iostream>
#include <thread>
#include <fstream>
#include <mutex>
#include <string>
#include <vector>
#include <chrono>
#include "Timer.h"

const std::string in_file{ "input.txt" };
const std::string out_file{ "output.txt" };
int read{ 0 }, write{ 0 };
std::mutex mutex;
std::vector<char> buffer;
const int size = 5;
bool alreadyRead{ false };

void ReadFromFile()
{
	Timer timer(100);
	std::ifstream file(in_file);
	if (!file.is_open())
	{
		std::cout << "\nInput file opening error\n";
		return;
	}

	char c = '\0'; 

	while (file.get(c)) 
	{
		mutex.lock();
		if (buffer.size() < 5)
		{
			if (c != '\n')
			{
				buffer.push_back(c);
				read++;
			}
		}
		mutex.unlock();

		timer.wait();
	}

	file.close();
	mutex.lock();
	alreadyRead = true;
	mutex.unlock();
}
void WriteToFile()
{
	Timer timer(150);
	std::ofstream file(out_file);
	if (!file.is_open())
	{
		std::cout << "\nOutput file opening error\n";
		return;
	}
	char c;
	while (true)
	{
		mutex.lock();
		if (alreadyRead && buffer.size() == 0)
		{
			mutex.unlock();
			break;
		}
		if (buffer.size() != 0)
		{
			c = buffer[0];
			buffer.erase(buffer.begin());
		}
		else
		{
			mutex.unlock();
			continue;
		}

		if (c == '.')
		{
			buffer.clear();
			mutex.unlock();
			continue;
		}

		mutex.unlock();
		file << c;
		write++;

		timer.wait();
	}
	file.close();
}

int main()
{
	std::thread t1(ReadFromFile);
	std::thread t2(WriteToFile);
	std::cout << "Processing...\n";
	t1.join();
    t2.join();
	std::cout << "Ready\n";
	std::cout << "Read: " << read << "\nRecorded: " << write<<std::endl;
}
