/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:50:31 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 01:44:39 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*now;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		now = node;
		(*del)(node->content);
		node = node->next;
		free(now);
	}
	*lst = 0;
}
