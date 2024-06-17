#pragma once
#include <iostream>
#include <cstring>
#include <memory>
#include <algorithm>

class MyClass
{
private:
	std::unique_ptr<char[]> string_; // String storing
	
	void CopyFrom(const char* input_string) { // Copies the string to string_
		if (input_string != nullptr) {
			int length = strlen(input_string);
			string_ = std::make_unique<char[]>(length + 1);
			strcpy_s(string_.get(), length + 1, input_string);
			string_[length] = '\0';
		}
		else {
			string_.reset();
		}
	}

public:
	MyClass() : string_(nullptr) { // Default constructor
	}

	MyClass(const char* input_string) { // Constructor that accepts a C-string
		CopyFrom(input_string);
	}

	MyClass(char c, int count) { // Constructor that takes a character and a number of iterations
		string_ = std::make_unique<char[]>(count + 1);
		for (int i = 0; i < count; ++i) {
			string_[i] = c;
		}
		string_[count] = '\0';
	}

	MyClass(const MyClass& other) { // Copy constructor
		CopyFrom(other.string_.get());
	}

	MyClass(const MyClass& other, int position, int length) { // Constructor taking another MyClass object, position and length
		if (other.string_ != nullptr && position < other.size()) {
			if (position + length > other.size()) {
				throw std::out_of_range("Out of range");
			}
			string_ = std::make_unique<char[]>(length + 1);
			for (int i = 0; i < length; ++i) {
				string_[i] = other.string_[position + i];
			}
			string_[length] = '\0';
		}
		else {
			string_.reset();
		}
	}

	MyClass(const char* input_string, int length) // Constructor taking C-string and length
	{
		if (input_string != nullptr) {
			string_ = std::make_unique<char[]>(length + 1);
			for (int i = 0; i < length; ++i) {
				string_[i] = input_string[i];
			}
			string_[length] = '\0';
		}
		else {
			string_.reset();
		}
	}

	MyClass(MyClass&& other) noexcept // Move constructor
	{
		string_ = std::move(other.string_);
	}

	MyClass(const char* begin, const char* end) // The constructor creates a substring from a string
	{
		int length = end - begin;
		string_ = std::make_unique<char[]>(length + 1);
		for (int i = 0; i < length; ++i) {
			string_[i] = begin[i];
		}
		string_[length] = '\0';
	}

	MyClass(std::initializer_list<char> init_list) // The constructor allows you to create a string from a list of characters
	{
		string_ = std::make_unique<char[]>(init_list.size() + 1);
		std::copy(init_list.begin(), init_list.end(), string_.get());
		string_[init_list.size()] = '\0';
	}

	MyClass& operator=(MyClass other) { // Assignment operator
		swap(other);
		return *this;
	}

	bool operator==(const MyClass& other) const { // Overload operator (==)
		if (string_ == nullptr || other.string_ == nullptr) {
			return string_ == other.string_;
		}
		return strcmp(string_.get(), other.string_.get()) == 0;
	}

	bool operator==(const std::string& other) const { // Overload operator (==)
		if (string_ == nullptr) {
			return other.empty();
		}
		return other == string_.get();
	}

	friend bool operator==(const std::string& left_side, const MyClass& right_side) { // Overload operator (==)
		return right_side == left_side;
	}

	bool operator<(const MyClass& other) const { // ***For std::sort
		if (string_ == nullptr || other.string_ == nullptr) {
			return string_ < other.string_;
		}
		return strcmp(string_.get(), other.string_.get()) < 0;
	}

	MyClass& replace(int position, int length, const MyClass& replacement) { // Implementation of the replace method
		if (position > size()) {
			throw std::out_of_range("Out of range");
		}
		int new_length = size() - length + replacement.size();
		std::unique_ptr<char[]> other = std::make_unique<char[]>(new_length + 1);
		if (position > 0) {
			memcpy(other.get(), string_.get(), position);
		}
		if (replacement.string_ != nullptr) {
			memcpy(other.get() + position, replacement.string_.get(), replacement.size());
		}
		if (size() > position + length) {
			memcpy(other.get() + position + replacement.size(), string_.get() + position + length, size() - position - length);
		}
		other[new_length] = '\0';
		string_ = std::move(other);
		return *this;
	}

	void push_back(char c) { // The method adds the character 'c' to the end of the string
		int length = (string_ != nullptr) ? strlen(string_.get()) : 0;
		std::unique_ptr<char[]> other = std::make_unique<char[]>(length + 2);
		if (string_ != nullptr) {
			strcpy_s(other.get(), length + 1, string_.get());
		}
		other[length] = c;
		other[length + 1] = '\0';
		string_ = std::move(other);
	}

	void swap(MyClass& other) { // Method of swapping the contents of one object and another 
		std::swap(string_, other.string_);
	}

	int find(const char* substring, int position = 0) const { // The method searches for a substring in a string, starting at position 'position'
		if (string_ == nullptr || substring == nullptr || *substring == '\0') {
			return -1;
		}
		const char* found_pos = strstr(string_.get() + position, substring);
		if (found_pos == nullptr) {
			return -1;
		}
		return static_cast<int>(found_pos - string_.get());
	}

	int find(char c, int position = 0) const { // The method searches for the character 'c' in the string, starting at position 'position'
		if (string_ == nullptr) {
			return -1; 
		}
		const char* found_pos = strchr(string_.get() + position, c);
		if (found_pos == nullptr) {
			return -1; 
		}
		return static_cast<int>(found_pos - string_.get());
	}

	void pop_back() { // The method removes the last character from a string
		if (string_ != nullptr && size() > 0) {
			int length = size();
			std::unique_ptr<char[]> other = std::make_unique<char[]>(length);
			strncpy_s(other.get(), length, string_.get(), length - 1);
			other[length - 1] = '\0';
			string_ = std::move(other);
		}
	}

	int size() const { // The method returns the size of the string
		return (string_ != nullptr) ? strlen(string_.get()) : 0;
	}

	bool empty() const { // The method returns true if the string is empty, false otherwise
		return size() == 0;
	}
	
	void clear() { // The method clears a string
		string_.reset();
	}

	char* begin() { // The method returns a pointer to the beginning of the line
		return string_.get();
	} 

	char* end() { // The method returns a pointer to the end of the string
		return string_.get() + size();
	}

	~MyClass() = default;
};