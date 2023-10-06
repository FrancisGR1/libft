#include "libft.h"


//Testing for failed malloc
/*

void *mock_malloc(size_t size) {
    (void)size;
    return NULL; 
}

#define malloc(size) mock_malloc(size)
*/
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t		size;

	size = ft_strlen(s) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		ptr = 0;
	else 
		ft_memcpy(ptr, s, size);
	return (ptr);
}
/*
int main() {
	const char *originalString = "Hello, World!";
	char *duplicateString = ft_strdup(originalString);

	if (duplicateString != NULL) {
		printf("Original: %s\n", originalString);
		printf("Duplicate: %s\n", duplicateString);

		// Clean up memory
		free(duplicateString);
	} else {
		printf("Memory allocation failed. -> %p\n", duplicateString);
	}

	return 0;
}
*/
