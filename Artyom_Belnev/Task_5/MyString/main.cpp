#include<iostream>
using namespace std;

class MyString
{
public:

	MyString()
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str)
	{

		length = strlen(str);

		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';

	}

	~MyString()
	{
		if (this->str != nullptr) delete[] this->str; 
	}

	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

	}

	MyString& operator =(const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;

	}



	MyString operator+(const MyString& other)
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		delete[] this->str;
		
		this->str = newStr.str;

		return  *this;
	}

	int size() {
		return length;
	}

	bool compare(const MyString& other) {
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		if (this->length == other.length)
		{
			for (int i = 0; i < this->length; i++)
			{
				if (this->str[i] != other.str[i]) return true;
			}
			return false;
		}
		return true;
	}

	int find(const MyString& other) const {
		int pos = 0;

		int thisLength = strlen(this->str);

		int subLength = strlen(other.str);

		int count = 0;

		for (int i = 0; i <= thisLength - subLength; i++) { 
			if (this->str[i] == other.str[0]) {

				for (int y = 0; y < subLength; y++) {
					if (this->str[i + y] == other.str[y]) {
						count++;
					}
				}

				if (count == subLength) {
					return i;
				}
				else {
					count = 0;
				}
			}
		}
		return npos; 
	}



	void push_back(char ch) {
		char* newStr = new char[this->length + 2];

		for (int i = 0; i < this->length; i++)
		{
			newStr[i] = this->str[i];
		}

		newStr[this->length++] = ch;
		newStr[this->length] = '\0';

		delete[] this->str;
		this->str = newStr;
	}

	void substr(int pos) {
		char* newStr = new char[this->length];
		int cout = 0;

		for (int i = 0; i < this->length; i++)
		{
			if (i >= pos) newStr[i] = this->str[cout++];
		}

		newStr[this->length] = '\0';

		delete[] this->str;
		this->str = newStr;
	}


	bool operator ==(const MyString& other) const
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator !=(const MyString& other)
	{
		return !(this->operator==(other));
	}

	char& operator [](int index)
	{
		if (index < 0 || index >= length) throw std::out_of_range("Index out of range");

		return this->str[index];
	}


private:
	char* str;
	int length;
	static const size_t npos = -1;
};















