#include "libft.h"
#include <stdio.h>

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
