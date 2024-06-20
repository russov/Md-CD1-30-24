#include "pch.h"
#include "StringCustom.h"
#include <iostream>

StringCustom::StringCustom() 
{
	s = new char[strsize] {'\0'};
}

StringCustom::~StringCustom()
{
	delete[] s;
	s = nullptr;
}

StringCustom::StringCustom(const StringCustom& str)
{
	this->setSizeStringCustom(str.getSizeStringCustom());
	this->s = new char[this->getSizeStringCustom() + 1];
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
	if (cstr) {
		size_t cstrSize = std::strlen(cstr) + 1; 
		setSizeStringCustom(cstrSize);
 
		this->s = new char[getSizeStringCustom()]; 

		
		std::strcpy(this->s, cstr);
	}
}

StringCustom::StringCustom(const char* cstr, int n)
{
	size_t len = std::strlen(cstr);

	if (n > len) {
		throw std::out_of_range("Out of range");
	}

	this->strsize = n;
	this->s = new char[n + 1];

	std::strncpy(this->s, cstr, n);
	this->s[n] = '\0';
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
	s = str.s;
	setArraySizeStringCustom(str.getSizeStringCustom());
	str.s = nullptr;
	str.setArraySizeStringCustom(0);
}

char StringCustom::getCharStringCustom(int num) const
{
	if (num > this->getSizeStringCustom())
	{
		return this->s[this->getSizeStringCustom() - 1];
	}
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

int StringCustom::StringCustomFind(char c) const
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

void StringCustom::append(const StringCustom& other) {
	int newSize = strsize + other.strsize - 1;
	char* newS = new char[newSize];
	std::strcpy(newS, s);
	std::strcat(newS, other.s);
	delete[] s;
	s = newS;
	strsize = newSize;
}

void StringCustom::append(const char* cstr) {
	if (!cstr) return;
	int cstrLen = std::strlen(cstr);
	int newSize = strsize + cstrLen;
	char* newS = new char[newSize];
	std::strcpy(newS, s);
	std::strcat(newS, cstr);
	delete[] s;
	s = newS;
	strsize = newSize;
}

void StringCustom::clear() {
	delete[] s;
	s = new char[1] {'\0'};
	strsize = 1;
}

int StringCustom::find(char c) const {
	return StringCustomFind(c);
}

size_t StringCustom::length() const {
	return strsize - 1;
}

size_t StringCustom::size() const {
	return strsize;
}

void StringCustom::sortStringCustom()
{
	std::sort(s, s + strsize - 1);
}