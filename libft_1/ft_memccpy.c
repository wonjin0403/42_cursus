/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:26:54 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:43:26 by wonjlee          ###   ########.fr       */
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
	return (0);
}
