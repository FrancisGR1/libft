#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t		i;
	unsigned char		*ptr;
	
	p = malloc(nmemb * size);
	if (!p || nmemb == 0 || size == 0)
		return (NULL);
	ptr = p;
	i = 0;
	while (i < nmemb * size)
		ptr[i++] = 0;
	return (p);
}
/*
int main()
{
    // Test case 1: Allocate and initialize an array of 5 integers
    int *intArray = (int *)ft_calloc(0, sizeof(int));
    if (intArray != NULL) {
        for (int i = 0; i < 5; i++) {
            printf("%d ", intArray[i]); // Should print "0 0 0 0 0 "
        }
	free(intArray);
    }
    else
	    printf("%p\n", intArray);

    // Test case 2: Allocate and initialize an array of 3 doubles
    double *doubleArray = (double *)ft_calloc(3, sizeof(double));
    if (doubleArray != NULL) {
	    for (int i = 0; i < 3; i++) {
		    printf("\n%lf  \n", doubleArray[i]); // Should print "0.000000 0.000000 0.000000 "
	    }
	    free(doubleArray);
    }
    else
	    printf("%p\n", intArray);

    return 0;
}
*/
