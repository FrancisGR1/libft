#include "./minunit/minunit.h"
#include "../Strings/strings.h"

// Test str_length with valid string
MU_TEST(test_str_length_valid) {
    t_string *str = str_create("hello");
    size_t length = str_length(str);
    
    mu_assert_int_eq(5, length);
    
    str_deallocate(str);
}

// Test str_length with empty string
MU_TEST(test_str_length_empty) {
    t_string *str = str_create("");
    size_t length = str_length(str);
    
    mu_assert_int_eq(0, length);
    
    str_deallocate(str);
}

// Test str_length with NULL string
MU_TEST(test_str_length_null) {
    size_t length = str_length(NULL);
    
    mu_assert_int_eq(0, length);
}

// Test str_length with longer string
MU_TEST(test_str_length_longer) {
    t_string *str = str_create("Hello, World!");
    size_t length = str_length(str);
    
    mu_assert_int_eq(13, length);
    
    str_deallocate(str);
}

// Test str_length with single character
MU_TEST(test_str_length_single_char) {
    t_string *str = str_create("A");
    size_t length = str_length(str);
    
    mu_assert_int_eq(1, length);
    
    str_deallocate(str);
}

// Test str_capacity with valid string
MU_TEST(test_str_capacity_valid) {
    t_string *str = str_create("hello");
    size_t capacity = str_capacity(str);
    
    mu_assert(capacity >= 5, "capacity should be at least the string length");
    
    str_deallocate(str);
}

// Test str_capacity with empty string
MU_TEST(test_str_capacity_empty) {
    t_string *str = str_create("");
    size_t capacity = str_capacity(str);
    
    mu_assert(capacity >= 0, "capacity should be non-negative");
    
    str_deallocate(str);
}

// Test str_capacity with NULL string
MU_TEST(test_str_capacity_null) {
    size_t capacity = str_capacity(NULL);
    
    mu_assert_int_eq(0, capacity);
}

// Test str_capacity with longer string
MU_TEST(test_str_capacity_longer) {
    t_string *str = str_create("Hello, World!");
    size_t capacity = str_capacity(str);
    
    mu_assert(capacity >= 13, "capacity should be at least the string length");
    
    str_deallocate(str);
}

// Test str_capacity with single character
MU_TEST(test_str_capacity_single_char) {
    t_string *str = str_create("A");
    size_t capacity = str_capacity(str);
    
    mu_assert(capacity >= 1, "capacity should be at least 1");
    
    str_deallocate(str);
}

// Test str_max_size returns consistent value
MU_TEST(test_str_max_size_consistent) {
    size_t max_size1 = str_max_size();
    size_t max_size2 = str_max_size();
    
    mu_assert_int_eq(max_size1, max_size2);
}

// Test str_max_size returns positive value
MU_TEST(test_str_max_size_positive) {
    size_t max_size = str_max_size();
    
    mu_assert(max_size > 0, "max size should be positive");
}

// Test str_empty with empty string
MU_TEST(test_str_empty_empty_string) {
    t_string *str = str_create("");
    bool is_empty = str_empty(str);
    
    mu_assert(is_empty == true, "empty string should return true");
    
    str_deallocate(str);
}

// Test str_empty with NULL string
MU_TEST(test_str_empty_null) {
    bool is_empty = str_empty(NULL);
    
    mu_assert(is_empty == true, "NULL string should return true");
}

// Test str_empty with non-empty string
MU_TEST(test_str_empty_non_empty) {
    t_string *str = str_create("hello");
    bool is_empty = str_empty(str);
    
    mu_assert(is_empty == false, "non-empty string should return false");
    
    str_deallocate(str);
}

// Test str_empty with single character
MU_TEST(test_str_empty_single_char) {
    t_string *str = str_create("A");
    bool is_empty = str_empty(str);
    
    mu_assert(is_empty == false, "single character string should return false");
    
    str_deallocate(str);
}

// Test str_empty with whitespace
MU_TEST(test_str_empty_whitespace) {
    t_string *str = str_create(" ");
    bool is_empty = str_empty(str);
    
    mu_assert(is_empty == false, "whitespace string should return false");
    
    str_deallocate(str);
}

// Test relationship between length and capacity
MU_TEST(test_length_capacity_relationship) {
    t_string *str = str_create("hello world");
    size_t length = str_length(str);
    size_t capacity = str_capacity(str);
    
    mu_assert(capacity >= length, "capacity should be greater than or equal to length");
    
    str_deallocate(str);
}

// Test consistency of length and empty
MU_TEST(test_length_empty_consistency) {
    t_string *str1 = str_create("");
    t_string *str2 = str_create("test");
    
    mu_assert((str_length(str1) == 0) == str_empty(str1), "length 0 should match empty result");
    mu_assert((str_length(str2) == 0) == str_empty(str2), "non-zero length should match empty result");
    
    str_deallocate(str1);
    str_deallocate(str2);
}

// Test max_size is reasonable
MU_TEST(test_max_size_reasonable) {
    size_t max_size = str_max_size();
    
    mu_assert(max_size >= 1000, "max size should be reasonably large");
    mu_assert(max_size <= SIZE_MAX, "max size should not exceed SIZE_MAX");
}

// Test suite
MU_TEST_SUITE(string_util_test_suite) {
    MU_RUN_TEST(test_str_length_valid);
    MU_RUN_TEST(test_str_length_empty);
    MU_RUN_TEST(test_str_length_null);
    MU_RUN_TEST(test_str_length_longer);
    MU_RUN_TEST(test_str_length_single_char);
    
    MU_RUN_TEST(test_str_capacity_valid);
    MU_RUN_TEST(test_str_capacity_empty);
    MU_RUN_TEST(test_str_capacity_null);
    MU_RUN_TEST(test_str_capacity_longer);
    MU_RUN_TEST(test_str_capacity_single_char);
    
    MU_RUN_TEST(test_str_max_size_consistent);
    MU_RUN_TEST(test_str_max_size_positive);
    
    MU_RUN_TEST(test_str_empty_empty_string);
    MU_RUN_TEST(test_str_empty_null);
    MU_RUN_TEST(test_str_empty_non_empty);
    MU_RUN_TEST(test_str_empty_single_char);
    MU_RUN_TEST(test_str_empty_whitespace);
    
    MU_RUN_TEST(test_length_capacity_relationship);
    MU_RUN_TEST(test_length_empty_consistency);
    MU_RUN_TEST(test_max_size_reasonable);
}

int main() {
    MU_RUN_SUITE(string_util_test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
