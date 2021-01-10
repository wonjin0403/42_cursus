#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str);

int	main(void)
{
	char	arr[] = "-1 899";
	printf("%d\n", ft_atoi(arr));
}
