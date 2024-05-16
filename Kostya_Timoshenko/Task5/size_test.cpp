#include "pch.h"
#include "MyClass.h"

// size
// Testing the size method on an empty line
TEST(SizeStringTest, SizeEmptyString) {
    MyClass OriginString;
    EXPECT_EQ(0, OriginString.size());
}

// Testing the size method on a non-empty string
TEST(SizeStringTest, SizeNonEmptyString) {
    MyClass OriginString = "Task";
    EXPECT_EQ(4, OriginString.size());
}

// Testing the size method after adding a character to a string
TEST(SizeStringTest, SizeAfterPushBackString) {
    MyClass OriginString = "Task";
    OriginString.push_back('s');
    EXPECT_EQ(5, OriginString.size());
}

// Testing the size method after clearing a string
TEST(SizeStringTest, SizeAfterClearString) {
    MyClass OriginString = "Task";
    OriginString.clear();
    EXPECT_EQ(0, OriginString.size());
}

// Testing the size method after using the swap method
TEST(SizeStringTest, SizeAfterSwapString) {
    MyClass OriginString = "Task";
    MyClass NewString = "Today";
    OriginString.swap(NewString);
    EXPECT_EQ(5, OriginString.size());
    EXPECT_EQ(4, NewString.size());
}