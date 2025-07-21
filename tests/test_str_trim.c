#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test str_trim function
MU_TEST(test_str_trim_both_sides) {
    t_string *str = str_create("  hello world  ");
    str_trim(str);
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_left_only) {
    t_string *str = str_create("  hello world");
    str_trim(str);
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_right_only) {
    t_string *str = str_create("hello world  ");
    str_trim(str);
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_no_whitespace) {
    t_string *str = str_create("hello");
    str_trim(str);
    mu_assert_string_eq("hello", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_all_whitespace) {
    t_string *str = str_create("   ");
    str_trim(str);
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_empty_string) {
    t_string *str = str_create("");
    str_trim(str);
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_null_pointer) {
    // Should not crash
    str_trim(NULL);
    mu_check(1); // If we get here, the function handled NULL properly
}

MU_TEST(test_str_trim_mixed_whitespace) {
    t_string *str = str_create("\t\n  hello world \r\n\t ");
    str_trim(str);
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

// Test str_trim_left function
MU_TEST(test_str_trim_left_spaces) {
    t_string *str = str_create("   hello world");
    str_trim_left(str);
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_left_no_leading_spaces) {
    t_string *str = str_create("hello world   ");
    str_trim_left(str);
    mu_assert_string_eq("hello world   ", str->data);
    mu_assert_int_eq(14, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_left_all_spaces) {
    t_string *str = str_create("     ");
    str_trim_left(str);
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_left_empty) {
    t_string *str = str_create("");
    str_trim_left(str);
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_left_null) {
    // Should not crash
    str_trim_left(NULL);
    mu_check(1);
}

MU_TEST(test_str_trim_left_tabs_newlines) {
    t_string *str = str_create("\t\n\r  hello");
    str_trim_left(str);
    mu_assert_string_eq("hello", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

// Test str_trim_right function
MU_TEST(test_str_trim_right_spaces) {
    t_string *str = str_create("hello world   ");
    str_trim_right(str);
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_right_no_trailing_spaces) {
    t_string *str = str_create("   hello world");
    str_trim_right(str);
    mu_assert_string_eq("   hello world", str->data);
    mu_assert_int_eq(14, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_right_all_spaces) {
    t_string *str = str_create("     ");
    str_trim_right(str);
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_right_empty) {
    t_string *str = str_create("");
    str_trim_right(str);
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_right_null) {
    // Should not crash
    str_trim_right(NULL);
    mu_check(1);
}

MU_TEST(test_str_trim_right_tabs_newlines) {
    t_string *str = str_create("hello\t\n\r  ");
    str_trim_right(str);
    mu_assert_string_eq("hello", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

// Test str_trim_characters function
MU_TEST(test_str_trim_characters_basic) {
    t_string *str = str_create("abchello worldcba");
    str_trim_characters(str, "abc");
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_characters_left_only) {
    t_string *str = str_create("abchello world");
    str_trim_characters(str, "abc");
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_characters_right_only) {
    t_string *str = str_create("hello worldcba");
    str_trim_characters(str, "abc");
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_characters_no_match) {
    t_string *str = str_create("hello world");
    str_trim_characters(str, "xyz");
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_characters_all_match) {
    t_string *str = str_create("abcabc");
    str_trim_characters(str, "abc");
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_characters_empty_string) {
    t_string *str = str_create("");
    str_trim_characters(str, "abc");
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_characters_null_string) {
    // Should not crash
    str_trim_characters(NULL, "abc");
    mu_check(1);
}

MU_TEST(test_str_trim_characters_null_chars) {
    t_string *str = str_create("hello world");
    // Should not crash and not modify string
    str_trim_characters(str, NULL);
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_characters_single_char) {
    t_string *str = str_create("xxxhello worldxxx");
    str_trim_characters(str, "x");
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_trim_characters_overlapping) {
    t_string *str = str_create("abacbahello worldcbacaba");
    str_trim_characters(str, "abc");
    mu_assert_string_eq("hello world", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

// Test suites
MU_TEST_SUITE(test_suite_str_trim) {
    MU_RUN_TEST(test_str_trim_both_sides);
    MU_RUN_TEST(test_str_trim_left_only);
    MU_RUN_TEST(test_str_trim_right_only);
    MU_RUN_TEST(test_str_trim_no_whitespace);
    MU_RUN_TEST(test_str_trim_all_whitespace);
    MU_RUN_TEST(test_str_trim_empty_string);
    MU_RUN_TEST(test_str_trim_null_pointer);
    MU_RUN_TEST(test_str_trim_mixed_whitespace);
}

MU_TEST_SUITE(test_suite_str_trim_left) {
    MU_RUN_TEST(test_str_trim_left_spaces);
    MU_RUN_TEST(test_str_trim_left_no_leading_spaces);
    MU_RUN_TEST(test_str_trim_left_all_spaces);
    MU_RUN_TEST(test_str_trim_left_empty);
    MU_RUN_TEST(test_str_trim_left_null);
    MU_RUN_TEST(test_str_trim_left_tabs_newlines);
}

MU_TEST_SUITE(test_suite_str_trim_right) {
    MU_RUN_TEST(test_str_trim_right_spaces);
    MU_RUN_TEST(test_str_trim_right_no_trailing_spaces);
    MU_RUN_TEST(test_str_trim_right_all_spaces);
    MU_RUN_TEST(test_str_trim_right_empty);
    MU_RUN_TEST(test_str_trim_right_null);
    MU_RUN_TEST(test_str_trim_right_tabs_newlines);
}

MU_TEST_SUITE(test_suite_str_trim_characters) {
    MU_RUN_TEST(test_str_trim_characters_basic);
    MU_RUN_TEST(test_str_trim_characters_left_only);
    MU_RUN_TEST(test_str_trim_characters_right_only);
    MU_RUN_TEST(test_str_trim_characters_no_match);
    MU_RUN_TEST(test_str_trim_characters_all_match);
    MU_RUN_TEST(test_str_trim_characters_empty_string);
    MU_RUN_TEST(test_str_trim_characters_null_string);
    MU_RUN_TEST(test_str_trim_characters_null_chars);
    MU_RUN_TEST(test_str_trim_characters_single_char);
    MU_RUN_TEST(test_str_trim_characters_overlapping);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite_str_trim);
    MU_RUN_SUITE(test_suite_str_trim_left);
    MU_RUN_SUITE(test_suite_str_trim_right);
    MU_RUN_SUITE(test_suite_str_trim_characters);
    MU_REPORT();
    return MU_EXIT_CODE;
}
