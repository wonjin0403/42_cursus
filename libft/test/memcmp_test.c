#include <stdio.h>
#include <stddef.h>
int ft_memcmp(const void *s1, const void *s2, size_t n);

int	main(void)
{
	char a1[] = "123456";
	char a2[] = "1234567";
	printf("%d\n", ft_memcmp(a1, a2, 9));
}
