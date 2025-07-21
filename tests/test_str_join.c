#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test str_join function
MU_TEST(test_str_join_basic) {
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("world");
    t_string *str3 = str_create("test");
    t_string *strings[] = {str1, str2, str3};
    
    t_string *result = str_join(strings, 3, ", ");
    
    mu_assert(result != NULL, "str_join should not return NULL");
    mu_assert_string_eq("hello, world, test", result->data);
    
    str_deallocate(str1);
    str_deallocate(str2);
    str_deallocate(str3);
    str_deallocate(result);
}

MU_TEST(test_str_join_single_string) {
    t_string *str1 = str_create("alone");
    t_string *strings[] = {str1};
    
    t_string *result = str_join(strings, 1, ", ");
    
    mu_assert(result != NULL, "str_join should not return NULL");
    mu_assert_string_eq("alone", result->data);
    
    str_deallocate(str1);
    str_deallocate(result);
}

MU_TEST(test_str_join_empty_strings) {
    t_string *str1 = str_create("");
    t_string *str2 = str_create("");
    t_string *strings[] = {str1, str2};
    
    t_string *result = str_join(strings, 2, "-");
    
    mu_assert(result != NULL, "str_join should not return NULL");
    mu_assert_string_eq("-", result->data);
    
    str_deallocate(str1);
    str_deallocate(str2);
    str_deallocate(result);
}

MU_TEST(test_str_join_different_delimiter) {
    t_string *str1 = str_create("a");
    t_string *str2 = str_create("b");
    t_string *str3 = str_create("c");
    t_string *strings[] = {str1, str2, str3};
    
    t_string *result = str_join(strings, 3, " | ");
    
    mu_assert(result != NULL, "str_join should not return NULL");
    mu_assert_string_eq("a | b | c", result->data);
    
    str_deallocate(str1);
    str_deallocate(str2);
    str_deallocate(str3);
    str_deallocate(result);
}

MU_TEST(test_str_join_no_delimiter) {
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("world");
    t_string *strings[] = {str1, str2};
    
    t_string *result = str_join(strings, 2, "");
    
    mu_assert(result != NULL, "str_join should not return NULL");
    mu_assert_string_eq("helloworld", result->data);
    
    str_deallocate(str1);
    str_deallocate(str2);
    str_deallocate(result);
}

MU_TEST(test_str_join_null_strings) {
    t_string *result = str_join(NULL, 3, ", ");
    mu_assert(result == NULL, "str_join should return NULL for NULL strings array");
}

MU_TEST(test_str_join_zero_count) {
    t_string *str1 = str_create("test");
    t_string *strings[] = {str1};
    
    t_string *result = str_join(strings, 0, ", ");
    mu_assert(result == NULL, "str_join should return NULL for zero count");
    
    str_deallocate(str1);
}

MU_TEST(test_str_join_null_delimiter) {
    t_string *str1 = str_create("hello");
    t_string *strings[] = {str1};
    
    t_string *result = str_join(strings, 1, NULL);
    mu_assert(result == NULL, "str_join should return NULL for NULL delimiter");
    
    str_deallocate(str1);
}

// Test str_join_variadic function
MU_TEST(test_str_join_variadic_basic) {
    t_string *str1 = str_create("hello");
    t_string *str2 = str_create("world");
    t_string *str3 = str_create("test");
    
    t_string *result = str_join_variadic(3, str1, str2, str3);
    
    mu_assert(result != NULL, "str_join_variadic should not return NULL");
    mu_assert_string_eq("helloworldtest", result->data);
    
    str_deallocate(str1);
    str_deallocate(str2);
    str_deallocate(str3);
    str_deallocate(result);
}

MU_TEST(test_str_join_variadic_single) {
    t_string *str1 = str_create("alone");
    
    t_string *result = str_join_variadic(1, str1);
    
    mu_assert(result != NULL, "str_join_variadic should not return NULL");
    mu_assert_string_eq("alone", result->data);
    
    str_deallocate(str1);
    str_deallocate(result);
}

MU_TEST(test_str_join_variadic_empty_strings) {
    t_string *str1 = str_create("");
    t_string *str2 = str_create("");
    
    t_string *result = str_join_variadic(2, str1, str2);
    
    mu_assert(result != NULL, "str_join_variadic should not return NULL");
    mu_assert_string_eq("", result->data);
    
    str_deallocate(str1);
    str_deallocate(str2);
    str_deallocate(result);
}

MU_TEST(test_str_join_variadic_mixed_lengths) {
    t_string *str1 = str_create("a");
    t_string *str2 = str_create("longer");
    t_string *str3 = str_create("x");
    t_string *str4 = str_create("medium");
    
    t_string *result = str_join_variadic(4, str1, str2, str3, str4);
    
    mu_assert(result != NULL, "str_join_variadic should not return NULL");
    mu_assert_string_eq("alongerxmedium", result->data);
    
    str_deallocate(str1);
    str_deallocate(str2);
    str_deallocate(str3);
    str_deallocate(str4);
    str_deallocate(result);
}

MU_TEST(test_str_join_variadic_zero_count) {
    t_string *result = str_join_variadic(0);
    
    mu_assert(result != NULL, "str_join_variadic should not return NULL for zero count");
    mu_assert_string_eq("", result->data);
    
    str_deallocate(result);
}

MU_TEST(test_str_join_variadic_large_count) {
    t_string *str1 = str_create("1");
    t_string *str2 = str_create("2");
    t_string *str3 = str_create("3");
    t_string *str4 = str_create("4");
    t_string *str5 = str_create("5");
    t_string *str6 = str_create("6");
    
    t_string *result = str_join_variadic(6, str1, str2, str3, str4, str5, str6);
    
    mu_assert(result != NULL, "str_join_variadic should not return NULL");
    mu_assert_string_eq("123456", result->data);
    
    str_deallocate(str1);
    str_deallocate(str2);
    str_deallocate(str3);
    str_deallocate(str4);
    str_deallocate(str5);
    str_deallocate(str6);
    str_deallocate(result);
}

// Test suite for str_join
MU_TEST_SUITE(test_str_join_suite) {
    MU_RUN_TEST(test_str_join_basic);
    MU_RUN_TEST(test_str_join_single_string);
    MU_RUN_TEST(test_str_join_empty_strings);
    MU_RUN_TEST(test_str_join_different_delimiter);
    MU_RUN_TEST(test_str_join_no_delimiter);
    MU_RUN_TEST(test_str_join_null_strings);
    MU_RUN_TEST(test_str_join_zero_count);
    MU_RUN_TEST(test_str_join_null_delimiter);
}

// Test suite for str_join_variadic
MU_TEST_SUITE(test_str_join_variadic_suite) {
    MU_RUN_TEST(test_str_join_variadic_basic);
    MU_RUN_TEST(test_str_join_variadic_single);
    MU_RUN_TEST(test_str_join_variadic_empty_strings);
    MU_RUN_TEST(test_str_join_variadic_mixed_lengths);
    MU_RUN_TEST(test_str_join_variadic_zero_count);
    MU_RUN_TEST(test_str_join_variadic_large_count);
}

// Main function to run all tests
int main() {
    MU_RUN_SUITE(test_str_join_suite);
    MU_RUN_SUITE(test_str_join_variadic_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
