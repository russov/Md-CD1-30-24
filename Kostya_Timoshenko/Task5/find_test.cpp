#include "pch.h"
#include "MyClass.h"

// find
// Testing the find method to find a substring in a string
TEST(FindStringTest, FindSubString) {
    MyClass OriginString = "Task today";
    size_t Position = OriginString.find("today");
    EXPECT_EQ(5, Position);
}

// Testing the find method to find a character in a string
TEST(FindStringTest, FindCharacterString) {
    MyClass OriginString = "Task today";
    size_t Position = OriginString.find('t');
    EXPECT_EQ(5, Position);
}

// Testing the find method to find a substring in an empty string
TEST(FindStringTest, FindInEmptyString) {
    MyClass OriginString;
    size_t Position = OriginString.find("Task");
    EXPECT_EQ(std::string::npos, Position);
}

// Testing the find method to find a substring starting at position
TEST(FindStringTest, FindFromPositionString) {
    MyClass OriginString = "Task today Task";
    size_t Position = OriginString.find("Task", 5);
    EXPECT_EQ(11, Position);
}

// Testing the find method to find a substring in a string with different cases
TEST(FindStringTest, FindDifferentCaseString) {
    MyClass OriginString = "Task today";
    size_t Position = OriginString.find("TASK");
    EXPECT_EQ(std::string::npos, Position);
}

// Testing the find method to find a substring in a string containing special characters
TEST(FindStringTest, FindSpecialCharacterString) {
    MyClass OriginString = "Task \nToday";
    size_t Position = OriginString.find("\n");
    EXPECT_EQ(5, Position);
}

// Testing the find method to find a substring in a string containing a digits
TEST(FindStringTest, FindNumbersString) {
    MyClass OriginString = "98Task today";
    size_t Position = OriginString.find("98");
    EXPECT_EQ(0, Position);
}

// Testing the find method to find a substring in a string containing special characters
TEST(FindStringTest, FindSpecialCharactersString) {
    MyClass OriginString = "@@@Task ###today";
    size_t Position = OriginString.find("###");
    EXPECT_EQ(8, Position);
}