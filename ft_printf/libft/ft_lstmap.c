/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjlee <wonjlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:58:17 by wonjlee           #+#    #+#             */
/*   Updated: 2020/12/31 18:08:48 by wonjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*add;
	t_list	*start;

	ans = 0;
	if (lst == 0)
		return (0);
	while (lst)
	{
		if (!(add = ft_lstnew((*f)(lst->content))))
		{
			((ans) ? ft_lstclear(&ans, del) : 0);
			return (0);
		}
		lst = lst->next;
		if (ans == 0)
		{
			ans = add;
			start = add;
			continue;
		}
		ans->next = add;
		ans = ans->next;
	}
	return (start);
}
