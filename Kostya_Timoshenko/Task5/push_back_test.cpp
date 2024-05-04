#include "pch.h"

// push_back
// Testing the push_back method to add a character to an empty string
TEST(PushBackStringTest, PushBackEmptyString) {
    std::string EmptyString;
    EmptyString.push_back('a');
    EXPECT_EQ("a", EmptyString);
}

// Testing the push_back method to add a character to a non-empty string
TEST(PushBackStringTest, PushBackNonEmptyString) {
    std::string OriginString = "Task";
    OriginString.push_back('s');
    EXPECT_EQ("Tasks", OriginString);
}

// Testing the push_back method to add a special character
TEST(PushBackStringTest, PushBackSpecialCharacterString) {
    std::string OriginString = "Task";
    OriginString.push_back('\n');
    EXPECT_EQ(OriginString.back(), '\n');
}

// Testing the push_back method adding a character to a string that has already reached its reserved size
TEST(PushBackStringTest, PushBackRezervedString) {
    std::string OriginString = "Task";
    OriginString.reserve(4);
    OriginString.push_back('s');
    EXPECT_EQ(5, OriginString.size());
}

// Testing the push_back method checking push_back behavior after clearing a line
TEST(PushBackStringTest, PushBackClearString) {
    std::string OriginString = "Task";
    OriginString.clear();
    OriginString.push_back('t');
    EXPECT_EQ("t", OriginString);
}

// Testing the push_back method adding a character to a string that was copied
TEST(PushBackStringTest, PushBackCopyString) {
    std::string OriginString = "Task";
    std::string NewString = OriginString;
    NewString.push_back('s');
    EXPECT_EQ("Tasks", NewString);
}

// Testing the push_back method adding a character to a string after using the resize method
TEST(PushBackStringTest, PushBackAfterResizeString) {
    std::string OriginString = "Task";
    OriginString.resize(2);
    OriginString.push_back('x');
    EXPECT_EQ("Tax", OriginString);
}

// Testing the push_back method adding a character to a string after using the append method 
TEST(PushBackStringTest, PushBackAfterAppendString) {
    std::string OriginString = "Task";
    OriginString.append("ed");
    OriginString.push_back('W');
    EXPECT_EQ("TaskedW", OriginString);
}

// Testing the push_back method adding a character to a string after using the swap method
TEST(PushBackStringTest, PushBackAfterSwapString) {
    std::string OriginString = "Task";
    std::string NewString = "Today";
    OriginString.swap(NewString);
    OriginString.push_back('W');
    EXPECT_EQ("TodayW", OriginString);
}

// Testing the push_back method adding a character to a string after using the erase method
TEST(PushBackStringTest, PushBackAfterEraseString) {
    std::string OriginString = "Task";
    OriginString.erase(1, 3);
    OriginString.push_back('y');
    EXPECT_EQ("Ty", OriginString);
}

// Testing the push_back method in cycle
TEST(PushBackStringTest, PushBackInCycleString) {
    std::string OriginString;
    for (char symbol = 'a'; symbol <= 'e'; ++symbol) {
        OriginString.push_back(symbol);
    }
    EXPECT_EQ("abcde", OriginString);
}

// Testing the push_back method after method substr
TEST(PushBackStringTest, PushBackAfterSubString) {
    std::string OriginString = "Task today";
    std::string SubString = OriginString.substr(5);
    SubString.push_back('!');
    EXPECT_EQ("today!", SubString);
}