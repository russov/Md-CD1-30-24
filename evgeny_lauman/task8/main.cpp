#include <fstream>
#include <iostream>
#include <thread>
#include <queue>
#include <thread>
#include <mutex>


std::queue<char> buffer;
const int size = 5;

void readFileToBuffer(std::mutex& buf_mutex, bool& fin_eof, int& fin_counter)
{
	const std::string filename = "input.txt";
	std::ifstream fin;
	fin.open(filename, std::ios::in);
	if (fin.is_open())
	{
		char c;
		while (!fin.eof())
		{
			fin.get(c);
			++fin_counter;
			buf_mutex.lock();
			if (buffer.size() < 5)
			{
				buffer.push(c);
			}
			buf_mutex.unlock();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		fin_eof = true;
		fin.close();
	}
	else
		std::cout << "Error open file input.txt\n";
	return;
}

void writeFileFromBuffer(std::mutex& buf_mutex, bool& fin_eof, int& fout_counter)
{
	const std::string filename = "output.txt";
	std::ofstream fout;
	fout.open(filename, std::ios::out);
	if (fout.is_open())
	{
		char c;
		while (true)
		{
			buf_mutex.lock();
			if (buffer.empty() && fin_eof)
			{
				buf_mutex.unlock();
				break;
			}
			else if (buffer.empty())
			{
				buf_mutex.unlock();
				continue;
			}
			else
			{
				c = buffer.front();
				buffer.pop();
				if (c == '.')
				{
					for (auto i = 0; i < buffer.size(); i++)
					{
						buffer.pop();
					}
				}
				else
				{
					fout << c;
					++fout_counter;
				}
				buf_mutex.unlock();
				std::this_thread::sleep_for(std::chrono::milliseconds(150));
			}
		} 
		fout.close();
	}
	else
		std::cout << "Error open file numbers.txt\n";
	return;
}

int main()
{
	std::mutex buf_mutex;
	bool fin_eof = false;
	int fin_counter{ 0 }, fout_counter{ 0 };
	std::thread t_read(readFileToBuffer, std::ref(buf_mutex), std::ref(fin_eof), std::ref(fin_counter));
	std::thread t_write(writeFileFromBuffer, std::ref(buf_mutex), std::ref(fin_eof), std::ref(fout_counter));
	t_read.join();
	t_write.join();
	std::cout << "Count of input symbols: " << fin_counter << "\nCount of output symbols: " << fout_counter << std::endl;
	return 0;
}