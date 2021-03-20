#include "cub3d.h"

void    data_free(t_input *input)
{
    make_free(input);
    make_free_map(input->map);
    init_struct(input);
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

void    make_free(t_input *input)
{
    if(input->no != NULL)
    {
        free(input->no);
        input->no = NULL;
    } 
    if(input->so != NULL)
    {
        free(input->so);
        input->so = NULL;
    }
    if(input->we != NULL)
    {
        free(input->we);
        input->we = NULL;
    }
    if(input->ea != NULL)
    {
        free(input->ea);
        input->ea = NULL;
    }
    if(input->sprite != NULL)
    {
        free(input->sprite);
        input->sprite = NULL;
    }
}