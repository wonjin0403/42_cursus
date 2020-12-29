#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <string.h>
int	ft_check(char c, unsigned char const *set)
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
	size_t	start;
	size_t	end;
	char *	ans;
	
	start = 0;
	end = ft_strlen(s1) - 1;
	if (!s1)
		return (0);
	else if (!set)
		return (ft_strdup((char *)s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end] && end > 0 && ft_strchr(set, s1[end]))
		end--;
	printf("start %d\n", (int)start);
	printf("end	 %d\n", (int)end);
	if (end < start)
		return (ft_strdup(""));	
	if (!(ans = (char *)malloc(sizeof(char *) * (end - start + 1 + 1))))
			return (0);
	strlcpy(ans, s1 + start, end - start + 1 + 1);
	return (ans);
}
