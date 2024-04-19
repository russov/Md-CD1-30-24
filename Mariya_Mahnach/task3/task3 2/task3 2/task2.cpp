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
    double avar=1.0*sum/n;
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
        v.push_back(x);
    }
    for (int i = v.size() - 1; i > 0; i--)
    {
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    cout<<"Enter a set of integers (separated by spaces):\n";
    string str;
    getline(cin,str,'\n');
    int n=str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]!=' ' && (str[i]<'0' || str[i]>'9') && str[i]!='-')
        {
            cout<<"Wrong value!";
            return 0;
        }
    }
    ofstream fout("numbers.txt",ios::app);
    if(fout.is_open()) 
    {
        for(int i=0;i<n;i++)
        {
            if(str[i]==' ') fout<<'\n';
            else fout << str[i]; 
        }
        if(str[n-1]!=' ') fout<<'\n';
        cout<<"Data added to file\n";
    }
    fout.close();
    cout<<"Numbers in the file:"<<endl;
    print("numbers.txt");
    cout<<"Sum of numbers: "<<sum("numbers.txt")<<endl;
    cout<<"Arithmetic mean: "<<average("numbers.txt");
}

