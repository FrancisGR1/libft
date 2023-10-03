//se o nº tiver entre 0 e 127, retorna 1
//caso contrario, retorna 0;
#include "libft.h"

int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
int main(int c, char **v)
{
	int mine = ft_isascii(atoi(v[1]));
	int std = isascii(atoi(v[1]));
	
	printf("%d\n", mine);
	printf("%d\n", std);
}
*/
