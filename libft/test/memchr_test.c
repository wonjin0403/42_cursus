#include <string.h>
#include <stdio.h>
#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n );

int	main(void)
{
	char arr[] = "123456";
	printf("%c\n", *(char *)ft_memchr(arr, '3', 6));
}
