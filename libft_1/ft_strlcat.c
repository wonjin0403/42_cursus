/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:12:37 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:51:19 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (!dest && !src)
		return (0);
	while (*(dest))
	{
		if (len < dstsize)
			len++;
		dest++;
	}
	while (len + 1 < dstsize && *src)
	{
		*(dest++) = *(src++);
		len++;
	}
	*dest = 0;
	while (*(src++))
		len++;
	return (len);
}
