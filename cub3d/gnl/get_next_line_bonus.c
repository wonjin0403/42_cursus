/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:42:18 by wonjlee           #+#    #+#             */
/*   Updated: 2021/03/05 16:13:31 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "get_next_line_bonus.h"
#include "libft.h"

int		check_buff(char **backup, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	size_t		len;
	size_t		cnt;
	int			check;

	len = 0;
	while ((*backup)[len] && (*backup)[len] != '\n')
		len++;
	check = ((*backup)[len] == '\n') ? 1 : 0;
	if (!ft_new_strjoin(line, *backup, len))
		return (-1);
	cnt = -1;
	while ((*backup)[len + (++cnt)])
		buff[cnt] = (*backup)[len + 1 + cnt];
	buff[cnt] = 0;
	free(*backup);
	*backup = 0;
	if (check && !(*backup = ft_strdup(buff)))
		return (-1);
	return (check);
}

int		split_buff(char *buff, size_t len, char **line, char **backup)
{
	size_t		cnt;
	int			check;

	cnt = 0;
	check = 0;
	while (buff[cnt] != '\n' && cnt < len)
		cnt++;
	if (!ft_new_strjoin(line, buff, cnt))
		return (-1);
	if (buff[cnt] == '\n')
	{
		check = 1;
		cnt++;
	}
	if (cnt < len && !(*backup = ft_strdup(buff + cnt)))
		return (-1);
	return (check);
}

int		get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX + 1];
	char		buff[BUFFER_SIZE + 1];
	long		len;
	int			check;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	check = 0;
	*line = 0;
	len = 0;
	if (backup[fd] && ((check = check_buff(&backup[fd], line)) == -1))
		return (-1);
	while (check == 0 && (len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[len] = 0;
		if ((check = split_buff(buff, len, line, &backup[fd])) == -1)
			return (-1);
	}
	if (len == 0 && check == 0)
	{
		if (!*line)
			*line = ft_strdup("");
		return (0);
	}
	return (len < 0 ? -1 : 1);
}
