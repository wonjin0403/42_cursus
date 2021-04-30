#include "cub3d.h"

char    *take_path(char *line)
{
    int     len;
    char    *path;

    len = 0;
    while (line[len] && line[len] != ' ')
        len++;
    if(!(path = (char *)malloc(sizeof(char) * (len + 1))))
        return (0);
    ft_strlcpy(path, line, len + 1);
    return (path);
}

int     one_id(char *line, char *identifier, t_input *input)
{
    int     cnt;
    int     my_width;
    int     my_hight;

    cnt = -1;
    if(*identifier == 'R')
    {
        input->width = ft_atoi(line);
        while (*line >= '0' && *line <= '9')
            line++;
        while(*line == ' ')
            line++;
        input->hight = ft_atoi(line);
        mlx_get_screen_size(input->mlx, &my_width, &my_hight);
        if(input->width > my_width)
            input->width = my_width;
        else if(input->hight > my_hight)
            input->hight = my_hight;
    }
    else if(*identifier == 'S')
    {
        cnt = ft_numlen(line);
        if (!(input->sprite = take_path(line)))
            return (0);
    }
    else if(*identifier == 'F' || *identifier == 'C')
        take_color(line, identifier, input);
    return (1);
}

int     two_id(char *line, char *identifier, t_input *input)
{
    int     check;

    check = 1;
    if(!ft_strncmp(identifier, "NO", 2))
    {
        if (!(input->no = take_path(line)))
            check = 1;
    }
    else if(!ft_strncmp(identifier, "SO", 2))
    {
        if (!(input->so = take_path(line)))
            check = 1;
    }
    else if(!ft_strncmp(identifier, "WE", 2))
    {
        if (!(input->we = take_path(line)))
            check = 1;
    }
    else if(!ft_strncmp(identifier, "EA", 2))
    {
        if (!(input->ea = take_path(line)))
            check = 1;
    }
    return ((check) ? 1 : 0);
}

static void     set_param(t_input *input, int x, int y, char dir)
{
    input->pos_x = (double)x;
    input->pos_y = (double)y;
    if(dir == 'N')
    {
        input->dirX = 1;
        input->dirY = 0;
    }
    else if(dir == 'S')
    {
        input->dirX = -1;
        input->dirY = 0;
    }
    else if(dir == 'E')
    {
        input->dirX = 0;
        input->dirY = 1;
    }
    else if(dir == 'W')
    {
        input->dirX = 0;
        input->dirY = -1;
    }
    input->planeX = -1 * input->dirY; //0.66//크기 각도 60도 맞춰서 조절 추가
    input->planeY = -1 * input->dirX; //0.66
}

int    ft_mapcpy(char *line, char *new_map, t_input *input, int x)
{
    int cnt;
    int len;

    len = ft_strlen(line) + 2;
    cnt = 1;
    new_map[0] = ' ';
    new_map[len - 1] = ' ';
    new_map[len] = 0;
    while (*line)
    {
        if((*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W') &&\
            input->pos_x != -1)
        {
            printf("Error\nTwo starting point in map!");
            return (0);
        }
        else if((*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W'))
        {
            set_param(input, x, cnt, *line);
            *line = '0';
        }    
        else if(*line != '0' && *line != '1' && *line != '2' && *line != ' ')
        {
                printf("Error\nYou have wrong letter in map!");
                return (0);
        }
        new_map[cnt++] = *(line++);
    }
    return (1);
}

int         take_map(char *line, t_input *input)
{
    int     len;
    int     line_len;
    char    **new_map;

    len = (input->map == NULL) ? 3 : 1;
    while (input->map && (input->map)[len - 1])
        len++;
    if(!(new_map = (char **)malloc(sizeof(char *) * (len + 1))))
        return (0);
    line_len = ft_strlen(line);
    if(!(new_map[len - 2] = (char *)malloc(sizeof(char) * (line_len + 2 + 1))))
    {
        free(new_map);
        return (0);
    }
    if(!ft_mapcpy(line, new_map[len - 2], input, len - 1 - 1))
        return (0);
    (input->map == NULL) ? new_map[0] = make_empty_str(line_len + 2) : 0;
    new_map[len - 1] = make_empty_str(line_len + 2);
    new_map[len] = 0;
    while (input-> map && --len > 1)
        new_map[len - 2] = input->map[len - 2];
    free(input->map);
    input->map = new_map;
    return (1);
}