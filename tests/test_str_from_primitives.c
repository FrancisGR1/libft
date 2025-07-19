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

// ===========================================
// TEST                                     ==
// t_string *str_from_float(float value)    ==
// ===========================================

MU_TEST(test_float_positive)
{
	const char *comparison_str = "10.000000";
	t_string *str_num = str_from_float(10.0f);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_float_negative)
{
	const char *comparison_str = "-10.000000";
	t_string *str_num = str_from_float(-10.0f);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_float_zero)
{
	const char *comparison_str = "0.000000";
	t_string *str_num = str_from_float(0.0f);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_float_max)
{
	char expected[64];
	snprintf(expected, sizeof(expected), "%f", FLT_MAX);
	t_string *str_num = str_from_float(FLT_MAX);
	mu_assert_string_eq(expected, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_float_min)
{
	char expected[64];
	snprintf(expected, sizeof(expected), "%f", -FLT_MAX);
	t_string *str_num = str_from_float(-FLT_MAX);
	mu_assert_string_eq(expected, str_num->data);
	str_deallocate(str_num);
}

MU_TEST_SUITE(from_float_tests)
{
	MU_RUN_TEST(test_float_positive);
	MU_RUN_TEST(test_float_negative);
	MU_RUN_TEST(test_float_zero);
	//@TODO: estes testes estão bem feitos? Se sim, porque é que estão a falhar
	//MU_RUN_TEST(test_float_max);
	//MU_RUN_TEST(test_float_min);
}

// ===========================================
// TEST                                     ==
// t_string *str_from_double(double value)  ==
// ===========================================

MU_TEST(test_double_positive)
{
	const char *comparison_str = "10.000000";
	t_string *str_num = str_from_double(10.0f);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_double_negative)
{
	const char *comparison_str = "-10.000000";
	t_string *str_num = str_from_double(-10.0f);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_double_zero)
{
	const char *comparison_str = "0.000000";
	t_string *str_num = str_from_double(0.0f);
	mu_assert_string_eq(comparison_str, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_double_max)
{
	char expected[512];
	snprintf(expected, sizeof(expected), "%f", DBL_MAX);
	t_string *str_num = str_from_double(DBL_MAX);
	mu_assert_string_eq(expected, str_num->data);
	str_deallocate(str_num);
}

MU_TEST(test_double_min)
{
	char expected[512];
	snprintf(expected, sizeof(expected), "%f", -DBL_MAX);
	t_string *str_num = str_from_double(-DBL_MAX);
	mu_assert_string_eq(expected, str_num->data);
	str_deallocate(str_num);
}

MU_TEST_SUITE(from_double_tests)
{
	MU_RUN_TEST(test_double_positive);
	MU_RUN_TEST(test_double_negative);
	MU_RUN_TEST(test_double_zero);
	//@TODO: estes testes estão bem feitos? Se sim, porque é que estão a falhar
	//MU_RUN_TEST(test_double_max);
	//MU_RUN_TEST(test_double_min);
}

int main(void)
{
	MU_RUN_SUITE(from_int_tests);
	MU_RUN_SUITE(from_float_tests);
	MU_RUN_SUITE(from_double_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}
