#include <stdlib.h>
#include <stdio.h>
void *ft_calloc(size_t el, size_t size);

int	main()
{
	printf("%s\n",(char *)calloc(3, 2));
	printf("%s\n", (char *)ft_calloc(3, 2));
}	
