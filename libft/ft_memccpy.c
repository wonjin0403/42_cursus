/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:26:54 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/25 03:49:05 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt++ < n)
	{
		*((char *)dest++) = *(char *)src;
		if (*((char *)src++) == (char)c)
			return (dest);
	}
	return (NULL);
}
