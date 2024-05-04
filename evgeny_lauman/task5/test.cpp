#include "pch.h"
#include <vector>

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}


TEST(StringConstructorTest, Default_constructor)
{
	std::string s1;
	EXPECT_TRUE(s1.empty() && (s1.size() == 0));
}

TEST(StringConstructorTest, Repeat_character_constructor1)
{
	const std::string s1(4, '=');
	EXPECT_EQ("====", s1);
}


TEST(StringConstructorTest, Repeat_character_constructor3)
{
	const std::string s1(0, '=');
	EXPECT_EQ("", s1);
}

TEST(StringConstructorTest, Repeat_character_constructor4)
{
	const size_t str_size = 4294967295;
	const std::string s1(str_size, '=');
	EXPECT_EQ(s1.size(), str_size);
}

TEST(StringConstructorTest, Copy_character_range_constructor_unbound1)
{
	const std::string s1("Hello, World!");
	EXPECT_EQ("Hello, World!", s1);
}

TEST(StringConstructorTest, Copy_character_range_constructor_unbound2)
{
	const std::string s1{ "" };
	EXPECT_EQ("", s1);
}

TEST(StringConstructorTest, Copy_character_range_constructor_bound1)
{
	const std::string s1("Hello, World", 5);
	EXPECT_EQ("Hello", s1);
}

TEST(StringConstructorTest, Copy_character_range_constructor_bound2)
{
	const std::string s1("Hello, World", 0);
	EXPECT_EQ("", s1);
}

TEST(StringConstructorTest, Copy_character_range_constructor_bound3)
{
	const std::string s1("Hello, World", 12);
	EXPECT_EQ("Hello, World", s1);
}

TEST(StringConstructorTest, Copy_character_range_constructor_bound4)
{
	EXPECT_NO_THROW(std::string s1("Hello, World", 15));
}

TEST(StringConstructorTest, Copy_character_range_constructor_bound5)
{
	const std::string s1{ "Hello, World", 5 };
	EXPECT_EQ("Hello", s1);
}

TEST(StringConstructorTest, Copy_substring_constructor_unbound1)
{
	const std::string hw = "Hello, World";
	const std::string s1(hw, 7);
	EXPECT_EQ("World", s1);
}

TEST(StringConstructorTest, Copy_substring_constructor_unbound2)
{
	const std::string hw = "Hello, World";
	EXPECT_THROW(std::string s1(hw, 14), std::out_of_range);
}

TEST(StringConstructorTest, Copy_substring_constructor_unbound3)
{
	const std::string hw = "Hello, World";
	const std::string s1(hw, 0);
	EXPECT_EQ("Hello, World", s1);
}

TEST(StringConstructorTest, Copy_substring_constructor_bound1)
{
	const std::string hw = "Hello, World";
	const std::string s1(hw, 2, 4);
	EXPECT_EQ("llo,", s1);
}

TEST(StringConstructorTest, Copy_substring_constructor_bound2)
{
	const std::string hw = "Hello, World";
	EXPECT_NO_THROW(std::string s1(hw, 10, 10));
}

TEST(StringConstructorTest, Copy_substring_constructor_bound3)
{
	const std::string hw = "Hello, World";
	const std::string s1(hw, 10, 10);
	EXPECT_EQ("ld", s1);
}

TEST(StringConstructorTest, Copy_from_iterator_range_constructor)
{
	const int LENGTH = 6;
	const char str[LENGTH] = { "Hello" };
	const std::vector<char> chars(str, str + LENGTH);
	const std::string s1(chars.begin(), chars.end());
	EXPECT_TRUE(strcmp(str, s1.c_str()) == 0);
}

TEST(StringConstructorTest, Copy_constructor1)
{
	const std::string hw = "Hello, World";
	const std::string s1{ hw };
	EXPECT_EQ(hw, s1);
}

TEST(StringConstructorTest, Copy_constructor2)
{
	const std::string hw;
	const std::string s1{ hw };
	EXPECT_EQ(hw, s1);
}

TEST(StringConstructorTest, Move_constructor1)
{
	std::string hw = "Hello, World";
	std::string s1 = std::move(hw);
	EXPECT_TRUE(hw == "" && s1 == "Hello, World");
	std::cout << hw;
}

TEST(StringConstructorTest, Move_constructor2)
{
	const std::string hw = "Hello, World";
	EXPECT_NO_THROW(std::string s1 = std::move(hw));
	std::cout << hw;
}

TEST(StringConstructorTest, Initializer_list_constructor)
{
	const std::string s1 = { 'H', 'e', 'l', 'l', 'o' };
	EXPECT_EQ("Hello", s1);
}

TEST(StringPushBackTest, PushBackCopy)
{
	std::string a{ "Hello" };
	a.push_back('!');
	EXPECT_EQ("Hello!", a);
}

TEST(StringSizeTest, SizeZero)
{
	const std::string a{};
	EXPECT_TRUE(a.size() == 0);
}

TEST(StringSizeTest, SizePositive)
{
	const std::string a{ "Hello" };
	EXPECT_TRUE(a.size() == 5);
}

TEST(StringFindTest, FindByString)
{
	const std::string str("hello world, hello big world");
	std::string str2("hello");

	// different member versions of find in the same order as above:
	size_t found_first = str.find(str2);
	size_t found_second = str.find(str2, found_first + 1);
	EXPECT_TRUE(found_first == 0 && found_second == 13);
}

TEST(StringFindTest, FindByCString)
{
	std::string str("hello world, hello big world");

	// different member versions of find in the same order as above:
	size_t found_first = str.find("world");
	size_t found_second = str.find("world", found_first + 1, 1);
	EXPECT_TRUE(found_first == 6 && found_second == 23);
}

TEST(StringFindTest, FindByChar)
{
	const std::string str("hello world, hello big world");
	size_t found = str.find(',');
	EXPECT_EQ(found, 11);
}

TEST(StringLengthTest, LengthZero)
{
	const std::string a{};
	EXPECT_TRUE(a.length() == 0);
}

TEST(StringLengthTest, LengthPositive)
{
	const std::string a{ "Hello" };
	EXPECT_TRUE(a.length() == 5);
}

TEST(StringAtTest, AtFromRange)
{
	const std::string a{ "Hello" };
	const char ch = a.at(0);
	EXPECT_EQ(ch, 'H');
}


TEST(StringAtTest, AtOutOfRange)
{
	const std::string a{ "Hello" };
	EXPECT_THROW(a.at(10), std::out_of_range);
}


TEST(StringMaxSizeTest, MaxSize)
{
	const std::string a{ "Hello" };
	const size_t size = 9223372036854775807;
	std::cout << a.max_size();
	EXPECT_EQ(a.max_size(), size);
}
