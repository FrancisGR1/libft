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

int main(void)
{
	MU_RUN_SUITE(to_int_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}
