/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 22:37:50 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/25 16:01:51 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	long	ans;

	sign = 1;
	ans = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'\
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		*str++;
	}
	while (*str >= '0' && *str <= '9')
		ans = 10 * ans + (int)(*(str++) - '0');
	return (sign * (int)ans);
}
