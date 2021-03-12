#include "cub3d.h"

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
            img_data_free(img_data);
        free(line);
    }
    close(fd);
    if((re && (check_int_input(img_data) == 0 || check_path_input(img_data) == 0)) || !check_map(img_data))
    {
        re = 0;
        img_data_free(img_data);
    }
    return ((result && re) ? 1 : 0);
}

int     main(int argc, char *argv[])
{
    t_data  img_data;
    printf("%d\n", get_data(argv[argc - 1], &img_data));
    printf("x %d, y %d\n", img_data.x_size, img_data.y_size);
    printf("posx:%d, posy: %d\n", img_data.pos_x, img_data.pos_y);
    printf("f_rgb %d, c_rgb %d\n", img_data.f_rgb, img_data.c_rgb);
    printf("no %s\n", img_data.no);
    printf("so %s\n", img_data.so);
    printf("we %s\n", img_data.we);
    printf("ea %s\n", img_data.ea);
    printf("sprite %s\n", img_data.sprite);
    printf("map\n");        
    int i = 0;
    while(img_data.map && img_data.map[i] != NULL)
    {
        printf("%s\n", img_data.map[i]);
        i++;
    }
}
