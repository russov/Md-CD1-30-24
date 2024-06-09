#include <iostream>
#include <string>
#include "pch.h"

static void strBeg(std::string s)
{
	try 
	{
		std::cout << *(s.begin());
	}
	catch (...) {}
}