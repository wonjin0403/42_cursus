/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:30:12 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:55:19 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_check(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s, char const *set)
{
	int		start;
	int		end;
	char	*ans;

	start = 0;
	end = ft_strlen(s) - 1;
	if (!s || !set)
		return ((char *)s);
	while (start <= end && ft_check(set, s[start]))
		start++;
	while (end >= 0 && ft_check(set, s[end]))
		end--;
	if (end < start)
		return (ft_strdup(""));
	if (!(ans = (char *)malloc(sizeof(char) * (end - start + 1 + 1))))
		return (0);
	ft_strlcpy(ans, s + start, end - start + 1 + 1);
	return (ans);
}
