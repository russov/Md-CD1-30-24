// разработать многопоточное приложение, которое будет в потоке читать текстовый файл со скоростью один символ каждые 100 мс,
// и записывать символ в буфер, размер буфера 5 символом, если буфер переполнен, то вычитанный символ теряется, 
// второй поток забирает каждые 150 мс символ из буфера и записывает результат в другой файл. 
// Если в тексте встречается точка (.) необходимо очищать буфер без записи символов в выходной файл. 
// Для слежения за временем необходимо разработать класс таймер, который будет запускать функцию, 
// через строго настроенное время. Основной поток должен ожидать завершения потоков чтения и записи. 
// Поток чтения должен возвращать количество успешно прочитанных символов, 
// поток записи - количество успешно записанных символов. 
// Основной поток должен получить и вывести эти результаты на консоль.
//

#include <iostream>
#include <thread>
#include <fstream>
#include <vector>
#include <mutex>
#include "Timer.h"

using namespace std;

mutex mtx;

void readFromFile(vector<char>& buffer, atomic_bool& readFinish, int& itRead)
{
    ifstream readChar{ "textRead.txt" };
    if (!readChar.is_open())
    {
        cout << "File not exist\n";
        return;
    }

    Timer readTimer(100);
    char c;

    while (true)
    { 
        bool success{false};

        readTimer.stop([&] { success = static_cast<bool>(readChar.get(c)); });

        if (!success) {
            break;
        }

        if (c == '\n' || c == ' ')
        {
            itRead++;
            continue;
        }

        if (c == '.')
        {
            lock_guard<mutex> lock(mtx);
            buffer.clear();
            itRead++;
            continue;
        }

        lock_guard<mutex> lock(mtx);
        if (buffer.size() < 5)
        {
            buffer.push_back(c);
            itRead++;
        }
        else
        {
            itRead++;  
        }
    }

    readFinish = true;
    readChar.close();
}

void writeFunk(vector<char>& buffer, atomic_bool& readFinish, int& itWrite, ofstream& writeChar, bool& tick)
{
    lock_guard<mutex> lock(mtx);

    if (!buffer.empty())
    {
        writeChar << buffer.front();
        buffer.erase(buffer.begin());
        itWrite++;
    }
    else if (readFinish)
    {
        tick = false;
        return;
    }
}

void writeToFile(vector<char>& buffer, atomic_bool& readFinish, int& itWrite)
{
    ofstream writeChar{ "textWrite.txt" };
    if (!writeChar.is_open())
    {
        cout << "Unable to open output file.\n";
        return;
    }

    Timer write(150);
    bool tick{ true };
    while (tick)
    {
        write.stop(writeFunk, ref(buffer), ref(readFinish), ref(itWrite), ref(writeChar), ref(tick));
    }

    writeChar.close();
}

int main()
{
    vector<char> buffer;
    atomic_bool readFinish{false};
    int itRead{ 0 }, itWrite{ 0 };

    thread readThread(readFromFile, ref(buffer), ref(readFinish), ref(itRead));

    ofstream clearFile("textWrite.txt");
    clearFile.close();

    thread writeThread(writeToFile, ref(buffer), ref(readFinish), ref(itWrite));

    readThread.join();
    writeThread.join();

    cout << "Count read symbols: " << itRead << endl;
    cout << "Count write symbols: " << itWrite << endl;

    return 0;
}
