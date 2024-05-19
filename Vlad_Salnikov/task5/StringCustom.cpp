#include "pch.h"
#include "StringCustom.h"
#include <iostream>

StringCustom::StringCustom()
{
}

StringCustom::~StringCustom()
{
	delete[] s;
	s = nullptr;
}

StringCustom::StringCustom(const StringCustom& str)
{
	this->setSizeStringCustom(str.getSizeStringCustom());
	this->s = new char[this->getSizeStringCustom()];
	for (auto i = 0; i < this->getSizeStringCustom(); i++)
	{
		this->s[i] = str.getCharStringCustom(i);
	}
	this->s[this->getSizeStringCustom()] = '\0';
}

StringCustom::StringCustom(const StringCustom& str, int pos, int len)
{
	this->setSizeStringCustom(len + 1);
	this->s = new char[this->getSizeStringCustom()];
	for (auto i = pos; i < this->getSizeStringCustom()-1; i++)
	{
		this->s[i] = str.getCharStringCustom(i);
	}
	this->s[this->getSizeStringCustom()-1] = '\0';
}

StringCustom::StringCustom(const char* cstr)
{
	int cstrsize{ 0 };
	for (auto i = 0;; i++)
	{
		if (cstr[i] == '\0')
		{
			break;
		}
		++cstrsize;
	}
	setSizeStringCustom(cstrsize + 1);
	for (int i = 0; i < strsize; i++)
	{
		this->s[i] = cstr[i];
	}
}

StringCustom::StringCustom(const char* cstr, int n)
{
	int strsize{ 0 };
	for (auto i = 0;; i++)
	{
		++strsize;
		if (cstr[i] == '\0')
		{
			break;
		}
	}
	if (n > strsize)
	{
		n = strsize;
	}

	this->s = new char[strsize];
	for (int i = 0; i < n; i++)
	{
		this->s[i] = cstr[i];
	}
	this->s[this->getSizeStringCustom() - 1] = '\0';
}

StringCustom::StringCustom(int n, char c)
{
	this->setSizeStringCustom(n + 1);
	this->s = new char[this->getSizeStringCustom()];
	for (int i = 0; i < n; i++)
	{
		this->s[i] = c;
	}
	this->s[this->getSizeStringCustom() - 1] = '\0';
}

StringCustom::StringCustom(StringCustom&& str) noexcept
{
	//str = std::move(s);
}

char StringCustom::getCharStringCustom(int num) const
{
	return s[num];
}

int StringCustom::getSizeStringCustom() const
{
	return strsize;
}

void StringCustom::push_back(char c)
{
	char* buff = new char[this->getSizeStringCustom() + 1];
	for (int i = 0; i < this->getSizeStringCustom() + 1; i++)
	{
		buff[i] = this->s[i];
	}
	buff[this->getSizeStringCustom() - 1] = c;
	buff[this->getSizeStringCustom()] = '\0';

	this->setSizeStringCustom(this->getSizeStringCustom() + 1);
	this->s = new char[this->getSizeStringCustom()];
	for (auto i = 0; i < this->getSizeStringCustom(); i++)
	{
		this->s[i] = buff[i];
	}
	delete[] buff;
	buff = nullptr;
}

int StringCustom::StringCustomSize()
{
	return strsize;
}

void StringCustom::StringCustomClear()
{
	this->setSizeStringCustom(1);
	this->s = new char[this->getSizeStringCustom()] {'\0'};
}

int StringCustom::StringCustomLength()
{
	return strsize - 1;
}

void StringCustom::setSizeStringCustom(int num)
{
	strsize = num;
}

void StringCustom::setArraySizeStringCustom(int num)
{
	delete[] s;
	char* s = new char[num];
}

int StringCustom::fastCountCstr(const char* cstr) const
{
	int cstrsize{ 0 };
	for (auto i = 0;; i++)
	{
		++cstrsize;
		if (cstr[i] == '\0')
		{
			break;
		}
	}
	return cstrsize;
}

int StringCustom::StringCustomFind(char c)
{
	for (auto i = 0; i < this->getSizeStringCustom(); i++)
	{
		if (this->getCharStringCustom(i) == c)
		{
			return i;
		}
	}
	std::cout << "not found" << std::endl;
	return 0;
}