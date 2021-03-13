#include "cub3d.h"

int         check_map(t_data *img_data)
{
    t_queue *queue;
    char    **visited;
    int     cnt1;
    int     cnt2;
    int     pos[2];

    cnt1 = -1;
    visited = make_empty_map(img_data);
    while(img_data->map[++cnt1] && (cnt2 = -1))
        while(img_data->map[cnt1][++cnt2] && !(queue = NULL))
            if(img_data->map[cnt1][cnt2] != '1' && img_data->map[cnt1][cnt2] != ' '\
                && !visited[cnt1][cnt2])
            {
                queue = push(queue, cnt1, cnt2);
                if(!bfs(img_data->map, pos, visited, queue))
                {
                    make_free_map(visited);
                    perror("Error\nYou have wrong map!\n");
                    return (0);
                }
            }
    make_free_map(visited);
    return (1);
}

char        **make_empty_map(t_data *img_data)
{
    char    **visited;
    int     len;
    int     cnt;

    cnt = -1;
    len = 0;
    while (img_data->map && (img_data->map)[len])
        len++;
    if(!(visited = (char **)malloc(sizeof(char *) * (len + 1))))
        return (0);
    visited[len] = 0;
    while(++cnt < len)
    {
        if(!(visited[cnt] = ft_calloc(sizeof(char), ft_strlen(img_data->map[cnt]))))
        {
            make_free_map(visited);
            return (0);
        }
    }
    return (visited);
}

void        make_new_pos(int *pos, int *new_x, int *new_y, int cnt)
{
    const int     dx[4] = {1, 0, -1, 0};
    const int     dy[4] = {0, 1, 0, -1};

    *new_x = pos[0] + dx[cnt];
    *new_y = pos[1] + dy[cnt];
}

int         bfs(char **map, int *pos, char **visited, t_queue *queue)
{
    int     new_x;
    int     new_y;
    int     cnt;

    while(empty(queue))
    {
        queue = pop(queue, &pos[0], &pos[1]);
        cnt = -1;
        while(++cnt < 4)
        {
            make_new_pos(pos, &new_x, &new_y, cnt);
            if(new_x >= 0 && new_y >= 0 && map[new_x] && new_y < (int)ft_strlen(map[pos[0]]) &&\
                visited[new_x][new_y] != '1' && map[new_x][new_y] != '1')
            {
                if (map[new_x][new_y] == ' ')
                {
                    queue = remove_queue(queue);
                    return (0);
                }
                visited[new_x][new_y] = '1';
                queue = push(queue, new_x, new_y);
            }
        }
    }
    return (1);
}