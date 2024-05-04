#include <gtest/gtest.h>
#include <string>



//constructors
TEST(StrConstructor, Default){
    std::string str = "";
    EXPECT_EQ(str, "");
}

TEST(StrConstructor, Copy){
    std::string str = "1";
    std::string copystr = str;
    EXPECT_EQ(copystr, "1");
}

TEST(StrConstructor, SubString){
    std::string str = "Cat likes milk";
    std::string substr (str, 10, 4);
    EXPECT_EQ(substr, "milk");
}

TEST(StrConstructor, FromCString){
    char* ch = "a";
    std::string str(ch);
    EXPECT_EQ(str, "a");
}

TEST(StrConstructor, FromBuffer){
    char* ch = "abcdef";
    std::string str(ch, 3);
    EXPECT_EQ(str, "abc");
}

TEST(StrConstructor, Fill){
    std::string str(13, 'y');
    EXPECT_EQ(str, "yyyyyyyyyyyyy");
}

TEST(StrConstructor, Range){
    std::string str("No food is better than our food");
    std::string rangestr(str.begin(), str.end() - 24);
    EXPECT_EQ(rangestr, "No food");
}

TEST(StrConstructor, InitializerList){
    std::initializer_list<char> ch = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::string str(ch);
    EXPECT_EQ(str, "abcdef");
}

TEST(StrConstructor, Move){
    std::string &&str = "wow";
    std::string movestr(str);
    EXPECT_EQ(movestr, "wow");
}



//push_back()
TEST(StrPushBackTest, PushBackTwoSymbols){
    std::string str = "a";
    str.push_back('b');
    EXPECT_EQ(str, "ab");
}

TEST(StrPushBackTest, NotPushBack){
    std::string str = "abc";
    str.push_back('d');
    EXPECT_NE(str, "abc");
}

TEST(StrPushBackTest, PushBackEmptiness){
    std::string str = "";
    str.push_back(' ');
    EXPECT_EQ(str, " ");
}


//size()
TEST(StrSizeTest, SizeZero){
    std::string str = "";
    EXPECT_EQ(str.size(), 0);
}

TEST(StrSizeTest, SizeFive){
    std::string str = "12345";
    EXPECT_EQ(str.size(), 5);
}


//find()
TEST(StrFindTest, FindFirst){
    std::string str = "My dear friend";
    EXPECT_EQ( str.find("My") , 0);
}

TEST(StrFindTest, FindFromRepeated){
    std::string str = "death death death";
    EXPECT_EQ( str.find("th") , 3);
}

TEST(StrFindTest, FindSecondRepeated){
    std::string str = "death death death";
    EXPECT_EQ( str.find("th", 7) , 9);
}

TEST(StrFindTest, FindPartWord){
    std::string str = "My dear friend";
    EXPECT_EQ(str.find("fruit", 3, 2) , 8);
}

TEST(StrFindTest, FindNotExist){
    std::string str = "My dear friend";
    EXPECT_EQ( str.find("cats"), 18446744073709551615);
}

TEST(StrFindTest, FindChar){
    std::string str =  "cat";
    EXPECT_EQ(str.find('t'), 2);
}

TEST(StrFindTest, CString){
    char* ch = "cat";
    std::string str = ch;
    EXPECT_EQ(str.find("t"), 2);
}

TEST(StrFindTest, CStringFindSecondRepeated){
    char* ch = "death death death";
    std::string str = ch;
    EXPECT_EQ( str.find("th", 7) , 9);
}

TEST(StrFindTest, CStringFindPartWord){
    char* ch = "My dear friend";
    std::string str = ch;
    EXPECT_EQ(str.find("fruit", 3, 2) , 8);
}


//append
TEST(StrAppendTest, AppendString){
    std::string str1 = "abc";
    std::string str2 = "def";
    EXPECT_EQ(str1.append(str2), "abcdef");
}

TEST(StrAppendTest, AppendNothing){
    std::string str1 = "";
    std::string str2 = "";
    EXPECT_EQ(str1.append(str2), "");
}

TEST(StrAppendTest, AppendPartString){
    std::string str1 = "abc";
    std::string str2 = "def9999";
    EXPECT_EQ(str1.append(str2, 0, 3), "abcdef");
}

TEST(StrAppendTest, AppendCString){
    std::string str1 = "cat";
    char* ch = " are walking";
    std::string str2 = ch;
    EXPECT_EQ(str1.append(str2), "cat are walking");
}

TEST(StrAppendTest, AppendPartCString){
    std::string str1 = "cat";
    char* ch = " are walking :)";
    std::string str2 = ch;
    EXPECT_EQ(str1.append(str2, 0, 12), "cat are walking");
}

TEST(StrAppendTest, AppendFill){
    std::string str = "abc";
    EXPECT_EQ(str.append(9, 'c'), "abcccccccccc");
}

TEST(StrAppendTest, AppendRange){
    std::string str = "No ";
    std::string str2("food is the best invention of mankind");
    str.append(str2.begin(), str2.end() - 33);
    EXPECT_EQ(str, "No food");
}

TEST(StrAppendTest, AppendInitializerList){
    std::string str = "alphabet: ";
    std::initializer_list<char> ch = {'a', 'b', 'c', 'd', 'e', 'f', '.', '.'};

    EXPECT_EQ(str.append(ch), "alphabet: abcdef..");
}


//back
TEST(StrBackTest, ChangeLast){
    std::string str = "have a good day.";
    str.back() = ')';
    EXPECT_EQ(str, "have a good day)");
}

TEST(StrBackTest, CStringChangeLast){
    char* ch = "have a good day.";
    std::string str = ch;
    str.back() = ')';
    EXPECT_EQ(str, "have a good day)");
}


//clear
TEST(StrClearTest, ClearString){
    std::string str = "abcdefg";
    str.clear();
    EXPECT_EQ(str, "");
}

TEST(StrClearTest, ClearCString){
    char* ch = "abcdefg";
    std::string str = ch;
    str.clear();
    EXPECT_EQ(str, "");
}




