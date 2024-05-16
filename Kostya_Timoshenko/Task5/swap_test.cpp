#include "pch.h"
#include "MyClass.h"

// swap
TEST(SwapStringTest, SwapEmptyString) { 
    MyClass OriginString("Task");
    MyClass NewString;
    OriginString.swap(NewString);
    EXPECT_EQ(0, OriginString.size());
    EXPECT_EQ("Task", NewString);
}

TEST(SwapStringTest, SwapNonEmptyString) {
    MyClass OriginString("Task");
    MyClass NewString("Today");
    OriginString.swap(NewString);
    EXPECT_EQ("Today", OriginString);
    EXPECT_EQ("Task", NewString);
}

TEST(SwapStringTest, SwapSelfString) {
    MyClass OriginString("Task");
    OriginString.swap(OriginString);
    EXPECT_EQ("Task", OriginString);
}

TEST(SwapStringTest, SwapAfterPushBackString) {
    MyClass OriginString("Task");
    MyClass NewString("Today");
    OriginString.push_back('!');
    NewString.push_back('?');
    OriginString.swap(NewString);
    EXPECT_EQ("Today?", OriginString);
    EXPECT_EQ("Task!", NewString);
}

TEST(SwapStringTest, SwapAfterClearString) {
    MyClass OriginString("Task");
    MyClass NewString("Today?");
    OriginString.clear();
    OriginString.swap(NewString);
    EXPECT_EQ(6, OriginString.size());
    EXPECT_EQ(0, NewString.size());
}