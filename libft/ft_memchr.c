/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:56:56 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/23 19:23:07 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	cnt;
	char		*ans;

	ans = (char *)s;
	cnt = -1;
	while (++cnt < n)
	{
		if (((char *)ans)[cnt] == (char)c)
			return (ans + cnt);
	}
	return (0);
}
