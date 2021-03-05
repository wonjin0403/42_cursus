/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:56:56 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:43:04 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	cnt;
	char	*ans;

	ans = (char *)s;
	cnt = -1;
	while (++cnt < n)
	{
		if (((char *)ans)[cnt] == (char)c)
			return (ans + cnt);
	}
	return (0);
}
