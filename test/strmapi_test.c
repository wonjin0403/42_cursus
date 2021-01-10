#include <stdio.h>
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	f(unsigned int a, char c)
{
	return ((char)(a + c));
}
int	main()
{	
	printf("%s\n", ft_strmapi("abcde", *f));
}

