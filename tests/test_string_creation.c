#include "./minunit/minunit.h"
#include "../Strings/strings.h"

// Helper function to check if string structure is valid
static int is_valid_string(t_string *str) {
    return (str != NULL && 
            str->data != NULL && 
            str->memory != NULL && 
            str->size <= str->capacity);
}

// Test str_create with valid input
MU_TEST(test_str_create_valid) {
    t_string *str = str_create("Hello World");
    
    mu_check(str != NULL);
    mu_check(is_valid_string(str));
    mu_check(str->size == 11);
    mu_check(str->capacity == str->size + STRING_DEFAULT_CAPACITY);
    mu_check(strcmp(str->data, "Hello World") == 0);
    
    str_deallocate(str);
}

// Test str_create with empty string
MU_TEST(test_str_create_empty) {
    t_string *str = str_create("");
    
    mu_check(str != NULL);
    mu_check(is_valid_string(str));
    mu_check(str->size == 0);
    mu_check(str->capacity == STRING_DEFAULT_CAPACITY);
    mu_check(strcmp(str->data, "") == 0);
    
    str_deallocate(str);
}

// Test str_create with NULL input
MU_TEST(test_str_create_null) {
    t_string *str = str_create(NULL);
    mu_check(str == NULL);
}

// Test str_create with long string
MU_TEST(test_str_create_long) {
    char long_string[200];
    memset(long_string, 'A', 199);
    long_string[199] = '\0';
    
    t_string *str = str_create(long_string);
    
    mu_check(str != NULL);
    mu_check(is_valid_string(str));
    mu_check(str->size == 199);
    mu_check(strcmp(str->data, long_string) == 0);
    
    str_deallocate(str);
}

// Test str_create_from_multiple with valid input
MU_TEST(test_str_create_from_multiple_valid) {
    t_string **strings = str_create_from_multiple(3, "Hello", "World", "Test");
    
    mu_check(strings != NULL);
    mu_check(is_valid_string(strings[0]));
    mu_check(is_valid_string(strings[1]));
    mu_check(is_valid_string(strings[2]));
    mu_check(strings[3] == NULL);
    
    mu_check(strcmp(strings[0]->data, "Hello") == 0);
    mu_check(strcmp(strings[1]->data, "World") == 0);
    mu_check(strcmp(strings[2]->data, "Test") == 0);
    
    // Cleanup
    for (int i = 0; i < 3; i++) {
        str_deallocate(strings[i]);
    }
    free(strings);
}

// Test str_create_from_multiple with single string
MU_TEST(test_str_create_from_multiple_single) {
    t_string **strings = str_create_from_multiple(1, "Single");
    
    mu_check(strings != NULL);
    mu_check(is_valid_string(strings[0]));
    mu_check(strings[1] == NULL);
    mu_check(strcmp(strings[0]->data, "Single") == 0);
    
    str_deallocate(strings[0]);
    free(strings);
}

// Test str_create_from_multiple with zero count
MU_TEST(test_str_create_from_multiple_zero) {
    t_string **strings = str_create_from_multiple(0);
    mu_check(strings == NULL);
}

// Test str_create_from_multiple with empty strings
MU_TEST(test_str_create_from_multiple_empty) {
    t_string **strings = str_create_from_multiple(2, "", "");
    
    mu_check(strings != NULL);
    mu_check(is_valid_string(strings[0]));
    mu_check(is_valid_string(strings[1]));
    mu_check(strings[2] == NULL);
    
    mu_check(strcmp(strings[0]->data, "") == 0);
    mu_check(strcmp(strings[1]->data, "") == 0);
    
    str_deallocate(strings[0]);
    str_deallocate(strings[1]);
    free(strings);
}

// Test str_clear with valid string
MU_TEST(test_str_clear_valid) {
    t_string *str = str_create("Hello World");
    bool result = str_clear(str);
    
    mu_check(result == true);
    mu_check(str->size == 0);
    mu_check(str->data[0] == '\0');
    mu_check(str->memory != NULL);
    mu_check(str->capacity == 11 + STRING_DEFAULT_CAPACITY);
    
    str_deallocate(str);
}

// Test str_clear with NULL string
MU_TEST(test_str_clear_null) {
    bool result = str_clear(NULL);
    mu_check(result == false);
}

// Test str_clear multiple times
MU_TEST(test_str_clear_multiple) {
    t_string *str = str_create("Test");
    
    bool result1 = str_clear(str);
    bool result2 = str_clear(str);
    
    mu_check(result1 == true);
    mu_check(result2 == true);
    mu_check(str->size == 0);
    mu_check(str->data[0] == '\0');
    
    str_deallocate(str);
}

// Test str_deallocate with valid string
MU_TEST(test_str_deallocate_valid) {
    t_string *str = str_create("Test");
    bool result = str_deallocate(str);
    mu_check(result == true);
    // Note: Cannot test str after deallocation as it would be invalid memory access
}

// Test str_deallocate with NULL string
MU_TEST(test_str_deallocate_null) {
    bool result = str_deallocate(NULL);
    mu_check(result == false);
}

// Test string constants
MU_TEST(test_string_constants) {
    mu_check(STRING_DEFAULT_CAPACITY == STRING_DEFAULT_CAPACITY);
    mu_check(STRING_MEMORY_INITIAL_SIZE == STRING_MEMORY_INITIAL_SIZE);
    
    // Test predefined character sets
    mu_check(strlen(STRING_ASCII_LETTERS) == 52);
    mu_check(strlen(STRING_ASCII_LOWERCASE) == 26);
    mu_check(strlen(STRING_ASCII_UPPERCASE) == 26);
    mu_check(strlen(STRING_DIGITS) == 10);
    mu_check(strlen(STRING_HEXDIGITS) == 22);
}

// Test edge cases for str_create_from_multiple
MU_TEST(test_str_create_from_multiple_mixed) {
    t_string **strings = str_create_from_multiple(4, "Short", "A much longer string for testing", "", "123");
    
    mu_check(strings != NULL);
    mu_check(strings[4] == NULL);
    
    mu_check(strcmp(strings[0]->data, "Short") == 0);
    mu_check(strcmp(strings[1]->data, "A much longer string for testing") == 0);
    mu_check(strcmp(strings[2]->data, "") == 0);
    mu_check(strcmp(strings[3]->data, "123") == 0);
    
    // Test sizes
    mu_check(strings[0]->size == 5);
    mu_check(strings[1]->size == 32);
    mu_check(strings[2]->size == 0);
    mu_check(strings[3]->size == 3);
    
    // Cleanup
    for (int i = 0; i < 4; i++) {
        str_deallocate(strings[i]);
    }
    free(strings);
}

// Test str_create with special characters
MU_TEST(test_str_create_special_chars) {
    const char *special = "Hello\nWorld\t!\x01\x7F";
    t_string *str = str_create(special);
    
    mu_check(str != NULL);
    mu_check(is_valid_string(str));
    mu_check(str->size == strlen(special));
    mu_check(strcmp(str->data, special) == 0);
    
    str_deallocate(str);
}

// Test suite for creation functions
MU_TEST_SUITE(creation_tests) {
    MU_RUN_TEST(test_str_create_valid);
    MU_RUN_TEST(test_str_create_empty);
    MU_RUN_TEST(test_str_create_null);
    MU_RUN_TEST(test_str_create_long);
    MU_RUN_TEST(test_str_create_special_chars);
    
    MU_RUN_TEST(test_str_create_from_multiple_valid);
    MU_RUN_TEST(test_str_create_from_multiple_single);
    MU_RUN_TEST(test_str_create_from_multiple_zero);
    MU_RUN_TEST(test_str_create_from_multiple_empty);
    MU_RUN_TEST(test_str_create_from_multiple_mixed);
}

// Test suite for manipulation functions
MU_TEST_SUITE(manipulation_tests) {
    MU_RUN_TEST(test_str_clear_valid);
    MU_RUN_TEST(test_str_clear_null);
    MU_RUN_TEST(test_str_clear_multiple);
}

// Test suite for destruction functions
MU_TEST_SUITE(destruction_tests) {
    MU_RUN_TEST(test_str_deallocate_valid);
    MU_RUN_TEST(test_str_deallocate_null);
}

// Test suite for constants
MU_TEST_SUITE(constants_tests) {
    MU_RUN_TEST(test_string_constants);
}

// Main test runner
int main(int argc, char *argv[]) {
    MU_RUN_SUITE(creation_tests);
    MU_RUN_SUITE(manipulation_tests);
    MU_RUN_SUITE(destruction_tests);
    MU_RUN_SUITE(constants_tests);
    
    MU_REPORT();
    return MU_EXIT_CODE;
}
