/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:35:11 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/25 16:48:06 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = -1;
	while (++len < n-1 && *src)
		*(dest++) = *(src++);
	*(dest) = 0;
	while (*src++)
		len++;
	return (len);
}
