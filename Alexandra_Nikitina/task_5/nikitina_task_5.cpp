#include <gtest/gtest.h>
#include "NewString.h"


TEST(StrConstructor, Default) {
    NewString str{};
    NewString emptyString;
    EXPECT_EQ(str, emptyString);
}

TEST(StrConstructor, Copy){
    NewString str = "1";
    NewString copystr = str;
    EXPECT_EQ(copystr, "1");
}

TEST(StrConstructor, SubString){
    NewString str = "Cat likes milk";
    NewString substr (str, 10, 4);
    EXPECT_EQ(substr, "milk");
}

TEST(StrConstructor, FromCString){
    NewString str("a");
    EXPECT_EQ(str, "a");
}

TEST(StrConstructor, FromBuffer){
    NewString str('abcdef', 3);
    EXPECT_EQ(str, "abc");
}

TEST(StrConstructor, Fill){
    NewString str(13, 'y');
    EXPECT_EQ(str, "yyyyyyyyyyyyy");
}

TEST(StrConstructor, InitializerList){
    std::initializer_list<char> ch = {'a', 'b', 'c', 'd', 'e', 'f'};
    NewString str(ch);
    EXPECT_EQ(str, "abcdef");
}

TEST(StrConstructor, Move){
    NewString &&str = "wow";
    NewString movestr(str);
    EXPECT_EQ(movestr, "wow");
}

TEST(StrPushBackTest, PushBackTwoSymbols){
    NewString str = "a";
    str.push_back('b');
    EXPECT_EQ(str, "ab");
}

TEST(StrPushBackTest, PushBackEmptiness){
    NewString str = "";
    str.push_back(' ');
    EXPECT_EQ(str, " ");
}

TEST(StrSizeTest, SizeZero){
    NewString str = "";
    EXPECT_EQ(str.size(), 0);
}

TEST(StrSizeTest, SizeFive){
    NewString str = "12345";
    EXPECT_EQ(str.size(), 5);
}

TEST(StrFindTest, FindFromRepeated){
    NewString str = "death death death";
    EXPECT_EQ( str.find("th") , 3);
}

TEST(StrBackTest, Last){
    NewString str = "have a good day.";
    str.back();
    EXPECT_EQ(str, "have a good day");
}

TEST(StrClearTest, ClearString){
    NewString str = "abcdefg";
    str.clear();
    EXPECT_EQ(str, "");
}




