#include "minunit/minunit.h"
#include "../Strings/string_internals.h"

// Test fixture setup/teardown
static void setup_test() {
    // Reset global state before each test
    if (*_global_memory_is_created_ref()) {
        _destroy_global_memory();
    }
}

static void teardown_test() {
    // Clean up after each test
    if (*_global_memory_is_created_ref()) {
        _destroy_global_memory();
    }
}

// Test: Global memory reference functions
MU_TEST(test_global_memory_refs) {
    // Test that references are consistent
    t_string_memory **ref1 = _global_memory_ref();
    t_string_memory **ref2 = _global_memory_ref();
    mu_assert(ref1 == ref2, "Global memory references should be consistent");
    
    bool *created_ref1 = _global_memory_is_created_ref();
    bool *created_ref2 = _global_memory_is_created_ref();
    mu_assert(created_ref1 == created_ref2, "Global memory created references should be consistent");
}

// Test: Initial state
MU_TEST(test_initial_state) {
    mu_assert(*_global_memory_ref() == NULL, "Initial global memory should be NULL");
    mu_assert(*_global_memory_is_created_ref() == false, "Initial state should be not created");
}

// Test: Memory creation
MU_TEST(test_memory_create) {
    size_t test_size = 1024;
    t_string_memory *region = _memory_create(test_size);
    
    mu_assert(region != NULL, "Memory region should not be NULL");
    mu_assert(region->memory != NULL, "Memory region memory should not be NULL");
    mu_assert(region->size == 0, "Initial size should be 0");
    mu_assert(region->capacity == test_size, "Capacity should match requested size");
    
    _memory_destroy(region);
}

// Test: Memory creation with zero size
MU_TEST(test_memory_create_zero_size) {
    t_string_memory *region = _memory_create(0);
    
    mu_assert(region != NULL, "Memory region should not be NULL even with zero size");
    mu_assert(region->memory != NULL, "Memory region memory should not be NULL");
    mu_assert(region->size == 0, "Size should be 0");
    mu_assert(region->capacity == 0, "Capacity should be 0");
    
    _memory_destroy(region);
}

// Test: Global memory initialization
MU_TEST(test_init_global_memory) {
    size_t test_size = 2048;
    
    _init_global_memory(test_size);
    
    mu_assert(*_global_memory_ref() != NULL, "Global memory should be initialized");
    mu_assert(*_global_memory_is_created_ref() == true, "Global memory should be marked as created");
    mu_assert((*_global_memory_ref())->capacity == test_size, "Global memory capacity should match");
    mu_assert((*_global_memory_ref())->size == 0, "Global memory size should be 0");
}

// Test: Double initialization should fail gracefully
MU_TEST(test_double_init_global_memory) {
    size_t test_size = 1024;
    
    _init_global_memory(test_size);
    
    // Second init should print error but not crash
    _init_global_memory(test_size * 2);
    
    // Should still have original memory
    mu_assert(*_global_memory_ref() != NULL, "Global memory should still exist");
    mu_assert(*_global_memory_is_created_ref() == true, "Global memory should still be marked as created");
    mu_assert((*_global_memory_ref())->capacity == test_size, "Should have original capacity, not doubled");
}

// Test: Regional allocation
MU_TEST(test_regional_allocation) {
    size_t region_size = 1024;
    t_string_memory *region = _memory_create(region_size);
    
    // Test normal allocation
    void *ptr1 = _region_allocate(region, 100);
    mu_assert(ptr1 != NULL, "First allocation should succeed");
    mu_assert(region->size == 100, "Region size should be updated");
    
    // Test consecutive allocation
    void *ptr2 = _region_allocate(region, 200);
    mu_assert(ptr2 != NULL, "Second allocation should succeed");
    mu_assert(region->size == 300, "Region size should be cumulative");
    
    // Verify pointers are different and properly spaced
    mu_assert(ptr2 > ptr1, "Second pointer should be after first");
    mu_assert((char*)ptr2 - (char*)ptr1 == 100, "Pointers should be properly spaced");
    
    _memory_destroy(region);
}

// Test: Regional allocation with NULL region
MU_TEST(test_regional_allocation_null_region) {
    void *ptr = _region_allocate(NULL, 100);
    mu_assert(ptr == NULL, "Allocation with NULL region should fail");
}

// Test: Regional allocation overflow
MU_TEST(test_regional_allocation_overflow) {
    size_t region_size = 100;
    t_string_memory *region = _memory_create(region_size);
    
    // Allocate exactly capacity
    void *ptr1 = _region_allocate(region, region_size);
    mu_assert(ptr1 != NULL, "Allocation within capacity should succeed");
    mu_assert(region->size == region_size, "Region size should match capacity");
    
    // Try to allocate more - should fail
    void *ptr2 = _region_allocate(region, 1);
    mu_assert(ptr2 == NULL, "Overflow allocation should fail");
    mu_assert(region->size == region_size, "Size should not change on failed allocation");
    
    _memory_destroy(region);
}

// Test: Memory destruction
MU_TEST(test_memory_destroy) {
    t_string_memory *region = _memory_create(1024);
    mu_assert(region != NULL, "Memory region should be created");
    
    // Destroy should not crash
    _memory_destroy(region);
    // Note: Can't test much more without valgrind/address sanitizer
}

// Test: Memory destruction with NULL
MU_TEST(test_memory_destroy_null) {
    // Should not crash
    _memory_destroy(NULL);
}

// Test: Global memory destruction
MU_TEST(test_destroy_global_memory) {
    _init_global_memory(1024);
    
    mu_assert(*_global_memory_ref() != NULL, "Global memory should be initialized");
    mu_assert(*_global_memory_is_created_ref() == true, "Global memory should be marked as created");
    
    _destroy_global_memory();
    
    mu_assert(*_global_memory_ref() == NULL, "Global memory should be NULL after destruction");
    mu_assert(*_global_memory_is_created_ref() == false, "Global memory should be marked as not created");
}

// Test: Destroy non-existent global memory
MU_TEST(test_destroy_nonexistent_global_memory) {
    // Should handle gracefully
    _destroy_global_memory();
    
    mu_assert(*_global_memory_ref() == NULL, "Global memory should remain NULL");
    mu_assert(*_global_memory_is_created_ref() == false, "Global memory should remain not created");
}

// Test: Integration test - full workflow
MU_TEST(test_full_workflow) {
    // Initialize global memory
    _init_global_memory(1024);
    
    // Get reference to global memory
    t_string_memory *global_region = *_global_memory_ref();
    mu_assert(global_region != NULL, "Global region should not be NULL");
    
    // Allocate some memory
    void *ptr1 = _region_allocate(global_region, 100);
    mu_assert(ptr1 != NULL, "First allocation should succeed");
    
    void *ptr2 = _region_allocate(global_region, 200);
    mu_assert(ptr2 != NULL, "Second allocation should succeed");
    
    mu_assert(global_region->size == 300, "Total size should be cumulative");
    
    // Clean up
    _destroy_global_memory();
}

// Test suite
MU_TEST_SUITE(test_suite) {
    // Memory creation tests
    MU_RUN_TEST(test_global_memory_refs);
    MU_RUN_TEST(test_initial_state);
    MU_RUN_TEST(test_memory_create);
    MU_RUN_TEST(test_memory_create_zero_size);
    
    // Global memory tests
    MU_SUITE_CONFIGURE(&setup_test, &teardown_test);
    MU_RUN_TEST(test_init_global_memory);
    
    MU_SUITE_CONFIGURE(&setup_test, &teardown_test);
    MU_RUN_TEST(test_double_init_global_memory);
    
    // Regional allocation tests
    MU_RUN_TEST(test_regional_allocation);
    MU_RUN_TEST(test_regional_allocation_null_region);
    MU_RUN_TEST(test_regional_allocation_overflow);
    
    // Memory destruction tests
    MU_RUN_TEST(test_memory_destroy);
    MU_RUN_TEST(test_memory_destroy_null);
    
    MU_SUITE_CONFIGURE(&setup_test, &teardown_test);
    MU_RUN_TEST(test_destroy_global_memory);
    
    MU_SUITE_CONFIGURE(&setup_test, &teardown_test);
    MU_RUN_TEST(test_destroy_nonexistent_global_memory);
    
    // Integration tests
    MU_SUITE_CONFIGURE(&setup_test, &teardown_test);
    MU_RUN_TEST(test_full_workflow);
}

int main(int argc, char **argv) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
