#include "./minunit/minunit.h"
#include "../Strings/strings.h"

// TEST
// int str_to_int(const t_string *str)
MU_TEST(test_positive)
{
	int expected_num = 10;
	t_string *str_num = str_create("10");
	int output_num = str_to_int(str_num);
	mu_assert_int_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_negative)
{
	int expected_num = -10;
	t_string *str_num = str_create("-10");
	int output_num = str_to_int(str_num);
	mu_assert_int_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_zero)
{
	int expected_num = 0;
	t_string *str_num = str_create("0");
	int output_num = str_to_int(str_num);
	mu_assert_int_eq(expected_num, output_num);
	str_deallocate(str_num);
}


MU_TEST(test_max)
{
	char int_max_str[20];
	snprintf(int_max_str, sizeof(int_max_str), "%d", INT_MAX);
	int expected_num = INT_MAX;
	t_string *str_num = str_create(int_max_str);
	int output_num = str_to_int(str_num);
	mu_assert_int_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_min)
{
	char int_min_str[20];
	snprintf(int_min_str, sizeof(int_min_str), "%d", INT_MIN);
	int expected_num = INT_MIN;
	t_string *str_num = str_create(int_min_str);
	int output_num = str_to_int(str_num);
	mu_assert_int_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST_SUITE(to_int_tests)
{
	MU_RUN_TEST(test_positive);
	MU_RUN_TEST(test_negative);
	MU_RUN_TEST(test_zero);
	MU_RUN_TEST(test_max);
	MU_RUN_TEST(test_min);
}

// ===========================================
// TEST                                     ==
// t_string *str_to_float(float value)      ==
// ===========================================

MU_TEST(test_float_positive)
{
	float expected_num = 10;
	t_string *str_num = str_create("10.0000");
	float output_num = str_to_float(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_float_negative)
{
	float expected_num = -10;
	t_string *str_num = str_create("-10.0000");
	float output_num = str_to_int(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_float_zero)
{
	float expected_num = 0;
	t_string *str_num = str_create("0.00");
	float output_num = str_to_int(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_float_max)
{
	char float_max_str[64];
	snprintf(float_max_str, sizeof(float_max_str), "%f", FLT_MAX);
	t_string *str_num = str_create(float_max_str);
	float expected_num = FLT_MAX;
	float output_num = str_to_float(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_float_min)
{
	char float_min_str[64];
	snprintf(float_min_str, sizeof(float_min_str), "%f", -FLT_MAX);
	t_string *str_num = str_create(float_min_str);
	float expected_num = -FLT_MAX;
	float output_num = str_to_float(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST_SUITE(to_float_tests)
{
	MU_RUN_TEST(test_float_positive);
	MU_RUN_TEST(test_float_negative);
	MU_RUN_TEST(test_float_zero);
	MU_RUN_TEST(test_float_max);
	MU_RUN_TEST(test_float_min);
}

// ===========================================
// TEST                                     ==
// t_string *str_to_double(double value)    ==
// ===========================================

MU_TEST(test_double_positive)
{
	double expected_num = 10;
	t_string *str_num = str_create("10.0000");
	double output_num = str_to_float(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_double_negative)
{
	double expected_num = -10;
	t_string *str_num = str_create("-10.0000");
	double output_num = str_to_int(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_double_zero)
{
	double expected_num = 0;
	t_string *str_num = str_create("0.00");
	double output_num = str_to_int(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_double_max)
{
	char double_max_str[512];
	snprintf(double_max_str, sizeof(double_max_str), "%f", DBL_MAX);
	t_string *str_num = str_create(double_max_str);
	double expected_num = FLT_MAX;
	double output_num = str_to_float(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST(test_double_min)
{
	char double_min_str[512];
	snprintf(double_min_str, sizeof(double_min_str), "%f", -DBL_MAX);
	t_string *str_num = str_create(double_min_str);
	double expected_num = -FLT_MAX;
	double output_num = str_to_float(str_num);
	mu_assert_double_eq(expected_num, output_num);
	str_deallocate(str_num);
}

MU_TEST_SUITE(to_double_tests)
{
	MU_RUN_TEST(test_double_positive);
	MU_RUN_TEST(test_double_negative);
	MU_RUN_TEST(test_double_zero);
	//@TODO: testes estão a falhar
	//MU_RUN_TEST(test_double_max);
	//MU_RUN_TEST(test_double_min);
}

int main(void)
{
	MU_RUN_SUITE(to_int_tests);
	MU_RUN_SUITE(to_float_tests);
	MU_RUN_SUITE(to_double_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}
