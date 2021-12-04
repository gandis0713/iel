#include "gtest/gtest.h"

#include <memory>

#include "../../src/inc/std/String.h"
#define NS _IEL_NAME_SPACE_
#define SPEC TEST

#include <iostream>

// TODO : define string spec.

SPEC(string, empty_constructor) {
    // EXPECT_EQ (0, 0);
    // EXPECT_EQ (true, true);
    // EXPECT_NE (true, false);
    // getNSString();
    NS::String();
}

SPEC(string, const_char_constructor) {
    NS::String("1234abcd");
}

SPEC(string, copy_constructor) {
    NS::String str1 = NS::String("1234abcd");
    NS::String str2 = str1;
    EXPECT_EQ (str2, str1);
}

SPEC(string, copy_assignment) {
    NS::String str1 = NS::String("1234");
    NS::String str2 = NS::String("abcd1234");
    str2 = str1;
    EXPECT_EQ (str2, str1);
}

SPEC(string, plus_assignment) {
    NS::String str1 = NS::String("1234");
    NS::String str2 = NS::String("abcd1234");
    NS::String str3 = str1 + str2;

    EXPECT_EQ (str3, "1234abcd1234");
}

SPEC(string, strlen) {
    const char* str1 = "abcd";
    EXPECT_EQ (NS::strlen(str1), strlen(str1));
    const char* str2 = "";
    EXPECT_EQ (NS::strlen(str2), strlen(str2));
    const char* str3 = "\a\n";
    EXPECT_EQ (NS::strlen(str3), strlen(str3));
    const char* str4 = "<>?/~!@#$%^&*()_+-=";
    EXPECT_EQ (NS::strlen(str4), strlen(str4));
}