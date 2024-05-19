#pragma once
class StringCustom
{
public:
	StringCustom();
	explicit StringCustom(const StringCustom& str);
	explicit StringCustom(const StringCustom& str, int pos, int len);
	explicit StringCustom(const char* cstr);
	explicit StringCustom(const char* cstr, int n);
	explicit StringCustom(int n, char c);
	//template <class InputIterator>  StringCustom(InputIterator first, InputIterator last);
	explicit StringCustom(StringCustom&& str) noexcept;

	char getCharStringCustom(int) const;
	int getSizeStringCustom() const;
	void push_back(char c);
	void setSizeStringCustom(int);
	void setArraySizeStringCustom(int);
	int StringCustomSize();
	int StringCustomFind(char c);
	void StringCustomClear();
	int StringCustomLength();
	int fastCountCstr(const char* cstr) const;


	friend bool operator==(const StringCustom& str1, const StringCustom& str2)
	{
		if (str1.getSizeStringCustom() != str2.getSizeStringCustom())
		{
			return false;
		}

		for (auto i = 0; i < str1.strsize; i++)
		{
			if (str1.getCharStringCustom(i) != str2.getCharStringCustom(i))
			{
				return false;
			}
		}

		return true;
	}
	friend bool operator==(const char* cstr, const StringCustom& str2)
	{
		StringCustom str1(cstr);
		if (str1.getSizeStringCustom() != str2.getSizeStringCustom())
		{
			return false;
		}

		for (auto i = 0; i < str1.getSizeStringCustom(); i++)
		{
			if (str1.getCharStringCustom(i) != str2.getCharStringCustom(i))
			{
				return false;
			}
		}

		return true;
	}
	friend bool operator==(const StringCustom& str1, const char* cstr)
	{
		StringCustom str2(cstr);
		if (str1.strsize != str2.strsize)
		{
			return false;
		}

		for (auto i = 0; i < str1.strsize; i++)
		{
			if (str1.s[i] != str2.s[i])
			{
				return false;
			}
		}
		
		return true;
	}

	~StringCustom();

private:
	int strsize{ 1 };
	char* s = new char[strsize] {'\0'};
};

