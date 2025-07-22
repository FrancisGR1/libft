#include "./minunit/minunit.h"
#include "../Strings/strings.h"


// TEST
// t_string *str_from_int(int value)
MU_TEST(test_positive)
{
	const char *comparison_str = "10";
	t_string *str_num = str_from_int(10);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_negative)
{
	const char *comparison_str = "-10";
	t_string *str_num = str_from_int(-10);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_zero)
{
	const char *comparison_str = "0";
	t_string *str_num = str_from_int(0);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}


MU_TEST(test_max)
{
	char comparison_str[20];
	snprintf(comparison_str, sizeof(comparison_str), "%d", INT_MAX);
	t_string *str_num = str_from_int(INT_MAX);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_min)
{
	char comparison_str[20];
	snprintf(comparison_str, sizeof(comparison_str), "%d", INT_MIN);
	t_string *str_num = str_from_int(INT_MIN);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST_SUITE(from_int_tests)
{
	MU_RUN_TEST(test_positive);
	MU_RUN_TEST(test_negative);
	MU_RUN_TEST(test_zero);
	MU_RUN_TEST(test_max);
	MU_RUN_TEST(test_min);
}

int main(void)
{
	MU_RUN_SUITE(from_int_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}
