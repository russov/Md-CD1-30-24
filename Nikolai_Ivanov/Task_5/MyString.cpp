#include "pch.h"
#include <iostream>
#include <cstring>

class MyString
{
private:
	char* string;
public:
	MyString()
	{
		string=new char[1];
		string[0] = '\0';
	}

	~MyString()
	{
		if(string != nullptr) delete[] string;
		string = nullptr;
	}

	MyString(const char* s)
	{
		if (s != nullptr) 
		{
			int size = strlen(s);
			string = new char[size + 1];

			for (int i = 0; i < size; i++)
			{
				string[i] = s[i];
			}

			string[size] = '\0';
		}
		else 
		{
			string = new char[1];
			string[0] = '\0';
		}
	}

	MyString(const char* s, const int start, const int end)
	{
		if (s == nullptr || start < 0 || end < 0 || start >= strlen(s) || end < start)
		{
			string = new char[1];
			string[0] = '\0';
		}
		else
		{
			int size;
			if (end > strlen(s)) size = strlen(s) - start;
			else size = end - start;
			string = new char[size + 1];
			strncpy(string, s + start, size);
			string[size] = '\0';
		}
	}

	MyString(const MyString& s)
	{
		if (s.string == nullptr) string = nullptr; 
		else 
		{
			int size = strlen(s.string);
			string = new char[size + 1];
			strcpy(string, s.string);
			string[size] = '\0';
		}
	}
	
	MyString(const MyString& s, const int start, const int end)
	{
		if (s.string == nullptr || start < 0 || end < 0 || start >= strlen(s.string) 
			|| end < start || end-start>strlen(s.string))
			{
				string = new char[1];
				string[0] = '\0';
			}
		else
		{
			int size;
			if (end > strlen(s.string)) size = strlen(s.string) - start;
			else size = end - start+1;
			string = new char[size + 1];
			strncpy(string, s.string + start, size);
			string[size] = '\0';
		}
	}
	
	MyString(const char* s, const int buflen)
	{
		string = new char[buflen + 1]; 
		strncpy(string, s, buflen);
		string[buflen] = '\0'; 
	}
	
	MyString(const int n, const char c)
	{
		string = new char[n + 1];
		for (int i = 0; i < n; ++i)
		{
			string[i] = c;
		}
		string[n] = '\0';
	}
	
	MyString(const char* begin, const char* end)
	{
		int size = end - begin;
		string = new char[size + 1];
		std::copy(begin, end, string);
		string[size] = '\0';
	}
	
	MyString(const std::initializer_list<char> list)
	{
		int size= list.size();
		string = new char[size + 1]; 
		size_t i = 0;
		for (char c : list) {
			string[i++] = c;
		}
		string[size] = '\0';
	}

	MyString(MyString && s)
	{
		string = s.string;
		s.string = new char[1];
		s.string[0] = '\0';
	}

	char* Begin()
	{
		if (string != nullptr) return &string[0];
		else return nullptr;
	}
	
	void PushBack(const char c)
	{
		int size = strlen(string);
		char* str = new char[size + 2];
		if (string != nullptr)
		{
			for (int i = 0; i < size; ++i)
			{
				str[i] = string[i];
			}
		}
		str[size] = c;
		str[size + 1] = '\0';
		delete[] string;
		string = str;
	}
	
	int Size()
	{
		return strlen(string);
	}

	bool Empty()
	{
		if (string == nullptr || (strcmp(string, "") == 0) || (strcmp(string,"\0")==0)) return true;
		else return false;
	}

	int Find(const char* substr) {
		int s_size = strlen(substr);
		int size = strlen(string);
		int i = 0;

		while (i < size) {
			int j = 0;
			while (j < s_size && string[i + j] == substr[j]) {
				j++;
			}
			if (j == s_size) {
				return i;
			}
			i++;
		}
		return -1; 
	}

	void Print()
	{
		std::cout << "\nString: " << string << "\n";
	}

	void Swap(MyString& str)
	{
		char* tempString = string;
		string = str.string;
		str.string = tempString;
	}

	MyString Substr()
	{
		MyString newString;
		int size = strlen(string);
		newString.string = new char[size + 1];
		for (int i = 0; i < size; ++i)
		{
			newString.string[i] = string[i];
		}
		newString.string[size]='\0';
		return newString;
	}

	MyString Substr(const int start)
	{
		MyString newString;
		if (start < 0 || start >= strlen(string))
		{
			std::cerr << " Start of substing out of range\n";
			newString.string = new char[1];
			newString.string[0] = '\0';
			return newString;
		}
		
		int size = strlen(string);
		int sise_s = size - start;
		newString.string = new char[sise_s + 1];
		for (int i = 0; i < sise_s; ++i)
		{
			newString.string[i] = string[i + start];
		}
		newString.string[sise_s] = '\0';
		return newString;
	}

	MyString Substr(const int start, const int len)
	{
		MyString newString;
		if (start < 0 || start >= strlen(string))
		{
			std::cerr << " Start of substing out of range\n";
			newString.string = new char[1];
			newString.string[0] = '\0';
			return newString;
		}
		
		int size = strlen(string);
		int len1 = len;
		if (start + len > size)
		{
			len1 = size - start;
		}
		newString.string = new char[len1 + 1];
		for (int i = 0; i < len1; ++i)
		{
			newString.string[i] = string[i + start];
		}
		newString.string[len1] = '\0';
		return newString;
	}

	bool operator==(const MyString& str) const
	{
		if (string == nullptr) return false;
		if (std::strcmp(string, str.string) == 0) return true;
		return false;
	}

	bool operator==(const char* str) const
	{
		if (string == nullptr) return false;
		if (std::strcmp(string, str) == 0) return true;
		return false;
	}

	MyString& operator=(const MyString& other)
	{
		if (this == &other) 
		{
			return *this;
		}

		delete[] string;

		if (other.string != nullptr)
		{
			int size = strlen(other.string);
			string = new char[size + 1];
			strncpy(string, other.string, size);
			string[size] = '\0';
		}
		else
		{
			string = new char[1];
			string[0] = '\0';
		}
		return *this;
	}

	MyString& operator=(const char* other)
	{
		if (string == other)
		{
			return *this;
		}

		delete[] string;

		if (other != nullptr)
		{
			int size = strlen(other);
			string = new char[size + 1];
			strncpy(string, other, size);
			string[size] = '\0';
		}
		else
		{
			string = new char[1];
			string[0] = '\0';
		}
		return *this;
	}

};

