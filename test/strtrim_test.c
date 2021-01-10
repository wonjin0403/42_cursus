#include <stdio.h>
#include <string.h>

char *ft_strtrim(char const *s1, char const *set);

int	main()
{
	char str[] = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t";
	char str1[1];
	//str[10] = '\n';
	//str[11] = 'p';
	//str[12] = 'l';
	char *s2 = "Hello \t  Please\n Trim me !";
	printf("%s\n", (ft_strtrim(str, " \n\t")));
	printf("%d\n", *s2);
	printf("%lu\n", strlen(s2));
}
