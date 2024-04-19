#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int sum(vector<int> v)
{
    int sum = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
        sum += v[i];
    return sum;
}

double average(vector<int> v)
{
    int sum = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
        sum += v[i];
    double avar = (double)sum / n;
    return avar;
}

vector<int> readNum(string s)
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
    return v;
}

void print(vector<int> v)
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string filename = "numbers.txt";
    cout << "Enter a set of integers (separated by spaces):\n";
    string str;
    getline(cin, str, '\n');
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] != ' ' && (str[i] < '0' || str[i]>'9') && str[i] != '-')
        {
            cout << "Wrong value!";
            return 0;
        }
    }
    ofstream fout(filename, ios::app);
    if (fout.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            if (str[i] == ' ') fout << '\n';
            else fout << str[i];
        }
        if (str[n - 1] != ' ') fout << '\n';
        cout << "Data added to file\n";
    }
    fout.close();
    vector<int> v = readNum(filename);
    cout << "Numbers in the file:" << endl;
    print(v);
    cout << "Sum of numbers: " << sum(v) << endl;
    cout << "Arithmetic mean: " << average(v);
}

