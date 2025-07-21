#include "./minunit/minunit.h"
#include "../Strings/strings.h"


// Test str_compare function

MU_TEST(test_str_compare_equal_strings) {
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("hello");
    int result = str_compare(str1, str2);
    mu_assert_int_eq(0, result); // Equal strings should return 0
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_first_less_than_second) {
    t_string *str1 = str_create("abc");
    t_string *str2 = str_create("def");
    int result = str_compare(str1, str2);
    mu_assert(result < 0, "First string should be less than second");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_first_greater_than_second) {
    t_string *str1 = str_create("xyz");
    t_string *str2 = str_create("abc");
    int result = str_compare(str1, str2);
    mu_assert(result > 0, "First string should be greater than second");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_different_lengths_prefix) {
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("hello world");
    int result = str_compare(str1, str2);
    mu_assert(result < 0, "Shorter string should be less than longer when prefix matches");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_different_lengths_prefix_reverse) {
    t_string *str1 = str_create("hello world");
    t_string *str2 = str_create("hello");
    int result = str_compare(str1, str2);
    mu_assert(result > 0, "Longer string should be greater than shorter when prefix matches");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_empty_strings) {
    t_string *str1 = str_create("");
    t_string *str2 = str_create("");
    int result = str_compare(str1, str2);
    mu_assert_int_eq(0, result); // Empty strings should be equal
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_empty_vs_non_empty) {
    t_string *str1 = str_create("");
    t_string *str2 = str_create("hello");
    int result = str_compare(str1, str2);
    mu_assert(result < 0, "Empty string should be less than non-empty");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_non_empty_vs_empty) {
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("");
    int result = str_compare(str1, str2);
    mu_assert(result > 0, "Non-empty string should be greater than empty");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_case_sensitive) {
    t_string *str1 = str_create("Hello");
    t_string *str2 = str_create("hello");
    int result = str_compare(str1, str2);
    mu_assert(result < 0, "Uppercase should be less than lowercase in ASCII");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_both_null) {
    int result = str_compare(NULL, NULL);
    mu_assert_int_eq(0, result); // Both NULL should be equal
}

MU_TEST(test_str_compare_first_null) {
    t_string *str2 = str_create("hello");
    int result = str_compare(NULL, str2);
    mu_assert_int_eq(-1, result); // First NULL should return -1
    str_deallocate(str2);
}

MU_TEST(test_str_compare_second_null) {
    t_string *str1 = str_create("hello");
    int result = str_compare(str1, NULL);
    mu_assert_int_eq(1, result); // Second NULL should return 1
    str_deallocate(str1);
}

MU_TEST(test_str_compare_single_character) {
    t_string *str1 = str_create("a");
    t_string *str2 = str_create("b");
    int result = str_compare(str1, str2);
    mu_assert(result < 0, "Character 'a' should be less than 'b'");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_numbers_as_strings) {
    t_string *str1 = str_create("123");
    t_string *str2 = str_create("456");
    int result = str_compare(str1, str2);
    mu_assert(result < 0, "String '123' should be less than '456'");
    str_deallocate(str1);
    str_deallocate(str2);
}

// Test str_compare_ignore_case function

MU_TEST(test_str_compare_ignore_case_equal_same_case) {
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("hello");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert_int_eq(0, result); // Equal strings should return 0
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_equal_different_case) {
    t_string *str1 = str_create("Hello");
    t_string *str2 = str_create("hello");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert_int_eq(0, result); // Case-insensitive comparison should return 0
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_mixed_case) {
    t_string *str1 = str_create("HeLLo WoRLd");
    t_string *str2 = str_create("hello world");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert_int_eq(0, result); // Mixed case should be equal when ignoring case
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_first_less_than_second) {
    t_string *str1 = str_create("ABC");
    t_string *str2 = str_create("def");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert(result < 0, "ABC should be less than def (case-insensitive)");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_first_greater_than_second) {
    t_string *str1 = str_create("XYZ");
    t_string *str2 = str_create("abc");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert(result > 0, "XYZ should be greater than abc (case-insensitive)");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_different_lengths) {
    t_string *str1 = str_create("HELLO");
    t_string *str2 = str_create("hello world");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert(result < 0, "Shorter string should be less when prefix matches (case-insensitive)");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_empty_strings) {
    t_string *str1 = str_create("");
    t_string *str2 = str_create("");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert_int_eq(0, result); // Empty strings should be equal
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_empty_vs_non_empty) {
    t_string *str1 = str_create("");
    t_string *str2 = str_create("HELLO");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert(result < 0, "Empty string should be less than non-empty");
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_both_null) {
    int result = str_compare_ignore_case(NULL, NULL);
    mu_assert_int_eq(0, result); // Both NULL should be equal
}

MU_TEST(test_str_compare_ignore_case_first_null) {
    t_string *str2 = str_create("HELLO");
    int result = str_compare_ignore_case(NULL, str2);
    mu_assert_int_eq(-1, result); // First NULL should return -1
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_second_null) {
    t_string *str1 = str_create("hello");
    int result = str_compare_ignore_case(str1, NULL);
    mu_assert_int_eq(1, result); // Second NULL should return 1
    str_deallocate(str1);
}

MU_TEST(test_str_compare_ignore_case_all_uppercase) {
    t_string *str1 = str_create("HELLO WORLD");
    t_string *str2 = str_create("HELLO WORLD");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert_int_eq(0, result); // Same uppercase strings should be equal
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_numbers_and_letters) {
    t_string *str1 = str_create("Test123");
    t_string *str2 = str_create("test123");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert_int_eq(0, result); // Numbers should not be affected by case comparison
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_compare_ignore_case_special_characters) {
    t_string *str1 = str_create("Hello@World!");
    t_string *str2 = str_create("hello@world!");
    int result = str_compare_ignore_case(str1, str2);
    mu_assert_int_eq(0, result); // Special characters should not be affected by case
    str_deallocate(str1);
    str_deallocate(str2);
}

// Comparative tests between both functions

MU_TEST(test_compare_vs_ignore_case_different_behavior) {
    t_string *str1 = str_create("Hello");
    t_string *str2 = str_create("hello");
    
    int case_sensitive = str_compare(str1, str2);
    int case_insensitive = str_compare_ignore_case(str1, str2);
    
    mu_assert(case_sensitive != 0, "Case-sensitive comparison should not be equal");
    mu_assert_int_eq(0, case_insensitive); // Case-insensitive should be equal
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_compare_vs_ignore_case_same_behavior) {
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("world");
    
    int case_sensitive = str_compare(str1, str2);
    int case_insensitive = str_compare_ignore_case(str1, str2);
    
    // Both should have same sign (both negative in this case)
    mu_assert((case_sensitive < 0 && case_insensitive < 0), "Both comparisons should have same result for same-case strings");
    
    str_deallocate(str1);
    str_deallocate(str2);
}

// Test suite

MU_TEST_SUITE(test_string_compare_functions) {
    // str_compare tests
    MU_RUN_TEST(test_str_compare_equal_strings);
    MU_RUN_TEST(test_str_compare_first_less_than_second);
    MU_RUN_TEST(test_str_compare_first_greater_than_second);
    MU_RUN_TEST(test_str_compare_different_lengths_prefix);
    MU_RUN_TEST(test_str_compare_different_lengths_prefix_reverse);
    MU_RUN_TEST(test_str_compare_empty_strings);
    MU_RUN_TEST(test_str_compare_empty_vs_non_empty);
    MU_RUN_TEST(test_str_compare_non_empty_vs_empty);
    MU_RUN_TEST(test_str_compare_case_sensitive);
    MU_RUN_TEST(test_str_compare_both_null);
    MU_RUN_TEST(test_str_compare_first_null);
    MU_RUN_TEST(test_str_compare_second_null);
    MU_RUN_TEST(test_str_compare_single_character);
    MU_RUN_TEST(test_str_compare_numbers_as_strings);
    
    // str_compare_ignore_case tests
    MU_RUN_TEST(test_str_compare_ignore_case_equal_same_case);
    MU_RUN_TEST(test_str_compare_ignore_case_equal_different_case);
    MU_RUN_TEST(test_str_compare_ignore_case_mixed_case);
    MU_RUN_TEST(test_str_compare_ignore_case_first_less_than_second);
    MU_RUN_TEST(test_str_compare_ignore_case_first_greater_than_second);
    MU_RUN_TEST(test_str_compare_ignore_case_different_lengths);
    MU_RUN_TEST(test_str_compare_ignore_case_empty_strings);
    MU_RUN_TEST(test_str_compare_ignore_case_empty_vs_non_empty);
    MU_RUN_TEST(test_str_compare_ignore_case_both_null);
    MU_RUN_TEST(test_str_compare_ignore_case_first_null);
    MU_RUN_TEST(test_str_compare_ignore_case_second_null);
    MU_RUN_TEST(test_str_compare_ignore_case_all_uppercase);
    MU_RUN_TEST(test_str_compare_ignore_case_numbers_and_letters);
    MU_RUN_TEST(test_str_compare_ignore_case_special_characters);
    
    // Comparative tests
    MU_RUN_TEST(test_compare_vs_ignore_case_different_behavior);
    MU_RUN_TEST(test_compare_vs_ignore_case_same_behavior);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_string_compare_functions);
    MU_REPORT();
    return MU_EXIT_CODE;
}
