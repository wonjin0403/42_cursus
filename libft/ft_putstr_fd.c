#include <unistd.h>

size_t	ft_strlen(char *s)
{
	size_t	len;
	
	len = 0;
	while (*(s++))
		len++;
	return (len);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
