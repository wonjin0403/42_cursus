#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char arr[] = "123456";
	char *ans1 = strdup(arr);
	char *ans2 = ft_strdup(arr);
	printf("1 %s\n", ans1);
	printf("2 %s\n", ans2);
}
