/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:55:14 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:49:04 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	ft_numarr(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s != c && *s)
				s++;
		}
		while (*s == c && *s)
			s++;
	}
	return (cnt);
}

size_t	ft_numw(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && *s != c)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	numw;
	size_t	numarr;
	size_t	cnt;
	size_t	w;

	cnt = -1;
	numarr = ft_numarr(s, c);
	if (!s || !(ans = (char **)malloc((numarr + 1) * sizeof(char *))))
		return (0);
	while (++cnt < numarr)
	{
		while (*s == c)
			s++;
		numw = ft_numw(s, c);
		ans[cnt] = (char *)malloc((numw + 1) * sizeof(char));
		if (!ans[cnt])
			return (0);
		w = 0;
		while (w < numw)
			ans[cnt][w++] = *(s++);
		ans[cnt][w] = 0;
	}
	ans[cnt] = 0;
	return (ans);
}
