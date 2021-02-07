/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:15:12 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:53:50 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	cnt;
	char	*ans;

	if (!s || !f)
		return (0);
	cnt = 0;
	len = ft_strlen(s);
	ans = (char *)malloc((len + 1) * sizeof(char));
	if (!ans)
		return (0);
	ans[len] = 0;
	while (*s)
	{
		ans[cnt] = (*f)(cnt, *(s++));
		cnt++;
	}
	return (ans);
}
