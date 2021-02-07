/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:59:11 by wonjlee           #+#    #+#             */
/*   Updated: 2021/02/05 22:14:24 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

unsigned int	g_len;
t_flags			g_flags;

const char	*check_flags(const char *format)
{
	if (!*format)
		return (format);
	else if (*format == '%')
		format++;
	flags_init();
	while (*format == '-' || *format == '0')
	{
		if (*format == '-')
		{
			g_flags.minus = 1;
			g_flags.zero = 0;
		}
		else if (*format == '0' && g_flags.minus == 0)
			g_flags.zero = 1;
		format++;
	}
	g_flags.after_zero = g_flags.zero;
	return (format);
}

const char	*check_star(const char *format, va_list start_form)
{
	int		num;

	num = va_arg(start_form, int);
	if (g_flags.dot)
	{
		g_flags.precision = (num < 0) ? 0 : num;
		g_flags.dot = (num < 0) ? 0 : g_flags.dot;
		g_flags.zero = (num < 0) ? g_flags.zero : 0;
	}
	else
	{
		g_flags.minus = (num < 0) ? 1 : g_flags.minus;
		g_flags.zero = (num < 0) ? 0 : g_flags.zero;
		g_flags.width = (num > 0) ? num : -num;
	}
	return (++format);
}

const char	*check_else(const char *format)
{
	if (g_flags.dot)
	{
		if (*(format - 1) == '-')
		{
			g_flags.width = ft_atoi(format);
			g_flags.dot = 0;
			g_flags.minus = 1;
		}
		else
			g_flags.precision = ft_atoi(format);
	}
	else
		g_flags.width = ft_atoi(format);
	while (*format >= '0' && *format <= '9')
		format++;
	return (format);
}

const char	*check_wp(const char *format, va_list start_form)
{
	while (*format == '.' || *format == '*' ||\
			(*format >= '0' && *format <= '9'))
	{
		if (*format == '.')
		{
			g_flags.dot = 1;
			format++;
			g_flags.zero = (*format != '*') ? 0 : g_flags.zero;
		}
		else if (*format == '*')
			format = check_star(format, start_form);
		else
			format = check_else(format);
	}
	return (format);
}

int			ft_printf(const char *format, ...)
{
	va_list	start_form;
	char	*ptr;

	va_start(start_form, format);
	g_len = 0;
	while (*format)
	{
		while (*format && *format != '%')
			ft_putchar(*(format++), '1');
		format = check_flags(format);
		format = check_wp(format, start_form);
		if (*format == 'd' || *format == 'i' || *format == 'u'\
				|| *format == 'x' || *format == 'X' || *format == 'c')
			classif(*format, va_arg(start_form, int));
		else if (*format == '%')
			ft_putchar(*format, '%');
		else if (*format == 's')
			(ptr = va_arg(start_form, char *)) ? ft_putstr(ptr, *format) :\
				ft_putstr("(null)", *format);
		else if (*format == 'p')
			ft_putstr(ft_ptrhex((unsigned long long)va_arg(start_form, void *))\
					, *format);
		(*format) ? format++ : 0;
	}
	return (g_len);
}
