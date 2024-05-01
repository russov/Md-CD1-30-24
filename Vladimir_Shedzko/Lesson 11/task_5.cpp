#include "gtest/gtest.h"
#include <string>

TEST(StringTests, testConstructor) {
    std::string s0 {"Initial string"};

    std::string s1; // init with empty string
    ASSERT_EQ(s1, "");
    std::string s2 (s0); // init with copy of other string
    ASSERT_EQ(s2, s0);
    std::string s3 (s0, 8, 3); // init with substring from pos 8 of size 3
    ASSERT_EQ(s3, "str");
    std::string s4 ("A character sequence"); // init with c-string
    ASSERT_EQ(s4, "A character sequence");
    std::string s5 ("Another character sequence", 12); // init with first 12 symbols of c-string
    ASSERT_EQ(s5, "Another char");
    std::string s6a (10, 'x'); // init with 10 'x'
    ASSERT_EQ(s6a, "xxxxxxxxxx");
    std::string s6b (10, 42);      // 42 is the ASCII code for '*'
    ASSERT_EQ(s6b, "**********");
    std::string s7 (s0.begin(), s0.begin()+7);
    ASSERT_EQ(s7, "Initial"); // first 7 characters

    // ASSERT_THROW(std::string s7a (s0.begin(), s0.begin()+70), std::out_of_range);
}
TEST(StringTests, testPushBack) {
    std::string s0 {"Initial string"};
    s0.push_back('!');
    ASSERT_EQ(s0, "Initial string!");

    std::string s1 {'*'};
    long long max_bits {64};
    for (int i=0; i < max_bits; i++)
        s1+=s1;
    
    // ASSERT_THROW(s1.push_back('*'), std::length_error);
}