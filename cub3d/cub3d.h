#ifndef cub3d_h
# define cub3d_h
# define PI 3.14159265

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>

#include "libft.h"
#include "get_next_line_bonus.h"

typedef struct  s_queue{
    struct s_queue  *next;
    int             x;
    int             y;
}               t_queue;

typedef struct  s_ray_param
{
    double          rayDirX;
    double          rayDirY;
    double          sideDistX;
    double          sideDistY;
    double          deltaDistX;
    double          deltaDistY;
    double          perpWallDist;
    int             stepX;
    int             stepY;
    int             side;
    int             lineHeight;
}               t_ray_param;

typedef struct  s_mlx_data
{
    void        *img;
    char        *addr;
    int         x;
    int         y;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_mlx_data;

typedef struct  s_texture{
    t_mlx_data  north;
    t_mlx_data  south;
    t_mlx_data  east;
    t_mlx_data  west;
    t_mlx_data  sprite;
}               t_texture;

typedef struct  s_input
{
    int         save_bmp;
    int         width; //x_size;
    int         hight; //y_size;
    double      pos_x;
    double      pos_y;
    double      dirX;
    double      dirY;
    double      planeX;
    double      planeY;
    int         f_rgb;
    int         c_rgb;
    char        *no;
    char        *so;
    char        *we;
    char        *ea;
    char        *sprite;
    char        **map;
    //
    char        *mlx;
    char        *win;
    int         moveSpeed;
}               t_input;

typedef struct  s_data
{
    t_input     input;
    t_mlx_data  img_data;
    t_texture   texture;
}               t_data;

t_queue         *push(t_queue *queue, int x, int y);
t_queue         *pop(t_queue *queue, int *x, int *y);
t_queue         *remove_queue(t_queue *queue);
size_t          empty(t_queue *queue);

//free.c
void            data_free(t_input *input);
void            make_free_map(char **map);
void            make_free(t_input *input);

//bfs.c
int             check_map(t_input *input);
char            **make_empty_map(t_input *input);
void            make_new_pos(int *pos, int *new_x, int *new_y, int cnt);
int             bfs(char **map, int *pos, char **visited, t_queue *queue);

//parsing_utils.c
int             cal_rgb_num(int *rgb);
int             ft_numlen(char *line);
int             take_color(char *line, char *identifier, t_input *input);
char            *make_empty_str(int len);
void            init_struct(t_input *input);

//take_input.c
char            *take_path(char *line);
int             one_id(char *line, char *identifier, t_input *input);
int             two_id(char *line, char *identifier, t_input *input);
int             ft_mapcpy(char *line, char *new_map, t_input *img_data, int x);
int             take_map(char *line, t_input *input);
//static void     set_param(t_input *input, int x, int y, char dir);

//parsing.c
int             check_id(char *line, t_input *input);
int             check_int_input(t_input *input);
int             check_path_input(t_input *input);
int             get_data(char *path, t_input *input);

#endif