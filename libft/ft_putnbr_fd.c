#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	ans[11];
	int		len;
	int		cnt;
	int		num;

	num = n;
	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	if (n < 0)
	{
		len += 1;
		ans[0] = '-';
	}
	cnt = len - 1;
	while (n != 0)
	{
		ans[cnt--] = (n % 10 < 0 ? -(n % 10) : n % 10) + '0';
	   	n/= 10;
	}
	write(fd, ans, len);
}
