#include <iostream>
#include "CreateString.h"

int main()
{

	CreateString str = "Hello World";
	std::cout << str<< std::endl;
	int g;
	g = str.find('e');
	std::cout << g;
	std::cout << str;
	return 0;
}