/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 21:39:19 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/25 23:32:23 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(char *s1, char *s2, size_t n)

{
		unsigned int cnt;

		cnt = 0;
		if (n == 0)
			return (0);
		while (cnt < n - 1 && *s1 && *s2 &&\
				(unsigned char)*s1 == (unsigned char)*s2)
		{
			s1++;
			s2++;
			cnt++;
		}
		return ((unsigned char)*s1 - (unsigned char)*s2);

}
