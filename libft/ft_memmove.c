/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:24:09 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/25 15:09:45 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	copy[n + 1];
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
		copy[cnt++] = *((char *)src++);
	cnt = -1;
	while (++cnt < n)
		((char *)dest)[cnt] = copy[cnt];
	return (dest);
}
