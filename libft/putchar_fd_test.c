#include <stdio.h>
#include <fcntl.h>

//void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

int	main(void)
{
	int	fd = open("hello.txt", O_WRONLY);
	ft_putendl_fd("hello word", fd);
	ft_putendl_fd("hihi", fd);
	//ft_putchar_fd('A', fp);
}	
