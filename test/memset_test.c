#include <string.h>
#include <stdio.h>
void* ft_memset(void *s, int c, size_t n);

int	main(void)
{
	int arr[1];
	//char arr[4]
	char *s;

	//s = memset(arr, 48, 5);
	s = ft_memset(arr, 48, 3);
	printf("value: %c\n", 48);
	while (*s)
	{	
		printf("%c\n", *(s++));
	}
}

