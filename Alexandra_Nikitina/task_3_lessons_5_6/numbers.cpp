#include <iostream>
#include <fstream>

void PrintReverse(int amountt) {

    std::cout << "In reverse order: \n";
    std::ifstream inf("numbers.txt");
    if(!inf){
        std::cout << "File can't be opened";
    }
    int arr[amountt];
    for (int i=0; i<amountt; ++i){
        inf >> arr[i];
        }
    for (int i=amountt-1; i>=0; --i) { 
        std::cout << arr[i] << std::endl;
        }
    inf.close();
return;

}

void ArithmeticMean(int amounttt) {

std::ifstream inf("numbers.txt");
if(!inf){
    std::cout << "File can't be opened";
}
int arr[amounttt];
float average=0;
int summ=0;
for (int i=0; i<amounttt; ++i){
    inf >> arr[i];
    summ += arr[i];
    average = float(summ)/float(amounttt);
    }
std::cout << "Arithmetic mean = " << average << "\n";
inf.close();
return;

}

void Sum(int amountttt) {

std::ifstream inf("numbers.txt");
if(!inf){
    std::cout << "File can't be opened";
}
int arr[amountttt];
int sum=0;
for (int i=0; i<amountttt; ++i){
    inf >> arr[i];
    sum += arr[i];
    }
std::cout << "Sum = " << sum << "\n";
inf.close();
return;
}

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
    while (std::getline(iinf, line))
        ++new_amount;
        std::cout << "Number of digits in file:: " << new_amount << "\n";
    iinf.close();

    PrintReverse(new_amount);
    Sum(new_amount);
    ArithmeticMean(new_amount);

    return 0;
}