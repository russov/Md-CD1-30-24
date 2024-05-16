#include "pch.h"
#include "MyClass.h"

// clear
// Testing the clear method on an empty line
TEST(ClearStringTest, ClearEmptyString) {
    MyClass OriginString;
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method on a non-empty string
TEST(ClearStringTest, ClearNonEmptyString) {
    MyClass OriginString = "Task";
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
    EXPECT_EQ(0, OriginString.size());
}

// Testing the clear method after adding a character to a string
TEST(ClearStringTest, ClearAfterPushBackString) {
    MyClass OriginString;
    OriginString.push_back('T');
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after removing a character from a string
TEST(ClearStringTest, ClearAfterPopBackString) {
    MyClass OriginString = "T";
    OriginString.pop_back();
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after using the swap method
TEST(ClearStringTest, ClearSwapString) {
    MyClass OriginString = "Task";
    MyClass NewString;
    OriginString.swap(NewString);
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}