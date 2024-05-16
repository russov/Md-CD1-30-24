#include "pch.h"
#include "MyClass.h"

// pop_back

TEST(PopBackStringTest, PopBackNonEmptyString) {
    MyClass OriginString("Task");
    OriginString.pop_back();
    EXPECT_EQ("Tas", OriginString);
}

TEST(PopBackStringTest, PopBackCharString) {
    MyClass OriginString("H");
    OriginString.pop_back();
    EXPECT_EQ("", OriginString);
}

TEST(PopBackStringTest, PopBackEmptyString) {
    MyClass OriginString;
    OriginString.pop_back(); 
    EXPECT_EQ("", OriginString);
}

TEST(PopBackStringTest, PopBackMoreString) {
    MyClass OriginString("Task");
    OriginString.pop_back();
    OriginString.pop_back();
    EXPECT_EQ("Ta", OriginString);
}

TEST(PopBackStringTest, PopBackFullDeleteString) {
    MyClass OriginString("Task");
    for (int i = 0; i < 4; ++i) {
        OriginString.pop_back();
    }
    EXPECT_EQ("", OriginString);
}