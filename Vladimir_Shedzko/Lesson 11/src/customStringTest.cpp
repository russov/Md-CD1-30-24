#include <gtest/gtest.h>

#include "customString.h"

TEST(CustomStringConstructor, list) {
    CustomString s0 {"Initial string"}; // initializer list constructor
    EXPECT_EQ(s0, "Initial string");
}

TEST(CustomStringConstructor, empty) {
    CustomString s1; // init with empty string
    EXPECT_EQ(s1, "");
}

TEST(CustomStringConstructor, copy) {
    CustomString s0 {"Initial string"};
    CustomString s2 (s0); // init with copy of other string
    EXPECT_EQ(s2, s0);
}

TEST(CustomStringConstructor, copyFromPos) {
    CustomString s0 {"Initial string"};
    CustomString s2a (s0, 8); // init with substring from pos 8
    EXPECT_EQ(s2a, "string");
}

TEST(CustomStringConstructor, copyFromPosWithCount) {
    CustomString s0 {"Initial string"};  // initializer list constructor

    CustomString s2b (s0, 8, 3); // init with substring from pos 8 and count 3
    EXPECT_EQ(s2b, "str");
}

TEST(CustomStringConstructor, cString) {
    CustomString s3 ("A character sequence"); // init with c-string
    EXPECT_EQ(s3, "A character sequence");
}

TEST(CustomStringConstructor, cStringWithLimit) {
    CustomString s3a ("A character sequence", 11); // init with first c-string 11 chars
    EXPECT_EQ(s3a, "A character");
}

TEST(CustomStringConstructor, charRange) {
    CustomString s4a (10, 'x'); // init with 10 'x'
    EXPECT_EQ(s4a, "xxxxxxxxxx");
}

TEST(CustomStringConstructor, charCodeRange) {
    CustomString s4b (10, 42);      // 42 is the ASCII code for '*'
    EXPECT_EQ(s4b, "**********");
}

TEST(CustomStringConstructor, beginWithSize) {
    CustomString s0 {"Initial string"}; // initializer list constructor
    CustomString s5a (s0.begin(), s0.begin() + 7); // 7 characters from begin pointer
    EXPECT_EQ(s5a, "Initial"); 
}

TEST(CustomStringConstructor, beginToEnd) {
    CustomString s0 {"Initial string"}; // initializer list constructor

    CustomString s5b (s0.begin(), s0.end()); // from begin to end
    EXPECT_EQ(s5b, "Initial string"); 
}

TEST(CustomStringConstructor, move) {
    CustomString s0 {"Initial string"}; // initializer list constructor

    CustomString s6 = std::move(s0); // move constructor
    EXPECT_EQ(s6, "Initial string"); 
    EXPECT_EQ(s0, ""); 
}

TEST(CustomStringPushBack, testPushBack) {
    CustomString s0 {"Initial string"};
    s0.push_back('!');
    EXPECT_EQ(s0, "Initial string!");
}

TEST(CustomStringSize, testSize) {
    CustomString s0 {"Initial string of quite big size"};
    EXPECT_EQ(s0.size(), 32);
}

TEST(CustomStringFind, testFindChar) {
    auto s0 = CustomString("test string in C is still a string");
    
    EXPECT_EQ(s0.find('t'), 0); // find a character
}

TEST(CustomStringFind, testFindCharFromPos) {
    auto s0 = CustomString("test string in C is still a string");
    
    EXPECT_EQ(s0.find('t', 1), 3); // find a character from pos
}

TEST(CustomStringFind, testFindNonExistentChar) {
    auto s0 = CustomString("test string in C is still a string");
    
    EXPECT_EQ(s0.find('z'), CustomString::npos); // find a non-existent character
}

TEST(CustomStringFind, testFindString) {
        auto s0 = CustomString("test string in C is still a string");

    EXPECT_EQ(s0.find("string"), 5); // find a const string
}

TEST(CustomStringFind, testFindStringFromPos) {
    auto s0 = CustomString("test string in C is still a string");

    EXPECT_EQ(s0.find("string", 15), 28); // find a const string from pos
}

TEST(CustomStringFind, testFindNonExistentString) {
    auto s0 = CustomString("test string in C is still a string");

    EXPECT_EQ(s0.find("strng"), CustomString::npos); // find a non-existent const string
}

TEST(CustomStringResize, resizeLess) {
    CustomString s0 {"Resize test string in C"};
    s0.resize(18);
    EXPECT_EQ(s0, "Resize test string");
}

TEST(CustomStringResize, resizeWithChar) {
    CustomString s1a {"Resize test string in C"}; // resize with defined const char
    s1a.resize(25, '+');
    EXPECT_EQ(s1a, "Resize test string in C++");
}

TEST(CustomStringResize, resizeWithCharCode) {
    CustomString s1b {"Resize test string in C"}; // resize with char code
    s1b.resize(25, 112);
    EXPECT_EQ(s1b, "Resize test string in Cpp");
}

TEST(CustomStringPopBack, testPopBack) {
    auto s0 = CustomString("test string in C++");
    
    s0.pop_back();
    s0.pop_back();

    EXPECT_EQ(s0, "test string in C");
}

TEST(CustomStringSwap, testSwap) {
    auto s0 = CustomString("test string in C++");
    auto s1 = CustomString("kinda other string");

    s0.swap(s1);

    EXPECT_EQ(s0, "kinda other string");
    EXPECT_EQ(s1, "test string in C++");
}