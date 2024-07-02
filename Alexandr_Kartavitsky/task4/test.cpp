#include <gtest/gtest.h>
#include <string>

TEST(StringTest, Constructors)
{
    std::string empty_str;
    EXPECT_EQ(empty_str, "");

    std::string cstr_str("Hello");
    EXPECT_EQ(cstr_str, "Hello");

    std::string repeat_str(5, 'a');
    EXPECT_EQ(repeat_str, "aaaaa");

    std::string copy_str(cstr_str);
    EXPECT_EQ(copy_str, "Hello");
}

TEST(StringTest, PushBack)
{
    std::string str("Test");
    str.push_back('!');
    EXPECT_EQ(str, "Test!");
}

TEST(StringTest, Size)
{
    std::string str("Test");
    EXPECT_EQ(str.size(), 4);
    str.push_back('!');
    EXPECT_EQ(str.size(), 5);
}

TEST(StringTest, Find)
{
    std::string str("Hello, world!");
    EXPECT_EQ(str.find('w'), 7);
    EXPECT_EQ(str.find('z'), std::string::npos);
    EXPECT_EQ(str.find("world"), 7);
}

TEST(StringTest, Substr)
{
    std::string str("Hello, world!");
    EXPECT_EQ(str.substr(7, 5), "world");
}

TEST(StringTest, At)
{
    std::string str("Hello");
    EXPECT_EQ(str.at(1), 'e');
    EXPECT_THROW(str.at(10), std::out_of_range);
}

TEST(StringTest, Append)
{
    std::string str("Hello");
    str.append(", world!");
    EXPECT_EQ(str, "Hello, world!");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}