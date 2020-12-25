/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:51:48 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/24 20:56:14 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		cnt1;
	size_t		cnt2;

	cnt1 = -1;
	if (!*little)
		return ((char *)big);
	while (++cnt1 < len && big[cnt1])
	{
		cnt2 = 0;
		while (big[cnt1 + cnt2] == little[cnt2] && cnt1 + cnt2 < len\
				&& little[cnt2])
			cnt2++;
		if (!little[cnt2])
			return ((char *)(&big[cnt1]));
	}
	return (0);
}
