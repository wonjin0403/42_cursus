#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*add;

	while (lst)
	{
		add = ft_lstnew((*f)(add -> content));
		if (!add)
		{
			ft_lstclear(&ans, del);
			return (0);
		}
		ft_lstadd_back(&ans, add);
		lst = lst -> next;
	}
	return (ans);
}
