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
	explicit StringCustom(StringCustom&& str) noexcept;

	char getCharStringCustom(int) const;
	int getSizeStringCustom() const;
	void push_back(char c);
	void setSizeStringCustom(int);
	void setArraySizeStringCustom(int);
	int StringCustomSize();
	int StringCustomFind(char c) const;
	void StringCustomClear();
	int StringCustomLength();
	int fastCountCstr(const char* cstr) const;

	void append(const StringCustom& other);
	void append(const char* cstr);
	void clear();
	int find(char c) const;
	size_t length() const;
	size_t size() const;
	void sortStringCustom();




	const char* c_str() const {
		return s;
	}
	
	bool equals(const char* cstr) const {
		if (cstr == nullptr) {
			return false;
		}

		size_t cstrSize = std::strlen(cstr) + 1;

		if (getSizeStringCustom() != cstrSize) {
			return false;
		}

		return std::strcmp(s, cstr) == 0;
	}

	bool equals(const StringCustom& other) const {
		return equals(other.c_str());
	}

	friend bool operator==(const StringCustom& str1, const StringCustom& str2) {
		return str1.equals(str2);
	}

	friend bool operator==(const char* cstr, const StringCustom& str2) {
		return str2.equals(cstr);
	}

	friend bool operator==(const StringCustom& str1, const char* cstr) {
		return str1.equals(cstr);
	}

	friend bool operator<(const StringCustom& str1, const StringCustom& str2) {
		return std::strcmp(str1.s, str2.s) < 0;
	}

	~StringCustom();

private:
	int strsize{ 1 };
	char* s = new char[strsize] {'\0'};
};

