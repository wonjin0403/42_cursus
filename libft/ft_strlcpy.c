/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:35:11 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/26 03:46:36 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = 0;
	if (!src)
		return (0);

	while (len + 1 < n && src[len] && dest[len])
	{
		dest[len] = src[len];
		len++;
	}
	if (n > 0)
		dest[len] = 0;
	return (strlen(src));
}
