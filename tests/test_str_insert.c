#include "./minunit/minunit.h"
#include "../Strings/strings.h"
// ========== str_append Tests ==========

MU_TEST(test_str_append_normal) {
    t_string *str = str_create("Hello");
    str_append(str, " World");
    mu_assert_string_eq("Hello World", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_append_empty_string) {
    t_string *str = str_create("Hello");
    size_t original_size = str->size;
    str_append(str, "");
    mu_assert_string_eq("Hello", str->data);
    mu_assert_int_eq(original_size, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_append_to_empty_string) {
    t_string *str = str_create("");
    str_append(str, "World");
    mu_assert_string_eq("World", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_append_null_string) {
    t_string *str = str_create("Hello");
    size_t original_size = str->size;
    str_append(NULL, "World");
    str_append(str, NULL);
    mu_assert_string_eq("Hello", str->data);
    mu_assert_int_eq(original_size, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_append_multiple_times) {
    t_string *str = str_create("A");
    str_append(str, "B");
    str_append(str, "C");
    str_append(str, "D");
    mu_assert_string_eq("ABCD", str->data);
    mu_assert_int_eq(4, str->size);
    str_deallocate(str);
}

// ========== str_push_back Tests ==========

MU_TEST(test_str_push_back_normal) {
    t_string *str = str_create("Hello");
    str_push_back(str, '!');
    mu_assert_string_eq("Hello!", str->data);
    mu_assert_int_eq(6, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_push_back_to_empty) {
    t_string *str = str_create("");
    str_push_back(str, 'A');
    mu_assert_string_eq("A", str->data);
    mu_assert_int_eq(1, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_push_back_null_string) {
    str_push_back(NULL, 'A');
    mu_assert(1, "Did not crash!");
}

MU_TEST(test_str_push_back_multiple_chars) {
    t_string *str = str_create("Hi");
    str_push_back(str, ' ');
    str_push_back(str, 'B');
    str_push_back(str, 'o');
    str_push_back(str, 'b');
    mu_assert_string_eq("Hi Bob", str->data);
    mu_assert_int_eq(6, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_push_back_null_termination) {
    t_string *str = str_create("Test");
    str_push_back(str, 'Z');
    mu_assert_int_eq('\0', str->data[str->size]);
    str_deallocate(str);
}

// ========== str_insert Tests ==========

MU_TEST(test_str_insert_at_beginning) {
    t_string *str = str_create("World");
    str_insert(str, 0, "Hello ");
    mu_assert_string_eq("Hello World", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_insert_at_middle) {
    t_string *str = str_create("HelloWorld");
    str_insert(str, 5, " ");
    mu_assert_string_eq("Hello World", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_insert_at_end) {
    t_string *str = str_create("Hello");
    str_insert(str, str->size, " World");
    mu_assert_string_eq("Hello World", str->data);
    mu_assert_int_eq(11, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_insert_empty_string) {
    t_string *str = str_create("Hello");
    size_t original_size = str->size;
    str_insert(str, 2, "");
    mu_assert_string_eq("Hello", str->data);
    mu_assert_int_eq(original_size, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_insert_into_empty) {
    t_string *str = str_create("");
    str_insert(str, 0, "Hello");
    mu_assert_string_eq("Hello", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_insert_null_parameters) {
    t_string *str = str_create("Hello");
    size_t original_size = str->size;
    
    str_insert(NULL, 0, "World");
    str_insert(str, 0, NULL);
    
    mu_assert_string_eq("Hello", str->data);
    mu_assert_int_eq(original_size, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_insert_invalid_position) {
    t_string *str = str_create("Hello");
    size_t original_size = str->size;
    
    str_insert(str, str->size + 10, "World");
    mu_assert_string_eq("Hello", str->data);
    mu_assert_int_eq(original_size, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_insert_multiple_insertions) {
    t_string *str = str_create("ac");
    str_insert(str, 1, "b");
    str_insert(str, 0, "0");
    str_insert(str, str->size, "d");
    mu_assert_string_eq("0abcd", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

// ========== str_assign Tests ==========

MU_TEST(test_str_assign_normal) {
    t_string *str = str_create("Hello");
    str_assign(str, "World");
    mu_assert_string_eq("World", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_assign_longer_string) {
    t_string *str = str_create("Hi");
    str_assign(str, "This is a much longer string");
    mu_assert_string_eq("This is a much longer string", str->data);
    mu_assert_int_eq(28, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_assign_shorter_string) {
    t_string *str = str_create("This is a very long string");
    str_assign(str, "Short");
    mu_assert_string_eq("Short", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_assign_empty_string) {
    t_string *str = str_create("Hello");
    str_assign(str, "");
    mu_assert_string_eq("", str->data);
    mu_assert_int_eq(0, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_assign_null_parameters) {
    t_string *str = str_create("Hello");
    size_t original_size = str->size;
    
    str_assign(NULL, "World");
    str_assign(str, NULL);
    
    mu_assert_string_eq("Hello", str->data);
    mu_assert_int_eq(original_size, str->size);
    str_deallocate(str);
}

MU_TEST(test_str_assign_same_string) {
    t_string *str = str_create("Hello");
    str_assign(str, "Hello");
    mu_assert_string_eq("Hello", str->data);
    mu_assert_int_eq(5, str->size);
    str_deallocate(str);
}

// ========== Test Suites ==========

MU_TEST_SUITE(test_str_append_suite) {
    MU_RUN_TEST(test_str_append_normal);
    MU_RUN_TEST(test_str_append_empty_string);
    MU_RUN_TEST(test_str_append_to_empty_string);
    MU_RUN_TEST(test_str_append_null_string);
    MU_RUN_TEST(test_str_append_multiple_times);
}

MU_TEST_SUITE(test_str_push_back_suite) {
    MU_RUN_TEST(test_str_push_back_normal);
    MU_RUN_TEST(test_str_push_back_to_empty);
    MU_RUN_TEST(test_str_push_back_null_string);
    MU_RUN_TEST(test_str_push_back_multiple_chars);
    MU_RUN_TEST(test_str_push_back_null_termination);
}

MU_TEST_SUITE(test_str_insert_suite) {
    MU_RUN_TEST(test_str_insert_at_beginning);
    MU_RUN_TEST(test_str_insert_at_middle);
    MU_RUN_TEST(test_str_insert_at_end);
    MU_RUN_TEST(test_str_insert_empty_string);
    MU_RUN_TEST(test_str_insert_into_empty);
    MU_RUN_TEST(test_str_insert_null_parameters);
    MU_RUN_TEST(test_str_insert_invalid_position);
    MU_RUN_TEST(test_str_insert_multiple_insertions);
}

MU_TEST_SUITE(test_str_assign_suite) {
    MU_RUN_TEST(test_str_assign_normal);
    MU_RUN_TEST(test_str_assign_longer_string);
    MU_RUN_TEST(test_str_assign_shorter_string);
    MU_RUN_TEST(test_str_assign_empty_string);
    MU_RUN_TEST(test_str_assign_null_parameters);
    MU_RUN_TEST(test_str_assign_same_string);
}

// ========== Main Test Runner ==========

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_str_append_suite);
    MU_RUN_SUITE(test_str_push_back_suite);
    MU_RUN_SUITE(test_str_insert_suite);
    MU_RUN_SUITE(test_str_assign_suite);
    
    MU_REPORT();
    return MU_EXIT_CODE;
}
