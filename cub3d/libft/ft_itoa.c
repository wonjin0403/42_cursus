/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:39:29 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:45:03 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int n)
{
	int		len;

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

char		*ft_itoa(int n)
{
	int		len;
	int		cnt;
	char	*ans;

	len = ft_numlen(n);
	if (n < 0)
		len += 1;
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (0);
	if (n < 0)
		ans[0] = '-';
	else if (n == 0)
		ans[0] = '0';
	ans[len] = 0;
	cnt = len - 1;
	while (n != 0)
	{
		ans[cnt--] = ((n % 10 < 0) ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (ans);
}
