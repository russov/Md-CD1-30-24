#include <fstream>
#include <string>
#include <iostream>


int main()
{
	setlocale(LC_ALL, "rus");
	int counter{ 0 };
	std::string result;
	std::string str;
	std::ifstream file;
	file.open("test.txt");
	while (!file.eof())
	{
		getline(file, str);
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '{' || str[i] == '}')
			{
				++counter;
			}
		}
	}

	if (counter % 2) 
	{
		result = "Не все скобки закрыты!";
		std::cout << result;
	}
	else
	{
		result = "Все скобки закрыты!";
		std::cout << result;
	}

	std::ofstream fileOUT;
	fileOUT.open("out.txt", std::ios::out);
	fileOUT << result << std::endl;
	fileOUT.close();

	return 0;
}