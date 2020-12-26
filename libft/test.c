#include <string.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n);

int	main(void)
{
	char arr[] = "abcdef";
	char arr1[] = "12345";
	printf("%zu\n", ft_strlcat(arr, arr1, 4));
	printf("%s\n", arr);
}
