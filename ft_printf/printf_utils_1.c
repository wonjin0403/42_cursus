/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 01:10:15 by wonjlee           #+#    #+#             */
/*   Updated: 2021/02/05 22:08:37 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

extern unsigned int g_len;
extern t_flags		g_flags;

char		*hexadecimal(unsigned int num, char x)
{
	int		sign;
	int		len;
	char	*ans;
	char	*menu;

	if (x == 'X')
		menu = "0123456789ABCDEF";
	else
		menu = "0123456789abcdef";
	sign = 0;
	if (num < 0)
		sign = 1;
	len = ft_checklen((unsigned long long)num);
	if (!(ans = (char *)malloc(sizeof(char *) * (len + 1))))
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

void		ft_putchar(char c, char type)
{
	int		cnt;

	cnt = 0;
	if (type != '1' && g_flags.width && g_flags.minus == 0)
	{
		while (cnt++ < g_flags.width - 1)
		{
			if (g_flags.zero || (type == '%' && g_flags.after_zero))
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		g_len += cnt - 1;
	}
	g_len += 1;
	write(1, &c, 1);
	if (type != '1' && g_flags.width && g_flags.minus)
	{
		while (cnt++ < g_flags.width - 1)
			write(1, " ", 1);
		g_len += cnt - 1;
	}
}

int			ft_prefix(char *str, char type, int num_x)
{
	int		num_str;
	int		str_len;

	str_len = 0;
	num_str = ft_atoi(str);
	if (type == 's' && g_flags.dot &&\
			(size_t)g_flags.precision < ft_strlen(str))
		str_len = g_flags.precision;
	else if (!(g_flags.dot && g_flags.precision == 0 && (num_str == 0)) ||\
			((type == 'x' || type == 'X') && num_x))
		str_len = ft_strlen(str);
	if (type == 'p')
		g_flags.width -= 2;
	return (str_len);
}

void		ft_write_width(char *str, int str_len, int check_write)
{
	int cnt;

	cnt = 0;
	if (g_flags.minus == check_write && str_len < g_flags.width)
	{
		if (!check_write && *str == '-' && g_flags.zero)
			write(1, str, 1);
		while (cnt++ < g_flags.width - str_len)
			(g_flags.zero) ? write(1, "0", 1) : write(1, " ", 1);
		g_len += cnt - 1;
	}
}

void		ft_putstr(char *str, char type)
{
	int		str_len;
	int		num_x;
	int		cnt;
	char	*tr;

	cnt = 0;
	num_x = 0;
	if (((type == 'x' || type == 'X' || type == 'p') && *str != '0'))
		num_x = 1;
	if (g_flags.dot && type != 's')
	{
		tr = ft_putzeros(str, type);
		free(str);
		str = tr;
	}
	str_len = ft_prefix(str, type, num_x);
	ft_write_width(str, str_len, 0);
	(g_len) = (type == 'p') ? g_len + str_len + 2 : g_len + str_len;
	if (type == 'p')
		write(1, "0x", 2);
	(g_flags.zero && *str == '-' && type != 's' && str_len < g_flags.width)\
					? write(1, str + 1, str_len - 1) : write(1, str, str_len);
	(type != 's') ? free(str) : 0;
	ft_write_width(str, str_len, 1);
}
