#include <stdio.h>
#include <string.h>

char *ft_strtrim(char const *s1, char const *set);

int	main()
{
	char str[] = "12hello world12" ;
	char str1[1];
	//str[10] = '\n';
	//str[11] = 'p';
	//str[12] = 'l';
	printf("%s\n", ft_strtrim(str, "12"));
}
