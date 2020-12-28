#include <stdio.h>
#include <stddef.h>

size_t	ft_strlcat(char *dest, char *src, size_t n);
int	main(void)
{
	char	arr[] = "1";
	char	arr1[] = "abcd";
	char	*dest = arr;
	
	printf("%d\n", (int)ft_strlcat(arr, arr1, 3));
	printf("%s\n", arr);
}
