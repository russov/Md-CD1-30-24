#include "pch.h"
#include "StringCustom.h"

StringCustom::StringCustom()
{
}

StringCustom::~StringCustom()
{
	delete[] s;
}

StringCustom::StringCustom(const StringCustom& str)
{
	int strsize{ 0 };
	for (int i = 0;; i++)
	{
		++strsize;
		if (str.getCharStringCustom(i) == '\0')
		{
			break;
		}
	}

	char* s = new char[strsize];
	for (int i = 0; i < strsize; i++)
	{
		this->s[i] = str.getCharStringCustom(i);
	}
}

StringCustom::StringCustom(const StringCustom& str, int pos, int len)
{
	int strsize{ 0 };
	for (int i = 0;; i++)
	{
		++strsize;
		if (str.getCharStringCustom(i) == '\0')
		{
			break;
		}
	}
	if (len > strsize)
	{
		len = strsize;
	}

	char* s = new char[strsize];
	for (int i = pos; i < len; i++)
	{
		this->s[i] = str.getCharStringCustom(i);
	}
}

StringCustom::StringCustom(const char* cstr)
{
	int strsize{ 0 };
	for (int i = 0;; i++)
	{
		++strsize;
		if (cstr[i] == '\0')
		{
			break;
		}
	}
	char* s{ new char[strsize] };

	for (int i = 0; i < strsize; i++)
	{
		this->s[i] = cstr[i];
	}
}

StringCustom::StringCustom(const char* cstr, int n)
{
	int strsize{ 0 };
	for (int i = 0;; i++)
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

	char* s{ new char[strsize] };
	for (int i = 0; i < n; i++)
	{
		this->s[i] = cstr[i];
	}
}

StringCustom::StringCustom(int n, char c)
{
	int strsize{ n };

	char* s{ new char[strsize] };
	for (int i = 0; i < n; i++)
	{
		this->s[i] = c;
	}
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
	char* buff = new char[strsize + 1];
	for (int i = 0; i < strsize -1; i++)
	{
		buff[i] = this->s[i];
	}
	buff[strsize] = c;
	buff[strsize + 1] = '\0';
	this->s = std::move(buff);
	strsize += 1;
	delete[] buff;
}

int StringCustom::StringCustomSize()
{
	return strsize;
}

int StringCustom::StringCustomFind(char c)
{
	for (int i = 0; i < strsize; i++)
	{
		if (this->s[i] == c)
		{
			return i;
		}
	}
}

int StringCustom::StringCustomClear()
{
	strsize = 0;
	delete[] s;
	char* s = new char[strsize];

}

int StringCustom::StringCustomLength()
{
	return strsize - 1;
}

int StringCustom::setSizeStringCustom()
{
	return strsize + 1;
}