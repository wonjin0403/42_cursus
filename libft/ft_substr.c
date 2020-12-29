#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	cnt;
	size_t	len_str;
	
	cnt = 0;
	len_str = 0;
	if (ft_strlen(s) > start)
	{
		while (s[start + len_str] && len_str < len)
			len_str++;
	}
	ans = (char *)malloc((len_str + 1) * sizeof(char));
	if (!ans)
		return (0);
	while (s[start] && cnt < len && start < ft_strlen(s))
		ans[cnt++] = s[start++];
	ans[cnt] = 0;
	return (ans);
}
