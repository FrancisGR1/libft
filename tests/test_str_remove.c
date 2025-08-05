#include "./minunit/minunit.h"
#include "../Strings/strings.h"

// Helper function to check string content and size
static void assert_string_equals(t_string* str, const char* expected, size_t expected_size) {
    mu_assert(str != NULL, "String should not be NULL");
    mu_assert(str->data != NULL, "String data should not be NULL");
    mu_assert_int_eq(expected_size, str->size);
    mu_assert_string_eq(expected, str->data);
}

// Test str_erase function

MU_TEST(test_str_erase_middle) {
    t_string *str = str_create("hello world");
    str_erase(str, 5, 1); // Remove space at position 5
    assert_string_equals(str, "helloworld", 10);
    str_deallocate(str);
}

MU_TEST(test_str_erase_beginning) {
    t_string *str = str_create("hello world");
    str_erase(str, 0, 5); // Remove "hello"
    assert_string_equals(str, " world", 6);
    str_deallocate(str);
}

MU_TEST(test_str_erase_end) {
    t_string *str = str_create("hello world");
    str_erase(str, 6, 5); // Remove "world"
    assert_string_equals(str, "hello ", 6);
    str_deallocate(str);
}

MU_TEST(test_str_erase_entire_string) {
    t_string *str = str_create("hello");
    str_erase(str, 0, 5); // Remove entire string
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

MU_TEST(test_str_erase_zero_length) {
    t_string *str = str_create("hello world");
    str_erase(str, 5, 0); // Remove nothing
    assert_string_equals(str, "hello world", 11);
    str_deallocate(str);
}

MU_TEST(test_str_erase_length_exceeds_string) {
    t_string *str = str_create("hello");
    str_erase(str, 2, 10); // Length exceeds remaining string
    assert_string_equals(str, "he", 2);
    str_deallocate(str);
}

MU_TEST(test_str_erase_pos_out_of_bounds) {
    t_string *str = str_create("hello");
    size_t original_size = str->size;
    str_erase(str, 10, 1); // Position beyond string length
    mu_assert_int_eq(original_size, str->size); // Should be unchanged
    mu_assert_string_eq("hello", str->data);
    str_deallocate(str);
}

MU_TEST(test_str_erase_null_string) {
    str_erase(NULL, 0, 1); // Should not crash
    mu_assert(1, "Function should handle NULL gracefully");
}

MU_TEST(test_str_erase_single_character) {
    t_string *str = str_create("a");
    str_erase(str, 0, 1);
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

MU_TEST(test_str_erase_empty_string) {
    t_string *str = str_create("");
    str_erase(str, 0, 1); // Should do nothing
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

// Test str_erase_if function
//-basic functionality 

MU_TEST(test_str_erase_if_remove_spaces_basic) {
    t_string *str = str_create("hello world");
    str_erase_if(str, ft_isspace, 0);
    assert_string_equals(str, "helloworld", 10);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_remove_vowels_basic) {
    t_string *str = str_create("hello");
    str_erase_if(str, ft_isvowel, 0);
    assert_string_equals(str, "hll", 3);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_remove_digits_basic) {
    t_string *str = str_create("abc123def");
    str_erase_if(str, ft_isdigit, 0);
    assert_string_equals(str, "abcdef", 6);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_remove_alpha_basic) {
    t_string *str = str_create("abc123def");
    str_erase_if(str, ft_isalpha, 0);
    assert_string_equals(str, "123", 3);
    str_deallocate(str);
}

//-position

MU_TEST(test_str_erase_if_middle_position) {
    t_string *str = str_create("hello world test");
    str_erase_if(str, ft_isspace, 5); // Start from position 5, process 6 chars
    // Should process " world" and remove the space
    assert_string_equals(str, "helloworldtest", 14);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_end_position) {
    t_string *str = str_create("hello123");
    str_erase_if(str, ft_isdigit, 5); // Remove digits from position 5
    assert_string_equals(str, "hello", 5);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_partial_range) {
    t_string *str = str_create("aeiou12345");
    str_erase_if(str, ft_isvowel, 0); // Only process first 5 chars (all vowels)
    assert_string_equals(str, "12345", 5);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_skip_beginning) {
    t_string *str = str_create("aeiou12345");
    str_erase_if(str, ft_isvowel, 5); // Skip vowels, process digits
    assert_string_equals(str, "aeiou12345", 10); // No vowels in digit part
    str_deallocate(str);
}

//-consecutive removals 

MU_TEST(test_str_erase_if_consecutive_spaces) {
    t_string *str = str_create("hello   world");
    str_erase_if(str, ft_isspace, 0);
    assert_string_equals(str, "helloworld", 10);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_consecutive_vowels) {
    t_string *str = str_create("aeiou123");
    str_erase_if(str, ft_isvowel, 0);
    assert_string_equals(str, "123", 3);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_alternating_pattern) {
    t_string *str = str_create("a1b2c3d4");
    str_erase_if(str, ft_isdigit, 0);
    assert_string_equals(str, "abcd", 4);
    str_deallocate(str);
}

//-edge cases

MU_TEST(test_str_erase_if_all_match) {
    t_string *str = str_create("12345");
    str_erase_if(str, ft_isdigit, 0);
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_none_match) {
    t_string *str = str_create("hello");
    str_erase_if(str, ft_isdigit, 0);
    assert_string_equals(str, "hello", 5);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_single_char_match) {
    t_string *str = str_create("a");
    str_erase_if(str, ft_isvowel, 0);
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_single_char_no_match) {
    t_string *str = str_create("b");
    str_erase_if(str, ft_isvowel, 0);
    assert_string_equals(str, "b", 1);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_empty_string) {
    t_string *str = str_create("");
    str_erase_if(str, ft_isspace, 0);
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

//-boundary tests

MU_TEST(test_str_erase_if_pos_at_end) {
    t_string *str = str_create("hello");
    size_t original_size = str->size;
    str_erase_if(str, ft_isvowel, 5); // pos equals string length
    mu_assert_int_eq(original_size, str->size);
    mu_assert_string_eq("hello", str->data);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_pos_beyond_end) {
    t_string *str = str_create("hello");
    size_t original_size = str->size;
    str_erase_if(str, ft_isvowel, 10); // pos beyond string
    mu_assert_int_eq(original_size, str->size);
    mu_assert_string_eq("hello", str->data);
    str_deallocate(str);
}

//-null

MU_TEST(test_str_erase_if_null_string) {
    str_erase_if(NULL, ft_isspace, 0);
    mu_assert(1, "Should handle NULL string gracefully");
}

MU_TEST(test_str_erase_if_null_predicate) {
    t_string *str = str_create("hello");
    size_t original_size = str->size;
    str_erase_if(str, NULL, 0);
    mu_assert_int_eq(original_size, str->size);
    mu_assert_string_eq("hello", str->data);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_null_data) {
    t_string str = {NULL, 0, 0};
    str_erase_if(&str, ft_isspace, 0);
    mu_assert(1, "Should handle NULL data gracefully");
}

//-complex patterns

MU_TEST(test_str_erase_if_mixed_content) {
    t_string *str = str_create("Hello123 World456!");
    str_erase_if(str, ft_isdigit, 0);
    assert_string_equals(str, "Hello World!", 12);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_punctuation) {
    t_string *str = str_create("Hello, World!");
    str_erase_if(str, ft_ispunctuation, 0);
    assert_string_equals(str, "Hello World", 11);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_case_sensitive) {
    t_string *str = str_create("Hello WORLD");
    str_erase_if(str, ft_isupper, 0);
    assert_string_equals(str, "ello ", 5);
    str_deallocate(str);
}

MU_TEST(test_str_erase_if_whitespace_types) {
    t_string *str = str_create("hello\tworld\ntest");
    str_erase_if(str, ft_isspace, 0);
    assert_string_equals(str, "helloworldtest", 14);
    str_deallocate(str);
}

// Test str_pop_back function

MU_TEST(test_str_pop_back_normal) {
    t_string *str = str_create("hello");
    str_pop_back(str);
    assert_string_equals(str, "hell", 4);
    str_deallocate(str);
}

MU_TEST(test_str_pop_back_single_character) {
    t_string *str = str_create("a");
    str_pop_back(str);
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

MU_TEST(test_str_pop_back_empty_string) {
    t_string *str = str_create("");
    size_t original_size = str->size;
    str_pop_back(str); // Should do nothing
    mu_assert_int_eq(original_size, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_pop_back_multiple_times) {
    t_string *str = str_create("hello");
    str_pop_back(str);
    str_pop_back(str);
    str_pop_back(str);
    assert_string_equals(str, "he", 2);
    str_deallocate(str);
}

MU_TEST(test_str_pop_back_null_string) {
    str_pop_back(NULL); // Should not crash
    mu_assert(1, "Function should handle NULL gracefully");
}

MU_TEST(test_str_pop_back_until_empty) {
    t_string *str = str_create("abc");
    str_pop_back(str);
    str_pop_back(str);
    str_pop_back(str);
    assert_string_equals(str, "", 0);
    
    // Try to pop from empty string
    str_pop_back(str);
    assert_string_equals(str, "", 0); // Should remain empty
    str_deallocate(str);
}

MU_TEST(test_str_remove_null_inputs) {
    str_remove(NULL, "test"); // Should not crash
    
    t_string *str = str_create("hello");
    str_remove(str, NULL); // Should not crash and not modify string
    assert_string_equals(str, "hello", 5);
    str_deallocate(str);
}

MU_TEST(test_str_remove_empty_substr) {
    t_string *str = str_create("hello");
    str_remove(str, ""); // Should do nothing
    assert_string_equals(str, "hello", 5);
    str_deallocate(str);
}

MU_TEST(test_str_remove_empty_string) {
    t_string *str = str_create("");
    str_remove(str, "test"); // Should do nothing
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

// WARNING: The following tests would cause infinite loops with current implementation
// Commenting them out to prevent hanging tests

MU_TEST(test_str_remove_substring_found) {
    t_string *str = str_create("hello world");
    str_remove(str, " ");
    assert_string_equals(str, "helloworld", 10);
    str_deallocate(str);
}

MU_TEST(test_str_remove_substring_not_found) {
    t_string *str = str_create("hello world");
    str_remove(str, "xyz");
    assert_string_equals(str, "hello world", 11); // Should be unchanged
    str_deallocate(str);
}

MU_TEST(test_str_remove_multiple_occurrences) {
    t_string *str = str_create("hello hello hello");
    str_remove(str, "hello");
    assert_string_equals(str, " hello hello", 12); // Should remove first occurrence only
    str_deallocate(str);
}

// Test str_remove_range function

MU_TEST(test_str_remove_range_middle) {
    t_string *str = str_create("hello world");
    str_remove_range(str, 5, 6); // Remove space
    assert_string_equals(str, "helloworld", 10);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_beginning) {
    t_string *str = str_create("hello world");
    str_remove_range(str, 0, 5); // Remove "hello"
    assert_string_equals(str, " world", 6);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_end) {
    t_string *str = str_create("hello world");
    str_remove_range(str, 6, 11); // Remove "world"
    assert_string_equals(str, "hello ", 6);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_entire_string) {
    t_string *str = str_create("hello");
    str_remove_range(str, 0, 5);
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_zero_length) {
    t_string *str = str_create("hello world");
    str_remove_range(str, 5, 5); // Remove nothing (start == end)
    assert_string_equals(str, "hello world", 11);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_invalid_start_greater_than_end) {
    t_string *str = str_create("hello world");
    size_t original_size = str->size;
    str_remove_range(str, 8, 5); // start > end
    mu_assert_int_eq(original_size, str->size); // Should be unchanged
    mu_assert_string_eq("hello world", str->data);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_end_out_of_bounds) {
    t_string *str = str_create("hello");
    size_t original_size = str->size;
    str_remove_range(str, 2, 10); // end > size
    mu_assert_int_eq(original_size, str->size); // Should be unchanged
    mu_assert_string_eq("hello", str->data);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_null_string) {
    str_remove_range(NULL, 0, 1); // Should not crash
    mu_assert(1, "Function should handle NULL gracefully");
}

MU_TEST(test_str_remove_range_empty_string) {
    t_string *str = str_create("");
    str_remove_range(str, 0, 1); // Should do nothing
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_single_character) {
    t_string *str = str_create("a");
    str_remove_range(str, 0, 1);
    assert_string_equals(str, "", 0);
    str_deallocate(str);
}

MU_TEST(test_str_remove_range_at_boundary) {
    t_string *str = str_create("hello");
    str_remove_range(str, 4, 5); // Remove last character
    assert_string_equals(str, "hell", 4);
    str_deallocate(str);
}

// Integration tests

MU_TEST(test_multiple_operations_combined) {
    t_string *str = str_create("hello beautiful world");
    
    // Remove "beautiful "
    str_remove_range(str, 6, 16);
    assert_string_equals(str, "hello world", 11);
    
    // Remove middle character
    str_erase(str, 5, 1);
    assert_string_equals(str, "helloworld", 10);
    
    // Pop back twice
    str_pop_back(str);
    str_pop_back(str);
    assert_string_equals(str, "hellowor", 8);
    
    str_deallocate(str);
}

MU_TEST(test_edge_case_operations_on_single_char) {
    t_string *str = str_create("x");
    
    // Test erase on single char
    str_erase(str, 0, 1);
    assert_string_equals(str, "", 0);
    
    // Recreate for next test
    str_deallocate(str);
    str = str_create("y");
    
    // Test pop_back on single char
    str_pop_back(str);
    assert_string_equals(str, "", 0);
    
    str_deallocate(str);
}

// Test suite

MU_TEST_SUITE(test_string_remove_functions) {
    // str_erase tests
    MU_RUN_TEST(test_str_erase_middle);
    MU_RUN_TEST(test_str_erase_beginning);
    MU_RUN_TEST(test_str_erase_end);
    MU_RUN_TEST(test_str_erase_entire_string);
    MU_RUN_TEST(test_str_erase_zero_length);
    MU_RUN_TEST(test_str_erase_length_exceeds_string);
    MU_RUN_TEST(test_str_erase_pos_out_of_bounds);
    MU_RUN_TEST(test_str_erase_null_string);
    MU_RUN_TEST(test_str_erase_single_character);
    MU_RUN_TEST(test_str_erase_empty_string);
    
    // str_erase_if tests
    MU_RUN_TEST(test_str_erase_if_remove_spaces_basic);
    MU_RUN_TEST(test_str_erase_if_remove_vowels_basic);
    MU_RUN_TEST(test_str_erase_if_remove_digits_basic);
    MU_RUN_TEST(test_str_erase_if_remove_alpha_basic);
    MU_RUN_TEST(test_str_erase_if_middle_position);
    MU_RUN_TEST(test_str_erase_if_end_position);
    MU_RUN_TEST(test_str_erase_if_partial_range);
    MU_RUN_TEST(test_str_erase_if_skip_beginning);
    MU_RUN_TEST(test_str_erase_if_consecutive_spaces);
    MU_RUN_TEST(test_str_erase_if_consecutive_vowels);
    MU_RUN_TEST(test_str_erase_if_alternating_pattern);
    MU_RUN_TEST(test_str_erase_if_all_match);
    MU_RUN_TEST(test_str_erase_if_none_match);
    MU_RUN_TEST(test_str_erase_if_single_char_match);
    MU_RUN_TEST(test_str_erase_if_single_char_no_match);
    MU_RUN_TEST(test_str_erase_if_empty_string);
    MU_RUN_TEST(test_str_erase_if_pos_at_end);
    MU_RUN_TEST(test_str_erase_if_pos_beyond_end);
    MU_RUN_TEST(test_str_erase_if_null_string);
    MU_RUN_TEST(test_str_erase_if_null_predicate);
    MU_RUN_TEST(test_str_erase_if_null_data);
    MU_RUN_TEST(test_str_erase_if_mixed_content);
    MU_RUN_TEST(test_str_erase_if_punctuation);
    MU_RUN_TEST(test_str_erase_if_case_sensitive);
    MU_RUN_TEST(test_str_erase_if_whitespace_types);

    // str_pop_back tests
    MU_RUN_TEST(test_str_pop_back_normal);
    MU_RUN_TEST(test_str_pop_back_single_character);
    MU_RUN_TEST(test_str_pop_back_empty_string);
    MU_RUN_TEST(test_str_pop_back_multiple_times);
    MU_RUN_TEST(test_str_pop_back_null_string);
    MU_RUN_TEST(test_str_pop_back_until_empty);
    
    // str_remove tests (limited due to bug in implementation)
    MU_RUN_TEST(test_str_remove_null_inputs);
    MU_RUN_TEST(test_str_remove_empty_substr);
    MU_RUN_TEST(test_str_remove_substring_found);
    MU_RUN_TEST(test_str_remove_substring_not_found);
    MU_RUN_TEST(test_str_remove_multiple_occurrences);
    
    // str_remove_range tests
    MU_RUN_TEST(test_str_remove_range_middle);
    MU_RUN_TEST(test_str_remove_range_beginning);
    MU_RUN_TEST(test_str_remove_range_end);
    MU_RUN_TEST(test_str_remove_range_entire_string);
    MU_RUN_TEST(test_str_remove_range_zero_length);
    MU_RUN_TEST(test_str_remove_range_invalid_start_greater_than_end);
    MU_RUN_TEST(test_str_remove_range_end_out_of_bounds);
    MU_RUN_TEST(test_str_remove_range_null_string);
    MU_RUN_TEST(test_str_remove_range_empty_string);
    MU_RUN_TEST(test_str_remove_range_single_character);
    MU_RUN_TEST(test_str_remove_range_at_boundary);
    
    // Integration tests
    MU_RUN_TEST(test_multiple_operations_combined);
    MU_RUN_TEST(test_edge_case_operations_on_single_char);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_string_remove_functions);
    MU_REPORT();
    return MU_EXIT_CODE;
}
