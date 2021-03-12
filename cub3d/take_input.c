#include "cub3d.h"

char    *take_path(char *line)
{
    int     len;
    char    *path;

    len = 0;
    while (line[len] != ' ')
        len++;
    if(!(path = (char *)malloc(sizeof(char) * (len + 1))))
        return (0);
    ft_strlcpy(path, line, len);
    return (path);
}

int     one_id(char *line, char *identifier, t_data *img_data)
{
    int     cnt;

    cnt = -1;
    if(*identifier == 'R')
    {
        img_data->x_size = ft_atoi(line);
        while (*line == ' ' || (*line >= '0' && *line <= '9'))
            line++;
        img_data->y_size = ft_atoi(line);
    }
    else if(*identifier == 'S')
    {
        cnt = ft_numlen(line);
        if (!(img_data->sprite = take_path(line)))
            return (0);
    }
    else if(*identifier == 'F' || *identifier == 'C')
        take_color(line, identifier, img_data);
    return (1);
}

int     two_id(char *line, char *identifier, t_data *img_data)
{
    int     check;

    check = 1;
    if(!ft_strncmp(identifier, "NO", 2))
    {
        if (!(img_data->no = take_path(line)))
            check = 1;
    }
    else if(!ft_strncmp(identifier, "SO", 2))
    {
        if (!(img_data->so = take_path(line)))
            check = 1;
    }
    else if(!ft_strncmp(identifier, "WE", 2))
    {
        if (!(img_data->we = take_path(line)))
            check = 1;
    }
    else if(!ft_strncmp(identifier, "EA", 2))
    {
        if (!(img_data->ea = take_path(line)))
            check = 1;
    }
    return ((check) ? 1 : 0);
}

int    ft_mapcpy(char *line, char *new_map, t_data *img_data, int x)
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
            img_data->pos_x != -1)
        {
            perror("Error\nTwo starting point in map!");
            return (0);
        }
        else if((*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W'))
        {
                img_data->pos_x = x;
                img_data->pos_y = cnt;
        }
        else if(*line != '0' && *line != '1' && *line != '2' && *line != ' ')
        {
                perror("Error\nYou have wrong letter in map!");
                return (0);
        }
        new_map[cnt++] = *(line++);
    }
    return (1);
}

int         take_map(char *line, t_data *img_data)
{
    int     len;
    int     line_len;
    int     cnt;
    char    **new_map;

    len = 1;
    cnt = 0;
    if (img_data->map == NULL)
        len += 2;
    while (img_data->map && (img_data->map)[len - 1])
        len++;
    if(!(new_map = (char **)malloc(sizeof(char *) * (len + 1))))
        return (0);
    line_len = ft_strlen(line);
    if(!(new_map[len - 2] = (char *)malloc(sizeof(char) * (line_len + 2 + 1))))
    {
        free(new_map);
        return (0);
    }
    if(!ft_mapcpy(line, new_map[len - 2], img_data, len - 1 - 1))
        return (0);
    if (img_data->map == NULL)
        new_map[0] = make_empty_str(line_len + 2);
    new_map[len - 1] = make_empty_str(line_len + 2);
    new_map[len] = 0;
    while (img_data-> map && --len > 1)
        new_map[len - 2] = img_data->map[len - 2];
    free(img_data->map);
    img_data->map = new_map;
    return (1);
}