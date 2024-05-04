#include "pch.h"

// empty
// Testing the empty method on an empty string
TEST(EmptyStringTest, EmptyEmptyString) {
    std::string OriginString;
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method on a non-empty string
TEST(EmptyStringTest, EmptyNonEmptyString) {
    std::string OriginString = "Task";
    EXPECT_FALSE(OriginString.empty());
}

// Testing the empty method after clearing string
TEST(EmptyStringTest, EmptyAfterClearString) {
    std::string OriginString = "Task";
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method after adding a character to an empty string
TEST(EmptyStringTest, EmptyAfterPushBackString) {
    std::string OriginString;
    OriginString.push_back('T');
    EXPECT_FALSE(OriginString.empty());
}

// Testing the empty method after removing a character from a string
TEST(EmptyStringTest, EmptyAfterPopBackString) {
    std::string OriginString = "T";
    OriginString.pop_back();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method after using the assign method with an empty string
TEST(EmptyStringTest, EmptyAfterAssignString) {
    std::string OriginString = "Task";
    OriginString.assign("");
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method after using the swap method with an empty string
TEST(EmptyStringTest, EmptyAfterSwapEmptyString) {
    std::string OriginString = "Task";
    std::string NewString;
    OriginString.swap(NewString);
    EXPECT_TRUE(OriginString.empty());
}

// Testing the empty method after using the swap method with a non-empty string
TEST(EmptyStringTest, EmptyAfterSwapNonEmptyString) {
    std::string OriginString;
    std::string NewString = "Task";
    OriginString.swap(NewString);
    EXPECT_FALSE(OriginString.empty());
}

// Testing the empty method after using the substr method on an empty string
TEST(EmptyStringTest, EmptyAfterSubstrEmptyString) {
    std::string OriginString;
    std::string NewString = OriginString.substr(0, 0);
    EXPECT_TRUE(NewString.empty());
}

// Testing the empty method after using the substr method on a non-empty string
TEST(EmptyStringTest, EmptyAfterSubstrNonEmptyString) {
    std::string OriginString = "Task";
    std::string NewString = OriginString.substr(0, 0);
    EXPECT_TRUE(NewString.empty());
    NewString = OriginString.substr(0, 2);
    EXPECT_FALSE(NewString.empty());
}