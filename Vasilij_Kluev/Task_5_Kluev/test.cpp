#include "pch.h"
#include "../ConsoleApplication1/Header.h"

TEST(StringTest, DefaultConstructor) {
    std::string str;
    EXPECT_TRUE(str.empty());
}
TEST(StringTest, PushBack) {
    std::string str;
    str.push_back('a');
    EXPECT_EQ(str.size(), 1);
    EXPECT_EQ(str[0], 'a');
}
TEST(StringTest, Size) {
    std::string str = "test";
    EXPECT_EQ(str.size(), 4);
}
TEST(StringTest, Find) {
    std::string str = "Hello World";
    EXPECT_EQ(str.find("World"), 6);
    EXPECT_EQ(str.find("wrld"), !std::string::npos);
}
TEST(StringTest, Clear) {
    std::string str = "test";
    str.clear();
    EXPECT_TRUE(str.empty());
}
TEST(StringTest, Append) {
    std::string str = "Hello World";
    std::string atr2 = " New";
    str.append(atr2);
    EXPECT_EQ(str, "Hello World New");
}
TEST(StringTest, Replace) {
    std::string str = "Hello, world!";
    str.replace(7, 5, "there");
    EXPECT_EQ(str, "Hello, there!");
}