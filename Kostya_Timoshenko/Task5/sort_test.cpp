#include "pch.h"
#include "MyClass.h"

//sort
TEST(MyClassTest, Sort) {
    std::vector<MyClass> OriginStrings = { "Today", "Task", "Is", "The", "Hardest", "Ever"};
    std::sort(OriginStrings.begin(), OriginStrings.end());
    EXPECT_EQ("Ever", OriginStrings[0]);
    EXPECT_EQ("Hardest", OriginStrings[1]);
    EXPECT_EQ("Is", OriginStrings[2]);
    EXPECT_EQ("Task", OriginStrings[3]);
    EXPECT_EQ("The", OriginStrings[4]);
    EXPECT_EQ("Today", OriginStrings[5]);
}