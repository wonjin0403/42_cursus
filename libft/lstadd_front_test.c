#include <stdio.h>
#include "libft.h"
t_list *ft_lstnew(void *content);

int	main(void)
{
	t_list *lst;
	t_list *a;
	a = ft_lstnew((void *)"abcd");
	//lst = &a;
	//ft_lstadd_front(&lst, a);
	printf("a %s\n", (char *)((a)->content));
	ft_lstadd_back(&lst, a);
	//ft_lstclear(lst);
	printf("after%s\n", (char *)((lst)->content));
}
