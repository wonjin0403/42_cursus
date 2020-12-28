#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(char const *s)
{
	size_t len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	cnt;
	char	*ans;
	
	cnt = 0;
	len = ft_strlen(s);
	ans = (char *)malloc((len + 1) * sizeof(char *));
	if (!ans)
		return (0);
	printf("len %d\n", (int)len);
	while (*s)
		ans[cnt++] = (*f)(cnt, (char)(*(s++)));
	ans[cnt] = 0;
	return (ans);
}
