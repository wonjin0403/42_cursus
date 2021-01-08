#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/*
int main(void)
{
	char arr[10];

	int num = read(0, arr, 10);
	printf("%d\n", num);
	printf("%s\n", arr);
}*/
/*int	main(void)
{
	int fd1 = open("hello.txt", O_RDWR);
	//int fd2 = open("hi.txt", O_RDWR);
	char	*arr = (char *)malloc(10);
	//printf("add %p\n", arr);
	char	ans[10];
//	printf("f1 %d\n", fd1);
	//printf("f2 %d\n", fd2);
	int num = read(fd1, arr, 10);
	//int num2 = read(fd2, ans, 10);
	free(arr);
	printf("add2 %p\n", arr);
	//printf("%d\n", num);
	printf("first:%s\n", arr);
	read(fd1, ans, 10);
	printf("second:%s\n", ans);
	//printf("f2 %d\n", num2);
	//printf("f2 %s\n", ans);
	
	//close(fd1);
	//close(fd2);
}
*/
int main(void)
{
	int fd1 = open("hello.txt", O_RDWR);
	char    arr[10];
	char    ans[10];

	int len = (int)read(fd1, arr, 10);
	arr[len] = 0;
	printf("str:%s", arr);
	//arr[9] = '\0';
	//printf("first:%s\n", arr);
	//read(fd1, ans, 10);
	//ans[9] = '\0';
	//printf("second:%s\n", ans);

	close(fd1);
//	close(fd2);																//
}
