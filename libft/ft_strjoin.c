#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(char const *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*start;
	char	*ans;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	start = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	ans = start;
	if (!start)
		return (0);
	while (*s1)
		*(start++) = *(s1++);
	while (*s2)
		*(start++) = *(s2++);
	*start = 0;
	return (ans);
}
