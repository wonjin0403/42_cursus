#include "cub3d.h"

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
            ans = 16 * ans + 16 * (rgb[cnt] % 16);
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

int     take_color(char *line, char *identifier, t_input *input)
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
        input->f_rgb = cal_rgb_num(rgb);
    else if(*identifier == 'C')
        input->c_rgb = cal_rgb_num(rgb);
    return (0);
}

char    *make_empty_str(int len)
{
    char    *ans;
    int     cnt;

    cnt = 0;
    if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
        return (0);
    ans[len] = 0;
    while (cnt < len)
        ans[cnt++] = ' ';
    return (ans);
}

void    init_struct(t_input *input)
{
    input->width = -1;
    input->hight = -1;
    input->pos_x = -1;
    input->pos_y = -1;
    input->f_rgb = -1;
    input->c_rgb = -1;
    input->no = NULL;
    input->so = NULL;
    input->we = NULL;
    input->ea = NULL;
    input->sprite = NULL;
    input->map = NULL;
}