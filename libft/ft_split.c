#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_numarr(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{ 
		if (*s != c)
		{
			cnt++;
			while (*s != c && *s)
				s++;
		}
		while (*s == c && *s)
			s++;
	}
	return (cnt);
}

size_t	ft_numw(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && *s != c)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	numarr;
	size_t	numw;
	size_t	cnt;
	size_t	w;

	cnt = 0;
	numarr = ft_numarr(s, c);
	ans = (char **)malloc((numarr + 1) * sizeof(char *));
	if (!ans)
		return (0);
	ans[numarr] = 0;
	while (cnt < numarr)
	{
		numw = ft_numw(s, c);
		ans[cnt] = (char *)malloc((numw + 1) * sizeof(char));
		if (!ans[cnt])
			return (0);
		w = 0;
		while (w < numw)
			ans[cnt][w++] = *(s++);
		ans[cnt][w] = 0;
		cnt++;
		while (*s == c)
			s++;
	}
	return (ans);
}

