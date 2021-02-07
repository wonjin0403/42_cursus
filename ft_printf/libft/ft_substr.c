/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:20:24 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:54:56 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	cnt;
	size_t	len_str;

	cnt = 0;
	len_str = 0;
	if (!s)
		return (ft_strdup(""));
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
