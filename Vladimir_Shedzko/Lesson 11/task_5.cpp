#include <gtest/gtest.h>
#include <string>

TEST(StringConstructor, list) {
    std::string s0 {"Initial string"}; // initializer list constructor
    EXPECT_EQ(s0, "Initial string");
}

TEST(StringConstructor, empty) {
    std::string s1; // init with empty string
    EXPECT_EQ(s1, "");
}

TEST(StringConstructor, copy) {
    std::string s0 {"Initial string"};
    std::string s2 (s0); // init with copy of other string
    EXPECT_EQ(s2, s0);
}

TEST(StringConstructor, copyFromPos) {
    std::string s0 {"Initial string"};
    std::string s2a (s0, 8); // init with substring from pos 8
    EXPECT_EQ(s2a, "string");
}

TEST(StringConstructor, copyFromPosWithCount) {
    std::string s0 {"Initial string"};  // initializer list constructor

    std::string s2b (s0, 8, 3); // init with substring from pos 8 and count 3
    EXPECT_EQ(s2b, "str");
}

TEST(StringConstructor, cString) {
    std::string s3 ("A character sequence"); // init with c-string
    EXPECT_EQ(s3, "A character sequence");
}

TEST(StringConstructor, cStringWithLimit) {
    std::string s3a ("A character sequence", 11); // init with first c-string 11 chars
    EXPECT_EQ(s3a, "A character");
}

TEST(StringConstructor, charRange) {
    std::string s4a (10, 'x'); // init with 10 'x'
    EXPECT_EQ(s4a, "xxxxxxxxxx");
}

TEST(StringConstructor, charCodeRange) {
    std::string s4b (10, 42);      // 42 is the ASCII code for '*'
    EXPECT_EQ(s4b, "**********");
}

TEST(StringConstructor, beginWithSize) {
    std::string s0 {"Initial string"}; // initializer list constructor

    std::string s5a (s0.begin(), s0.begin() + 7); // 7 characters from begin pointer
    EXPECT_EQ(s5a, "Initial"); 
}

TEST(StringConstructor, beginToEnd) {
    std::string s0 {"Initial string"}; // initializer list constructor

    std::string s5b (s0.begin(), s0.end()); // 3 characters before end pointer
    EXPECT_EQ(s5b, "Initial string"); 
}

TEST(StringConstructor, move) {
    std::string s0 {"Initial string"}; // initializer list constructor

    std::string s6 = std::move(s0); // move constructor
    EXPECT_EQ(s6, "Initial string"); 
    EXPECT_EQ(s0, ""); 
}

TEST(StringPushBack, testPushBack) {
    std::string s0 {"Initial string"};
    s0.push_back('!');
    EXPECT_EQ(s0, "Initial string!");
}

TEST(StringSize, testSize) {
    std::string s0 {"Initial string of quite big size"};
    EXPECT_EQ(s0.size(), 32);
}

TEST(StringFind, testFindChar) {
    auto s0 = std::string("test string in C is still a string");
    
    EXPECT_EQ(s0.find('t'), 0); // find a character
}

TEST(StringFind, testFindCharFromPos) {
    auto s0 = std::string("test string in C is still a string");
    
    EXPECT_EQ(s0.find('t', 1), 3); // find a character from pos
}

TEST(StringFind, testFindNonExistentChar) {
    auto s0 = std::string("test string in C is still a string");
    
    EXPECT_EQ(s0.find('z'), std::string::npos); // find a non-existent character
}

TEST(StringFind, testFindString) {
        auto s0 = std::string("test string in C is still a string");

    EXPECT_EQ(s0.find("string"), 5); // find a const string
}

TEST(StringFind, testFindStringFromPos) {
    auto s0 = std::string("test string in C is still a string");

    EXPECT_EQ(s0.find("string", 15), 28); // find a const string from pos
}

TEST(StringFind, testFindNonExistentString) {
    auto s0 = std::string("test string in C is still a string");

    EXPECT_EQ(s0.find("strng"), std::string::npos); // find a non-existent const string
}

TEST(StringResize, resizeLess) {
    std::string s0 {"Resize test string in C"};
    s0.resize(18);
    EXPECT_EQ(s0, "Resize test string");
}

TEST(StringResize, resizeWithChar) {
    std::string s1a {"Resize test string in C"}; // resize with defined const char
    s1a.resize(25, '+');
    EXPECT_EQ(s1a, "Resize test string in C++");
}

TEST(StringResize, resizeWithCharCode) {
    std::string s1b {"Resize test string in C"}; // resize with char code
    s1b.resize(25, 112);
    EXPECT_EQ(s1b, "Resize test string in Cpp");
}

TEST(StringPopBack, testPopBack) {
    auto s0 = std::string("test string in C++");
    
    s0.pop_back();
    s0.pop_back();

    EXPECT_EQ(s0, "test string in C");
}

TEST(StringSwap, testSwap) {
    auto s0 = std::string("test string in C++");
    auto s1 = std::string("kinda other string");

    s0.swap(s1);

    EXPECT_EQ(s0, "kinda other string");
    EXPECT_EQ(s1, "test string in C++");
}