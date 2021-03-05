/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:11:35 by wonjlee           #+#    #+#             */
/*   Updated: 2021/01/07 11:32:35 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*ans;

	len = 0;
	if (!*src)
	{
		ans = (char *)malloc(1);
		if (!ans)
			return (0);
		*ans = 0;
		return (ans);
	}
	while (src[len])
		len++;
	ans = (char *)malloc((len + 1) * sizeof(char));
	if (!ans)
		return (0);
	len = 0;
	while (*src)
		ans[len++] = *(src++);
	ans[len] = *src;
	return (ans);
}
