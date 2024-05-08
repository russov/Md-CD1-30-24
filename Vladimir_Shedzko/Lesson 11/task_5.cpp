#include <gtest/gtest.h>
#include <string>

TEST(StringTests, testConstructor) {
    std::string s0 {"Initial string"}; // initializer list constructor
    EXPECT_EQ(s0, "Initial string");

    std::string s1; // init with empty string
    EXPECT_EQ(s1, "");

    std::string s2 (s0); // init with copy of other string
    EXPECT_EQ(s2, s0);
    std::string s2a (s0, 8); // init with substring from pos 8
    EXPECT_EQ(s2a, "string");
    std::string s2b (s0, 8, 3); // init with substring from pos 8 of size 3
    EXPECT_EQ(s2b, "str");

    std::string s3 ("A character sequence"); // init with c-string
    EXPECT_EQ(s3, "A character sequence");
    std::string s3a ("A character sequence", 11); // init with first c-string 12 chars
    EXPECT_EQ(s3a, "A character");

    std::string s4 ("Another character sequence", 12); // init with first 12 symbols of c-string
    EXPECT_EQ(s4, "Another char");

    std::string s5a (10, 'x'); // init with 10 'x'
    EXPECT_EQ(s5a, "xxxxxxxxxx");
    std::string s5b (10, 42);      // 42 is the ASCII code for '*'
    EXPECT_EQ(s5b, "**********");

    std::string s6a (s0.begin(), s0.begin()+7); // 7 characters from begin pointer
    EXPECT_EQ(s6a, "Initial"); 
    std::string s6b (s0.begin(), s0.end()); // copy from begin to end
    EXPECT_EQ(s6b, "Initial string"); 

    std::string s7 = std::move(s0); // move constructor
    EXPECT_EQ(s7, "Initial string"); 
    EXPECT_EQ(s0, ""); 
}

TEST(StringTests, testPushBack) {
    std::string s0 {"Initial string"};
    s0.push_back('!');
    EXPECT_EQ(s0, "Initial string!");
}

TEST(StringTests, testSize) {
    std::string s0 {"Initial string of quite big size"};
    EXPECT_EQ(s0.size(), 32);
}

TEST(StringTests, testFind) {
    auto s0 = std::string("test string in C is still a string");
    
    EXPECT_EQ(s0.find('t'), 0); // find a character
    EXPECT_EQ(s0.find('t', 1), 3); // find a character from pos
    EXPECT_EQ(s0.find('z'), std::string::npos); // find a non-existent character

    EXPECT_EQ(s0.find("string"), 5); // find a const string
    EXPECT_EQ(s0.find("string", 15), 28); // find a const string from pos
    EXPECT_EQ(s0.find("strng"), std::string::npos); // find a non-existent const string
}

TEST(StringTests, testResize) {
    std::string s0 {"Resize test string in C"};
    s0.resize(18);
    EXPECT_EQ(s0, "Resize test string");

    std::string s1a {"Resize test string in C"}; // resize with defined const char
    s1a.resize(25, '+');
    EXPECT_EQ(s1a, "Resize test string in C++");
    
    std::string s1b {"Resize test string in C"}; // resize with char code
    s1b.resize(25, 112);
    EXPECT_EQ(s1b, "Resize test string in Cpp");
}

TEST(StringTests, testPopBack) {
    auto s0 = std::string("test string in C++");
    
    s0.pop_back();
    s0.pop_back();

    EXPECT_EQ(s0, "test string in C");
}

TEST(StringTests, testSwap) {
    auto s0 = std::string("test string in C++");
    auto s1 = std::string("kinda other string");

    s0.swap(s1);

    EXPECT_EQ(s0, "kinda other string");
    EXPECT_EQ(s1, "test string in C++");
}