#include <stdlib.h>

int	ft_check(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	cnt;
	char *	ans;

	len = 0;
	cnt = 0;
	while (s1[cnt])
	{
		if (!ft_check(s1[cnt], set))
			len++;
		cnt++;
	}
	cnt = 0;
	ans = (char *)malloc((len + 1) * sizeof(char));
	while (*s1)
	{
		if (!ft_check(*s1, set))
			ans[cnt++] = *(s1++);
		else
			s1++;
	}
	ans[cnt] = 0;
	return (ans);
}
