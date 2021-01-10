#include <stdio.h>
int	ft_strncmp(const char *s1, const char *s2, size_t len);

int	main(void)
{
	char s1[] = "12345";
	char s2[] = "1233345";
	printf("ans %d\n", ft_strncmp(s1, s2, 5));
}
