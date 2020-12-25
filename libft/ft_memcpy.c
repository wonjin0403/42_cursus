/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:06:51 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/25 03:48:20 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n && ((char *)src)[cnt])
	{
		((char *)dest)[cnt] = ((char *)src)[cnt];
		cnt++;
	}
	if (!((char *)src)[cnt] && cnt < n)
	{
		((char *)dest)[cnt] = ((char *)src)[cnt];
	}
	return (dest);
}
