
#include "pch.h"
#include "..//NewStringClass/CreateString.h"
#include "..//NewStringClass/CreateString.cpp"

TEST(StringTest, DefaultConstructor)
{
    CreateString str;
    EXPECT_EQ(str.size(), 0);
}

TEST(StringTest, PushBack)
{
    CreateString str;
    str.push_back('a');
    EXPECT_EQ(str.size(), 1);
    EXPECT_EQ(str[0], 'a');
}

TEST(StringTest, Size) 
{
    CreateString str = "test";
    EXPECT_EQ(str.size(), 4);
}

TEST(StringTest, Find) 
{
    CreateString str = "Hello World";
    EXPECT_EQ(str.find('W'), 6);
}

TEST(CreateStringTest, Clear) 
{
    CreateString str = "Hello World";
    str.clear();
    EXPECT_EQ(str.size(), 0);
}

TEST(StringTest, Replace) 
{
    CreateString str = "Hello, world!";
    bool result = str.replace("world", "there");
    EXPECT_TRUE(result);
    EXPECT_TRUE(str == CreateString("Hello, there!"));
}