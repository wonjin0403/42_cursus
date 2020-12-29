#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*ans;

	ans = (t_list *)malloc(sizeof(t_list));
	if (!ans)
		return (0);
	ans -> content = content;
	ans -> next = 0;
	return (ans);
}
