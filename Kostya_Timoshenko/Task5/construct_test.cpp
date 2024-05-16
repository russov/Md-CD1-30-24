#include "pch.h"
#include "MyClass.h"

// construct
// Testing the default constructor (Empty line)
TEST(ConstructorStringTest, DefaultString) {
    EXPECT_NO_THROW({
        MyClass EmptyString;
        EXPECT_EQ(0, EmptyString.size());
        });
}

// Testing a constructor that accepts a c-string
TEST(ConstructorStringTest, BigString) {
    EXPECT_NO_THROW({
        MyClass FilledString ("Task!");
        EXPECT_EQ(5, FilledString.size());
        });
}

// Testing a copy constructor
TEST(ConstructorStringTest, CopyString) {
    MyClass OriginalString ("Task");
    EXPECT_NO_THROW({
        MyClass CopyString(OriginalString);
        EXPECT_EQ("Task", CopyString);
        });
}

// Testing the constructor, creating a string by repeating the symbol several times
TEST(ConstructorStringTest, RepeatSymbolString) {
    char SingleChar = 't';
    EXPECT_NO_THROW({
        MyClass MoreSymbolString(SingleChar, 4);
        EXPECT_EQ("tttt", MoreSymbolString);
        });
}

// Testing the constructor, creates a substring from a string, at the specified index and length
TEST(ConstructorStringTest, SubString) {
    MyClass OriginalString("TaskToday");
    EXPECT_NO_THROW({
        MyClass NewString(OriginalString, 1, 5);
        // Checking that a substring matches the expected result
        EXPECT_EQ("askTo", NewString);
        });
}

// Testing the constructor, creates a string from a buffer
TEST(ConstructorStringTest, BufferInString) {
    const char* Buffer ("Tough task!");
    EXPECT_NO_THROW({
        MyClass OriginalString(Buffer, 5);
        // Checking that a string matches the expected result
        EXPECT_EQ("Tough", OriginalString);
        });
}

// Testing the move constructor, moves data from one string to another
TEST(ConstructorStringTest, MoveDataInString) {
    MyClass OriginalString ("Tough task!");
    EXPECT_NO_THROW({
        MyClass NewString(std::move(OriginalString));
        EXPECT_TRUE(OriginalString.empty());
        EXPECT_EQ("Tough task!", NewString);
        });
}

// Testing a constructor with an iterator range that copies characters from an iterator range
TEST(ConstructorStringTest, RangeString) {
    MyClass OriginalString ("Tough task!");
    EXPECT_NO_THROW({
        MyClass NewString(OriginalString.begin(), OriginalString.end());
        EXPECT_EQ(OriginalString, NewString);
        });
}

// Testing a constructor with initialization from a list
TEST(ConstructorStringTest, InitializerListString) {
    std::initializer_list<char> OriginList = { 'T', 'a', 's', 'k' };
    EXPECT_NO_THROW({
        MyClass OriginString(OriginList);
        EXPECT_EQ("Task", OriginString);
        });
}
