#ifndef cub3d_h
#define cub3d_h

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "get_next_line_bonus.h"

typedef struct  s_queue{
    struct s_queue  *next;
    int             x;
    int             y;
}               t_queue;

typedef struct  s_data
{
    int     x_size;
    int     y_size;
    double  pos_x;
    double  pos_y;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    int     f_rgb;
    int     c_rgb;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *sprite;
    char    **map;
}               t_data;

t_queue         *push(t_queue *queue, int x, int y);
t_queue         *pop(t_queue *queue, int *x, int *y);
t_queue         *remove_queue(t_queue *queue);
size_t          empty(t_queue *queue);

//free.c
void            img_data_free(t_data *img_data);
void            make_free_map(char **map);
void            make_free(t_data *img_data);

//bfs.c
int             check_map(t_data *img_data);
char            **make_empty_map(t_data *img_data);
void            make_new_pos(int *pos, int *new_x, int *new_y, int cnt);
int             bfs(char **map, int *pos, char **visited, t_queue *queue);

//parsing_utils.c
int             cal_rgb_num(int *rgb);
int             ft_numlen(char *line);
int             take_color(char *line, char *identifier, t_data *img_data);
char            *make_empty_str(int len);
void            init_struct(t_data *param);

//take_input.c
char            *take_path(char *line);
int             one_id(char *line, char *identifier, t_data *img_data);
int             two_id(char *line, char *identifier, t_data *img_data);
int             ft_mapcpy(char *line, char *new_map, t_data *img_data, int x);
int             take_map(char *line, t_data *img_data);

//parsing.c
int             check_id(char *line, t_data *img_data);
int             check_int_input(t_data *img_data);
int             check_path_input(t_data *img_data);
int             get_data(char *path, t_data *img_data);

#endif