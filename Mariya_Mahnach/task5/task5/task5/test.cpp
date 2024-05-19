#include "pch.h"
#include "MyString.h"

//test .push_back()
TEST(TestPushBack, EmptyString)
{
	MyString s = "";
	s.PushBack('s');
	EXPECT_EQ(s, "s");
}
TEST(TestPushBack, NotEmptyString)
{
	MyString s = "dgrkl";
	s.PushBack('/');
	EXPECT_EQ(s, "dgrkl/");
}

//test .size()
TEST(TestSize, EmptyString)
{
	MyString s = "";
	EXPECT_EQ(0, s.Size());
}
TEST(TestSize, NotEmptyString)
{
	MyString s = "0123456789";
	EXPECT_EQ(10, s.Size());
}

//test .find()
TEST(TestFind, SubstringIsExist)
{
	MyString s{ "A friend in need is a friend indeed." };
	EXPECT_EQ(2, s.Find("friend"));
}
TEST(TestFind, SubstringIsNotExist)
{
	MyString s{ "A friend in need is a friend indeed." };
	EXPECT_LT(36, s.Find("acacac"));
}

//test .empty()
TEST(TestEmpty, EmptyString)
{
	MyString s = "";
	EXPECT_TRUE(s.Empty());
}
TEST(TestEmpty, NotEmptyString)
{
	MyString s = "0123456789";
	EXPECT_FALSE(s.Empty());
}

//test .swap()
TEST(Swap, Test)
{
	MyString s1 = "====", s2 = "8888";
	s1.Swap(s2);
	EXPECT_EQ(s1, "8888");
	EXPECT_EQ(s2, "====");
}

//test .substr()
TEST(TestSubstr, EmptyPoz)
{
	MyString s = "ABCDEF";
	EXPECT_EQ(s.Substr(), s);

}
TEST(TestSubstr,WithoutEnd)
{
	MyString s = "ABCDEF";
	EXPECT_EQ(s.Substr(4), "EF");
}
TEST(TestSubstr, WithBothPoz)
{
	MyString s = "ABCDEF";
	EXPECT_EQ(s.Substr(2,3), "CDE");
}
TEST(TestSubstr, EndPozLargerThenSize)
{
	MyString s = "ABCDEF";
	EXPECT_EQ(s.Substr(3, 42), "DEF");
}
TEST(TestSubstr, BeginLargerThenSize)
{
	MyString s = "ABCDEF";
	ASSERT_THROW(s.Substr(85, 1), std::out_of_range);
}

//test constructors

TEST(TestConstr, Default)
{
	MyString s;
	EXPECT_EQ(s, "");
}
TEST(TestConstr, Copy)
{
	MyString str = "qwerty";
	MyString s(str);
	EXPECT_EQ(s, str);
}
TEST(TestConstr,Substring)
{
	MyString str = "qwerty";
	MyString s(str,1,3);
	EXPECT_EQ(s, "wer");
}
TEST(TestConstr, CString)
{
	char* str = "qwerty";
	MyString s(str);
	EXPECT_EQ(s, "qwerty");
}
TEST(TestConstr, Buffer)
{
	MyString s("qwertyuiop",8);
	EXPECT_EQ(s, "qwertyui");
}
TEST(TestConstr, Fill)
{
	MyString s(10,'=');
	EXPECT_EQ(s, "==========");
}
TEST(TestConstr, Range)
{
	MyString str = "qwertyuiop";
	MyString s(str.Begin(),str.Begin()+5);
	EXPECT_EQ(s, "qwert");
}
TEST(TestConstr, List)
{
	std::initializer_list<char> list = { 'q','w','e','r','t','y','u','i' };
	MyString s(list);
	EXPECT_EQ(s, "qwertyui");
}
TEST(TestConstr, Move)
{
	MyString &&str = "qwerty";
	MyString s(str);
	EXPECT_EQ(s, "qwerty");
	//move constructor
	//Acquires the contents of str.
	//	str is left in an unspecified but valid state.
}
