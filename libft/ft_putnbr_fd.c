#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*ans;
	
	ans = itoa(n);
	write(fd, ans, ft_strlen(ans));
}
