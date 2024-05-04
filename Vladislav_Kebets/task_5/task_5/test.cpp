#include "pch.h"
#include <string>

TEST(TestConstructor, EmptyStringConstructor) {
	std::string str;
	EXPECT_EQ(str, "");
}

TEST(TestConstructor, InitializerList) {
	std::initializer_list<char> list{ 's','t','r','i','n','g' };
	std::string str(list);
	EXPECT_EQ(str,"string");
}

TEST(TestConstructor, CopyConstructor) {
	std::string str{"string"};
	std::string str2(str);
	EXPECT_EQ(str2, "string");
}

TEST(TestConstructor, SubstringConstructor) {
	std::string str{ "string" };
	std::string str2(str,2,3);
	EXPECT_EQ(str2, "rin");
	std::string str3(str, 2, 100);
	EXPECT_EQ(str3, "ring");
}

TEST(TestConstructor, FromCString) {
	const char* text{ "string" };
	std::string str(text);
	EXPECT_EQ(str, "string");
}

TEST(TestConstructor, FromSequence) {
	const char* text{ "string" };
	std::string str(text,3);
	EXPECT_EQ(str, "str");
}

TEST(TestConstructor, FillConstructor) {
	std::string str(5, 'q');
	EXPECT_EQ(str, "qqqqq");
}

TEST(TestConstructor, MoveConstructor) {
	std::string str{ "string" };
	std::string str2(std::move(str));
	EXPECT_EQ(str, "");
	EXPECT_EQ(str2, "string");
}

TEST(TestStringMetod, PushBack) {
	std::string str{ "somethin" };
	str.push_back('g');
	EXPECT_EQ(str, "something");
}

TEST(TestStringMetod, Size) {
	std::string str{ "something" };
	EXPECT_EQ(str.size(), 9);
}

TEST(TestStringMetod, Find) {
	std::string str{ "something s" };
	EXPECT_EQ(str.find('o'), 1);
	EXPECT_EQ(str.find('s', 1), 10);
	EXPECT_EQ(str.find('o', 4), std::string::npos);
	EXPECT_EQ(str.find("meth"), 2);
}

TEST(TestStringMetod, Swap) {
	std::string str{ "something" };
	std::string str2{ "nothing" };
	swap(str, str2);
	EXPECT_EQ(str, "nothing");
	EXPECT_EQ(str2, "something");

}

TEST(TestStringMetod, Front) {
	std::string str{ "something" };
	EXPECT_EQ(str.front(), 's');
	str.front()='S';
	EXPECT_EQ(str.front(), 'S');
	EXPECT_EQ(str, "Something");
}

TEST(TestStringMetod, Erase) {
	std::string str{ "something" };
	str.erase(6, 1);
	EXPECT_EQ(str, "somethng");
	str.erase(4, 100);
	EXPECT_EQ(str, "some");
}
