/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee </var/mail/wonjlee>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:09:39 by wonjlee           #+#    #+#             */
/*   Updated: 2021/01/09 16:28:37 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
	int	fd = open("exp.txt", O_RDWR); 
	int num = 1;
	char	*line;
	
	while (num == 1)
	{
		num = get_next_line(fd, &line);
		//printf("num:%d\n", num);
		//if (num == 1)
		printf("str:%s\n", line);
		//printf("free\n");
		free(line);
		//num = 0;
		//line = 0;
	}
	close(fd);
}
