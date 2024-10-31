#include "libft.h"

void *ft_memcat(void *dst, void *src, size_t dst_offset, size_t data_cnt)
{
	unsigned char *dst_with_offset;

	if (!dst || !src)
		return (NULL);
	dst_with_offset = (unsigned char *)(dst + dst_offset);
	while (data_cnt--)
		*dst_with_offset = *(unsigned char *)src++;
	return (dst);
}
