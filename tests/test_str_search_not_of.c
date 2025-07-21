#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test str_find_first_not_of function

MU_TEST(test_str_find_first_not_of_normal_case) {
    t_string *str = str_create("hello world");
    int result = str_find_first_not_of(str, "hel", 0);
    mu_assert_int_eq(3, result); // 'l' at position 3 should be the first char not in "hel"
    str_deallocate(str);
}

MU_TEST(test_str_find_first_not_of_no_match) {
    t_string *str = str_create("hello");
    int result = str_find_first_not_of(str, "helo", 0);
    mu_assert_int_eq(-1, result); // All characters are in the buffer
    str_deallocate(str);
}

MU_TEST(test_str_find_first_not_of_first_char) {
    t_string *str = str_create("abcde");
    int result = str_find_first_not_of(str, "xyz", 0);
    mu_assert_int_eq(0, result); // First character 'a' is not in "xyz"
    str_deallocate(str);
}

MU_TEST(test_str_find_first_not_of_with_spaces) {
    t_string *str = str_create("   hello");
    int result = str_find_first_not_of(str, " ", 0);
    mu_assert_int_eq(3, result); // First non-space character at position 3
    str_deallocate(str);
}

MU_TEST(test_str_find_first_not_of_empty_string) {
    t_string *str = str_create("");
    int result = str_find_first_not_of(str, "abc", 0);
    mu_assert_int_eq(-1, result); // Empty string should return -1
    str_deallocate(str);
}

MU_TEST(test_str_find_first_not_of_null_str) {
    int result = str_find_first_not_of(NULL, "abc", 0);
    mu_assert_int_eq(-1, result); // NULL string should return -1
}

MU_TEST(test_str_find_first_not_of_null_buffer) {
    t_string *str = str_create("hello");
    int result = str_find_first_not_of(str, NULL, 0);
    mu_assert_int_eq(-1, result); // NULL buffer should return -1
    str_deallocate(str);
}

MU_TEST(test_str_find_first_not_of_empty_buffer) {
    t_string *str = str_create("hello");
    int result = str_find_first_not_of(str, "", 0);
    mu_assert_int_eq(-1, result); // Empty buffer should return -1
    str_deallocate(str);
}

MU_TEST(test_str_find_first_not_of_pos_out_of_bounds) {
    t_string *str = str_create("hello");
    int result = str_find_first_not_of(str, "abc", 10);
    mu_assert_int_eq(-1, result); // Position beyond string length should return -1
    str_deallocate(str);
}

MU_TEST(test_str_find_first_not_of_single_char) {
    t_string *str = str_create("a");
    int result = str_find_first_not_of(str, "b", 0);
    mu_assert_int_eq(0, result); // Single char not in buffer
    str_deallocate(str);
}

// Test str_find_last_not_of function

MU_TEST(test_str_find_last_not_of_normal_case) {
    t_string *str = str_create("hello world");
    int result = str_find_last_not_of(str, "drl", str->size - 1);
    mu_assert_int_eq(9, result); // 'o' at position 9 should be the last char not in "drl"
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_no_match) {
    t_string *str = str_create("hello");
    int result = str_find_last_not_of(str, "helo", str->size - 1);
    mu_assert_int_eq(-1, result); // All characters are in the buffer
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_last_char) {
    t_string *str = str_create("abcde");
    int result = str_find_last_not_of(str, "xyz", str->size - 1);
    mu_assert_int_eq(4, result); // Last character 'e' is not in "xyz"
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_with_trailing_spaces) {
    t_string *str = str_create("hello   ");
    int result = str_find_last_not_of(str, " ", str->size - 1);
    mu_assert_int_eq(4, result); // Last non-space character at position 4
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_empty_string) {
    t_string *str = str_create("");
    int result = str_find_last_not_of(str, "abc", 0);
    mu_assert_int_eq(-1, result); // Empty string should return -1
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_null_str) {
    int result = str_find_last_not_of(NULL, "abc", 0);
    mu_assert_int_eq(-1, result); // NULL string should return -1
}

MU_TEST(test_str_find_last_not_of_null_buffer) {
    t_string *str = str_create("hello");
    int result = str_find_last_not_of(str, NULL, str->size - 1);
    mu_assert_int_eq(-1, result); // NULL buffer should return -1
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_empty_buffer) {
    t_string *str = str_create("hello");
    int result = str_find_last_not_of(str, "", str->size - 1);
    mu_assert_int_eq(-1, result); // Empty buffer should return -1
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_pos_out_of_bounds) {
    t_string *str = str_create("hello");
    int result = str_find_last_not_of(str, "abc", 100);
    mu_assert_int_eq(4, result); // Should clamp to size-1 and find last non-matching char
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_single_char) {
    t_string *str = str_create("a");
    int result = str_find_last_not_of(str, "b", 0);
    mu_assert_int_eq(0, result); // Single char not in buffer
    str_deallocate(str);
}

MU_TEST(test_str_find_last_not_of_first_char_match) {
    t_string *str = str_create("abcde");
    int result = str_find_last_not_of(str, "abcd", str->size - 1);
    mu_assert_int_eq(4, result); // Only 'e' is not in "abcd"
    str_deallocate(str);
}

// Edge case tests

MU_TEST(test_both_functions_with_special_chars) {
    t_string *str = str_create("a@b#c$");
    
    int first_result = str_find_first_not_of(str, "a@", 0);
    mu_assert_int_eq(2, first_result); // 'b' at position 2
    
    int last_result = str_find_last_not_of(str, "$c", str->size - 1);
    mu_assert_int_eq(3, last_result); // '#' at position 3
    
    str_deallocate(str);
}

MU_TEST(test_both_functions_with_repeating_chars) {
    t_string *str = str_create("aaabbbccc");
    
    int first_result = str_find_first_not_of(str, "a", 0);
    mu_assert_int_eq(3, first_result); // First 'b' at position 3
    
    int last_result = str_find_last_not_of(str, "c", str->size - 1);
    mu_assert_int_eq(5, last_result); // Last 'b' at position 5
    
    str_deallocate(str);
}

// Test suite

MU_TEST_SUITE(test_string_search_functions) {
    MU_RUN_TEST(test_str_find_first_not_of_normal_case);
    MU_RUN_TEST(test_str_find_first_not_of_no_match);
    MU_RUN_TEST(test_str_find_first_not_of_first_char);
    MU_RUN_TEST(test_str_find_first_not_of_with_spaces);
    MU_RUN_TEST(test_str_find_first_not_of_empty_string);
    MU_RUN_TEST(test_str_find_first_not_of_null_str);
    MU_RUN_TEST(test_str_find_first_not_of_null_buffer);
    MU_RUN_TEST(test_str_find_first_not_of_empty_buffer);
    MU_RUN_TEST(test_str_find_first_not_of_pos_out_of_bounds);
    MU_RUN_TEST(test_str_find_first_not_of_single_char);
    
    MU_RUN_TEST(test_str_find_last_not_of_normal_case);
    MU_RUN_TEST(test_str_find_last_not_of_no_match);
    MU_RUN_TEST(test_str_find_last_not_of_last_char);
    MU_RUN_TEST(test_str_find_last_not_of_with_trailing_spaces);
    MU_RUN_TEST(test_str_find_last_not_of_empty_string);
    MU_RUN_TEST(test_str_find_last_not_of_null_str);
    MU_RUN_TEST(test_str_find_last_not_of_null_buffer);
    MU_RUN_TEST(test_str_find_last_not_of_empty_buffer);
    MU_RUN_TEST(test_str_find_last_not_of_pos_out_of_bounds);
    MU_RUN_TEST(test_str_find_last_not_of_single_char);
    MU_RUN_TEST(test_str_find_last_not_of_first_char_match);
    
    MU_RUN_TEST(test_both_functions_with_special_chars);
    MU_RUN_TEST(test_both_functions_with_repeating_chars);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_string_search_functions);
    MU_REPORT();
    return MU_EXIT_CODE;
}
