#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string line;
	ifstream file("input.cpp");
	stack <char> braces;
	bool error = false;
	if (!file.is_open())
	{
		cout << "error! \n";
	}
	else
	{
		while (getline(file, line))
		{
			for (char c : line)
			{
				if (c == '{')
				{
					braces.push('{');
				}
				else if (c == '}')
				{
					if (braces.empty()) {
						error = true;
						break;
					}
					braces.pop();
				}
			}
		}
	}

	file.close();
	ofstream outfile("result.txt");
	if (braces.empty() && !error)
	{
		outfile << "All curly braces are closed.";
		cout << "All curly braces are closed. \n";
	}
	else {
		outfile << "Not all curly braces are closed.";
		cout << "Not all curly braces are closed. \n";
	}

	outfile.close();

	return 0;
}
	



