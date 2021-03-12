#include "cub3d.h"

void    img_data_free(t_data *img_data)
{
    make_free(img_data);
    make_free_map(img_data->map);
    init_struct(img_data);
}

void    make_free_map(char **map)
{
    char    **start;
    
    start = map;
    if (map)
    {
        while (*map)
            free(*(map++));
    }
    free(start);
}

void    make_free(t_data *img_data)
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