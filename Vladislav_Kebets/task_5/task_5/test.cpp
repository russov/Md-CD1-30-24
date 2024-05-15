#include "pch.h"
#include <String>
#include "../MyString/MyString.cpp"

TEST(TestConstructor, EmptyStringConstructor) {
	MyString::String str;
	EXPECT_EQ(str, "");
}

TEST(TestConstructor, InitializerList) {
	std::initializer_list<char> list{ 's','t','r','i','n','g' };
	MyString::String str(list);
	EXPECT_EQ(str, "string");
}

TEST(TestConstructor, CopyConstructor) {
	MyString::String str{ "String" };
	MyString::String str2(str);
	EXPECT_EQ(str2, "String");
}

TEST(TestConstructor, SubStringConstructor) {
	MyString::String str{ "String" };
	MyString::String str2(str, 2, 3);
	EXPECT_EQ(str2, "rin");
	MyString::String str3(str, 2, 100);
	EXPECT_EQ(str3, "ring");
}

TEST(TestConstructor, FromCString) {
	const char* text{ "String" };
	MyString::String str(text);
	EXPECT_EQ(str, "String");
}

TEST(TestConstructor, FromSequence) {
	const char* text{ "String" };
	MyString::String str(text, 3);
	EXPECT_EQ(str, "Str");
}

TEST(TestConstructor, FillConstructor) {
	MyString::String str(5, 'q');
	EXPECT_EQ(str, "qqqqq");
}

TEST(TestConstructor, MoveConstructor) {
	MyString::String str{ "String" };
	MyString::String str2(std::move(str));
	EXPECT_EQ(str, "");
	EXPECT_EQ(str2, "String");
}

TEST(TestStringMetod, PushBack) {
	MyString::String str{ "somethin" };
	str.push_back('g');
	EXPECT_EQ(str, "something");
}

TEST(TestStringMetod, Size) {
	MyString::String str{ "something" };
	EXPECT_EQ(str.size(), 9);
}

TEST(TestStringMetod, Find) {
	MyString::String str{ "something s" };
	EXPECT_EQ(str.find('o'), 1);
	EXPECT_EQ(str.find('s', 1), 10);
	EXPECT_EQ(str.find('o', 4), MyString::npos);
	EXPECT_EQ(str.find("meth"), 2);
}

TEST(TestStringMetod, Front) {
	MyString::String str{ "something" };
	EXPECT_EQ(str.front(), 's');
	str.front() = 'S';
	EXPECT_EQ(str.front(), 'S');
	EXPECT_EQ(str, "Something");
}

TEST(TestStringMetod, Erase) {
	MyString::String str{ "something" };
	str.erase(6, 1);
	EXPECT_EQ(str, "somethng");
	str.erase(4, 100);
	EXPECT_EQ(str, "some");
}
