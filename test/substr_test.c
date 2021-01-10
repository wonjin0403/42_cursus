#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(void)
{
	printf("%s\n", ft_substr("abcdefg", 8, 0));
}
