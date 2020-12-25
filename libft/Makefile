CC = gcc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_memset.c\
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c
		

OBJS = $(FILES:.c=.o)

NAME = libft.a

all : $(NAME)

so:
		$(CC) -fPIC $(CFLAGS) $(FILEX)
			gcc -shared -o libft.so $(OBJ)

%.o : %.c
	$(CC) -c $(FILES) $(CFLAGS)

$(NAME) : $(OBJS)
	ar rcs $@ $(OBJS)
clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

.PHONY  : all clean fclean
