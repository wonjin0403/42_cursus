#include <stdio.h>
#include <limits.h>

char *ft_itoa(int n);

int	main()
{
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-23));

}
