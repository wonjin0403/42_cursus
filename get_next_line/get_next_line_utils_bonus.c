/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:14:49 by wonjlee           #+#    #+#             */
/*   Updated: 2021/01/09 17:37:00 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (*(str + 1) == 0 ? 0 : (str + 1));
		str++;
	}
	return (0);
}

int		ft_strjoin(char **line, char *buff, size_t len)
{
	size_t	cnt;
	size_t	before_len;
	char	*before;

	cnt = -1;
	if (!*line)
	{
		if (!(*line = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		while (++cnt < len)
			(*line)[cnt] = *(buff++);
		(*line)[cnt] = 0;
		return (1);
	}
	before_len = ft_strlen(*line);
	if (!(before = (char *)malloc(sizeof(char) * (len + before_len + 1))))
		return (0);
	before = ft_strncpy(before, *line, before_len);
	free(*line);
	*line = before;
	cnt = -1;
	while (++cnt < len)
		(*line)[cnt + before_len] = *(buff++);
	(*line)[cnt + before_len] = 0;
	return (1);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (*(src + idx) && idx < n)
	{
		dest[idx] = src[idx];
		++idx;
	}
	while (idx < n)
	{
		dest[idx] = '\0';
		++idx;
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*ans;

	len = 0;
	if (!*src)
	{
		ans = (char *)malloc(1);
		if (!ans)
			return (0);
		*ans = 0;
		return (ans);
	}
	while (src[len])
		len++;
	ans = (char *)malloc((len + 1) * sizeof(char));
	if (!ans)
		return (0);
	len = 0;
	while (*src)
		ans[len++] = *(src++);
	ans[len] = *src;
	return (ans);
}
