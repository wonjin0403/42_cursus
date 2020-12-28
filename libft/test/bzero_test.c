#include <stdio.h>

int	main(void)
{
	char a[] = "123456";

	ft_bzero(a, 3);
	for (int i = 0; i< 6; i++)
		printf("%c\n", a[i]);
}
