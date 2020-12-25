/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:05:03 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/25 15:22:54 by wonjin           ###   ########.fr       */
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
