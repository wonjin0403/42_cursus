#include <stddef.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (!dest && !src)
		return (0);
	while (*(dest))
	{
		if (len < dstsize)
			len++;
		dest++;
	}
	while (len + 1 < dstsize && *src)
	{
		*(dest++) = *(src++);
		len++;
	}
	*dest = 0;
	while (*(src++))
		len++;
	return (len);
}
