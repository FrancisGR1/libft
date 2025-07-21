#include "../Strings/strings.h"
#include "minunit/minunit.h"

// Tests for str_find function
MU_TEST(test_str_find_basic) {
    t_string *str = str_create("hello world hello");
    
    int result = str_find(str, "world", 0);
    mu_assert_int_eq(6, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_from_position) {
    t_string *str = str_create("hello world hello");
    
    int result = str_find(str, "hello", 7);
    mu_assert_int_eq(12, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_not_found) {
    t_string *str = str_create("hello world");
    
    int result = str_find(str, "xyz", 0);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_at_beginning) {
    t_string *str = str_create("hello world");
    
    int result = str_find(str, "hello", 0);
    mu_assert_int_eq(0, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_at_end) {
    t_string *str = str_create("hello world");
    
    int result = str_find(str, "world", 0);
    mu_assert_int_eq(6, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_single_char) {
    t_string *str = str_create("hello");
    
    int result = str_find(str, "l", 0);
    mu_assert_int_eq(2, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_pos_out_of_bounds) {
    t_string *str = str_create("hello");
    
    int result = str_find(str, "o", 10);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_null_inputs) {
    t_string *str = str_create("hello");
    
    mu_assert_int_eq(-1, str_find(NULL, "hello", 0));
    mu_assert_int_eq(-1, str_find(str, NULL, 0));
    
    str_deallocate(str);
}

// Tests for str_rfind function
MU_TEST(test_str_rfind_basic) {
    t_string *str = str_create("hello world hello");
    
    int result = str_rfind(str, "hello", 16);
    mu_assert_int_eq(12, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_rfind_first_occurrence) {
    t_string *str = str_create("hello world hello");
    
    int result = str_rfind(str, "hello", 10);
    mu_assert_int_eq(0, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_rfind_not_found) {
    t_string *str = str_create("hello world");
    
    int result = str_rfind(str, "xyz", 10);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_rfind_single_char) {
    t_string *str = str_create("hello");
    
    int result = str_rfind(str, "l", 4);
    mu_assert_int_eq(3, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_rfind_at_beginning) {
    t_string *str = str_create("hello world");
    
    int result = str_rfind(str, "hello", 10);
    mu_assert_int_eq(0, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_rfind_pos_too_small) {
    t_string *str = str_create("hello world");
    
    int result = str_rfind(str, "hello", 3);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_rfind_empty_pattern) {
    t_string *str = str_create("hello");
    
    int result = str_rfind(str, "", 4);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_rfind_null_inputs) {
    t_string *str = str_create("hello");
    
    mu_assert_int_eq(-1, str_rfind(NULL, "hello", 0));
    mu_assert_int_eq(-1, str_rfind(str, NULL, 0));
    
    str_deallocate(str);
}

// Tests for str_find_first_of function
MU_TEST(test_str_find_first_of_basic) {
    t_string *str = str_create("hello world hello");
    
    int result = str_find_first_of(str, "world", 0);
    mu_assert_int_eq(6, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_first_of_from_position) {
    t_string *str = str_create("hello world hello");
    
    int result = str_find_first_of(str, "hello", 7);
    mu_assert_int_eq(12, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_first_of_not_found) {
    t_string *str = str_create("hello world");
    
    int result = str_find_first_of(str, "xyz", 0);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_first_of_at_beginning) {
    t_string *str = str_create("hello world");
    
    int result = str_find_first_of(str, "hello", 0);
    mu_assert_int_eq(0, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_first_of_pos_out_of_bounds) {
    t_string *str = str_create("hello");
    
    int result = str_find_first_of(str, "o", 10);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_first_of_null_inputs) {
    t_string *str = str_create("hello");
    
    mu_assert_int_eq(-1, str_find_first_of(NULL, "hello", 0));
    mu_assert_int_eq(-1, str_find_first_of(str, NULL, 0));
    
    str_deallocate(str);
}

// Tests for str_find_last_of function
MU_TEST(test_str_find_last_of_basic) {
    t_string *str = str_create("hello world hello");
    
    int result = str_find_last_of(str, "hello", 16);
    mu_assert_int_eq(12, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_last_of_within_range) {
    t_string *str = str_create("hello world hello");
    
    int result = str_find_last_of(str, "hello", 10);
    mu_assert_int_eq(0, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_last_of_not_found) {
    t_string *str = str_create("hello world");
    
    int result = str_find_last_of(str, "xyz", 10);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_last_of_single_occurrence) {
    t_string *str = str_create("hello world");
    
    int result = str_find_last_of(str, "world", 10);
    mu_assert_int_eq(6, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_last_of_multiple_occurrences) {
    t_string *str = str_create("test test test");
    
    int result = str_find_last_of(str, "test", 13);
    mu_assert_int_eq(10, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_last_of_at_beginning) {
    t_string *str = str_create("hello world hello");
    
    int result = str_find_last_of(str, "hello", 4);
    mu_assert_int_eq(0, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_last_of_pos_out_of_bounds) {
    t_string *str = str_create("hello");
    
    int result = str_find_last_of(str, "hello", 10);
    mu_assert_int_eq(-1, result);
    
    str_deallocate(str);
}

MU_TEST(test_str_find_last_of_null_inputs) {
    t_string *str = str_create("hello");
    
    mu_assert_int_eq(-1, str_find_last_of(NULL, "hello", 0));
    mu_assert_int_eq(-1, str_find_last_of(str, NULL, 0));
    
    str_deallocate(str);
}

// Edge case tests
MU_TEST(test_all_functions_empty_string) {
    t_string *str = str_create("");
    
    mu_assert_int_eq(-1, str_find(str, "test", 0));
    mu_assert_int_eq(-1, str_rfind(str, "test", 0));
    mu_assert_int_eq(-1, str_find_first_of(str, "test", 0));
    mu_assert_int_eq(-1, str_find_last_of(str, "test", 0));
    
    str_deallocate(str);
}

MU_TEST(test_all_functions_pattern_longer_than_string) {
    t_string *str = str_create("hi");
    
    mu_assert_int_eq(-1, str_find(str, "hello", 0));
    mu_assert_int_eq(-1, str_rfind(str, "hello", 1));
    mu_assert_int_eq(-1, str_find_first_of(str, "hello", 0));
    mu_assert_int_eq(-1, str_find_last_of(str, "hello", 1));
    
    str_deallocate(str);
}

// Test suites
MU_TEST_SUITE(test_str_find_suite) {
    MU_RUN_TEST(test_str_find_basic);
    MU_RUN_TEST(test_str_find_from_position);
    MU_RUN_TEST(test_str_find_not_found);
    MU_RUN_TEST(test_str_find_at_beginning);
    MU_RUN_TEST(test_str_find_at_end);
    MU_RUN_TEST(test_str_find_single_char);
    MU_RUN_TEST(test_str_find_pos_out_of_bounds);
    MU_RUN_TEST(test_str_find_null_inputs);
}

MU_TEST_SUITE(test_str_rfind_suite) {
    MU_RUN_TEST(test_str_rfind_basic);
    MU_RUN_TEST(test_str_rfind_first_occurrence);
    MU_RUN_TEST(test_str_rfind_not_found);
    MU_RUN_TEST(test_str_rfind_single_char);
    MU_RUN_TEST(test_str_rfind_at_beginning);
    MU_RUN_TEST(test_str_rfind_pos_too_small);
    MU_RUN_TEST(test_str_rfind_empty_pattern);
    MU_RUN_TEST(test_str_rfind_null_inputs);
}

MU_TEST_SUITE(test_str_find_first_of_suite) {
    MU_RUN_TEST(test_str_find_first_of_basic);
    MU_RUN_TEST(test_str_find_first_of_from_position);
    MU_RUN_TEST(test_str_find_first_of_not_found);
    MU_RUN_TEST(test_str_find_first_of_at_beginning);
    MU_RUN_TEST(test_str_find_first_of_pos_out_of_bounds);
    MU_RUN_TEST(test_str_find_first_of_null_inputs);
}

MU_TEST_SUITE(test_str_find_last_of_suite) {
    MU_RUN_TEST(test_str_find_last_of_basic);
    MU_RUN_TEST(test_str_find_last_of_within_range);
    MU_RUN_TEST(test_str_find_last_of_not_found);
    MU_RUN_TEST(test_str_find_last_of_single_occurrence);
    MU_RUN_TEST(test_str_find_last_of_multiple_occurrences);
    MU_RUN_TEST(test_str_find_last_of_at_beginning);
    MU_RUN_TEST(test_str_find_last_of_pos_out_of_bounds);
    MU_RUN_TEST(test_str_find_last_of_null_inputs);
}

MU_TEST_SUITE(test_edge_cases_suite) {
    MU_RUN_TEST(test_all_functions_empty_string);
    MU_RUN_TEST(test_all_functions_pattern_longer_than_string);
}

// Main function to run all tests
int main() {
    MU_RUN_SUITE(test_str_find_suite);
    MU_RUN_SUITE(test_str_rfind_suite);
    MU_RUN_SUITE(test_str_find_first_of_suite);
    MU_RUN_SUITE(test_str_find_last_of_suite);
    MU_RUN_SUITE(test_edge_cases_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
