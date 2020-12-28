#include <stdio.h>
#include <string.h>
size_t ft_strlcpy(char *dest, const char *src, size_t size);

int	main(void)
{
	char arr[6] = "1234";
	char str[] = "";
	printf("%d \n", (int)ft_strlcpy(arr, str, 1));
	printf("str %s\n", arr);
}
