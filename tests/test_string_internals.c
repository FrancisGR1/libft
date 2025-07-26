#include "minunit/minunit.h"
#include "../Strings/string_internals.h"
#include <stdlib.h>

MU_TEST(test_memory_create_valid_capacity) {
    t_string_memory *region = _memory_create(100);
    mu_assert(region != NULL, "Expected non-NULL region for valid capacity");
    mu_assert(region->memory != NULL, "Expected non-NULL memory allocation");
    mu_assert_int_eq(0, region->size);
    mu_assert_int_eq(100, region->capacity);
    _memory_destroy(region);
}

MU_TEST(test_memory_create_zero_capacity) {
    t_string_memory *region = _memory_create(0);
    mu_assert(region == NULL, "Expected NULL region for zero capacity");
}

MU_TEST(test_memory_create_allocation_failure) {
    t_string_memory *region = _memory_create(100);
    mu_assert(region != NULL, "Expected successful allocation");
    mu_assert(region->memory != NULL, "Expected successful memory allocation");
    _memory_destroy(region);
}

MU_TEST(test_region_allocate_valid) {
    t_string_memory *region = _memory_create(100);
    void *ptr = _region_allocate(region, 50);
    mu_assert(ptr != NULL, "Expected non-NULL pointer for valid allocation");
    mu_assert_int_eq(50, region->size);
    mu_assert(ptr == region->memory, "Expected pointer to start of memory");
    _memory_destroy(region);
}

MU_TEST(test_region_allocate_null_region) {
    void *ptr = _region_allocate(NULL, 50);
    mu_assert(ptr == NULL, "Expected NULL pointer for NULL region");
}

MU_TEST(test_region_allocate_exceeds_capacity) {
    t_string_memory *region = _memory_create(100);
    void *ptr = _region_allocate(region, 150);
    mu_assert(ptr == NULL, "Expected NULL pointer for allocation exceeding capacity");
    mu_assert_int_eq(0, region->size);
    _memory_destroy(region);
}

MU_TEST(test_region_allocate_multiple) {
    t_string_memory *region = _memory_create(100);
    void *ptr1 = _region_allocate(region, 30);
    void *ptr2 = _region_allocate(region, 20);
    mu_assert(ptr1 != NULL, "Expected non-NULL pointer for first allocation");
    mu_assert(ptr2 != NULL, "Expected non-NULL pointer for second allocation");
    mu_assert_int_eq(50, region->size);
    mu_assert(ptr2 == (char *)ptr1 + 30, "Expected second pointer to follow first");
    _memory_destroy(region);
}

MU_TEST(test_memory_destroy_valid) {
    t_string_memory *region = _memory_create(100);
    _memory_destroy(region);
    mu_check(1);
}

MU_TEST(test_memory_destroy_null_region) {
    _memory_destroy(NULL);
    mu_check(1);
}

MU_TEST(test_memory_destroy_null_memory) {
    t_string_memory *region = malloc(sizeof(t_string_memory));
    region->memory = NULL;
    region->size = 0;
    region->capacity = 0;
    _memory_destroy(region);
    mu_check(1);
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_memory_create_valid_capacity);
    MU_RUN_TEST(test_memory_create_zero_capacity);
    MU_RUN_TEST(test_memory_create_allocation_failure);
    MU_RUN_TEST(test_region_allocate_valid);
    MU_RUN_TEST(test_region_allocate_null_region);
    MU_RUN_TEST(test_region_allocate_exceeds_capacity);
    MU_RUN_TEST(test_region_allocate_multiple);
    MU_RUN_TEST(test_memory_destroy_valid);
    MU_RUN_TEST(test_memory_destroy_null_region);
    MU_RUN_TEST(test_memory_destroy_null_memory);
}

int main(void) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
