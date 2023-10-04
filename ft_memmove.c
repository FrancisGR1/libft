#include "libft.h"
#include <string.h>
#include <ctype.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	len;
	int	i;
	unsigned char	*arr;
	unsigned char	*ptr;
	
	i = 0;
	arr[n];
	while(*(src + i) && i < n)
		arr[i++] = *src;
	i = 0;
	ptr = dest;
	while(i < n)
		*(ptr + i) = arr[i++];	
	return (dest);
}

int main (void)
{
	char dest1[10];
	char dest2[10];
	char arr[] = "Testestesfd";
	char arr1[] = "TESTETSETEESDF";
	//ft_memmove(dest1, arr, 5);
	memmove(dest2, arr, 5);
	
	printf("FT: %s\n", dest1);
	printf("STD: %s\n", dest2);
}

/*https://www.youtube.com/watch?v=DGwdAQauEV4&ab_channel=PortfolioCourses*/
/*https://stackoverflow.com/questions/43088070/meaning-of-overlapping-when-using-memcpy*/
