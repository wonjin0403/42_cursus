#include <string.h>
#include <stdio.h>
void *ft_memmove(void *dest, void *src, size_t n);

int	main(void)
{
	char arr2[4] = "abcd";
	char *ans1 = ft_memmove(arr2, "123", 5);
	printf("ft ans %s\n", ans1);
	
	
	int	 arr[6];
	int 	arr1[3] = {2001, 2001, 30001};
	int *ans = ft_memmove(arr1, arr1, 3);
	printf("ans %d \n", ans[0]);
	printf("ans %d \n", ans[1]);
	printf("ans %d \n", ans[2]);
	printf("ans %d \n", ans[3]);
	printf("end");
}
