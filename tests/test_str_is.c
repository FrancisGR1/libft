#include "minunit/minunit.h"
#include "../Strings/strings.h"

// Test str_is_alpha function
MU_TEST(test_str_is_alpha_all_letters)
{
    t_string *str = str_create("hello");
    
    bool result = str_is_alpha(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alpha_mixed_case)
{
    t_string *str = str_create("HelloWorld");
    
    bool result = str_is_alpha(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alpha_with_numbers)
{
    t_string *str = str_create("hello123");
    
    bool result = str_is_alpha(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alpha_with_spaces)
{
    t_string *str = str_create("hello world");
    
    bool result = str_is_alpha(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alpha_with_special_chars)
{
    t_string *str = str_create("hello!");
    
    bool result = str_is_alpha(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alpha_empty_string)
{
    t_string *str = str_create("");
    
    bool result = str_is_alpha(str);
    
    mu_check(result == true); // Empty string passes all character tests
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alpha_null_string)
{
    bool result1 = str_is_alpha(NULL);
    mu_check(result1 == false);
    
    t_string *str = str_create("test");
    str->data = NULL;
    bool result2 = str_is_alpha(str);
    mu_check(result2 == false);
    
    str_deallocate(str);
}

// Test str_is_digit function
MU_TEST(test_str_is_digit_all_digits)
{
    t_string *str = str_create("12345");
    
    bool result = str_is_digit(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_digit_with_letters)
{
    t_string *str = str_create("123abc");
    
    bool result = str_is_digit(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_digit_with_spaces)
{
    t_string *str = str_create("123 456");
    
    bool result = str_is_digit(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_digit_with_special_chars)
{
    t_string *str = str_create("123.45");
    
    bool result = str_is_digit(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_digit_single_digit)
{
    t_string *str = str_create("7");
    
    bool result = str_is_digit(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_digit_zero)
{
    t_string *str = str_create("0");
    
    bool result = str_is_digit(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_digit_empty_string)
{
    t_string *str = str_create("");
    
    bool result = str_is_digit(str);
    
    mu_check(result == true); // Empty string passes all character tests
    
    str_deallocate(str);
}

MU_TEST(test_str_is_digit_null_string)
{
    bool result1 = str_is_digit(NULL);
    mu_check(result1 == false);
    
    t_string *str = str_create("test");
    str->data = NULL;
    bool result2 = str_is_digit(str);
    mu_check(result2 == false);
    
    str_deallocate(str);
}

// Test str_is_alnum function
MU_TEST(test_str_is_alnum_letters_and_digits)
{
    t_string *str = str_create("abc123");
    
    bool result = str_is_alnum(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alnum_only_letters)
{
    t_string *str = str_create("hello");
    
    bool result = str_is_alnum(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alnum_only_digits)
{
    t_string *str = str_create("12345");
    
    bool result = str_is_alnum(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alnum_with_spaces)
{
    t_string *str = str_create("abc 123");
    
    bool result = str_is_alnum(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alnum_with_special_chars)
{
    t_string *str = str_create("abc123!");
    
    bool result = str_is_alnum(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alnum_mixed_case)
{
    t_string *str = str_create("Hello123");
    
    bool result = str_is_alnum(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alnum_empty_string)
{
    t_string *str = str_create("");
    
    bool result = str_is_alnum(str);
    
    mu_check(result == true); // Empty string passes all character tests
    
    str_deallocate(str);
}

MU_TEST(test_str_is_alnum_null_string)
{
    bool result1 = str_is_alnum(NULL);
    mu_check(result1 == false);
    
    t_string *str = str_create("test");
    str->data = NULL;
    bool result2 = str_is_alnum(str);
    mu_check(result2 == false);
    
    str_deallocate(str);
}

// Test str_is_lower function
MU_TEST(test_str_is_lower_all_lowercase)
{
    t_string *str = str_create("hello");
    
    bool result = str_is_lower(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_lower_with_uppercase)
{
    t_string *str = str_create("Hello");
    
    bool result = str_is_lower(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_lower_with_numbers)
{
    t_string *str = str_create("hello123");
    
    bool result = str_is_lower(str);
    
    mu_check(result == false); // Numbers are not lowercase letters
    
    str_deallocate(str);
}

MU_TEST(test_str_is_lower_with_spaces)
{
    t_string *str = str_create("hello world");
    
    bool result = str_is_lower(str);
    
    mu_check(result == false); // Spaces are not lowercase letters
    
    str_deallocate(str);
}

MU_TEST(test_str_is_lower_only_lowercase_letters)
{
    t_string *str = str_create("abcdef");
    
    bool result = str_is_lower(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_lower_empty_string)
{
    t_string *str = str_create("");
    
    bool result = str_is_lower(str);
    
    mu_check(result == true); // Empty string passes all character tests
    
    str_deallocate(str);
}

MU_TEST(test_str_is_lower_null_string)
{
    bool result1 = str_is_lower(NULL);
    mu_check(result1 == false);
    
    t_string *str = str_create("test");
    str->data = NULL;
    bool result2 = str_is_lower(str);
    mu_check(result2 == false);
    
    str_deallocate(str);
}

// Test str_is_upper function
MU_TEST(test_str_is_upper_all_uppercase)
{
    t_string *str = str_create("HELLO");
    
    bool result = str_is_upper(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_upper_with_lowercase)
{
    t_string *str = str_create("Hello");
    
    bool result = str_is_upper(str);
    
    mu_check(result == false);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_upper_with_numbers)
{
    t_string *str = str_create("HELLO123");
    
    bool result = str_is_upper(str);
    
    mu_check(result == false); // Numbers are not uppercase letters
    
    str_deallocate(str);
}

MU_TEST(test_str_is_upper_with_spaces)
{
    t_string *str = str_create("HELLO WORLD");
    
    bool result = str_is_upper(str);
    
    mu_check(result == false); // Spaces are not uppercase letters
    
    str_deallocate(str);
}

MU_TEST(test_str_is_upper_only_uppercase_letters)
{
    t_string *str = str_create("ABCDEF");
    
    bool result = str_is_upper(str);
    
    mu_check(result == true);
    
    str_deallocate(str);
}

MU_TEST(test_str_is_upper_empty_string)
{
    t_string *str = str_create("");
    
    bool result = str_is_upper(str);
    
    mu_check(result == true); // Empty string passes all character tests
    
    str_deallocate(str);
}

MU_TEST(test_str_is_upper_null_string)
{
    bool result1 = str_is_upper(NULL);
    mu_check(result1 == false);
    
    t_string *str = str_create("test");
    str->data = NULL;
    bool result2 = str_is_upper(str);
    mu_check(result2 == false);
    
    str_deallocate(str);
}

// Edge cases
MU_TEST(test_validation_single_character)
{
    t_string *alpha_str = str_create("a");
    t_string *digit_str = str_create("5");
    t_string *upper_str = str_create("A");
    t_string *lower_str = str_create("z");
    
    mu_check(str_is_alpha(alpha_str) == true);
    mu_check(str_is_digit(digit_str) == true);
    mu_check(str_is_alnum(alpha_str) == true);
    mu_check(str_is_alnum(digit_str) == true);
    mu_check(str_is_upper(upper_str) == true);
    mu_check(str_is_lower(lower_str) == true);
    
    str_deallocate(alpha_str);
    str_deallocate(digit_str);
    str_deallocate(upper_str);
    str_deallocate(lower_str);
}

MU_TEST(test_validation_special_characters)
{
    t_string *special_str = str_create("@#$%");
    
    mu_check(str_is_alpha(special_str) == false);
    mu_check(str_is_digit(special_str) == false);
    mu_check(str_is_alnum(special_str) == false);
    mu_check(str_is_upper(special_str) == false);
    mu_check(str_is_lower(special_str) == false);
    
    str_deallocate(special_str);
}

// Test functions for str_is_space
MU_TEST(test_str_is_space_valid)
{
    t_string *str = str_create("   ");
    mu_assert(str_is_space(str), "Should return true for only spaces");
    str_deallocate(str);
    
    str = str_create("\t\t");
    mu_assert(str_is_space(str), "Should return true for only tabs");
    str_deallocate(str);
    
    str = str_create("\n");
    mu_assert(str_is_space(str), "Should return true for newline");
    str_deallocate(str);
    
    str = str_create(" \t\n\r");
    mu_assert(str_is_space(str), "Should return true for mixed whitespace characters");
    str_deallocate(str);
}

MU_TEST(test_str_is_space_invalid)
{
    t_string *str = str_create("hello world");
    mu_assert(!str_is_space(str), "Should return false when containing non-whitespace");
    str_deallocate(str);
    
    str = str_create("   a   ");
    mu_assert(!str_is_space(str), "Should return false when containing letters");
    str_deallocate(str);
    
    str = str_create(" 1 ");
    mu_assert(!str_is_space(str), "Should return false when containing digits");
    str_deallocate(str);
}

MU_TEST(test_str_is_space_empty_and_null)
{
    t_string *str = str_create("");
    mu_assert(str_is_space(str), "Empty string should return true (vacuous truth)");
    str_deallocate(str);
    
    mu_assert(!str_is_space(NULL), "Should return false for NULL string");
}

// Test functions for str_is_printable
MU_TEST(test_str_is_printable_valid)
{
    t_string *str = str_create("Hello World 123!");
    mu_assert(str_is_printable(str), "Should return true for printable characters");
    str_deallocate(str);
    
    str = str_create("abc123XYZ!@#$%");
    mu_assert(str_is_printable(str), "Should return true for mixed printable characters");
    str_deallocate(str);
    
    str = str_create(" ");
    mu_assert(str_is_printable(str), "Should return true for space (printable)");
    str_deallocate(str);
    
    str = str_create("~");
    mu_assert(str_is_printable(str), "Should return true for tilde");
    str_deallocate(str);
}

MU_TEST(test_str_is_printable_invalid)
{
    t_string *str = str_create("hello\n");
    mu_assert(!str_is_printable(str), "Should return false when containing newline");
    str_deallocate(str);
    
    str = str_create("test\t");
    mu_assert(!str_is_printable(str), "Should return false when containing tab");
    str_deallocate(str);
    
    str = str_create("hello\x01world");
    mu_assert(!str_is_printable(str), "Should return false when containing control characters");
    str_deallocate(str);
}

MU_TEST(test_str_is_printable_empty_and_null)
{
    t_string *str = str_create("");
    mu_assert(str_is_printable(str), "Empty string should return true (vacuous truth)");
    str_deallocate(str);
    
    mu_assert(!str_is_printable(NULL), "Should return false for NULL string");
}

// Cross-function consistency tests
MU_TEST(test_classification_consistency)
{
    // Test that digits are also alphanumeric
    t_string *str = str_create("123");
    mu_assert(str_is_digit(str), "Should be digits");
    mu_assert(str_is_alnum(str), "Digits should also be alphanumeric");
    str_deallocate(str);
    
    // Test that alpha are also alphanumeric
    str = str_create("abc");
    mu_assert(str_is_alpha(str), "Should be alphabetic");
    mu_assert(str_is_alnum(str), "Alphabetic should also be alphanumeric");
    str_deallocate(str);
    
    // Test that lowercase letters are alphabetic
    str = str_create("hello");
    mu_assert(str_is_lower(str), "Should be lowercase");
    mu_assert(str_is_alpha(str), "Lowercase should also be alphabetic");
    str_deallocate(str);
    
    // Test that uppercase letters are alphabetic
    str = str_create("HELLO");
    mu_assert(str_is_upper(str), "Should be uppercase");
    mu_assert(str_is_alpha(str), "Uppercase should also be alphabetic");
    str_deallocate(str);
}

MU_TEST(test_mutually_exclusive_cases)
{
    // Test that string cannot be both upper and lower (for non-empty strings with letters)
    t_string *str = str_create("hello");
    mu_assert(str_is_lower(str) && !str_is_upper(str), "Lowercase string should not be uppercase");
    str_deallocate(str);
    
    str = str_create("HELLO");
    mu_assert(str_is_upper(str) && !str_is_lower(str), "Uppercase string should not be lowercase");
    str_deallocate(str);
    
    // Test mixed case
    str = str_create("Hello");
    mu_assert(!str_is_upper(str) && !str_is_lower(str), "Mixed case should be neither upper nor lower");
    str_deallocate(str);
}

MU_TEST(test_edge_case_combinations)
{
    // Test string with only special characters
    t_string *str = str_create("!@#$%");
    mu_assert(!str_is_alpha(str), "Special chars should not be alpha");
    mu_assert(!str_is_digit(str), "Special chars should not be digit");
    mu_assert(!str_is_alnum(str), "Special chars should not be alnum");
    mu_assert(!str_is_lower(str), "Special chars should not be lower");
    mu_assert(!str_is_upper(str), "Special chars should not be upper");
    mu_assert(!str_is_space(str), "Special chars should not be space");
    mu_assert(str_is_printable(str), "Special chars should be printable");
    str_deallocate(str);
}

// Test suite
MU_TEST_SUITE(test_suite)
{
    // str_is_alpha tests
    MU_RUN_TEST(test_str_is_alpha_all_letters);
    MU_RUN_TEST(test_str_is_alpha_mixed_case);
    MU_RUN_TEST(test_str_is_alpha_with_numbers);
    MU_RUN_TEST(test_str_is_alpha_with_spaces);
    MU_RUN_TEST(test_str_is_alpha_with_special_chars);
    MU_RUN_TEST(test_str_is_alpha_empty_string);
    MU_RUN_TEST(test_str_is_alpha_null_string);
    
    // str_is_digit tests
    MU_RUN_TEST(test_str_is_digit_all_digits);
    MU_RUN_TEST(test_str_is_digit_with_letters);
    MU_RUN_TEST(test_str_is_digit_with_spaces);
    MU_RUN_TEST(test_str_is_digit_with_special_chars);
    MU_RUN_TEST(test_str_is_digit_single_digit);
    MU_RUN_TEST(test_str_is_digit_zero);
    MU_RUN_TEST(test_str_is_digit_empty_string);
    MU_RUN_TEST(test_str_is_digit_null_string);
    
    // str_is_alnum tests
    MU_RUN_TEST(test_str_is_alnum_letters_and_digits);
    MU_RUN_TEST(test_str_is_alnum_only_letters);
    MU_RUN_TEST(test_str_is_alnum_only_digits);
    MU_RUN_TEST(test_str_is_alnum_with_spaces);
    MU_RUN_TEST(test_str_is_alnum_with_special_chars);
    MU_RUN_TEST(test_str_is_alnum_mixed_case);
    MU_RUN_TEST(test_str_is_alnum_empty_string);
    MU_RUN_TEST(test_str_is_alnum_null_string);
    
    // str_is_lower tests
    MU_RUN_TEST(test_str_is_lower_all_lowercase);
    MU_RUN_TEST(test_str_is_lower_with_uppercase);
    MU_RUN_TEST(test_str_is_lower_with_numbers);
    MU_RUN_TEST(test_str_is_lower_with_spaces);
    MU_RUN_TEST(test_str_is_lower_only_lowercase_letters);
    MU_RUN_TEST(test_str_is_lower_empty_string);
    MU_RUN_TEST(test_str_is_lower_null_string);
    
    // str_is_upper tests
    MU_RUN_TEST(test_str_is_upper_all_uppercase);
    MU_RUN_TEST(test_str_is_upper_with_lowercase);
    MU_RUN_TEST(test_str_is_upper_with_numbers);
    MU_RUN_TEST(test_str_is_upper_with_spaces);
    MU_RUN_TEST(test_str_is_upper_only_uppercase_letters);
    MU_RUN_TEST(test_str_is_upper_empty_string);
    MU_RUN_TEST(test_str_is_upper_null_string);
    
    // Edge case tests
    MU_RUN_TEST(test_validation_single_character);
    MU_RUN_TEST(test_validation_special_characters);

    // str_is_space tests
    MU_RUN_TEST(test_str_is_space_valid);
    MU_RUN_TEST(test_str_is_space_invalid);
    MU_RUN_TEST(test_str_is_space_empty_and_null);

    // str_is_printable tests
    MU_RUN_TEST(test_str_is_printable_valid);
    MU_RUN_TEST(test_str_is_printable_invalid);
    MU_RUN_TEST(test_str_is_printable_empty_and_null);

    // Cross-function tests
    MU_RUN_TEST(test_classification_consistency);
    MU_RUN_TEST(test_mutually_exclusive_cases);
    MU_RUN_TEST(test_edge_case_combinations);
}


int main(void)
{
	MU_RUN_TEST(test_suite);
	MU_RUN_TEST(test_edge_case_combinations);
	MU_REPORT();
	return MU_EXIT_CODE;
}
