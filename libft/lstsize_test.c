#include "libft.h"
#include <stdio.h>

int	main()
{
	t_list **a;
	t_list *b = ft_lstnew((void *)"ab");
	a = &b;
	printf("%s\n", (char *)((*a) -> content));
	for (int i = 0; i < 5; i++)
	{
		ft_lstadd_back(a, ft_lstnew((void *)("1234")));
		//ft_lstadd_front(a, ft_lstnew((void *)("1234")));
		printf("%s\n", (char *)((*a) -> content));
	}
	//int num = ft_lstsize(*a);
	printf("%d\n", ft_lstsize(*a));
	printf("%s\n", (char *)(ft_lstlast(*a)->content));
}
