#include "pch.h"
#include "StringCustom.h"
#include <gtest/gtest.h>

TEST(ConstructorTest, DefaultConstructor) {
    StringCustom str;
    EXPECT_STREQ(str.c_str(), "");
}

TEST(ConstructorTest, CopyConstructor) {
    StringCustom str("example");
    StringCustom copy(str);
    EXPECT_STREQ(copy.c_str(), "example");
}

TEST(ConstructorTest, SubstringConstructor) {
    StringCustom str("example");
    StringCustom substr(str, 2, 4);
    EXPECT_STREQ(substr.c_str(), "ampl");
}

TEST(ConstructorTest, CStrConstructor) {
    StringCustom str("example");
    EXPECT_STREQ(str.c_str(), "example");
}

TEST(ConstructorTest, CStrLenConstructor) {
    StringCustom str("example", 4);
    EXPECT_STREQ(str.c_str(), "exam");
}

TEST(ConstructorTest, CharFillConstructor) {
    StringCustom str(5, 'x');
    EXPECT_STREQ(str.c_str(), "xxxxx");
}

TEST(ConstructorTest, MoveConstructor) {
    StringCustom str("example");
    StringCustom moved(std::move(str));
    EXPECT_STREQ(moved.c_str(), "example");
    EXPECT_EQ(str.c_str(), nullptr);
}

TEST(MethodTest, PushBack) {
    StringCustom str("exam");
    str.push_back('p');
    EXPECT_STREQ(str.c_str(), "examp");
}

TEST(MethodTest, Clear) {
    StringCustom str("example");
    str.clear();
    EXPECT_STREQ(str.c_str(), "");
    EXPECT_EQ(str.size(), 1);
}

TEST(MethodTest, Find) {
    StringCustom str("example");
    EXPECT_EQ(str.find('a'), 2);
    EXPECT_EQ(str.find('z'), -1);
}

TEST(MethodTest, Length) {
    StringCustom str("example");
    EXPECT_EQ(str.length(), 7);
}

TEST(MethodTest, AppendStringCustom) {
    StringCustom str1("Hello");
    StringCustom str2("World");
    str1.append(str2);
    EXPECT_STREQ(str1.c_str(), "HelloWorld");
}

TEST(MethodTest, AppendCString) {
    StringCustom str("Hello");
    str.append(", World");
    EXPECT_STREQ(str.c_str(), "Hello, World");
}

TEST(MethodTest, Sort) {
    StringCustom str("acdb");
    str.sort();
    EXPECT_STREQ(str.c_str(), "abcd");
}

TEST(OperatorTest, EqualsOperatorStringCustom) {
    StringCustom str1("example");
    StringCustom str2("example");
    EXPECT_TRUE(str1 == str2);
}

TEST(OperatorTest, EqualsOperatorCStr) {
    StringCustom str("example");
    EXPECT_TRUE(str == "example");
    EXPECT_TRUE("example" == str);
}

TEST(OperatorTest, LessThanOperator) {
    StringCustom str1("abc");
    StringCustom str2("bcd");
    EXPECT_TRUE(str1 < str2);
}