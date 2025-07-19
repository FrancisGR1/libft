#include "./minunit/minunit.h"
#include "../Strings/strings.h"

// t_string **str_split_using_char_as_delim(const t_string* str, const char* delimiters, int *count);
// Helper function to clean up split results
void cleanup_splits(t_string **splits, int count)
{
    if (splits) {
        for (int i = 0; i < count; i++) {
            if (splits[i]) {
                str_deallocate(splits[i]);
            }
        }
        free(splits);
    }
}

// Test basic splitting functionality
MU_TEST(test_str_split_using_char_as_delim_basic)
{
    t_string *str = str_create("hello,world,test");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, ",", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello", result[0]->data);
    mu_assert_string_eq("world", result[1]->data);
    mu_assert_string_eq("test", result[2]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test splitting with single character
MU_TEST(test_str_split_using_char_as_delim_single_char)
{
    t_string *str = str_create("a|b|c|d");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, "|", &count);
    
    mu_assert_int_eq(4, count);
    mu_check(result != NULL);
    mu_assert_string_eq("a", result[0]->data);
    mu_assert_string_eq("b", result[1]->data);
    mu_assert_string_eq("c", result[2]->data);
    mu_assert_string_eq("d", result[3]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test splitting with multiple character delimiter
MU_TEST(test_str_split_using_char_as_delim_multi_char_delimiter)
{
    t_string *str = str_create("hello::world::test");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, "::", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello", result[0]->data);
    mu_assert_string_eq("world", result[1]->data);
    mu_assert_string_eq("test", result[2]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test no delimiter found
MU_TEST(test_str_split_using_char_as_delim_no_delimiter)
{
    t_string *str = str_create("hello");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, ",", &count);
    
    mu_assert_int_eq(1, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello", result[0]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test empty string
MU_TEST(test_str_split_using_char_as_delim_empty_string)
{
    t_string *str = str_create("");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, ",", &count);
    
    mu_check(result == NULL);
    mu_assert_int_eq(0, count);
    
    str_deallocate(str);
}

// Test string with only delimiter
MU_TEST(test_str_split_using_char_as_delim_only_delimiter)
{
    t_string *str = str_create(",,,");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, ",", &count);
    
    mu_check(result == NULL);
    mu_assert_int_eq(0, count);
    
    str_deallocate(str);
}

// Test consecutive delimiters
MU_TEST(test_str_split_using_char_as_delim_consecutive_delimiters)
{
    t_string *str = str_create("hello,,world");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, ",", &count);
    
    mu_assert_int_eq(2, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello", result[0]->data);
    mu_assert_string_eq("world", result[1]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test delimiter at beginning
MU_TEST(test_str_split_using_char_as_delim_delimiter_at_start)
{
    t_string *str = str_create(",hello,world");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, ",", &count);
    
    mu_assert_int_eq(2, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello", result[0]->data);
    mu_assert_string_eq("world", result[1]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test delimiter at end
MU_TEST(test_str_split_using_char_as_delim_delimiter_at_end)
{
    t_string *str = str_create("hello,world,");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, ",", &count);
    
    mu_assert_int_eq(2, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello", result[0]->data);
    mu_assert_string_eq("world", result[1]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test null string parameter
MU_TEST(test_str_split_using_char_as_delim_null_string)
{
    int count = 0;
    t_string **result = str_split_using_char_as_delim(NULL, ",", &count);
    
    mu_check(result == NULL);
}

// Test null delimiter parameter
MU_TEST(test_str_split_using_char_as_delim_null_delimiter)
{
    t_string *str = str_create("hello,world");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, NULL, &count);
    
    mu_check(result == NULL);
    
    str_deallocate(str);
}

// Test whitespace delimiter
MU_TEST(test_str_split_using_char_as_delim_whitespace)
{
    t_string *str = str_create("hello world test");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, " ", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello", result[0]->data);
    mu_assert_string_eq("world", result[1]->data);
    mu_assert_string_eq("test", result[2]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test mixed whitespace delimiters
MU_TEST(test_str_split_using_char_as_delim_mixed_whitespace)
{
    t_string *str = str_create("hello\tworld\ntest");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, " \t\n", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello", result[0]->data);
    mu_assert_string_eq("world", result[1]->data);
    mu_assert_string_eq("test", result[2]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}

// Test single character string
MU_TEST(test_str_split_using_char_as_delim_single_char_string)
{
    t_string *str = str_create("a");
    int count = 0;
    t_string **result = str_split_using_char_as_delim(str, ",", &count);
    
    mu_assert_int_eq(1, count);
    mu_check(result != NULL);
    mu_assert_string_eq("a", result[0]->data);
    
    cleanup_splits(result, count);
    str_deallocate(str);
}
// Test suite
MU_TEST_SUITE(str_split_using_char_as_delim_test_suite)
{
    MU_RUN_TEST(test_str_split_using_char_as_delim_basic);
    MU_RUN_TEST(test_str_split_using_char_as_delim_single_char);
    MU_RUN_TEST(test_str_split_using_char_as_delim_multi_char_delimiter);
    MU_RUN_TEST(test_str_split_using_char_as_delim_no_delimiter);
    MU_RUN_TEST(test_str_split_using_char_as_delim_empty_string);
    MU_RUN_TEST(test_str_split_using_char_as_delim_only_delimiter);
    MU_RUN_TEST(test_str_split_using_char_as_delim_consecutive_delimiters);
    MU_RUN_TEST(test_str_split_using_char_as_delim_delimiter_at_start);
    MU_RUN_TEST(test_str_split_using_char_as_delim_delimiter_at_end);
    MU_RUN_TEST(test_str_split_using_char_as_delim_null_string);
    MU_RUN_TEST(test_str_split_using_char_as_delim_null_delimiter);
    MU_RUN_TEST(test_str_split_using_char_as_delim_whitespace);
    MU_RUN_TEST(test_str_split_using_char_as_delim_mixed_whitespace);
    MU_RUN_TEST(test_str_split_using_char_as_delim_single_char_string);
}

//-----------------------------------
//-----------------------------------
//-----------------------------------
//-----------------------------------
//-----------------------------------
//-----------------------------------
//-----------------------------------
//
// t_string **str_split_using_str_as_delim(const t_string *str, const char *delimiter, int *count);
MU_TEST(test_str_split_using_str_as_delim_basic_comma)
{
    t_string *str = str_create("apple,banana,cherry");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, ",", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("apple", result[0]->data);
    mu_assert_string_eq("banana", result[1]->data);
    mu_assert_string_eq("cherry", result[2]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test splitting with multi-character delimiter
MU_TEST(test_str_split_using_str_as_delim_multi_char_delimiter)
{
    t_string *str = str_create("apple::banana::cherry");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, "::", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("apple", result[0]->data);
    mu_assert_string_eq("banana", result[1]->data);
    mu_assert_string_eq("cherry", result[2]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test splitting with no delimiter present
MU_TEST(test_str_split_using_str_as_delim_no_delimiter)
{
    t_string *str = str_create("hello world");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, ",", &count);
    
    mu_assert_int_eq(1, count);
    mu_check(result != NULL);
    mu_assert_string_eq("hello world", result[0]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test splitting with empty string
MU_TEST(test_str_split_using_str_as_delim_empty_string)
{
    t_string *str = str_create("");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, ",", &count);
    
    mu_assert_int_eq(0, count);
    mu_check(result == NULL);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test splitting with delimiter at start
MU_TEST(test_str_split_using_str_as_delim_delimiter_at_start)
{
    t_string *str = str_create(",apple,banana");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, ",", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("", result[0]->data);
    mu_assert_string_eq("apple", result[1]->data);
    mu_assert_string_eq("banana", result[2]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test splitting with delimiter at end
MU_TEST(test_str_split_using_str_as_delim_delimiter_at_end)
{
    t_string *str = str_create("apple,banana,");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, ",", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("apple", result[0]->data);
    mu_assert_string_eq("banana", result[1]->data);
    mu_assert_string_eq("", result[2]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test splitting with consecutive delimiters
MU_TEST(test_str_split_using_str_as_delim_consecutive_delimiters)
{
    t_string *str = str_create("apple,,banana");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, ",", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("apple", result[0]->data);
    mu_assert_string_eq("", result[1]->data);
    mu_assert_string_eq("banana", result[2]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test splitting with only delimiter
MU_TEST(test_str_split_using_str_as_delim_only_delimiter)
{
    t_string *str = str_create(",");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, ",", &count);
    
    mu_assert_int_eq(2, count);
    mu_check(result != NULL);
    mu_assert_string_eq("", result[0]->data);
    mu_assert_string_eq("", result[1]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test with NULL string input
MU_TEST(test_str_split_using_str_as_delim_null_string)
{
    int count = 0;
    t_string **result = str_split_using_str_as_delim(NULL, ",", &count);
    
    mu_check(result == NULL);
}

// Test with NULL delimiter input
MU_TEST(test_str_split_using_str_as_delim_null_delimiter)
{
    t_string *str = str_create("apple,banana");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, NULL, &count);
    
    mu_check(result == NULL);
    str_deallocate(str);
}

// Test with NULL count parameter
MU_TEST(test_str_split_using_str_as_delim_null_count)
{
    t_string *str = str_create("apple,banana");
    t_string **result = str_split_using_str_as_delim(str, ",", NULL);
    
    mu_check(result == NULL);
    str_deallocate(str);
}

// Test with empty delimiter
MU_TEST(test_str_split_using_str_as_delim_empty_delimiter)
{
    t_string *str = str_create("apple,banana");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, "", &count);
    
    mu_check(result == NULL);
    str_deallocate(str);
}

// Test with longer multi-character delimiter
MU_TEST(test_str_split_using_str_as_delim_long_delimiter)
{
    t_string *str = str_create("apple---banana---cherry");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, "---", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("apple", result[0]->data);
    mu_assert_string_eq("banana", result[1]->data);
    mu_assert_string_eq("cherry", result[2]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test with overlapping delimiter patterns
MU_TEST(test_str_split_using_str_as_delim_overlapping_patterns)
{
    t_string *str = str_create("appleaaabananaaaaacherry");
    int count = 0;
    t_string **result = str_split_using_str_as_delim(str, "aaa", &count);
    
    mu_assert_int_eq(3, count);
    mu_check(result != NULL);
    mu_assert_string_eq("apple", result[0]->data);
    mu_assert_string_eq("banan", result[1]->data);
    mu_assert_string_eq("aacherry", result[2]->data);
    
    // Cleanup
    for (int i = 0; i < count; i++) {
        str_deallocate(result[i]);
    }
    free(result);
    str_deallocate(str);
}

// Test suite
MU_TEST_SUITE(str_split_using_str_as_delim_test_suite)
{
    MU_RUN_TEST(test_str_split_using_str_as_delim_basic_comma);
    MU_RUN_TEST(test_str_split_using_str_as_delim_multi_char_delimiter);
    MU_RUN_TEST(test_str_split_using_str_as_delim_no_delimiter);
    MU_RUN_TEST(test_str_split_using_str_as_delim_empty_string);
    MU_RUN_TEST(test_str_split_using_str_as_delim_delimiter_at_start);
    MU_RUN_TEST(test_str_split_using_str_as_delim_delimiter_at_end);
    MU_RUN_TEST(test_str_split_using_str_as_delim_consecutive_delimiters);
    MU_RUN_TEST(test_str_split_using_str_as_delim_only_delimiter);
    MU_RUN_TEST(test_str_split_using_str_as_delim_null_string);
    MU_RUN_TEST(test_str_split_using_str_as_delim_null_delimiter);
    MU_RUN_TEST(test_str_split_using_str_as_delim_null_count);
    MU_RUN_TEST(test_str_split_using_str_as_delim_empty_delimiter);
    MU_RUN_TEST(test_str_split_using_str_as_delim_long_delimiter);
    MU_RUN_TEST(test_str_split_using_str_as_delim_overlapping_patterns);
}

int main()
{
    MU_RUN_SUITE(str_split_using_char_as_delim_test_suite);
    MU_RUN_SUITE(str_split_using_str_as_delim_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
