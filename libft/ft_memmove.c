/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:24:09 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/26 20:39:27 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	cnt;

	cnt = 0;
	if (!(char *)dest && !(char *)src)
		return (0);
	while (cnt < n)
	{
		if (dest < src)
			((char *)dest)[cnt] = ((char *)src)[cnt];
		else
			((char *)dest)[n - 1 - cnt] = ((char *)src)[n - 1 - cnt];
		cnt++;
	}
	/*
	while (cnt < n)
		copy[cnt++] = *((char *)src++);
	cnt = -1;
	while (++cnt < n)
		((char *)dest)[cnt] = ((char *)copy)[cnt];
	*/
	return (dest);
}
