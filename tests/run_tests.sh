#!/bin/sh
set -e

LIB="../libft.a"

bold() {
	printf "\033[1m$1\033[0m\n"
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

	bold "[$(echo "$name" | tr '[:lower:]' '[:upper:]')]"

printf "compiled!\n"
	local output=$(cc $files $LIB -g -o "test_$name" && ./test_"$name")
	echo "$output"

	# The following output format is assumed: 
	# <title> 
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
test "size" 	       test_str_size.c 	             ../Strings/str_size.c
test "split" 	       test_str_split.c 	     ../Strings/str_split.c
test "substr" 	       test_str_substr.c 	     ../Strings/str_substr.c



#------
#------


printf "\n"
printf "=====================================\n"
bold "FINAL SUMMARY"
printf "=====================================\n"
printf "Total Tests: %d\n" $TOTAL_TESTS
printf "Total Assertions: %d\n" $TOTAL_ASSERTIONS
printf "Total Failures: %d\n" $TOTAL_FAILURES
