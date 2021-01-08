#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char arr[5] = "abcd";
	arr[4] = 0;
	char buff[10] = "1234567890";
	int	fd = open("hello.txt", O_RDWR);
	write(fd, arr, 5);
	close(fd);
	fd = open("hello.txt", O_RDWR);
	int len = read(fd, buff, 5);
	printf("buff:%s\n", buff);
	printf("%d\n", buff[4]);
	close(fd);
}
