/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:06:33 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/25 03:47:44 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
		((char *)s)[cnt++] = 0;
}
