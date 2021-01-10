/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:40:23 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:50:39 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*start;
	char	*ans;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (ft_strdup(""));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	start = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	ans = start;
	if (!start)
		return (0);
	while (*s1)
		*(start++) = *(s1++);
	while (*s2)
		*(start++) = *(s2++);
	*start = 0;
	return (ans);
}
