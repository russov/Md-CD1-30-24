#include "pch.h"

// size
// Testing the size method on an empty line
TEST(SizeStringTest, SizeEmptyString) {
    std::string OriginString;
    EXPECT_EQ(0, OriginString.size());
}

// Testing the size method on a non-empty string
TEST(SizeStringTest, SizeNonEmptyString) {
    std::string OriginString = "Task";
    EXPECT_EQ(4, OriginString.size());
}

// Testing the size method after adding a character to a string
TEST(SizeStringTest, SizeAfterPushBackString) {
    std::string OriginString = "Task";
    OriginString.push_back('s');
    EXPECT_EQ(5, OriginString.size());
}

// Testing the size method after clearing a string
TEST(SizeStringTest, SizeAfterClearString) {
    std::string OriginString = "Task";
    OriginString.clear();
    EXPECT_EQ(0, OriginString.size());
}

// Testing the size method after replacing part of a string
TEST(SizeStringTest, SizeAfterReplaceString) {
    std::string OriginString = "Task";
    OriginString.replace(1, 2, "Abc");
    EXPECT_EQ(5, OriginString.size());
}

// Testing the size method after inserting a substring into a string
TEST(SizeStringTest, SizeAfterInsertString) {
    std::string OriginString = "Task";
    OriginString.insert(2, "Abc");
    EXPECT_EQ(7, OriginString.size());
}

// Testing the size method after removing part of a string
TEST(SizeStringTest, SizeAfterEraseString) {
    std::string OriginString = "Task";
    OriginString.erase(1, 2);
    EXPECT_EQ(2, OriginString.size());
}

// Testing the size method after using the append method
TEST(SizeStringTest, SizeAfterAppendString) {
    std::string OriginString = "Task";
    OriginString.append("ed");
    EXPECT_EQ(6, OriginString.size());
}

// Testing the size method after using the substr method
TEST(SizeStringTest, SizeAfterSubstrString) {
    std::string OriginString = "Task";
    std::string NewString = OriginString.substr(2);
    EXPECT_EQ(2, NewString.size());
}

// Testing the size method after using the swap method
TEST(SizeStringTest, SizeAfterSwapString) {
    std::string OriginString = "Task";
    std::string NewString = "Today";
    OriginString.swap(NewString);
    EXPECT_EQ(5, OriginString.size());
    EXPECT_EQ(4, NewString.size());
}