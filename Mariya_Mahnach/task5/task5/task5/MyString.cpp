#include "pch.h"
#include <iostream>

class MyString
{
private:
	char* str;
public:
	void PushBack(const char c) 
	{
		char* ptr=this->str;
		while ((*ptr) != '\0')
		{
			ptr++;
		}
		*ptr = c;
		ptr++;
		*ptr = '\0';
		delete ptr;
	}

	int Size() 
	{
		char* ptr;
		int n=0;
		while ((*ptr) != '\0')
		{
			ptr++;
			n++;
		}
		delete ptr;
		return n;
	}

	int Find(const char* s) 
	{
		char* ptr = this->str;
		int poz = 0, endpoz=this->Size();
		while (poz <= endpoz)
		{
			bool f = false;
			const char* ptr1 = s, *ptr2=ptr;
			while (*ptr1 == *ptr2)
			{
				ptr1++;
				ptr2++;
				if (*ptr1 == '\0') { f = true; break; }
			}
			if (f) break;
			poz++;
			ptr++;
			delete ptr1;
			delete ptr2;
		}
		delete ptr;
		if (poz > endpoz) return -1;
		else return poz;
	}

	int Find(const MyString* s)
	{
		const char* str = s->str;
		int n = this->Find(str);
		delete str;
		return n;
	}

	bool Empty() 
	{
		if (str == "\0") return false;
		else return true;
	}

	void Swap(MyString str1) 
	{
		char* helpStr = str1.str;
		str1.str = this->str;
		this->str = str1.str;
		delete helpStr;
	}

	MyString Substr() 
	{
		return this;
	}

	MyString Substr(const int a) 
	{
		MyString newStr;
		char* ptr = str+a;
		while (*ptr != '\0')
		{
			newStr.PushBack(*ptr);
			ptr++;
		}
		delete ptr;
		return newStr;
	}

	MyString Substr(const int a, const int b)
	{
		MyString newStr;
		if (a >= this->Size()) { throw std::out_of_range("Out of range"); }
		char* ptr = str + a;
		int n = a;
		while (*ptr != '\0' && n<b)
		{
			newStr.PushBack(*ptr);
			ptr++;
			n++;
		}
		delete ptr;
		return newStr;
	}

	char* Begin()
	{
		return str;
	}

	void operator=(char* s)
	{
		this->str = s;
	}

	friend bool operator==(const MyString s1, MyString s2);
	




	MyString()
	{
		str = "\0";
	}

	MyString(const MyString* str1)
	{
		this->str = str1->str;
	}

	MyString(char* s)
	{
		char* ptr = s;
		while (*ptr != '\0')
		{
			this->PushBack(*ptr);
			ptr++;
		}
		delete ptr;
	}

	MyString(const MyString& str1)
	{
		this->str = str1.str;
	}

	MyString(char* s, int a, int b)
	{
		s += a;
		int n = a;
		this->str = "\0";
		while (n< b)
		{
			this->PushBack(*s);
			n++;
			s++;
		}
	}

	MyString(MyString s, int a, int b)
	{
		char* s1 = s.str;
		MyString(s1, a, b);
	}

	MyString(char* s, int a)
	{
		while (a--)
		{
			this->PushBack(*s);
			s++;
		}
	}

	MyString(int n, char c)
	{
		while (n--)
		{
			this->PushBack(c);
		}
	}

	MyString(char* begin, char* end)
	{
		try 
		{
			while (begin != end)
			{
				this->PushBack(*begin);
				begin++;
			}
		}
		catch(...)
		{
			std::cout << "Error\n";
		}
	}

	MyString(std::initializer_list<char> list)
	{
		int n = list.size();
		for (int i = 0; i < n; i++)
		{
			const char* c = list.begin()+i;
			this->PushBack(*c);
		}
	}

	MyString(MyString&& string)
	{
		this->str = string.str;
	}
	
};


bool operator==(const MyString s1, const MyString s2)
{
	char* ptr1 = s1.str;
	char* ptr2 = s2.str;
	while (ptr1 != '\0' || ptr2 != '\0')
	{
		if (*ptr1 != *ptr2)
		{
			delete ptr1;
			delete ptr2;
			return false;
		}
		ptr1++;
		ptr2++;
	}
	return true;
}