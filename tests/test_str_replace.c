#include "./minunit/minunit.h"
#include "../Strings/strings.h"

/*
 * TESTING:
 * void str_replace(t_string* str, const char* old_str, const char* new_str);
 */
MU_TEST(test_replace_middle)
{
	const char *test_string = "Hello and Goodbye World";
	t_string *str = str_create("Hello World");
	str_replace(str, " ", " and Goodbye ");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_beginning)
{
	const char *test_string = "Goodbye World";
	t_string *str = str_create("Hello World");
	str_replace(str, "Hello", "Goodbye");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_ending)
{
	const char *test_string = "Hello Planet";
	t_string *str = str_create("Hello World");
	str_replace(str, "World", "Planet");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_no_occurrence)
{
	const char *test_string = "Hello World";
	t_string *str = str_create("Hello World");
	str_replace(str, "Z", "A");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_multiple_occurrences)
{
	const char *test_string = "Heflo World";
	t_string *str = str_create("Hello World");
	str_replace(str, "l", "f");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_empty)
{
	const char *test_string = "";
	t_string *str = str_create("");
	str_replace(str, "l", "f");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_with_empty)
{
	const char *test_string = "HelloWorld!";
	t_string *str = str_create("Hello World!");
	str_replace(str, " ", "");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_null)
{
	t_string *str = str_create("");
	str_replace(NULL, NULL, NULL);
	mu_assert(1, "Did not Crash!");
	str_deallocate(str);
}

MU_TEST_SUITE(replace_tests) 
{
	MU_RUN_TEST(test_replace_middle);
	MU_RUN_TEST(test_replace_beginning);
	MU_RUN_TEST(test_replace_ending);
	MU_RUN_TEST(test_replace_no_occurrence);
	MU_RUN_TEST(test_replace_multiple_occurrences);
	MU_RUN_TEST(test_replace_empty);
	MU_RUN_TEST(test_replace_with_empty);
	MU_RUN_TEST(test_replace_null);
}

/*
 * TESTING:
 * void str_replace_all(t_string *str, const char *old_str, const char *new_str);
 */
MU_TEST(test_replace_all_middle)
{
	const char *test_string = "a a a a a x x x a a a a";
	t_string *str = str_create("a a a a a z z z a a a a");
	str_replace_all(str, "z", "x");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_all_beginning)
{
	const char *test_string = "x x x a a a a a a a a a";
	t_string *str = str_create("z z z a a a a a a a a a");
	str_replace_all(str, "z", "x");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_all_ending)
{
	const char *test_string = "a a a a a a a a a x x x";
	t_string *str = str_create("a a a a a a a a a z z z");
	str_replace_all(str, "z", "x");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_all_no_occurrence)
{
	const char *test_string = "Hello World";
	t_string *str = str_create("Hello World");
	str_replace_all(str, "Z", "A");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_all_multiple_occurrences)
{
	const char *test_string = "Heffo Worfd";
	t_string *str = str_create("Hello World");
	str_replace_all(str, "l", "f");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_all_empty)
{
	const char *test_string = "";
	t_string *str = str_create("");
	str_replace_all(str, "l", "f");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_all_with_empty)
{
	const char *test_string = "HelloWorld!GoodbyeLOL!";
	t_string *str = str_create("Hello World! Goodbye         LOL  !   ");
	str_replace_all(str, " ", "");
	mu_assert_string_eq(test_string, str->data);
	mu_assert_int_eq(ft_strlen(test_string), str->size);
	str_deallocate(str);
}

MU_TEST(test_replace_all_null)
{
	t_string *str = str_create("");
	str_replace_all(NULL, NULL, NULL);
	mu_assert(1, "Did not Crash!");
	str_deallocate(str);
}

MU_TEST_SUITE(replace_all_tests) 
{
	MU_RUN_TEST(test_replace_all_middle);
	MU_RUN_TEST(test_replace_all_beginning);
	MU_RUN_TEST(test_replace_all_ending);
	MU_RUN_TEST(test_replace_all_no_occurrence);
	MU_RUN_TEST(test_replace_all_multiple_occurrences);
	MU_RUN_TEST(test_replace_all_empty);
	MU_RUN_TEST(test_replace_all_with_empty);
	MU_RUN_TEST(test_replace_all_null);
}

int main(void)
{
	MU_RUN_SUITE(replace_tests);
	MU_RUN_SUITE(replace_all_tests);
	MU_REPORT();
	return MU_EXIT_CODE;
}
