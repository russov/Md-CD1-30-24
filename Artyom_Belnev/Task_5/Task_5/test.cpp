#include "pch.h"
#include <string>

using namespace std;

TEST(StringConstructorTest, DefaultConstructor) {
    string strTest;
    EXPECT_EQ(strTest.size(), 0);
}


TEST(StringConstructorTest, CopyConstructor) {
    const string ORIGINAL("Task5");
    string copy(ORIGINAL);
    EXPECT_EQ(copy, ORIGINAL);
}

TEST(StringPushBackTest, PushBack) {
    string strTest = "Task5";
    strTest.push_back('!');
    EXPECT_EQ(strTest, "Task5!");
}

TEST(StringSizeTest, Size) {
    string strTest = "Task5";
    EXPECT_EQ(strTest.size(), 5);
}


TEST(StringFindTest, Find) {
    string strTest = "Task5 gtest";
    size_t found = strTest.find("gtest");
    EXPECT_NE(found, string::npos);
}

TEST(StringSubstrTest, Substring) {
    string strTest = "Task5 gtest";
    string sub = strTest.substr(6);
    EXPECT_EQ(sub, "gtest");
}

TEST(StringCompareTest, Compare) {
    string strTest1 = "Task5";
    string strTest2 = "Task5";
    int result = strTest1.compare(strTest2);
    EXPECT_EQ(result, 0);
}


TEST(StringOperatorBracketsTest, BracketOperator) {
    string strTest = "Task5";
    char c = strTest[4];
    EXPECT_EQ(c, '5');
}
