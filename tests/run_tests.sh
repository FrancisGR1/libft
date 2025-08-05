#!/bin/sh
set -e

ARG1=$1
LIB="../libft.a"

bold() {
	printf "\n\033[1m$1\033[0m\n"
}

TOTAL_TESTS=0
TOTAL_ASSERTIONS=0
TOTAL_FAILURES=0


test() {
	# $1: test name (e.g., "internals")
	# $2 - $n: source files (space-separated string)
	local name=$1
	shift
	local files="$@"

	# Check script argument
	if [ -n "$ARG1" ] && [ "$name" != "$ARG1" ]; then
		return 0 
	fi

	bold "[$(echo "$name" | tr '[:lower:]' '[:upper:]')]"

	printf "compiled!\n"
	local output=$(cc $files $LIB -g -o "test_$name" && ./test_"$name")
	echo "$output"

	# The following output format is assumed: 
	# <title> 
	# compiled!
	# <n dots> 
	# <n> tests, <n> assertions, <n> failures
	local test_line=$(echo "$output" | grep "tests.*assertions.*failures")
	local tests=$(echo "$test_line" | awk '{print $1}')
	local assertions=$(echo "$test_line" | awk '{print $3}')
	local failures=$(echo "$test_line" | awk '{print $5}')

	TOTAL_TESTS=$((TOTAL_TESTS + tests))
	TOTAL_ASSERTIONS=$((TOTAL_ASSERTIONS + assertions))
	TOTAL_FAILURES=$((TOTAL_FAILURES + failures))

	rm "test_$name"
}

printf "\n\n================\n"
bold "TESTING STRINGS"
printf "================\n\n"

    # Tests
    test "internals"       test_string_internals.c       ../Strings/string_internals.c
    test "creation"        test_string_creation.c        ../Strings/string_creation.c
    test "insert"          test_str_insert.c             ../Strings/str_insert.c
    test "replace"         test_str_replace.c            ../Strings/str_replace.c
    test "from_primitives" test_str_from_primitives.c    ../Strings/str_from_primitives.c
    test "to_primitives"   test_str_to_primitives.c      ../Strings/str_to_primitives.c
    test "size"            test_str_size.c               ../Strings/str_size.c
    test "split"           test_str_split.c              ../Strings/str_split.c
    test "copy"            test_str_copy.c               ../Strings/str_copy.c
    test "substr"          test_str_substr.c             ../Strings/str_substr.c
    test "join"            test_str_join.c               ../Strings/str_join.c
    test "search"          test_str_search.c             ../Strings/str_search.c
    test "search_not_of"   test_str_search.c             ../Strings/str_search_not_of.c
    test "compare"         test_str_compare.c            ../Strings/str_compare.c
    test "match"           test_str_match.c              ../Strings/str_match.c
    test "arithmetics"     test_str_arithmetics.c        ../Strings/str_arithmetics.c
    test "is"              test_str_is.c                 ../Strings/str_is.c ../Strings/str_is_p2.c
    test "remove"          test_str_remove.c             ../Strings/str_remove.c
    test "trim"            test_str_trim.c               ../Strings/str_trim.c
    test "case"            test_str_case.c               ../Strings/str_case.c
    test "modify_size"     test_str_modify_size.c        ../Strings/str_modify_size.c
    test "accessors"       test_str_accessors.c          ../Strings/str_accessors.c

    printf "\n"
    printf "=====================================\n"
    bold   "FINAL SUMMARY"
    printf "=====================================\n"
    printf "Total Tests: %d\n"      $TOTAL_TESTS
    printf "Total Assertions: %d\n" $TOTAL_ASSERTIONS
    printf "Total Failures: %d\n"   $TOTAL_FAILURES
