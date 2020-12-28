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
	size_t len;
	char	*start;

	start = s;
	len = ft_strlen(s);
	while (*s)
		s++;
	s = '\n';
	write(fd, s, len + 1);
}
