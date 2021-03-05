/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:13:04 by wonjlee           #+#    #+#             */
/*   Updated: 2021/03/05 16:00:43 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 128
# include <stddef.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		split_buff(char *buff, size_t len, char **line, char **backup);
int		check_buff(char **backup, char **line);
int		ft_new_strjoin(char **line, char *buff, size_t len);
//char	*ft_strchr(char *str, char c);
char	*ft_strncpy(char *dest, char *src, unsigned int len);
#endif
