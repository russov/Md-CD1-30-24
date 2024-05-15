#include "pch.h"
#include "../MyString/main.cpp"

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
    MyString strTest = "Task5";
    strTest.push_back('!');
    EXPECT_EQ(strTest, "Task5!");
}
 
 
TEST(StringSizeTest, Size) {
    MyString strTest = "Task5";
    EXPECT_EQ(strTest.size(), 5);
}

TEST(StringOperatorBracketsTest, BracketOperator) {
    string strTest = "Task5";
    char c = strTest[4];
    EXPECT_EQ(c, '5');
}
 
TEST(StringCompareTest, Compare) {
    string strTest1 = "Task";
    string strTest2 = "Task";
    int result = strTest1.compare(strTest2);
    EXPECT_EQ(result, 0);
}

 TEST(StringSubstrTest, Substring) {
    string strTest = "Task5 gtest";
    string sub = strTest.substr(6);
    EXPECT_EQ(sub, "gtest");
}

TEST(StringFindTest, Find) {
    string strTest = "Task5 gtest";
    size_t found = strTest.find("gtest");
    EXPECT_NE(found, string::npos);
}

