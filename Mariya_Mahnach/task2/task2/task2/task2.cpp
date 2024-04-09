#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
    double avar=(double)sum/n;
    return avar;
}

void print(string s)
{
    ifstream fin(s);
    vector <int> v;
    while (!fin.eof())
    {
        int x;
        fin >> x;
        if (fin.eof()) break;
        v.push_back(x);
    }
    fin.close();
    for (int i = v.size()-1; i >= 0; i--)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string filename = "numbers.txt";
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
    ofstream fout(filename,ios::app);
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
    cout<<"Числа в файле:"<<endl;
    print(filename);
    cout<<"Сумма чисел: "<<sum(filename)<<endl;
    cout<<"Среднее арифмитическое: "<<average(filename);
}

