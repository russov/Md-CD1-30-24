#include "pch.h"
#include "StringCustom.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(PushBackTest, TddCharBack) {
	StringCustom test{""};
	test.push_back('q');
	StringCustom val1{ "q" };
	EXPECT_EQ(val1, test);
}

TEST(SizeTest, StrSize) {
	StringCustom test{ "qweqwe" };
	EXPECT_EQ(7, test.getSizeStringCustom());
}

TEST(FindTest, StrFind) {
	StringCustom test{"qwert"};
	EXPECT_EQ(1, test.StringCustomFind('w'));
}

TEST(ClearTest, StrClear) {
	StringCustom test{ "asdf" };
	test.StringCustomClear();
	EXPECT_EQ("", test);
}

TEST(LengthTest, StrLength) {
	StringCustom test{ "qwe w" };
	EXPECT_EQ(5, test.StringCustomLength());
}
 

//Constructor
TEST(DefaultConstTest, DefCon) {
	StringCustom str;
	EXPECT_EQ("", str);
}

TEST(CopyConstTest, StrCopy) {
	StringCustom str{ "qw" };
	StringCustom strcon{ str };
	EXPECT_EQ(str, strcon);
}

TEST(SubstringConstTest, StrSub) {
	StringCustom str{ "test" };
	StringCustom strcon{ str, 0, 2 };
	EXPECT_EQ("te", strcon);
}

TEST(CStringTest, StrCStr) {
	const char* str = "qwert";
	StringCustom strcon(str);
	EXPECT_EQ("qwert", strcon);
}

TEST(BufferConstTest, StrBuff) {
	std::string strcon("qwert", 3);
	EXPECT_EQ("qwe", strcon);
}

TEST(FillConstTest, StrFill) {
	StringCustom strcon(5, 'q');
	EXPECT_EQ("qqqqq", strcon);
}

//TEST(RangeConstTest, StrRange) {
//	std::string str{ "qwert" };
//	std::string strcon{ str.begin() + 1, str.end() };
//	EXPECT_EQ("wert", strcon);
//}

//TEST(MoveConstTest, StrMove) {
//	std::string&& str{ "qwert" };
//	std::string strcon(str);
//	EXPECT_EQ("qwert", strcon);
//}