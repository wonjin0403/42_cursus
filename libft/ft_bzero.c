/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:06:33 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:46:02 by wonjlee          ###   ########.fr       */
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
