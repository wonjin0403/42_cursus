/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 22:04:24 by wonjlee           #+#    #+#             */
/*   Updated: 2021/02/05 22:20:22 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_un_numlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_unsigned_itoa(int num)
{
	unsigned int	len;
	unsigned int	cnt;
	char			*ans;
	unsigned int	n;

	n = num;
	len = ft_un_numlen(n);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (0);
	ans[len] = 0;
	if (num == 0)
		ans[0] = '0';
	cnt = len - 1;
	while (n != 0)
	{
		ans[cnt--] = ((n % 10 < 0) ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (ans);
}
