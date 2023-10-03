#include <stdlib.h>
#include <stdio.h>

int main (int c, char **v)
{
	unsigned char i = atoi(v[1]);
	printf("unsgned char of %d: %c\n", i, i);
}
