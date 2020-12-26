/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:06:51 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/25 22:53:37 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cnt;

	cnt = 0;
	if (!(char *)dest && !(char *)src)
		return (0);
	while (cnt < n)
	{
		((char *)dest)[cnt] = ((char *)src)[cnt];
		cnt++;
	}
	return (dest);
}
