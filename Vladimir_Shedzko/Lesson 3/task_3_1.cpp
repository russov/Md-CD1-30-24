#include <iostream>
#include <fstream>
#include <string>

#define FILE_NAME "numbers.txt"

using namespace std;

void readBackwards(){
    ifstream inNums(FILE_NAME);
    inNums.close();
}

void getSum(){
    int sum = 0;
    ifstream inNums(FILE_NAME);
    int a;
    while (inNums >> a)
        sum += a;
    inNums.close();
    cout << "Сумма чисел в файле: " << sum << endl;
}

int main(){
    ofstream outNums(FILE_NAME); 
    cout << "Введите целые числа" << endl;
    int num;
    while (cin >> num){
        outNums << num;
    }
    outNums.close();
    getSum();
}