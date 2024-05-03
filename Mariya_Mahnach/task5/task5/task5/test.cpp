#include "pch.h"

//test .push_back()
TEST(TestPushBack, EmptyString)
{
	std::string s = "";
	s.push_back('s');
	EXPECT_EQ(s, "s");
}
TEST(TestPushBack, NotEmptyString)
{
	std::string s = "dgrkl";
	s.push_back('/');
	EXPECT_EQ(s, "dgrkl/");
}

//test .size()
TEST(TestSize, EmptyString)
{
	std::string s = "";
	EXPECT_EQ(0, s.size());
}
TEST(TestSize, NotEmptyString)
{
	std::string s = "0123456789";
	EXPECT_EQ(10, s.size());
}

//test .find()
TEST(TestFind, SubstringIsExist)
{
	std::string s{ "A friend in need is a friend indeed." };
	EXPECT_EQ(2, s.find("friend"));
}
TEST(TestFind, SubstringIsNotExist)
{
	std::string s{ "A friend in need is a friend indeed." };
	EXPECT_LT(36, s.find("acacac"));
}

//test .empty()
TEST(TestEmpty, EmptyString)
{
	std::string s = "";
	EXPECT_TRUE(s.empty());
}
TEST(TestEmpty, NotEmptyString)
{
	std::string s = "0123456789";
	EXPECT_FALSE(s.empty());
}

//test .swap()
TEST(Swap, Test)
{
	std::string s1 = "====", s2 = "8888";
	s1.swap(s2);
	EXPECT_EQ(s1, "8888");
	EXPECT_EQ(s2, "====");
}

//test .substr()
TEST(TestSubstr, EmptyPoz)
{
	std::string s = "ABCDEF";
	EXPECT_EQ(s.substr(), s);

}
TEST(TestSubstr,WithoutEnd)
{
	std::string s = "ABCDEF";
	EXPECT_EQ(s.substr(4), "EF");
}
TEST(TestSubstr, WithBothPoz)
{
	std::string s = "ABCDEF";
	EXPECT_EQ(s.substr(2,3), "CDE");
}
TEST(TestSubstr, EndPozLargerThenSize)
{
	std::string s = "ABCDEF";
	EXPECT_EQ(s.substr(3, 42), "DEF");
}
TEST(TestSubstr, BeginLargerThenSize)
{
	std::string s = "ABCDEF";
	ASSERT_THROW(s.substr(85, 1), std::out_of_range);
}

//test constructors

TEST(TestConstr, Default)
{
	std::string s;
	EXPECT_EQ(s, "");
}
TEST(TestConstr, Copy)
{
	std::string str = "qwerty";
	std::string s(str);
	EXPECT_EQ(s, str);
}
TEST(TestConstr,Substring)
{
	std::string str = "qwerty";
	std::string s(str,1,3);
	EXPECT_EQ(s, "wer");
}
TEST(TestConstr, CString)
{
	char* str = "qwerty";
	std::string s(str);
	EXPECT_EQ(s, "qwerty");
}
TEST(TestConstr, Buffer)
{
	std::string s("qwertyuiop",8);
	EXPECT_EQ(s, "qwertyui");
}
TEST(TestConstr, Fill)
{
	std::string s(10,'=');
	EXPECT_EQ(s, "==========");
}
TEST(TestConstr, Range)
{
	std::string str = "qwertyuiop";
	std::string s(str.begin(),str.begin()+5);
	EXPECT_EQ(s, "qwert");
}
TEST(TestConstr, List)
{
	std::initializer_list<char> list = { 'q','w','e','r','t','y','u','i' };
	std::string s(list);
	EXPECT_EQ(s, "qwertyui");
}
TEST(TestConstr, Move)
{
	std::string &&str = "qwerty";
	std::string s(str);
	EXPECT_EQ(s, "qwerty");
	//move constructor
	//Acquires the contents of str.
	//	str is left in an unspecified but valid state.
}
