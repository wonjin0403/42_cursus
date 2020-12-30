/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:05:12 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:40:38 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	cnt;

	cnt = -1;
	while (++cnt < n)
	{
		if (((unsigned char *)s1)[cnt] != ((unsigned char *)s2)[cnt])
			return (((unsigned char *)s1)[cnt] - ((unsigned char *)s2)[cnt]);
	}
	return (0);
}
