#include "pch.h"

// replace
// Testing the replace method to replace a substring in a string
TEST(ReplaceStringTest, ReplaceString) {
    std::string OriginString = "Task today";
    OriginString.replace(5, 5, "after");
    EXPECT_EQ("Task after", OriginString);
}

// Testing the replace method to replace a character in a string
TEST(ReplaceStringTest, ReplaceCharacterString) {
    std::string OriginString = "Task today";
    OriginString.replace(0, 1, "W");
    EXPECT_EQ("Wask today", OriginString);
}

// Testing the replace method to replace an entire string
TEST(ReplaceStringTest, ReplaceFullString) {
    std::string OriginString = "Task today";
    OriginString.replace(0, OriginString.size(), "Not before");
    EXPECT_EQ("Not before", OriginString);
}

// Testing the replace method to replace a substring in an empty string
TEST(ReplaceStringTest, ReplaceEmptyString) {
    std::string OriginString;
    OriginString.replace(0, 0, "Task today");
    EXPECT_EQ(OriginString, "Task today");
}

// Testing the replace method to replace a substring with a substring with spaces
TEST(ReplaceStringTest, ReplaceSubstringSpacesString) {
    std::string OriginString = "Task,today";
    OriginString.replace(4, 1, " ");
    EXPECT_EQ("Task today", OriginString);
}

// Testing the replace method to replace a string with a substring with special characters
TEST(ReplaceStringTest, ReplaceSubstringSpecialCharactersString) {
    std::string OriginString = "Task today";
    OriginString.replace(0, 4, "****");
    EXPECT_EQ("**** today", OriginString);
}

// Testing the replace method to replace a string with a substring with numbers
TEST(ReplaceStringTest, ReplaceSubstringNumbersString) {
    std::string OriginString = "Task today";
    OriginString.replace(0, 4, "1111");
    EXPECT_EQ("1111 today", OriginString);
}

// Testing the replace method to replace a string with a substring with characters of different case
TEST(ReplaceStringTest, ReplaceSubstringDifferentCaseString) {
    std::string OriginString = "Task today";
    OriginString.replace(0, 4, "TASK");
    EXPECT_EQ("TASK today", OriginString);
}