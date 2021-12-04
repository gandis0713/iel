#include "gtest/gtest.h"

#include "../../src/inc/std/String.h"

#define NS IEL_NAME_SPACE

TEST(string, empty_constructor) {
    NS::String str = NS::String();
    EXPECT_EQ (str, "");
}

TEST(string, const_char_constructor) {
    NS::String str = NS::String("1234abcd");
    EXPECT_EQ (str, "1234abcd");
}

TEST(string, copy_constructor) {
    NS::String str1 = NS::String("1234abcd");
    NS::String str2 = str1;
    EXPECT_EQ (str2, str1);
}

TEST(string, copy_assignment) {
    NS::String str1 = NS::String("1234");
    NS::String str2 = NS::String("abcd1234");
    str2 = str1;
    EXPECT_EQ (str2, str1);
}

TEST(string, plus_assignment) {
    NS::String str1 = NS::String("1234");
    NS::String str2 = NS::String("abcd1234");
    NS::String str3 = str1 + str2;

    EXPECT_EQ (str3, "1234abcd1234");
}

TEST(string, strlen) {
    const char* str1 = "abcd";
    EXPECT_EQ (NS::strlen(str1), strlen(str1));
    const char* str2 = "";
    EXPECT_EQ (NS::strlen(str2), strlen(str2));
    const char* str3 = "\a\n";
    EXPECT_EQ (NS::strlen(str3), strlen(str3));
    const char* str4 = "<>?/~!@#$%^&*()_+-=";
    EXPECT_EQ (NS::strlen(str4), strlen(str4));
}