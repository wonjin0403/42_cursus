/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:14:49 by wonjlee           #+#    #+#             */
/*   Updated: 2021/01/08 13:53:23 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	while (++cnt < before_len)
		before[cnt] = (*line)[cnt];
	free(*line);
	*line = before;
	cnt = -1;
	while (++cnt < len)
		(*line)[cnt + before_len] = *(buff++);
	(*line)[cnt + before_len] = 0;
	return (1);
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
