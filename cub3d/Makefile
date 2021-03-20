CC = gcc
FLAGS = -Wall -Wextra -Werror -L. -lmlx -framework OpenGL -framework AppKit -lz  #-lmlx -framework OpenGL -framework AppKit -lz
INC = -I ./libft/ -I ./gnl/ -I ./minilibx_mms_20200219 
#./minilibx_opengl_20191021/

SRCS = raycaster1.c\
		parsing.c\
		parsing_utils.c\
		take_input.c\
		free.c\
		bfs.c\
		queue.c\
		gnl/get_next_line_bonus.c\
		gnl/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

NAME = cub3d

all : $(NAME)

# $(NAME) : $(SRCS)
# 	$(MAKE) -C ./libft all
# 	$(MAKE) -C ./minilibx_opengl_20191021 all
# 	$(CC) -g3 -fsanitize=address $(FLAGS) $(INC) $(SRCS) ./libft/libft.a ./minilibx_opengl_20191021/libmlx.a

$(NAME) : $(SRCS)
	$(MAKE) -C ./libft all
	$(MAKE) -C ./minilibx_mms_20200219 all
	cp ./minilibx_mms_20200219/libmlx.dylib .
	$(CC) $(FLAGS) $(INC) -o $(NAME) $(SRCS) ./libft/libft.a 
	#./libmlx.dylib

clean :
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./minilibx_mms_20200219 clean
	rm -rf libmlx.dylib

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
