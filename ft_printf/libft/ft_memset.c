/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:07:10 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:42:06 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
		((char *)s)[cnt++] = (char)c;
	return (s);
}
