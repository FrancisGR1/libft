#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test functions for str_at
MU_TEST(test_str_at_valid_indices)
{
    t_string *str = str_create("hello");
    mu_assert(str_at(str, 0) == 'h', "Should return 'h' at index 0");
    mu_assert(str_at(str, 1) == 'e', "Should return 'e' at index 1");
    mu_assert(str_at(str, 4) == 'o', "Should return 'o' at index 4");
    str_deallocate(str);
}

MU_TEST(test_str_at_out_of_bounds)
{
    t_string *str = str_create("hello");
    mu_assert(str_at(str, 5) == '\0', "Should return '\\0' for index equal to size");
    mu_assert(str_at(str, 10) == '\0', "Should return '\\0' for index greater than size");
    str_deallocate(str);
}

MU_TEST(test_str_at_empty_string)
{
    t_string *str = str_create("");
    mu_assert(str_at(str, 0) == '\0', "Should return '\\0' for index 0 in empty string");
    mu_assert(str_at(str, 1) == '\0', "Should return '\\0' for any index in empty string");
    str_deallocate(str);
}

MU_TEST(test_str_at_null_input)
{
    mu_assert(str_at(NULL, 0) == '\0', "Should return '\\0' for NULL string");
    mu_assert(str_at(NULL, 5) == '\0', "Should return '\\0' for NULL string with any index");
}

MU_TEST(test_str_at_single_character)
{
    t_string *str = str_create("a");
    mu_assert(str_at(str, 0) == 'a', "Should return 'a' at index 0");
    mu_assert(str_at(str, 1) == '\0', "Should return '\\0' for index 1 in single char string");
    str_deallocate(str);
}

MU_TEST(test_str_at_special_characters)
{
    t_string *str = str_create("a\nb\tc");
    mu_assert(str_at(str, 0) == 'a', "Should return 'a' at index 0");
    mu_assert(str_at(str, 1) == '\n', "Should return newline at index 1");
    mu_assert(str_at(str, 2) == 'b', "Should return 'b' at index 2");
    mu_assert(str_at(str, 3) == '\t', "Should return tab at index 3");
    mu_assert(str_at(str, 4) == 'c', "Should return 'c' at index 4");
    str_deallocate(str);
}

// Test functions for str_c_str
MU_TEST(test_str_c_str_valid_string)
{
    t_string *str = str_create("hello world");
    const char* result = str_c_str(str);
    mu_assert(result != NULL, "Should return non-NULL pointer");
    mu_assert_string_eq("hello world", result);
    str_deallocate(str);
}

MU_TEST(test_str_c_str_empty_string)
{
    t_string *str = str_create("");
    const char* result = str_c_str(str);
    mu_assert(result != NULL, "Should return non-NULL pointer for empty string");
    mu_assert_string_eq("", result);
    str_deallocate(str);
}

MU_TEST(test_str_c_str_null_input)
{
    mu_assert(str_c_str(NULL) == NULL, "Should return NULL for NULL string");
}

MU_TEST(test_str_c_str_single_character)
{
    t_string *str = str_create("x");
    const char* result = str_c_str(str);
    mu_assert(result != NULL, "Should return non-NULL pointer");
    mu_assert_string_eq("x", result);
    str_deallocate(str);
}

MU_TEST(test_str_c_str_special_characters)
{
    t_string *str = str_create("tab\there\nnewline");
    const char* result = str_c_str(str);
    mu_assert(result != NULL, "Should return non-NULL pointer");
    mu_assert_string_eq("tab\there\nnewline", result);
    str_deallocate(str);
}

// Test functions for str_begin
MU_TEST(test_str_begin_valid_string)
{
    t_string *str = str_create("hello");
    char* result = str_begin(str);
    mu_assert(result != NULL, "Should return non-NULL pointer");
    mu_assert(*result == 'h', "Should point to first character 'h'");
    str_deallocate(str);
}

MU_TEST(test_str_begin_empty_string)
{
    t_string *str = str_create("");
    char* result = str_begin(str);
    mu_assert(result != NULL, "Should return non-NULL pointer for empty string");
    str_deallocate(str);
}

MU_TEST(test_str_begin_null_input)
{
    mu_assert(str_begin(NULL) == NULL, "Should return NULL for NULL string");
}

MU_TEST(test_str_begin_single_character)
{
    t_string *str = str_create("z");
    char* result = str_begin(str);
    mu_assert(result != NULL, "Should return non-NULL pointer");
    mu_assert(*result == 'z', "Should point to first character 'z'");
    str_deallocate(str);
}

MU_TEST(test_str_begin_pointer_consistency)
{
    t_string *str = str_create("test");
    char* begin_ptr = str_begin(str);
    const char* c_str_ptr = str_c_str(str);
    mu_assert(begin_ptr == c_str_ptr, "str_begin and str_c_str should return same pointer");
    str_deallocate(str);
}

// Test functions for str_end
MU_TEST(test_str_end_valid_string)
{
    t_string *str = str_create("hello");
    char* result = str_end(str);
    mu_assert(result != NULL, "Should return non-NULL pointer");
    mu_assert(*result == 'o', "Should point to last character 'o'");
    str_deallocate(str);
}

MU_TEST(test_str_end_empty_string)
{
    t_string *str = str_create("");
    char* result = str_end(str);
    mu_assert(result != NULL, "Should return non-NULL pointer for empty string");
    // For empty string, str_end should return pointer to data (same as begin)
    mu_assert(result == str_begin(str), "For empty string, end should equal begin");
    str_deallocate(str);
}

MU_TEST(test_str_end_null_input)
{
    mu_assert(str_end(NULL) == NULL, "Should return NULL for NULL string");
}

MU_TEST(test_str_end_single_character)
{
    t_string *str = str_create("x");
    char* result = str_end(str);
    mu_assert(result != NULL, "Should return non-NULL pointer");
    mu_assert(*result == 'x', "Should point to last character 'x'");
    str_deallocate(str);
}

MU_TEST(test_str_end_multiple_characters)
{
    t_string *str = str_create("abcdef");
    char* result = str_end(str);
    mu_assert(result != NULL, "Should return non-NULL pointer");
    mu_assert(*result == 'f', "Should point to last character 'f'");
    str_deallocate(str);
}

// Additional edge case tests
MU_TEST(test_accessor_functions_consistency)
{
    t_string *str = str_create("test");
    
    // Test that str_at(0) matches *str_begin()
    mu_assert(str_at(str, 0) == *str_begin(str), "str_at(0) should match *str_begin()");
    
    // Test that str_at(size-1) matches *str_end() for non-empty string
    mu_assert(str_at(str, 3) == *str_end(str), "str_at(size-1) should match *str_end()");
    
    str_deallocate(str);
}

MU_TEST(test_pointer_arithmetic_consistency)
{
    t_string *str = str_create("hello");
    char* begin = str_begin(str);
    char* end = str_end(str);
    
    // For a 5-character string, end should be begin + 4
    mu_assert(end == begin + 4, "End pointer should be begin + (size - 1)");
    
    str_deallocate(str);
}

MU_TEST(test_all_functions_with_whitespace)
{
    t_string *str = str_create("  spaces  ");
    
    mu_assert(str_at(str, 0) == ' ', "Should handle leading spaces");
    mu_assert(str_at(str, 8) == ' ', "Should handle trailing spaces");
    mu_assert(*str_begin(str) == ' ', "Begin should point to first space");
    mu_assert(*str_end(str) == ' ', "End should point to last space");
    
    const char* c_str = str_c_str(str);
    mu_assert_string_eq("  spaces  ", c_str);
    
    str_deallocate(str);
}

// Test suite
MU_TEST_SUITE(string_accessor_test_suite)
{
    // str_at tests
    MU_RUN_TEST(test_str_at_valid_indices);
    MU_RUN_TEST(test_str_at_out_of_bounds);
    MU_RUN_TEST(test_str_at_empty_string);
    MU_RUN_TEST(test_str_at_null_input);
    MU_RUN_TEST(test_str_at_single_character);
    MU_RUN_TEST(test_str_at_special_characters);
    
    // str_c_str tests
    MU_RUN_TEST(test_str_c_str_valid_string);
    MU_RUN_TEST(test_str_c_str_empty_string);
    MU_RUN_TEST(test_str_c_str_null_input);
    MU_RUN_TEST(test_str_c_str_single_character);
    MU_RUN_TEST(test_str_c_str_special_characters);
    
    // str_begin tests
    MU_RUN_TEST(test_str_begin_valid_string);
    MU_RUN_TEST(test_str_begin_empty_string);
    MU_RUN_TEST(test_str_begin_null_input);
    MU_RUN_TEST(test_str_begin_single_character);
    MU_RUN_TEST(test_str_begin_pointer_consistency);
    
    // str_end tests
    MU_RUN_TEST(test_str_end_valid_string);
    MU_RUN_TEST(test_str_end_empty_string);
    MU_RUN_TEST(test_str_end_null_input);
    MU_RUN_TEST(test_str_end_single_character);
    MU_RUN_TEST(test_str_end_multiple_characters);
    
    // Cross-function consistency tests
    MU_RUN_TEST(test_accessor_functions_consistency);
    MU_RUN_TEST(test_pointer_arithmetic_consistency);
    MU_RUN_TEST(test_all_functions_with_whitespace);
}

int main(int argc, char *argv[])
{
    MU_RUN_SUITE(string_accessor_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
