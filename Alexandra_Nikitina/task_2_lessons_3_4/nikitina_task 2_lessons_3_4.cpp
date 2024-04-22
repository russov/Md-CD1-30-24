#include <iostream>
#include <fstream>
#include <string>

void PrintReverse(int* arr, int amount);

void ArithmeticMean(int* arr, int amount);

void Sum(int* arr, int amount);

int main(){

    std::ofstream outf("numbers.txt", std::ios::app);

    if(!outf){
        std::cout << "File can't be opened";
    }

    int amount;
    std::cout << "Enter amount of numbers: ";
    std::cin >> amount;

    while (!amount){
        std::cout << "Incorrect type, try again\n";
        std::cin.clear();
        std::cin.ignore(100000000, '\n');
        std::cout << "Enter amount of numbers: ";
        std::cin >> amount;
    }

    int num=0;
    for (int i=0; i<amount; ++i){
        std::cout << "num " << i+1 << " = ";
        std::cin >> num;

        while (!num){
            std::cout << "Incorrect type, try again\n";
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            std::cout << "num " << i+1 << " = ";
            std::cin >> num;
        }
        outf << num << "\n";
    }

    outf.close();
 
 
    int new_amount =0;
    std::string line;
    std::ifstream iinf("numbers.txt");
    if(!iinf){
        std::cout << "File can't be opened";
    }

    while (std::getline(iinf, line)){
        ++new_amount;
    }
    iinf.clear();
    iinf.seekg(0);
    std::cout << "Number of digits in file:: " << new_amount << "\n";
 
    int* arr = new int[new_amount];
     
    for (int i=0; i<new_amount; ++i){
        iinf >> arr[i];
        std::cout << arr[i] << "\n";
    }

    iinf.close();

    PrintReverse(arr, new_amount);
    Sum(arr, new_amount);
    ArithmeticMean(arr, new_amount);

    delete[] arr;
    arr = nullptr;

    return 0;
}

void PrintReverse(int* arr, int amount) {

    std::cout << "In reverse order: \n";
    for (int i=amount-1; i>=0; --i) { 
        std::cout << arr[i] << std::endl;
        }

return;
}

void ArithmeticMean(int* arr, int amount) {

    float average=0;
    int summ=0;
    
    for (int i=0; i<amount; ++i){
        summ += arr[i];
        average = float(summ)/amount;
        }
    std::cout << "Arithmetic mean = " << average << "\n";

return;
}

void Sum(int* arr, int amount) {

    int sum=0;
    for (int i=0; i<amount; ++i){
        sum += arr[i];
        }
    std::cout << "Sum = " << sum << "\n";

return;
}
