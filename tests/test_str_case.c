#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test str_to_upper function
MU_TEST(test_str_to_upper_basic) {
    t_string *str = str_create("hello world");
    char *result = str_to_upper(str);
    
    mu_assert_string_eq("HELLO WORLD", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_upper_mixed_case) {
    t_string *str = str_create("HeLLo WoRLd");
    char *result = str_to_upper(str);
    
    mu_assert_string_eq("HELLO WORLD", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_upper_with_numbers) {
    t_string *str = str_create("hello123world");
    char *result = str_to_upper(str);
    
    mu_assert_string_eq("HELLO123WORLD", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_upper_with_special_chars) {
    t_string *str = str_create("hello-world!");
    char *result = str_to_upper(str);
    
    mu_assert_string_eq("HELLO-WORLD!", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_upper_empty_string) {
    t_string *str = str_create("");
    char *result = str_to_upper(str);
    
    mu_assert_string_eq("", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_upper_null_input) {
    char *result = str_to_upper(NULL);
    mu_assert(result == NULL, "Should return NULL for NULL input");
}

MU_TEST(test_str_to_upper_already_upper) {
    t_string *str = str_create("ALREADY UPPER");
    char *result = str_to_upper(str);
    
    mu_assert_string_eq("ALREADY UPPER", result);
    
    free(result);
    str_deallocate(str);
}

// Test str_to_lower function
MU_TEST(test_str_to_lower_basic) {
    t_string *str = str_create("HELLO WORLD");
    char *result = str_to_lower(str);
    
    mu_assert_string_eq("hello world", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_lower_mixed_case) {
    t_string *str = str_create("HeLLo WoRLd");
    char *result = str_to_lower(str);
    
    mu_assert_string_eq("hello world", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_lower_with_numbers) {
    t_string *str = str_create("HELLO123WORLD");
    char *result = str_to_lower(str);
    
    mu_assert_string_eq("hello123world", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_lower_with_special_chars) {
    t_string *str = str_create("HELLO-WORLD!");
    char *result = str_to_lower(str);
    
    mu_assert_string_eq("hello-world!", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_lower_empty_string) {
    t_string *str = str_create("");
    char *result = str_to_lower(str);
    
    mu_assert_string_eq("", result);
    
    free(result);
    str_deallocate(str);
}

MU_TEST(test_str_to_lower_null_input) {
    char *result = str_to_lower(NULL);
    mu_assert(result == NULL, "Should return NULL for NULL input");
}

MU_TEST(test_str_to_lower_already_lower) {
    t_string *str = str_create("already lower");
    char *result = str_to_lower(str);
    
    mu_assert_string_eq("already lower", result);
    
    free(result);
    str_deallocate(str);
}

// Test str_to_title function
MU_TEST(test_str_to_title_basic) {
    t_string *str = str_create("hello world");
    str_to_title(str);
    
    mu_assert_string_eq("Hello World", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_title_multiple_words) {
    t_string *str = str_create("the quick brown fox");
    str_to_title(str);
    
    mu_assert_string_eq("The Quick Brown Fox", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_title_with_punctuation) {
    t_string *str = str_create("hello, world! how are you?");
    str_to_title(str);
    
    mu_assert_string_eq("Hello, World! How Are You?", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_title_with_numbers) {
    t_string *str = str_create("test123 another456test");
    str_to_title(str);
    
    mu_assert_string_eq("Test123 Another456Test", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_title_mixed_case) {
    t_string *str = str_create("hELLo WoRLd");
    str_to_title(str);
    
    mu_assert_string_eq("Hello World", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_title_empty_string) {
    t_string *str = str_create("");
    str_to_title(str);
    
    mu_assert_string_eq("", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_title_null_input) {
    str_to_title(NULL);
    // Should not crash - test passes if no segfault
    mu_check(1);
}

MU_TEST(test_str_to_title_single_char) {
    t_string *str = str_create("a");
    str_to_title(str);
    
    mu_assert_string_eq("A", str->data);
    
    str_deallocate(str);
}

// Test str_to_capitalize function
MU_TEST(test_str_to_capitalize_basic) {
    t_string *str = str_create("hello world");
    str_to_capitalize(str);
    
    mu_assert_string_eq("Hello world", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_capitalize_already_capitalized) {
    t_string *str = str_create("Hello world");
    str_to_capitalize(str);
    
    mu_assert_string_eq("Hello world", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_capitalize_all_upper) {
    t_string *str = str_create("HELLO WORLD");
    str_to_capitalize(str);
    
    mu_assert_string_eq("HELLO WORLD", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_capitalize_starts_with_number) {
    t_string *str = str_create("123hello");
    str_to_capitalize(str);
    
    mu_assert_string_eq("123hello", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_capitalize_single_char) {
    t_string *str = str_create("a");
    str_to_capitalize(str);
    
    mu_assert_string_eq("A", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_capitalize_empty_string) {
    t_string *str = str_create("");
    str_to_capitalize(str);
    
    mu_assert_string_eq("", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_capitalize_null_input) {
    str_to_capitalize(NULL);
    // Should not crash - test passes if no segfault
    mu_check(1);
}

// Test str_to_casefold function
MU_TEST(test_str_to_casefold_basic) {
    t_string *str = str_create("HELLO WORLD");
    str_to_casefold(str);
    
    mu_assert_string_eq("hello world", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_casefold_mixed_case) {
    t_string *str = str_create("HeLLo WoRLd");
    str_to_casefold(str);
    
    mu_assert_string_eq("hello world", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_casefold_with_numbers) {
    t_string *str = str_create("HELLO123WORLD");
    str_to_casefold(str);
    
    mu_assert_string_eq("hello123world", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_casefold_with_special_chars) {
    t_string *str = str_create("HELLO-WORLD!");
    str_to_casefold(str);
    
    mu_assert_string_eq("hello-world!", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_casefold_already_lower) {
    t_string *str = str_create("already lower");
    str_to_casefold(str);
    
    mu_assert_string_eq("already lower", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_casefold_empty_string) {
    t_string *str = str_create("");
    str_to_casefold(str);
    
    mu_assert_string_eq("", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_to_casefold_null_input) {
    str_to_casefold(NULL);
    // Should not crash - test passes if no segfault
    mu_check(1);
}

// Test suite
MU_TEST_SUITE(test_suite_str_to_upper) {
    MU_RUN_TEST(test_str_to_upper_basic);
    MU_RUN_TEST(test_str_to_upper_mixed_case);
    MU_RUN_TEST(test_str_to_upper_with_numbers);
    MU_RUN_TEST(test_str_to_upper_with_special_chars);
    MU_RUN_TEST(test_str_to_upper_empty_string);
    MU_RUN_TEST(test_str_to_upper_null_input);
    MU_RUN_TEST(test_str_to_upper_already_upper);
}

MU_TEST_SUITE(test_suite_str_to_lower) {
    MU_RUN_TEST(test_str_to_lower_basic);
    MU_RUN_TEST(test_str_to_lower_mixed_case);
    MU_RUN_TEST(test_str_to_lower_with_numbers);
    MU_RUN_TEST(test_str_to_lower_with_special_chars);
    MU_RUN_TEST(test_str_to_lower_empty_string);
    MU_RUN_TEST(test_str_to_lower_null_input);
    MU_RUN_TEST(test_str_to_lower_already_lower);
}

MU_TEST_SUITE(test_suite_str_to_title) {
    MU_RUN_TEST(test_str_to_title_basic);
    MU_RUN_TEST(test_str_to_title_multiple_words);
    MU_RUN_TEST(test_str_to_title_with_punctuation);
    MU_RUN_TEST(test_str_to_title_with_numbers);
    MU_RUN_TEST(test_str_to_title_mixed_case);
    MU_RUN_TEST(test_str_to_title_empty_string);
    MU_RUN_TEST(test_str_to_title_null_input);
    MU_RUN_TEST(test_str_to_title_single_char);
}

MU_TEST_SUITE(test_suite_str_to_capitalize) {
    MU_RUN_TEST(test_str_to_capitalize_basic);
    MU_RUN_TEST(test_str_to_capitalize_already_capitalized);
    MU_RUN_TEST(test_str_to_capitalize_all_upper);
    MU_RUN_TEST(test_str_to_capitalize_starts_with_number);
    MU_RUN_TEST(test_str_to_capitalize_single_char);
    MU_RUN_TEST(test_str_to_capitalize_empty_string);
    MU_RUN_TEST(test_str_to_capitalize_null_input);
}

MU_TEST_SUITE(test_suite_str_to_casefold) {
    MU_RUN_TEST(test_str_to_casefold_basic);
    MU_RUN_TEST(test_str_to_casefold_mixed_case);
    MU_RUN_TEST(test_str_to_casefold_with_numbers);
    MU_RUN_TEST(test_str_to_casefold_with_special_chars);
    MU_RUN_TEST(test_str_to_casefold_already_lower);
    MU_RUN_TEST(test_str_to_casefold_empty_string);
    MU_RUN_TEST(test_str_to_casefold_null_input);
}

// Main function to run all tests
int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite_str_to_upper);
    MU_RUN_SUITE(test_suite_str_to_lower);
    MU_RUN_SUITE(test_suite_str_to_title);
    MU_RUN_SUITE(test_suite_str_to_capitalize);
    MU_RUN_SUITE(test_suite_str_to_casefold);
    
    MU_REPORT();
    return MU_EXIT_CODE;
}
