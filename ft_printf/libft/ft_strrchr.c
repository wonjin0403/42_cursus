/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 00:38:41 by wonjin            #+#    #+#             */
/*   Updated: 2020/12/25 15:28:30 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*point;

	point = 0;
	while (*str)
	{
		if (*str == (char)c)
			point = (char *)str;
		str++;
	}
	if (*str == (char)c)
		point = (char *)str;
	return (point);
}
