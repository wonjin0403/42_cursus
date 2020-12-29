#include <stdio.h>
#include "libft.h"
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);

int	main(void)
{
	t_list *lst;
	t_list *a;
	a = ft_lstnew((void *)"abcd");
	//lst = &a;
	ft_lstadd_front(&lst, a);
	printf("%s\n", (char *)((lst)->content));
}
