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
	int setSizeStringCustom();
	int StringCustomSize();
	int StringCustomFind(char c);
	int StringCustomClear();
	int StringCustomLength();

	~StringCustom();

private:
	int strsize{ 0 };
	char* s = new char[strsize];
};

