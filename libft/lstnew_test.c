#include <stdio.h>
#include "libft.h"
t_list *ft_lstnew(void	*content);
int	main()
{
	t_list *a;
	a = ft_lstnew((void *)"abcd");
	printf("context %s\n", (char *)a->content);
	printf("next %s\n", (char *)a->next);
}
