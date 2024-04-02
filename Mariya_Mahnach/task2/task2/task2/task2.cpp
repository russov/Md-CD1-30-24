#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int sum(string s)
{
    ifstream fin(s);
    int sum=0;
    while(!fin.eof())
    {
        int x=0;
        fin>>x;
        sum+=x;
    }
    fin.close();
    return sum;
}

double average(string s)
{
    ifstream fin(s);
    int sum=0,n=-1;
    while(!fin.eof())
    {
        int x=0;
        fin>>x;
        sum+=x;
        n++;
    }
    fin.close();
    double avar=1.0*sum/n;
    return avar;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout<<"Введите набор целых чисел (через пробел):\n";
    string str;
    getline(cin,str,'\n');
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]!=' ' && (str[i]<'0' || str[i]>'9') && str[i]!='-')
        {
            cout<<"Неправильное значение!";
            return 0;
        }
    }
    ofstream fout("numbers.txt",ios::app);
    if(fout.is_open()) 
    {
        for(int i=0;i<n;i++)
        {
            if(str[i]==' ') fout<<'\n';
            else fout<<str[i];
        }
        if(str[n-1]!=' ') fout<<'\n';
        cout<<"Данные добавлены в файл\n";
    }
    fout.close();
    cout<<"Сумма чисел: "<<sum("numbers.txt")<<endl;
    cout<<"Среднее арифмитическое: "<<average("numbers.txt");
}

