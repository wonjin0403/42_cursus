/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 01:20:20 by wonjlee           #+#    #+#             */
/*   Updated: 2021/02/05 22:04:08 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

extern t_flags	g_flags;

int		ft_checklen(unsigned long long num)
{
	int len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_ptrhex(unsigned long long num)
{
	int		len;
	char	*ans;
	char	*menu;

	menu = "0123456789abcdef";
	len = ft_checklen(num);
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ans[len] = 0;
	if (num == 0)
		ans[0] = '0';
	while (num != 0)
	{
		ans[--len] = menu[num % 16];
		num /= 16;
	}
	return (ans);
}

char	*ft_putzeros(char *str, char type)
{
	int		str_len;
	int		num_zero;
	int		cnt;
	char	*ans;

	cnt = 0;
	str_len = ft_strlen(str);
	if ((type == 'd' || type == 'i') && *str == '-')
		num_zero = g_flags.precision - (str_len - 1);
	else
		num_zero = g_flags.precision - str_len;
	num_zero = (num_zero < 0) ? 0 : num_zero;
	ans = (char *)malloc(sizeof(char) * (num_zero + str_len + 1));
	str_len = num_zero + str_len;
	ans[str_len] = 0;
	while (cnt < str_len)
	{
		if ((type == 'd' || type == 'i') && *str == '-')
			ans[cnt++] = *(str++);
		else if (num_zero-- > 0)
			ans[cnt++] = '0';
		else
			ans[cnt++] = *(str++);
	}
	return (ans);
}

void	flags_init(void)
{
	g_flags.minus = 0;
	g_flags.zero = 0;
	g_flags.after_zero = 0;
	g_flags.dot = 0;
	g_flags.width = 0;
	g_flags.precision = 0;
}

void	classif(char type, int input)
{
	if (type == 'c')
		ft_putchar((char)input, type);
	else if (type == 'd' || type == 'i')
		ft_putstr(ft_itoa(input), type);
	else if (type == 'u')
		ft_putstr(ft_unsigned_itoa(input), type);
	else
		ft_putstr(hexadecimal(input, type), type);
}
