#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "libft.h"
#include "get_next_line_bonus.h"

typedef struct  s_data
{
    int     x_size;
    int     y_size;
    int     pos_x;
    int     pos_y;
    int     f_rgb;
    int     c_rgb;
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *sprite;
    char    **map;
}           t_data;

int     cal_rgb_num(int *rgb)
{
    int     ans;
    int     cnt;

    cnt = -1;
    ans = 0;
    while (++cnt < 3)
    {
        while (rgb[cnt] != 0)
        {
            ans += 16 * (rgb[cnt] % 16);
            rgb[cnt] = rgb[cnt] / 16;
        }
    }
    return (ans);
}

int     ft_numlen(char *line)
{
    int     len;

    len = 0;
    while (*(line++))
        len++;
    return (len);
}

int     take_color(char *line, char *identifier, t_data *img_data)
{
    int cnt;
    int rgb[3];

    cnt = 0;
    while(++cnt < 3)
    {
        rgb[cnt] = ft_atoi(line);
        while(*line >= '0' && *line <= '9')
            line++;
        while (*line == ' ' || *line == ',' )
            line++;
    }
    if(*identifier == 'F')
        img_data->f_rgb = cal_rgb_num(rgb);
    else if(*identifier == 'C')
        img_data->c_rgb = cal_rgb_num(rgb);
    return (0);
}

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
        {
            //make_free(img_data);
            return (0);
        }
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
    //if (check)
    //    make_free(&img_data);
    return ((check) ? 1 : 0);
}

static void make_free(t_data *img_data)
{
    if(img_data->no != NULL)
    {
        free(img_data->no);
        img_data->no = NULL;
    } 
    if(img_data->so != NULL)
    {
        free(img_data->so);
        img_data->so = NULL;
    }
    if(img_data->we != NULL)
    {
        free(img_data->we);
        img_data->we = NULL;
    }
    if(img_data->ea != NULL)
    {
        free(img_data->ea);
        img_data->ea = NULL;
    }
    if(img_data->sprite != NULL)
    {
        free(img_data->sprite);
        img_data->sprite = NULL;
    }
}

static void make_free_map(t_data *img_data)
{
    if (img_data->map)
    {
        while (*(img_data->map))
            free(*((img_data->map)++));
    }
}

static int  map_width(char *line)
{
    int len;
    while (*line)
    {
        if (*line != ' ') 
            len++;
        line++;
    }
    return(len);
}

int    ft_mapcpy(char *line, char *new_map, t_data *img_data, int x)
{
    int cnt;

    cnt = 0;
    while (*line)
     {
        new_map[cnt++] = *line : 0;
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
        else if(*line != '0' && *line != '1' && *line != '2')
        {
                perror("Error\nYou have wrong letter in map!");
                return (0);
        }
        line++;
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
    while (img_data->map && (img_data->map)[len])
        len++;
    if(!(new_map = (char **)malloc(sizeof(char *) * (len + 1))))
        return (0);
    new_map[len] = 0;
    //line_len = map_width(line);
    line_len = ft_strlen(line);
    if(!(new_map[len - 1] = (char *)malloc(sizeof(char) * (line_len + 1))))
    {
        free(new_map);
        return (0);
    }
    if(ft_mapcpy(line, new_map[len - 1], img_data, len - 1))
        return (0);
    while (--len > 0)
        new_map[len - 1] = img_data->map[len - 1];
    free(img_data->map);
    img_data->map = new_map;
    return (1);
}

int         check_id(char *line, t_data *img_data)
{
    char    *identifier;
    char    *ori_line;
    size_t  cnt;
    int     re;

    cnt = 0;
    ori_line = line;
    while (*line && *line == ' ')
        line++;
    while (line[cnt] && line[cnt] >= 'A' && line[cnt] <= 'Z')
        cnt++;
    if (!(identifier = (char *)malloc(sizeof(char) * cnt + 1)))
        return (0);
    identifier[cnt] = 0;
    cnt = 0;
    while (*line && *line >= 'A' && *line <= 'Z')
        identifier[cnt++] = *(line++);
    while (*line && *line == ' ')
        line++;
    if(cnt == 2)
        re = two_id(line, identifier, img_data);
    else if(cnt == 1)
        re = one_id(line, identifier, img_data);
    else
        re = take_map(ori_line, img_data);
    free(identifier);
    return ((re == 0) ? 0 : 1);
}

static void init_struct(t_data *param)
{
    param->x_size = -1;
    param->y_size = -1;
    param->pos_x = -1;
    param->pos_y = -1;
    param->f_rgb = -1;
    param->c_rgb = -1;
    param->no = NULL;
    param->so = NULL;
    param->we = NULL;
    param->ea = NULL;
    param->sprite = NULL;
    param->map = NULL;
}

int         check_int_input(t_data *img_data)
{
    if(img_data->pos_x == -1|| img_data->pos_y == -1)
    {
        perror("Error\nYou have no starting point!");
        return (0);
    }
    else if(img_data->x_size == -1 || img_data->y_size == -1)
    {
        perror("Error\nYou don't have identifier 'R'");
        return (0);
    }
    else if(img_data->f_rgb == -1)
    {
        perror("Error\nYou don't have identifier 'F'");
        return (0);
    }
    else if(img_data->c_rgb == -1)
    {
        perror("Error\nYou don't have identifier 'C'");
        return (0);
    }
    else if(img_data->map == NULL) 
    {
        perror("Error\nYou don't have map");
        return (0);
    }
    return(1);
}

int        check_path_input(t_data *img_data)
{        
    if(img_data->no == NULL)
    {
        perror("Error\nYou don't have identifier 'NO'");
        return (0);
    }
    else if(img_data->so == NULL)
    {
        perror("Error\nYou don't have identifier 'SO'");
        return (0);
    }
    else if(img_data->we == NULL)
    {
        perror("Error\nYou don't have identifier 'WE'"); 
        return (0);
    }
    else if(img_data->ea == NULL)
    {
        perror("Error\nYou don't have identifier 'EA'");
        return (0);
    }
    else if(img_data->sprite == NULL)
    {
        perror("Error\nYou don't have identifier 'S'");
        return (0);
    }
    return (1);
}

//int         check_map(t_data &img_data)

int         get_data(char *path, t_data *img_data)
{
    int     fd;
    int     result;
    int     re;
    char    *line;

    init_struct(img_data);
    re = 1;
    result = 1;
    fd = open(path, O_RDWR);
    while (result == 1 && re == 1)
    {
        result = get_next_line(fd, &line);
        if (*line)
            re = check_id(line, img_data);
        if (!re)
        {
            make_free(img_data);
            make_free_map(img_data);
        }
        free(line);
    }
    if(re && (check_int_input(img_data) == 0 || check_path_input(img_data) == 0))
    {
        make_free(img_data);
        make_free_map(img_data);
    }
    return ((result && re) ? 1 : 0);
}

int     main(int argc, char *argv[])
{
    t_data  img_data;
    printf("%d\n", get_data(argv[argc - 1], &img_data));
}