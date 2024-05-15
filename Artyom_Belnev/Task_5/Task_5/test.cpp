#include "pch.h"
#include <string>

using namespace std;

TEST(StringConstructorTest, DefaultConstructor) {
    const string strTest;
    EXPECT_EQ(strTest.size(), 0);
}


TEST(StringConstructorTest, CopyConstructor) {
    const string ORIGINAL("Task5");
    string copy(ORIGINAL);
    EXPECT_EQ(copy, ORIGINAL);
}

TEST(StringConstructorTest, SubStringConstructor) {
    const string strTest = "Task5 gTest";
    string subStr(strTest, 6, 5);
    EXPECT_EQ(subStr, "gTest");
}

TEST(StringConstructorTest, FromCStringConstructor) {
    char* ch = "a";
    string strTest(ch);
    EXPECT_EQ(strTest, "a");
}

TEST(StrConstructorTest, FromBufferConstructor) {
    char* ch = "abcdef";
    string strTest(ch, 5);
    EXPECT_EQ(strTest, "abcde");
}

TEST(StrConstructortest, MoveConstructor) {
    string&& strTest = "Task5";
    string movestrTest(strTest);
    EXPECT_EQ(movestrTest, "Task5");
}


TEST(StrConstructorTest, RangeConstructor) {
    const string strTest("London is the capital of Great Britain");
    string rangestrTest(strTest.begin(), strTest.end() - 32);
    EXPECT_EQ(rangestrTest, "London");
}

TEST(StrConstructorTest, InitializerListConstructor) {
    initializer_list<char> ch = { 'a', 'b', 'c', 'd', 'e', 'f' };
    string str(ch);
    EXPECT_EQ(str, "abcdef");
}


TEST(StringPushBackTest, PushBack) {
    string strTest = "Task5";
    strTest.push_back('!');
    EXPECT_EQ(strTest, "Task5!");
}

TEST(StringSizeTest, Size) {
    const string strTest = "Task5";
    EXPECT_EQ(strTest.size(), 5);
}


TEST(StringFindTest, Find) {
    const string strTest = "Task5 gtest";
    size_t found = strTest.find("gtest");
    EXPECT_NE(found, string::npos);
}

TEST(StringSubstrTest, Substring) {
    const string strTest = "Task5 gtest";
    string sub = strTest.substr(6);
    EXPECT_EQ(sub, "gtest");
}

TEST(StringCompareTest, Compare) {
    const string strTest1 = "Task5";
    string strTest2 = "Task5";
    int result = strTest1.compare(strTest2);
    EXPECT_EQ(result, 0);
}


TEST(StringOperatorBracketsTest, BracketOperator) {
    const string strTest = "Task5";
    char c = strTest[4];
    EXPECT_EQ(c, '5');
}
