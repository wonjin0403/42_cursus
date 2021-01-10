#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include <limits.h>

int	main(void)
{
	int	fd = open("hello.txt", O_WRONLY);
	ft_putendl_fd("hello word", fd);
	ft_putendl_fd("hihi", fd);
	ft_putnbr_fd(INT_MAX, fd);
	ft_putnbr_fd(INT_MIN, fd);
	ft_putnbr_fd(-10, fd);
	//ft_putchar_fd('A', fp);
}	
