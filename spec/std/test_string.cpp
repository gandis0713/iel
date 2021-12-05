#include "gtest/gtest.h"

#include "../../src/inc/std/string.h"

namespace iel = IEL_NAME_SPACE;

TEST(spec_string, empty_constructor) {
    iel::String str = iel::String();
    EXPECT_EQ (str, "");
}

TEST(spec_string, const_char_constructor) {
    iel::String str = iel::String("1234abcd");
    EXPECT_EQ (str, "1234abcd");
}

TEST(spec_string, copy_constructor) {
    iel::String str = "\0";
    EXPECT_EQ (str.size(), 0);
    iel::String str1 = iel::String("1234abcd");
    iel::String str2 = str1;
    EXPECT_EQ (str2, str1);
}

TEST(spec_string, copy_assignment) {
    iel::String str1 = iel::String("1234");
    iel::String str2 = iel::String("abcd1234");
    str2 = str1;
    EXPECT_EQ (str2, str1);
}

TEST(spec_string, plus_assignment) {
    iel::String str1 = iel::String("1234");
    iel::String str2 = iel::String("abcd1234");
    iel::String str3 = str1 + str2;

    EXPECT_EQ (str3, "1234abcd1234");
}

TEST(spec_string, equal_operator) {
    iel::String str = iel::String("1234");
    EXPECT_EQ (str, "1234");
    EXPECT_EQ (str, "1234\0");
    str = "\0";
    EXPECT_EQ (str, "");
    EXPECT_EQ (str, "\0");
}

TEST(spec_string, not_equal_operator) {
    iel::String str = iel::String("1234");
    EXPECT_NE (str, "123");
}

TEST(spec_string, index_operator) {
    iel::String str = iel::String("1234");
    EXPECT_EQ (str[0], '1');
    EXPECT_EQ (str[1], '2');
    EXPECT_EQ (str[2], '3');
    EXPECT_EQ (str[3], '4');
}

TEST(spec_string, strlen) {
    const char* str1 = "abcd";
    EXPECT_EQ (iel::strlen(str1), strlen(str1));
    const char* str2 = "";
    EXPECT_EQ (iel::strlen(str2), strlen(str2));
    const char* str3 = "\a\n";
    EXPECT_EQ (iel::strlen(str3), strlen(str3));
    const char* str4 = "<>?/~!@#$%^&*()_+-=";
    EXPECT_EQ (iel::strlen(str4), strlen(str4));
}