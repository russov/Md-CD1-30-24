#include "pch.h"

// clear
// Testing the clear method on an empty line
TEST(ClearStringTest, ClearEmptyString) {
    std::string OriginString;
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method on a non-empty string
TEST(ClearStringTest, ClearNonEmptyString) {
    std::string OriginString = "Task";
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
    EXPECT_EQ(0, OriginString.size());
}

// Testing the clear method after adding a character to a string
TEST(ClearStringTest, ClearAfterPushBackString) {
    std::string OriginString;
    OriginString.push_back('T');
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after removing a character from a string
TEST(ClearStringTest, ClearAfterPopBackString) {
    std::string OriginString = "T";
    OriginString.pop_back();
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after using the assign method with a non-empty string
TEST(ClearStringTest, ClearAssignNonEmptyString) {
    std::string OriginString;
    OriginString.assign("Task");
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after using the assign method with an empty string
TEST(ClearStringTest, ClearAssignEmptyString) {
    std::string OriginString = "Task";
    OriginString.assign("");
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}
// Testing the clear method after using the resize method
TEST(ClearStringTest, ClearResizeString) {
    std::string OriginString = "Task";
    OriginString.resize(10, 't');
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after using the swap method
TEST(ClearStringTest, ClearSwapString) {
    std::string OriginString = "Task";
    std::string NewString;
    OriginString.swap(NewString);
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after using the append method
TEST(ClearStringTest, ClearAppendString) {
    std::string OriginString = "Task";
    OriginString.append("ed");
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after using the insert method
TEST(ClearStringTest, ClearAfterInsertString) {
    std::string OriginString = "Task";
    OriginString.insert(2, "Abc");
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}

// Testing the clear method after using the replace method
TEST(ClearStringTest, ClearAfterReplaceString) {
    std::string OriginString = "Task";
    OriginString.replace(1, 2, "Abc");
    OriginString.clear();
    EXPECT_TRUE(OriginString.empty());
}