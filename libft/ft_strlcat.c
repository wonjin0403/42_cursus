#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	cnt;

	len = 0;
	cnt = 0;
	while (*(dest))
	{
		len++;
		dest++;
	}
	while (len < dstsize - 1 && *src)
	{
		*(dest++) = *(src++);
		len++;
	}
	*dest = 0;
	while (*(src++))
		len++;
	return (len);
}
