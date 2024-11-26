#include "hash_table.h"

//Credit to Kyle Loudon and his book "Mastering Algorithms"
int hash_str(const void *key)
{
	const char *str;
	size_t res;
	size_t tmp;

	res = 0;
	str = key;
	while (*str)
	{
		res = (res << 4) + *str;
		tmp = (res & 0xf0000000);
		if (tmp)
		{
			res = res ^ (tmp >> 24);
			res = res ^ tmp;
		}
		str++;
	}
	return (res);
}
