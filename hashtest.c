#include "libft.h"


int str_cmp_w(const void *key1, const void *key2)
{
	return (ft_strcmp((char *)key1, (char *)key2) == 0);
}

int main(void)
{
	t_ht *ht;
	void *data;
	ht_init(&ht, 200, hash_str, str_cmp_w);
	char *hello = malloc(20);
	strncpy(hello, "hello", 6);
	printf("inserted: %s\n", hello);
	ht_insert(ht, hello);
	char *yo = malloc(20);
	strncpy(yo, "yoyo", 6);
	ht_insert(ht, yo);
	printf("\n\n\n");

	// Use a copy of the string for lookup
	char lookup_str[20] = "hello";
	data = lookup_str;
	if (!ht_lookup(ht, &data))
		printf("found: %s\n", (char *) data);
	else
		printf("did not find %s\n", hello);
	// Free resources
	ht_destroy(ht, free);
}
