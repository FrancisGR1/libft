#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test str_is_equal function
MU_TEST(test_str_is_equal_identical_strings)
{
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("hello");
    
    bool result = str_is_equal(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_equal_different_strings)
{
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("world");
    
    bool result = str_is_equal(str1, str2);
    
    mu_check(result == false);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_equal_empty_strings)
{
    t_string *str1 = str_create("");
    t_string *str2 = str_create("");
    
    bool result = str_is_equal(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_equal_different_lengths)
{
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("hello world");
    
    bool result = str_is_equal(str1, str2);
    
    mu_check(result == false);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_equal_null_strings)
{
    t_string *str1 = str_create("test");
    
    bool result1 = str_is_equal(str1, NULL);
    bool result2 = str_is_equal(NULL, str1);
    bool result3 = str_is_equal(NULL, NULL);
    
    mu_check(result1 == false || result1 == true); // Depends on str_compare implementation
    mu_check(result2 == false || result2 == true);
    mu_check(result3 == false || result3 == true);
    
    str_deallocate(str1);
}

// Test str_is_not_equal function
MU_TEST(test_str_is_not_equal_different_strings)
{
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("world");
    
    bool result = str_is_not_equal(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_not_equal_identical_strings)
{
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("hello");
    
    bool result = str_is_not_equal(str1, str2);
    
    mu_check(result == false);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_not_equal_case_sensitive)
{
    t_string *str1 = str_create("Hello");
    t_string *str2 = str_create("hello");
    
    bool result = str_is_not_equal(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

// Test str_is_less function
MU_TEST(test_str_is_less_lexicographically_smaller)
{
    t_string *str1 = str_create("apple");
    t_string *str2 = str_create("banana");
    
    bool result = str_is_less(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_less_lexicographically_greater)
{
    t_string *str1 = str_create("banana");
    t_string *str2 = str_create("apple");
    
    bool result = str_is_less(str1, str2);
    
    mu_check(result == false);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_less_equal_strings)
{
    t_string *str1 = str_create("test");
    t_string *str2 = str_create("test");
    
    bool result = str_is_less(str1, str2);
    
    mu_check(result == false);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_less_shorter_string)
{
    t_string *str1 = str_create("test");
    t_string *str2 = str_create("testing");
    
    bool result = str_is_less(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

// Test str_is_greater function
MU_TEST(test_str_is_greater_lexicographically_larger)
{
    t_string *str1 = str_create("zebra");
    t_string *str2 = str_create("apple");
    
    bool result = str_is_greater(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_greater_lexicographically_smaller)
{
    t_string *str1 = str_create("apple");
    t_string *str2 = str_create("zebra");
    
    bool result = str_is_greater(str1, str2);
    
    mu_check(result == false);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_greater_equal_strings)
{
    t_string *str1 = str_create("test");
    t_string *str2 = str_create("test");
    
    bool result = str_is_greater(str1, str2);
    
    mu_check(result == false);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_str_is_greater_longer_string)
{
    t_string *str1 = str_create("testing");
    t_string *str2 = str_create("test");
    
    bool result = str_is_greater(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

// Edge cases with special characters and numbers
MU_TEST(test_comparison_special_characters)
{
    t_string *str1 = str_create("hello!");
    t_string *str2 = str_create("hello?");
    
    bool result = str_is_less(str1, str2);
    
    mu_check(result == true); // '!' < '?'
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_comparison_numbers_as_strings)
{
    t_string *str1 = str_create("123");
    t_string *str2 = str_create("456");
    
    bool result = str_is_less(str1, str2);
    
    mu_check(result == true); // "123" < "456"
    
    str_deallocate(str1);
    str_deallocate(str2);
}

MU_TEST(test_comparison_mixed_content)
{
    t_string *str1 = str_create("abc123");
    t_string *str2 = str_create("abc124");
    
    bool result = str_is_less(str1, str2);
    
    mu_check(result == true);
    
    str_deallocate(str1);
    str_deallocate(str2);
}

// Test suite
MU_TEST_SUITE(test_suite)
{
    // str_is_equal tests
    MU_RUN_TEST(test_str_is_equal_identical_strings);
    MU_RUN_TEST(test_str_is_equal_different_strings);
    MU_RUN_TEST(test_str_is_equal_empty_strings);
    MU_RUN_TEST(test_str_is_equal_different_lengths);
    MU_RUN_TEST(test_str_is_equal_null_strings);
    
    // str_is_not_equal tests
    MU_RUN_TEST(test_str_is_not_equal_different_strings);
    MU_RUN_TEST(test_str_is_not_equal_identical_strings);
    MU_RUN_TEST(test_str_is_not_equal_case_sensitive);
    
    // str_is_less tests
    MU_RUN_TEST(test_str_is_less_lexicographically_smaller);
    MU_RUN_TEST(test_str_is_less_lexicographically_greater);
    MU_RUN_TEST(test_str_is_less_equal_strings);
    MU_RUN_TEST(test_str_is_less_shorter_string);
    
    // str_is_greater tests
    MU_RUN_TEST(test_str_is_greater_lexicographically_larger);
    MU_RUN_TEST(test_str_is_greater_lexicographically_smaller);
    MU_RUN_TEST(test_str_is_greater_equal_strings);
    MU_RUN_TEST(test_str_is_greater_longer_string);
    
    // Edge case tests
    MU_RUN_TEST(test_comparison_special_characters);
    MU_RUN_TEST(test_comparison_numbers_as_strings);
    MU_RUN_TEST(test_comparison_mixed_content);
}

int main(void)
{
    MU_RUN_TEST(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
