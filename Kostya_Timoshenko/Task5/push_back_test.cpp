#include "pch.h"
#include "MyClass.h"

// push_back
// Testing the push_back method to add a character to an empty string
TEST(PushBackStringTest, PushBackEmptyString) {
    MyClass EmptyString;
    EmptyString.push_back('a');
    EXPECT_EQ("a", EmptyString);
}

// Testing the push_back method to add a character to a non-empty string
TEST(PushBackStringTest, PushBackNonEmptyString) {
    MyClass OriginString = "Task";
    OriginString.push_back('s');
    EXPECT_EQ("Tasks", OriginString);
}

// Testing the push_back method checking push_back behavior after clearing a line
TEST(PushBackStringTest, PushBackClearString) {
    MyClass OriginString = "Task";
    OriginString.clear();
    OriginString.push_back('t');
    EXPECT_EQ("t", OriginString);
}

// Testing the push_back method adding a character to a string that was copied
TEST(PushBackStringTest, PushBackCopyString) {
    MyClass OriginString = "Task";
    MyClass NewString = OriginString;
    NewString.push_back('s');
    EXPECT_EQ("Tasks", NewString);
}

// Testing the push_back method adding a character to a string after using the swap method
TEST(PushBackStringTest, PushBackAfterSwapString) {
    MyClass OriginString = "Task";
    MyClass NewString = "Today";
    OriginString.swap(NewString);
    OriginString.push_back('W');
    EXPECT_EQ("TodayW", OriginString);
}

// Testing the push_back method in cycle
TEST(PushBackStringTest, PushBackInCycleString) {
    MyClass OriginString;
    for (char symbol = 'a'; symbol <= 'e'; ++symbol) {
        OriginString.push_back(symbol);
    }
    EXPECT_EQ("abcde", OriginString);
}