#include "./minunit/minunit.h"
#include "../Strings/strings.h"
#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Tests for str_substr function
MU_TEST(test_str_substr_normal_case)
{
    t_string *str = str_create("hello world");
    t_string *substr = str_substr(str, 6, 5);
    
    mu_assert(substr != NULL, "substr should not be NULL");
    mu_assert_string_eq("world", substr->data);
    mu_assert_int_eq(5, substr->size);
    
    str_deallocate(substr);
    str_deallocate(str);
}

MU_TEST(test_str_substr_from_beginning)
{
    t_string *str = str_create("testing");
    t_string *substr = str_substr(str, 0, 4);
    
    mu_assert(substr != NULL, "substr should not be NULL");
    mu_assert_string_eq("test", substr->data);
    mu_assert_int_eq(4, substr->size);
    
    str_deallocate(substr);
    str_deallocate(str);
}

MU_TEST(test_str_substr_to_end)
{
    t_string *str = str_create("programming");
    t_string *substr = str_substr(str, 4, 100); // len exceeds string length
    
    mu_assert(substr != NULL, "substr should not be NULL");
    mu_assert_string_eq("ramming", substr->data);
    mu_assert_int_eq(7, substr->size);
    
    str_deallocate(substr);
    str_deallocate(str);
}

MU_TEST(test_str_substr_single_character)
{
    t_string *str = str_create("abc");
    t_string *substr = str_substr(str, 1, 1);
    
    mu_assert(substr != NULL, "substr should not be NULL");
    mu_assert_string_eq("b", substr->data);
    mu_assert_int_eq(1, substr->size);
    
    str_deallocate(substr);
    str_deallocate(str);
}

MU_TEST(test_str_substr_empty_result)
{
    t_string *str = str_create("hello");
    t_string *substr = str_substr(str, 2, 0);
    
    mu_assert(substr != NULL, "substr should not be NULL");
    mu_assert_string_eq("", substr->data);
    mu_assert_int_eq(0, substr->size);
    
    str_deallocate(substr);
    str_deallocate(str);
}

MU_TEST(test_str_substr_null_input)
{
    t_string *substr = str_substr(NULL, 0, 5);
    mu_assert(substr == NULL, "substr should be NULL when input is NULL");
}

MU_TEST(test_str_substr_position_out_of_bounds)
{
    t_string *str = str_create("short");
    t_string *substr = str_substr(str, 10, 5);
    
    mu_assert(substr == NULL, "substr should be NULL when position is out of bounds");
    
    str_deallocate(str);
}

MU_TEST(test_str_substr_at_end_position)
{
    t_string *str = str_create("test");
    t_string *substr = str_substr(str, 4, 5); // pos equals str->size
    
    mu_assert(substr == NULL, "substr should be NULL when position equals string size");
    
    str_deallocate(str);
}

// Tests for str_count function
MU_TEST(test_str_count_normal_case)
{
    t_string *str = str_create("hello world hello");
    size_t count = str_count(str, "hello");
    
    mu_assert_int_eq(2, count);
    
    str_deallocate(str);
}

MU_TEST(test_str_count_single_occurrence)
{
    t_string *str = str_create("programming is fun");
    size_t count = str_count(str, "fun");
    
    mu_assert_int_eq(1, count);
    
    str_deallocate(str);
}

MU_TEST(test_str_count_no_occurrence)
{
    t_string *str = str_create("hello world");
    size_t count = str_count(str, "xyz");
    
    mu_assert_int_eq(0, count);
    
    str_deallocate(str);
}

MU_TEST(test_str_count_overlapping_patterns)
{
    t_string *str = str_create("aaaa");
    size_t count = str_count(str, "aa");
    
    // Should count non-overlapping occurrences: "aa|aa" = 2
    mu_assert_int_eq(2, count);
    
    str_deallocate(str);
}

MU_TEST(test_str_count_single_character)
{
    t_string *str = str_create("banana");
    size_t count = str_count(str, "a");
    
    mu_assert_int_eq(3, count);
    
    str_deallocate(str);
}

MU_TEST(test_str_count_empty_substring)
{
    t_string *str = str_create("hello");
    size_t count = str_count(str, "");
    mu_assert_int_eq(0, count);
    str_deallocate(str);
}

MU_TEST(test_str_count_null_string)
{
    size_t count = str_count(NULL, "test");
    mu_assert_int_eq(0, count);
}

MU_TEST(test_str_count_null_substring)
{
    t_string *str = str_create("hello world");
    size_t count = str_count(str, NULL);
    
    mu_assert_int_eq(0, count);
    
    str_deallocate(str);
}

MU_TEST(test_str_count_null_data)
{
    t_string str = {NULL, 0, 0, NULL};
    size_t count = str_count(&str, "test");
    
    mu_assert_int_eq(0, count);
}

MU_TEST(test_str_count_whole_string_match)
{
    t_string *str = str_create("hello");
    size_t count = str_count(str, "hello");
    
    mu_assert_int_eq(1, count);
    
    str_deallocate(str);
}

MU_TEST(test_str_count_longer_substring)
{
    t_string *str = str_create("hi");
    size_t count = str_count(str, "hello");
    
    mu_assert_int_eq(0, count);
    
    str_deallocate(str);
}

// Test suites
MU_TEST_SUITE(test_suite_str_substr)
{
    MU_RUN_TEST(test_str_substr_normal_case);
    MU_RUN_TEST(test_str_substr_from_beginning);
    MU_RUN_TEST(test_str_substr_to_end);
    MU_RUN_TEST(test_str_substr_single_character);
    MU_RUN_TEST(test_str_substr_empty_result);
    MU_RUN_TEST(test_str_substr_null_input);
    MU_RUN_TEST(test_str_substr_position_out_of_bounds);
    MU_RUN_TEST(test_str_substr_at_end_position);
}

MU_TEST_SUITE(test_suite_str_count)
{
    MU_RUN_TEST(test_str_count_normal_case);
    MU_RUN_TEST(test_str_count_single_occurrence);
    MU_RUN_TEST(test_str_count_no_occurrence);
    MU_RUN_TEST(test_str_count_overlapping_patterns);
    MU_RUN_TEST(test_str_count_single_character);
    MU_RUN_TEST(test_str_count_empty_substring);
    MU_RUN_TEST(test_str_count_null_string);
    MU_RUN_TEST(test_str_count_null_substring);
    MU_RUN_TEST(test_str_count_null_data);
    MU_RUN_TEST(test_str_count_whole_string_match);
    MU_RUN_TEST(test_str_count_longer_substring);
}

int main()
{
    MU_RUN_SUITE(test_suite_str_substr);
    MU_RUN_SUITE(test_suite_str_count);
    MU_REPORT();
    return MU_EXIT_CODE;
}
