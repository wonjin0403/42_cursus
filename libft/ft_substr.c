#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	cnt;
	size_t	len_str;
	
	cnt = 0;
	len_str = 0;
	while (s[start + len_str] && len_str < len)
		len_str++;
	ans = (char *)malloc((len + 1) * sizeof(char));
	if (!ans)
		return (0);
	while (s[start] && cnt < len)
		ans[cnt++] = s[start++];
	ans[cnt] = 0;
	return (ans);
}
