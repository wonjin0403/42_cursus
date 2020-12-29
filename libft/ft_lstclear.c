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
		(*del)(node -> content);
		node = node -> next;
		free(now);
	}
	lst = 0;
}
