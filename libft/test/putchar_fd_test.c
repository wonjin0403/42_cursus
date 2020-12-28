#include <stdio.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd);

int	main(void)
{
	int	fp = open("hello.txt", O_WRONLY);
	ft_putchar_fd('A', fp);
}	
