#include "pch.h"
#include "../MyString/MyString.cpp"

TEST(TestConstructor, EmptyStringConstructor) {
	MyString::string str;
	EXPECT_EQ(str, "");
}

TEST(TestConstructor, InitializerList) {
	std::initializer_list<char> list{ 's','t','r','i','n','g' };
	MyString::string str(list);
	EXPECT_EQ(str, "string");
}

TEST(TestConstructor, CopyConstructor) {
	MyString::string str{ "string" };
	MyString::string str2(str);
	EXPECT_EQ(str2, "string");
}

TEST(TestConstructor, SubStringConstructor) {
	MyString::string str{ "string" };
	MyString::string str2(str, 2, 3);
	EXPECT_EQ(str2, "rin");
	MyString::string str3(str, 2, 100);
	EXPECT_EQ(str3, "ring");
}

TEST(TestConstructor, FromCstring) {
	const char* text{ "string" };
	MyString::string str(text);
	EXPECT_EQ(str, "string");
}

TEST(TestConstructor, FromSequence) {
	const char* text{ "string" };
	MyString::string str(text, 3);
	EXPECT_EQ(str, "str");
}

TEST(TestConstructor, FillConstructor) {
	MyString::string str(5, 'q');
	EXPECT_EQ(str, "qqqqq");
}

TEST(TestConstructor, MoveConstructor) {
	MyString::string str{ "string" };
	MyString::string str2(std::move(str));
	EXPECT_EQ(str, "");
	EXPECT_EQ(str2, "string");
}

TEST(TestStringMetod, PushBack) {
	MyString::string str{ "somethin" };
	str.push_back('g');
	EXPECT_EQ(str, "something");
}

TEST(TestStringMetod, Size) {
	MyString::string str{ "something" };
	EXPECT_EQ(str.size(), 9);
}

TEST(TestStringMetod, Find) {
	MyString::string str{ "something s" };
	EXPECT_EQ(str.find('o'), 1);
	EXPECT_EQ(str.find('s', 1), 10);
	EXPECT_EQ(str.find('o', 4), MyString::npos);
	EXPECT_EQ(str.find("meth"), 2);
}

TEST(TestStringMetod, Front) {
	MyString::string str{ "something" };
	EXPECT_EQ(str.front(), 's');
	str.front() = 'S';
	EXPECT_EQ(str.front(), 'S');
	EXPECT_EQ(str, "Something");
}

TEST(TestStringMetod, Erase) {
	MyString::string str{ "something" };
	str.erase(6, 1);
	EXPECT_EQ(str, "somethng");
	str.erase(4, 100);
	EXPECT_EQ(str, "some");
}
