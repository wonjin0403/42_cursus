#include <unistd.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	get_next_line(int fd, char **line)
{
	static char	*arr;
	char		buff[BUFFER_SIZE + 1];
	size_t		cnt;
	size_t		cnt2;
	size_t		len;
	int			check;
	char		*sub;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = 0;
	check = 0;
	if (arr)
	{
		len = 0;
		while (arr[len] && arr[len] != '\n')
			len++;
		if (arr[len] == '\n')
			check = 1;
		if (!ft_strjoin(line, arr, len))
			return (-1);
		if ((sub = ft_strchr(arr, '\n')) && *sub)
		{
			cnt = 0;
			while (*sub)
				buff[cnt++] = *(sub++);
			free(arr);
			arr = 0;
			if (!(arr = (char *)malloc(sizeof(char) + (cnt + 1))))
				return (-1);
			cnt2 = -1;
			while (++cnt2 < cnt)
				arr[cnt2] = buff[cnt2];
			arr[cnt2] = 0;
			return (1);
		}
		else
		{
			free(arr);
			arr = 0;
		}
	}
	while (check == 0)
	{
		if ((len = read(fd, buff, BUFFER_SIZE)) == 0)
		{	
			if (!*line)
				*line = ft_strdup("");
			return (0);
		}
		if ((long)len < 0)
		{
			//free(arr);
			//arr = 0;
			return (-1);
		}
		buff[len] = 0;
		cnt = 0;
		while (buff[cnt] != '\n' && cnt < len)
			cnt++;
		if (!ft_strjoin(line, buff, cnt))
		{	
			free(arr);
			arr = 0;
			return (-1);
		}
		if (buff[cnt] == '\n')
		{
			check = 1;
			cnt++;
		}
		if (cnt < len)
		{
			if (!(arr = (char *)malloc(sizeof(char) * (len + 1 - cnt))))
				return (-1);
			cnt2 = 0;
			while (cnt < len)
				arr[cnt2++] = buff[cnt++];
			arr[cnt2] = 0;
		}
	}
	return (1);
}
