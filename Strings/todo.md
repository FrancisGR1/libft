grep -R -n -A2 "@TODO\|TODO" .

- From Primitive Types
t_string* str_from_unicode(const wchar_t* wstr);

- To Primitive Types
bool string_to_bool_from_cstr(const char* boolstr);

- Encode
wchar_t* string_to_unicode(const char* str);
t_string* str_base64_encode(const t_string *input);
t_string* str_base64_decode(const t_string* input);

- Content Query
char string_at(const String* str, size_t index);
const char* string_data(const String* str);
const char* string_c_str(const String* str);
const char* string_cbegin(const String* str);
const char* string_cend(const String* str);
const char* string_crbegin(const String* str);
const char* string_crend(const String* str);

char* string_begin(const String* str);
char* string_end(const String* str);
char* string_rbegin(const String* str);
char* string_rend(const String* str);
char* string_back(const String* str);
char* string_front(const String* str);

- Size and Capacity
size_t string_length_utf8(const char* str);
size_t string_utf8_char_len(char c);

- String checks

bool string_is_equal(const String* str1, const String* str2);
bool string_is_not_equal(const String* str1, const String* str2);
bool string_is_less(const String* str1, const String* str2);
bool string_is_greater(const String* str1, const String* str2);
bool string_is_less_or_equal(const String* str1, const String* str2);
bool string_is_greater_or_equal(const String* str1, const String* str2);

bool string_is_alpha(const String* str);
bool string_is_digit(const String* str);
bool string_is_alnum(const String* str);
bool string_is_lower(const String* str);
bool string_is_upper(const String* str);

bool string_is_title(const String* str);
bool string_is_space(const String* str);
bool string_is_printable(const String* str);
bool string_is_palindrome(const String* str);

bool string_contains(const String* str, const char* substr);
bool string_starts_with(const String* str, const char* substr);
bool string_ends_with(const String* str, const char* substr);

bool string_set_pool_size(String* str, size_t newSize);

- Compare
int string_compare(const String* str1, const String* str2);
int string_compare_ignore_case(const String* str1, const String* str2);
int string_strcmp(const char* str1, const char* str2);

- Search 
int string_find(const String* str, const char* buffer, size_t pos);
int string_rfind(const String* str, const char* buffer, size_t pos);
int string_find_first_of(const String* str, const char* buffer, size_t pos);
int string_find_last_of(const String* str, const char* buffer, size_t pos);
int string_find_first_not_of(const String* str, const char* buffer, size_t pos);
int string_find_last_not_of(const String* str, const char* buffer, size_t pos);

- Substr

- Split

- Join
String* string_join(String **strings, int count, const char *delimiter);
String* string_join_variadic(size_t count, ...);

- Modification, Mutation

- Removal
void string_erase(String* str, size_t pos, size_t len);
void string_pop_back(String* str);
void string_remove(String* str, const char* substr);
void string_remove_range(String* str, size_t startPos, size_t endPos);

- Resize/Capacity
void string_resize(String* str, size_t newSize);
void string_reserve(String *str, size_t newCapacity);
void string_shrink_to_fit(String* str);

- Assignment/Swap
void string_swap(String* str1, String* str2);

- Trim
void string_trim(String *str);
void string_trim_left(String *str);
void string_trim_right(String *str);
void string_trim_characters(String* str, const char* chars);

- Pad
void string_pad_left(String *str, size_t totalLength, char padChar);
void string_pad_right(String *str, size_t totalLength, char padChar);

- Case
void string_to_upper(String* str);
void string_to_lower(String* str);
void string_to_title(String* str);
void string_to_capitalize(String* str);
void string_to_casefold(String* str);
void string_swap_case(String* str);


- Others, utils
String* string_repeat(const String* str, size_t count);
void string_shuffle(String* str);
void string_reverse(String* str);
void string_format(String* str, const char* format, ...);
size_t string_copy(const String* str, char* buffer, size_t pos, size_t len);
