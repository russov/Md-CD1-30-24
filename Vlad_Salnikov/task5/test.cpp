#include "pch.h"
#include <string>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(PushBackTest, TddCharBack) {
	std::string test{""};
	test.push_back('q');
	std::string val1{ "q" };
	EXPECT_EQ(val1, test);
}

TEST(SizeTest, StrSize) {
	std::string test{ "qweqwe" };
	EXPECT_EQ(6, size(test));
}

TEST(FindTest, StrFind) {
	std::string test{"qwert"};
	EXPECT_EQ(1, test.find('w'));
}

TEST(ClearTest, StrClear) {
	std::string test{ "asdf" };
	test.clear();
	EXPECT_EQ("", test);
}

TEST(LengthTest, StrLength) {
	std::string test{ "qwe w" };
	EXPECT_EQ(5, test.length());
}

TEST(CapacityTest, StrCapacity) {
	std::string test{ "Test string" };
	EXPECT_EQ(15, test.capacity());
}

//Constructor
TEST(DefaultConstTest, DefCon) {
	std::string str;
	EXPECT_EQ("", str);
}

TEST(CopyConstTest, StrCopy) {
	std::string str{ "qwerty" };
	std::string strcon{ str };
	EXPECT_EQ(str, strcon);
}

TEST(SubstringConstTest, StrSub) {
	std::string str{ "test" };
	std::string strcon{ str, 0, 2 };
	EXPECT_EQ("te", strcon);
}

TEST(CStringTest, StrCStr) {
	const char* str = "qwert";
	std::string strcon(str);
	EXPECT_EQ("qwert", strcon);
}

TEST(BufferConstTest, StrBuff) {
	std::string strcon("qwert", 3);
	EXPECT_EQ("qwe", strcon);
}

TEST(FillConstTest, StrFill) {
	std::string strcon(5, 'q');
	EXPECT_EQ("qqqqq", strcon);
}

TEST(RangeConstTest, StrRange) {
	std::string str{ "qwert" };
	std::string strcon{ str.begin() + 1, str.end() };
	EXPECT_EQ("wert", strcon);
}

TEST(MoveConstTest, StrMove) {
	std::string&& str{ "qwert" };
	std::string strcon(str);
	EXPECT_EQ("qwert", strcon);
}