#include "minunit/minunit.h"
#include "../Strings/strings.h"

MU_TEST(test_str_copy_valid) {
    t_string *str = str_create("hello");
    char buffer[10] = {0};
    size_t copied = str_copy(str, buffer, 0, 5);
    mu_assert_int_eq(5, copied);
    mu_assert_string_eq("hello", buffer);
    str_deallocate(str);
}

MU_TEST(test_str_copy_partial) {
    t_string *str = str_create("hello");
    char buffer[10] = {0};
    size_t copied = str_copy(str, buffer, 1, 3);
    mu_assert_int_eq(3, copied);
    mu_assert_string_eq("ell", buffer);
    str_deallocate(str);
}

MU_TEST(test_str_copy_null_string) {
    char buffer[10] = {0};
    size_t copied = str_copy(NULL, buffer, 0, 5);
    mu_assert_int_eq(0, copied);
    mu_assert_string_eq("", buffer);
}

MU_TEST(test_str_copy_null_buffer) {
    t_string *str = str_create("hello");
    size_t copied = str_copy(str, NULL, 0, 5);
    mu_assert_int_eq(0, copied);
    str_deallocate(str);
}

MU_TEST(test_str_copy_null_data) {
    t_string *str = str_create("");
    str->data = NULL; // Simulate uninitialized data
    char buffer[10] = {0};
    size_t copied = str_copy(str, buffer, 0, 5);
    mu_assert_int_eq(0, copied);
    mu_assert_string_eq("", buffer);
    str_deallocate(str);
}

MU_TEST(test_str_copy_pos_beyond_size) {
    t_string *str = str_create("hello");
    char buffer[10] = {0};
    size_t copied = str_copy(str, buffer, 10, 5);
    mu_assert_int_eq(0, copied);
    mu_assert_string_eq("", buffer);
    str_deallocate(str);
}

MU_TEST(test_str_copy_zero_length) {
    t_string *str = str_create("hello");
    char buffer[10] = {0};
    size_t copied = str_copy(str, buffer, 0, 0);
    mu_assert_int_eq(5, copied); // Copies entire string when len is 0
    mu_assert_string_eq("hello", buffer);
    str_deallocate(str);
}

MU_TEST(test_str_copy_exceeds_size) {
    t_string *str = str_create("hello");
    char buffer[10] = {0};
    size_t copied = str_copy(str, buffer, 2, 10);
    mu_assert_int_eq(3, copied); // Copies from pos to end (size - pos)
    mu_assert_string_eq("llo", buffer);
    str_deallocate(str);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_str_copy_valid);
    MU_RUN_TEST(test_str_copy_partial);
    MU_RUN_TEST(test_str_copy_null_string);
    MU_RUN_TEST(test_str_copy_null_buffer);
    MU_RUN_TEST(test_str_copy_null_data);
    MU_RUN_TEST(test_str_copy_pos_beyond_size);
    MU_RUN_TEST(test_str_copy_zero_length);
    MU_RUN_TEST(test_str_copy_exceeds_size);
}

int main(void) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
