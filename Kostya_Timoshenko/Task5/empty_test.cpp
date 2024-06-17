#include "pch.h"
#include "MyClass.h"

// empty
// Testing the empty method on an empty string
TEST(EmptyStringTest, EmptyEmptyString) {
    MyClass OriginString;
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method on a non-empty string
TEST(EmptyStringTest, EmptyNonEmptyString) {
    MyClass OriginString = "Task";
    EXPECT_FALSE(OriginString.empty());
}

// Testing the empty method after clearing string
TEST(EmptyStringTest, EmptyAfterClearString) {
    MyClass OriginString = "Task";
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method after adding a character to an empty string
TEST(EmptyStringTest, EmptyAfterPushBackString) {
    MyClass OriginString;
    OriginString.push_back('T');
    EXPECT_FALSE(OriginString.empty());
}

// Testing the empty method after removing a character from a string
TEST(EmptyStringTest, EmptyAfterPopBackString) {
    MyClass OriginString = "T";
    OriginString.pop_back();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method after using the swap method with an empty string
TEST(EmptyStringTest, EmptyAfterSwapEmptyString) {
    MyClass OriginString = "Task";
    MyClass NewString;
    OriginString.swap(NewString);
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method after using the swap method with a non-empty string
TEST(EmptyStringTest, EmptyAfterSwapNonEmptyString) {
    MyClass OriginString;
    MyClass NewString = "Task";
    OriginString.swap(NewString);
    EXPECT_FALSE(OriginString.empty());
}