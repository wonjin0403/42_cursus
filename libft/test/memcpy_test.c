#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char a[4] = "1234";
	char c[10] = "";
	int hi[4] = {1, 2, 3, 4};
	int out[10];
	char *b = memcpy(c, a, 0);
	printf("output %s\n", b);
	//printf("output %d\n", b[1]);
	//printf("output %d\n", b[2]);
	//while (*b)
	//{
		//printf("%d\n", i);
	//	printf("output %c\n", *(b++));

	//}
}
