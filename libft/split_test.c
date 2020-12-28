#include <stdio.h>
char	**ft_split(char const *s, char c);

int	main(void)
{
	char	**ans;
	
	ans = ft_split("", '1');
	while (*ans)
		printf("%s\n", *(ans++));
}
