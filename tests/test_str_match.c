#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test functions for str_contains
MU_TEST(test_str_contains_basic_match)
{
    t_string *str = str_create("hello world");
    mu_assert(str_contains(str, "hello"), "Should find 'hello' in 'hello world'");
    mu_assert(str_contains(str, "world"), "Should find 'world' in 'hello world'");
    mu_assert(str_contains(str, "lo wo"), "Should find 'lo wo' in 'hello world'");
    str_deallocate(str);
}

MU_TEST(test_str_contains_no_match)
{
    t_string *str = str_create("hello world");
    mu_assert(!str_contains(str, "xyz"), "Should not find 'xyz' in 'hello world'");
    mu_assert(!str_contains(str, "Hello"), "Should not find 'Hello' (case sensitive) in 'hello world'");
    str_deallocate(str);
}

MU_TEST(test_str_contains_empty_substr)
{
    t_string *str = str_create("hello");
    mu_assert(str_contains(str, ""), "Should find empty string in any string");
    str_deallocate(str);
}

MU_TEST(test_str_contains_empty_string)
{
    t_string *str = str_create("");
    mu_assert(str_contains(str, ""), "Should find empty string in empty string");
    mu_assert(!str_contains(str, "a"), "Should not find 'a' in empty string");
    str_deallocate(str);
}

MU_TEST(test_str_contains_null_inputs)
{
    t_string *str = str_create("hello");
    mu_assert(!str_contains(NULL, "hello"), "Should return false for NULL string");
    mu_assert(!str_contains(str, NULL), "Should return false for NULL substring");
    mu_assert(!str_contains(NULL, NULL), "Should return false for both NULL");
    str_deallocate(str);
}

MU_TEST(test_str_contains_full_match)
{
    t_string *str = str_create("test");
    mu_assert(str_contains(str, "test"), "Should find exact match");
    str_deallocate(str);
}

// Test functions for str_starts_with
MU_TEST(test_str_starts_with_basic_match)
{
    t_string *str = str_create("hello world");
    mu_assert(str_starts_with(str, "hello"), "Should start with 'hello'");
    mu_assert(str_starts_with(str, "h"), "Should start with 'h'");
    mu_assert(str_starts_with(str, "hello world"), "Should start with entire string");
    str_deallocate(str);
}

MU_TEST(test_str_starts_with_no_match)
{
    t_string *str = str_create("hello world");
    mu_assert(!str_starts_with(str, "world"), "Should not start with 'world'");
    mu_assert(!str_starts_with(str, "Hello"), "Should not start with 'Hello' (case sensitive)");
    mu_assert(!str_starts_with(str, "x"), "Should not start with 'x'");
    str_deallocate(str);
}

MU_TEST(test_str_starts_with_empty_substr)
{
    t_string *str = str_create("hello");
    mu_assert(str_starts_with(str, ""), "Should start with empty string");
    str_deallocate(str);
}

MU_TEST(test_str_starts_with_empty_string)
{
    t_string *str = str_create("");
    mu_assert(str_starts_with(str, ""), "Empty string should start with empty string");
    mu_assert(!str_starts_with(str, "a"), "Empty string should not start with 'a'");
    str_deallocate(str);
}

MU_TEST(test_str_starts_with_longer_substr)
{
    t_string *str = str_create("hi");
    mu_assert(!str_starts_with(str, "hello"), "Short string should not start with longer substring");
    str_deallocate(str);
}

MU_TEST(test_str_starts_with_null_inputs)
{
    t_string *str = str_create("hello");
    mu_assert(!str_starts_with(NULL, "hello"), "Should return false for NULL string");
    mu_assert(!str_starts_with(str, NULL), "Should return false for NULL substring");
    mu_assert(!str_starts_with(NULL, NULL), "Should return false for both NULL");
    str_deallocate(str);
}

// Test functions for str_ends_with
MU_TEST(test_str_ends_with_basic_match)
{
    t_string *str = str_create("hello world");
    mu_assert(str_ends_with(str, "world"), "Should end with 'world'");
    mu_assert(str_ends_with(str, "d"), "Should end with 'd'");
    mu_assert(str_ends_with(str, "hello world"), "Should end with entire string");
    str_deallocate(str);
}

MU_TEST(test_str_ends_with_no_match)
{
    t_string *str = str_create("hello world");
    mu_assert(!str_ends_with(str, "hello"), "Should not end with 'hello'");
    mu_assert(!str_ends_with(str, "World"), "Should not end with 'World' (case sensitive)");
    mu_assert(!str_ends_with(str, "x"), "Should not end with 'x'");
    str_deallocate(str);
}

MU_TEST(test_str_ends_with_empty_substr)
{
    t_string *str = str_create("hello");
    mu_assert(str_ends_with(str, ""), "Should end with empty string");
    str_deallocate(str);
}

MU_TEST(test_str_ends_with_empty_string)
{
    t_string *str = str_create("");
    mu_assert(str_ends_with(str, ""), "Empty string should end with empty string");
    mu_assert(!str_ends_with(str, "a"), "Empty string should not end with 'a'");
    str_deallocate(str);
}

MU_TEST(test_str_ends_with_longer_substr)
{
    t_string *str = str_create("hi");
    mu_assert(!str_ends_with(str, "hello"), "Short string should not end with longer substring");
    str_deallocate(str);
}

MU_TEST(test_str_ends_with_null_inputs)
{
    t_string *str = str_create("hello");
    mu_assert(!str_ends_with(NULL, "hello"), "Should return false for NULL string");
    mu_assert(!str_ends_with(str, NULL), "Should return false for NULL substring");
    mu_assert(!str_ends_with(NULL, NULL), "Should return false for both NULL");
    str_deallocate(str);
}

// Additional edge case tests
MU_TEST(test_single_character_strings)
{
    t_string *str = str_create("a");
    
    // str_contains tests
    mu_assert(str_contains(str, "a"), "Single char should contain itself");
    mu_assert(!str_contains(str, "b"), "Single char should not contain different char");
    
    // str_starts_with tests
    mu_assert(str_starts_with(str, "a"), "Single char should start with itself");
    mu_assert(!str_starts_with(str, "b"), "Single char should not start with different char");
    
    // str_ends_with tests
    mu_assert(str_ends_with(str, "a"), "Single char should end with itself");
    mu_assert(!str_ends_with(str, "b"), "Single char should not end with different char");
    
    str_deallocate(str);
}

MU_TEST(test_repeated_characters)
{
    t_string *str = str_create("aaaa");
    
    mu_assert(str_contains(str, "aa"), "Should find repeated pattern");
    mu_assert(str_starts_with(str, "aaa"), "Should start with repeated pattern");
    mu_assert(str_ends_with(str, "aaa"), "Should end with repeated pattern");
    
    str_deallocate(str);
}

// Test suite
MU_TEST_SUITE(string_match_test_suite)
{
    // str_contains tests
    MU_RUN_TEST(test_str_contains_basic_match);
    MU_RUN_TEST(test_str_contains_no_match);
    MU_RUN_TEST(test_str_contains_empty_substr);
    MU_RUN_TEST(test_str_contains_empty_string);
    MU_RUN_TEST(test_str_contains_null_inputs);
    MU_RUN_TEST(test_str_contains_full_match);
    
    // str_starts_with tests
    MU_RUN_TEST(test_str_starts_with_basic_match);
    MU_RUN_TEST(test_str_starts_with_no_match);
    MU_RUN_TEST(test_str_starts_with_empty_substr);
    MU_RUN_TEST(test_str_starts_with_empty_string);
    MU_RUN_TEST(test_str_starts_with_longer_substr);
    MU_RUN_TEST(test_str_starts_with_null_inputs);
    
    // str_ends_with tests
    MU_RUN_TEST(test_str_ends_with_basic_match);
    MU_RUN_TEST(test_str_ends_with_no_match);
    MU_RUN_TEST(test_str_ends_with_empty_substr);
    MU_RUN_TEST(test_str_ends_with_empty_string);
    MU_RUN_TEST(test_str_ends_with_longer_substr);
    MU_RUN_TEST(test_str_ends_with_null_inputs);
    
    // Edge case tests
    MU_RUN_TEST(test_single_character_strings);
    MU_RUN_TEST(test_repeated_characters);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(string_match_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
