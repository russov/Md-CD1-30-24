#include <gtest/gtest.h>
#include "String.h" 

TEST(StringTest, Constructors) {
    String empty_str;
    EXPECT_EQ(empty_str.size(), 0);
    EXPECT_STREQ(empty_str.c_str(), "");

    String cstr_str("Hello");
    EXPECT_EQ(cstr_str.size(), 5);
    EXPECT_STREQ(cstr_str.c_str(), "Hello");

    String repeat_str(5, 'a');
    EXPECT_EQ(repeat_str.size(), 5);
    EXPECT_STREQ(repeat_str.c_str(), "aaaaa");

    String copy_str(cstr_str);
    EXPECT_EQ(copy_str.size(), 5);
    EXPECT_STREQ(copy_str.c_str(), "Hello");
}

TEST(StringTest, PushBack) {
    String str("Test");
    str.push_back('!');
    EXPECT_EQ(str.size(), 5);
    EXPECT_STREQ(str.c_str(), "Test!");
}

TEST(StringTest, Size) {
    String str("Test");
    EXPECT_EQ(str.size(), 4);
    str.push_back('!');
    EXPECT_EQ(str.size(), 5);
}

TEST(StringTest, Find) {
    String str("Hello, world!");
    EXPECT_EQ(str.find('w'), 7);
    EXPECT_EQ(str.find('z'), String::npos);
    EXPECT_EQ(str.find("world"), 7);
}

TEST(StringTest, Substr) {
    String str("Hello, world!");
    String substr = str.substr(7, 5);
    EXPECT_EQ(substr.size(), 5);
    EXPECT_STREQ(substr.c_str(), "world");
}

TEST(StringTest, At) {
    String str("Hello");
    EXPECT_EQ(str.at(1), 'e');
    EXPECT_THROW(str.at(10), std::out_of_range);
}

TEST(StringTest, Append) {
    String str("Hello");
    str.append(", world!");
    EXPECT_EQ(str.size(), 13);
    EXPECT_STREQ(str.c_str(), "Hello, world!");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
