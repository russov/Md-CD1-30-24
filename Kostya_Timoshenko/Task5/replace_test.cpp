#include "pch.h"
#include "MyClass.h"

// replace
// Testing the replace method to replace a substring in a string
TEST(ReplaceStringTest, ReplaceString) {
    MyClass OriginString = "Task today";
    OriginString.replace(5, 5, "after");
    EXPECT_EQ("Task after", OriginString);
}

// Testing the replace method to replace a character in a string
TEST(ReplaceStringTest, ReplaceCharacterString) {
    MyClass OriginString = "Task today";
    OriginString.replace(0, 1, "W");
    EXPECT_EQ("Wask today", OriginString);
}

// Testing the replace method to replace an entire string
TEST(ReplaceStringTest, ReplaceFullString) {
    MyClass OriginString = "Task today";
    OriginString.replace(0, OriginString.size(), "Not before");
    EXPECT_EQ("Not before", OriginString);
}

// Testing the replace method to replace a substring in an empty string
TEST(ReplaceStringTest, ReplaceEmptyString) {
    MyClass OriginString;
    OriginString.replace(0, 0, "Task today");
    EXPECT_EQ("Task today", OriginString);
}

// Testing the replace method to replace a substring with a substring with spaces
TEST(ReplaceStringTest, ReplaceSubstringSpacesString) {
    MyClass OriginString = "Task,today";
    OriginString.replace(4, 1, " ");
    EXPECT_EQ("Task today", OriginString);
}

// Testing the replace method to replace a string with a substring with special characters
TEST(ReplaceStringTest, ReplaceSubstringSpecialCharactersString) {
    MyClass OriginString = "Task today";
    OriginString.replace(0, 4, "****");
    EXPECT_EQ("**** today", OriginString);
}

// Testing the replace method to replace a string with a substring with numbers
TEST(ReplaceStringTest, ReplaceSubstringNumbersString) {
    MyClass OriginString = "Task today";
    OriginString.replace(0, 4, "1111");
    EXPECT_EQ("1111 today", OriginString);
}

// Testing the replace method to replace a string with a substring with characters of different case
TEST(ReplaceStringTest, ReplaceSubstringDifferentCaseString) {
    MyClass OriginString = "Task today";
    OriginString.replace(0, 4, "TASK");
    EXPECT_EQ("TASK today", OriginString);
}