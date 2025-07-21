#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test str_resize function
MU_TEST(test_str_resize_shrink)
{
    t_string *str = str_create("hello world");
    size_t original_size = str->size;
    
    // Shrink the string
    str_resize(str, 5);
    
    mu_assert_int_eq(5, str->size);
    mu_assert_string_eq("hello", str->data);
    mu_check(str->data[5] == '\0');
    
    str_deallocate(str);
}

MU_TEST(test_str_resize_expand_within_capacity)
{
    t_string *str = str_create("hello");
    size_t original_capacity = str->capacity;
    
    // Expand within existing capacity
    str_resize(str, 8);
    
    mu_assert_int_eq(8, str->size);
    mu_assert_int_eq(original_capacity, str->capacity);
    mu_assert_string_eq("hello", str->data);
    mu_check(str->data[5] == '\0');
    mu_check(str->data[6] == '\0');
    mu_check(str->data[7] == '\0');
    
    str_deallocate(str);
}

MU_TEST(test_str_resize_expand_beyond_capacity)
{
    t_string *str = str_create("hi");
    size_t original_capacity = str->capacity;
    
    // Expand beyond current capacity
    str_resize(str, 20);

    mu_assert_int_eq(20, str->size);
    mu_check(str->capacity == original_capacity);
    mu_assert_string_eq("hi", str->data);
    
    // Check that new space is null-filled
    for (size_t i = 2; i < 20; i++) {
        mu_check(str->data[i] == '\0');
    }
    
    str_deallocate(str);
}

MU_TEST(test_str_resize_same_size)
{
    t_string *str = str_create("test");
    size_t original_size = str->size;
    size_t original_capacity = str->capacity;
    
    str_resize(str, original_size);
    
    mu_assert_int_eq(original_size, str->size);
    mu_assert_int_eq(original_capacity, str->capacity);
    mu_assert_string_eq("test", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_resize_null_string)
{
    // Should handle NULL gracefully without crashing
    str_resize(NULL, 10);
    
    t_string *str = str_create("test");
    str->data = NULL;
    str_resize(str, 10);
    
    str_deallocate(str);
}

// Test str_reserve function
MU_TEST(test_str_reserve_increase_capacity)
{
    t_string *str = str_create("hello");
    size_t original_size = str->size;
    
    str_reserve(str, 50);
    
    mu_assert_int_eq(original_size, str->size);
    mu_check(str->capacity >= 50);
    mu_assert_string_eq("hello", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_reserve_smaller_than_current)
{
    t_string *str = str_create("hello world");
    size_t original_capacity = str->capacity;
    size_t original_size = str->size;
    
    // Request smaller capacity than current
    str_reserve(str, 5);
    
    // Should not change capacity if requested is smaller
    mu_assert_int_eq(original_capacity, str->capacity);
    mu_assert_int_eq(original_size, str->size);
    mu_assert_string_eq("hello world", str->data);
    
    str_deallocate(str);
}

MU_TEST(test_str_reserve_null_string)
{
    // Should handle NULL gracefully
    str_reserve(NULL, 10);
}

// Test str_shrink_to_fit function
MU_TEST(test_str_shrink_to_fit_normal)
{
    t_string *str = str_create("hello");
    
    // First expand capacity
    str_reserve(str, 100);
    size_t large_capacity = str->capacity;
    
    // Then shrink to fit
    str_shrink_to_fit(str);
    
    mu_assert_int_eq(str->size + 1, str->capacity);
    mu_assert_string_eq("hello", str->data);
    mu_check(str->capacity < large_capacity);
    
    str_deallocate(str);
}

MU_TEST(test_str_shrink_to_fit_already_optimal)
{
    t_string *str = str_create("test");
    
    // If already optimal size, should not change
    if (str->capacity == str->size + 1) {
        size_t original_capacity = str->capacity;
        str_shrink_to_fit(str);
        mu_assert_int_eq(original_capacity, str->capacity);
    }
    
    str_deallocate(str);
}

MU_TEST(test_str_shrink_to_fit_null_string)
{
    // Should handle NULL gracefully
    str_shrink_to_fit(NULL);
    
    t_string *str = str_create("test");
    str->data = NULL;
    str_shrink_to_fit(str);
    
    str_deallocate(str);
}

// Test str_set_memory_size function
MU_TEST(test_str_set_memory_size_valid)
{
    t_string *str = str_create("hello world");
    char *original_data = ft_strdup(str->data);
    
    bool result = str_set_memory_size(str, 100);
    
    mu_check(result == true);
    mu_assert_string_eq(original_data, str->data);
    
    free(original_data);
    str_deallocate(str);
}

MU_TEST(test_str_set_memory_size_zero)
{
    t_string *str = str_create("test");
    
    bool result = str_set_memory_size(str, 0);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_set_memory_size_null_string)
{
    bool result = str_set_memory_size(NULL, 100);
    mu_check(result == false);
}

MU_TEST(test_str_set_memory_size_empty_string)
{
    t_string *str = str_create("");
    bool result = str_set_memory_size(str, 50);
    
    mu_check(result == true);
    mu_assert_string_eq(str->data, "");
    str_deallocate(str);
}

// Test suite
MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_str_resize_shrink);
    MU_RUN_TEST(test_str_resize_expand_within_capacity);
    MU_RUN_TEST(test_str_resize_expand_beyond_capacity);
    MU_RUN_TEST(test_str_resize_same_size);
    MU_RUN_TEST(test_str_resize_null_string);
    
    MU_RUN_TEST(test_str_reserve_increase_capacity);
    MU_RUN_TEST(test_str_reserve_smaller_than_current);
    MU_RUN_TEST(test_str_reserve_null_string);
    
    MU_RUN_TEST(test_str_shrink_to_fit_normal);
    MU_RUN_TEST(test_str_shrink_to_fit_already_optimal);
    MU_RUN_TEST(test_str_shrink_to_fit_null_string);
    
    MU_RUN_TEST(test_str_set_memory_size_valid);
    MU_RUN_TEST(test_str_set_memory_size_zero);
    MU_RUN_TEST(test_str_set_memory_size_null_string);
    MU_RUN_TEST(test_str_set_memory_size_empty_string);
}

int main(void)
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
