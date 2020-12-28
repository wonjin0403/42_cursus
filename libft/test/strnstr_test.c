#include <stdio.h>
char *ft_strnstr(const char *big, const char *little, size_t len);
int	main(void)
{
	char arr[] = "123456789";
	char arr1[] = "34";
	char *ans = ft_strnstr(arr, arr1, 8);
	printf("hi\n");
	printf("%s\n", ans);
}
