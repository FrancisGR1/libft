#include "libft.h"
//Esta função é horrível mas para os meus propósitos é mais do que suficiente
int ft_rand(void) 
{
	static unsigned long next = 1;
	next = next * 1103515245 + 12345;
	return((unsigned)(next/65536) % 32768);
}

