/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:24:09 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:42:37 by wonjlee          ###   ########.fr       */
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
	return (dest);
}
