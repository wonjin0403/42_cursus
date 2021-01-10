/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:13:04 by wonjlee           #+#    #+#             */
/*   Updated: 2021/01/09 17:43:15 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		split_buff(char *buff, size_t len, char **line, char **backup);
int		check_buff(char **backup, char **line);
size_t	ft_strlen(char *str);
int		ft_strjoin(char **line, char *buff, size_t len);
char	*ft_strdup(char *src);
char	*ft_strchr(char *str, char c);
char	*ft_strncpy(char *dest, char *src, unsigned int len);
#endif
