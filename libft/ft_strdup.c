/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee  <wonjlee@stduent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 02:33:10 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/25 14:37:55 by wonjin           ###   ########.fr       */
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
		*ans = 0;
		return (ans);
	}
	while (src[len])
		len++;
	ans = (char *)malloc(len * sizeof(char));
	if (!ans)
		return (-1);
	len = 0;
	while (*src)
		ans[len++] = *(src++);
	ans[len] = *src;
	return (ans);
}
