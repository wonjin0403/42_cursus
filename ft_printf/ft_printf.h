/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 01:33:57 by wonjlee           #+#    #+#             */
/*   Updated: 2021/02/05 22:09:26 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct	s_flags
{
	int minus;
	int zero;
	int	after_zero;
	int dot;
	int width;
	int precision;
}				t_flags;
int				ft_printf(const char *format, ...);
int				ft_checklen(unsigned long long num);
int				ft_prefix(char *str, char type, int num_x);

void			classif(char type, int input);
void			flags_init(void);
void			ft_putstr(char *str, char type);
void			ft_putchar(char c, char type);
void			ft_write_width(char *str, int str_len, int check_write);

const char		*check_flags(const char *format);
const char		*check_wp(const char *format, va_list start_form);
const char		*check_else(const char *format);
const char		*check_star(const char *format, va_list start_form);
char			*ft_ptrhex(unsigned long long num);
char			*ft_unsigned_itoa(int num);
char			*hexadecimal(unsigned int num, char x);
char			*ft_putzeros(char *str, char type);
#endif
