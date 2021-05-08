#include "cub3d.h"

int    change_dir(int keycode, t_data *data)
{
    double  angle;
    double  old_dirX;
    double  old_planeX;
    double  new_x;
    double  new_y;
    int     sign;
    double  old_posX;

    mlx_destroy_image(data->input.mlx, data->img_data.img);
    data->img_data.img = mlx_new_image(data->input.mlx, 1920, 1080);
    data->img_data.addr = mlx_get_data_addr(data->img_data.img, &(data->img_data.bits_per_pixel), &(data->img_data.line_length), &(data->img_data.endian));
    init_img(data);
    printf("keycode %d\n", keycode);
    if (keycode == 0 || keycode == 2)
    {
        angle = (keycode == 0) ? 1 * 180 / (PI * 300) : -1 * 180 / (PI * 300);    
        old_dirX = data->input.dirX;
        old_planeX = data->input.planeX;
        data->input.dirX = cos(angle) * data->input.dirX - sin(angle) * data->input.dirY;
        data->input.dirY = sin(angle) * old_dirX + cos(angle) * data->input.dirY;

        data->input.planeX = cos(angle) * data->input.planeX - sin(angle) * data->input.planeY;
        data->input.planeY = sin(angle) * old_planeX + cos(angle) * data->input.planeY;
    }
    else if (keycode == 13 || keycode == 1)
    {
        sign = (keycode == 13) ? 1 : -1;
        new_x = data->input.pos_x + data->input.dirX * data->input.moveSpeed * sign;
        new_y = data->input.pos_y + data->input.dirY * data->input.moveSpeed * sign;
        printf("posX %f, posY %f, moveSpeed %f, sign %d\n", data->input.pos_x, data->input.pos_y, data->input.moveSpeed, sign);
        printf("dirX %f, dirY %f\n", data->input.dirX, data->input.dirY);
        old_posX = data->input.pos_x;
        printf("newx: %f, new_y: %f, worldMap[new_x][new_y]: %c\n", new_x, new_y, data->input.map[(int)new_x][(int)new_y]);
        if (new_x > 0 && data->input.map[(int)new_x] &&  new_y > 0 && new_y < ft_strlen(data->input.map[(int)new_x]))
        {
            if (data->input.map[(int)new_x][(int)data->input.pos_y] != '1')
                data->input.pos_x = new_x;
            if (data->input.map[(int)old_posX][(int)new_y] != '1')
                data->input.pos_y = new_y;
        }
    }
    //space 점프 shift 달리기
    else if (keycode == 53)
    {
        //mlx_destroy_image(param->mlx, param->img);
        //mlx_destroy_window(param->mlx, param->win);
        exit(1);
    }
    return (1);
}

int    make_text_info(void *mlx, char *path, t_mlx_data *info)
{
    info->img = mlx_xpm_file_to_image(mlx, path,\
                &(info->x), &(info->y));
    printf("path :%s\n", path);
    if(info->img == NULL)
        return (0);
    info->addr = mlx_get_data_addr(info->img,\
    &(info->bits_per_pixel), &(info->line_length), &(info->endian));
    return (1);
}

int    take_texture(t_input *input, t_texture *texture)
{
    int result;

    result = 1;
    printf("input->no %s\n", input->no);
    result *= make_text_info(input->mlx, input->no, &texture->north);
    result *= make_text_info(input->mlx, input->so, &texture->south);
    result *= make_text_info(input->mlx, input->ea, &texture->east);
    result *= make_text_info(input->mlx, input->we, &texture->west);
    result *= make_text_info(input->mlx, input->sprite, &texture->sprite);
    if(result == 0)
        return (0);
    return (1);
}

t_mlx_data     choose_text(int side, t_ray_param *param, t_texture *texture, int x, int y)
{
    if(side == 0 && param->rayDirX > 0)
        return (texture->north);
    else if(side == 0 && param->rayDirX < 0)
        return (texture->south);
    else if(side == 0 && param->rayDirX == 0 && param->rayDirY > 0)
        return (texture->west);
    else if(side == 0 && param->rayDirX == 0 && param->rayDirY < 0)
        return (texture->east);
    else if(side == 1 && param->rayDirY > 0)
        return (texture->east);
    else if(side == 1 && param->rayDirY < 0)
        return (texture->west);
    else if(side == 1 && param->rayDirY == 0 && param->rayDirX > 0)
        return (texture->north);
    else if(side == 1 && param->rayDirY == 0 && param->rayDirX < 0)
        return (texture->south);
    else
    {
        printf("side %d, param->rayDirx %f, param->rayDirY %f\n", side, param->rayDirX, param->rayDirY);
        printf("stepx %d, stepY %d, deltadistx %f deltadisty %f\n", param->stepX, param->stepY, param->deltaDistX, param->deltaDistY);
        printf("x %d y %d\n", x, y);
        printf("what the\n");
        return (texture->west);
    }
    //반환값
}

void	verLine(t_mlx_data *img_data, t_mlx_data *texture, int side, int x, int y1, int y2, int texX)
{
    //width -> x, hight -> y
	int		y;
	char	*empty_img;
    char    *texture_img;
	double  step;

	y = y1;
    step = (double)(texture->y) / (double)(y2 - y1);
    printf("step %f diff %d\n", step, y2 - y1);
    //printf("step %f\n", step);
	while(y < y2)
	{
		empty_img = img_data->addr + (y * img_data->line_length + x * (img_data->bits_per_pixel / 8));
		texture_img = texture->addr + ((int)((y - y1) * step) * texture->line_length + texX * (texture->bits_per_pixel / 8));
        if(side == 1)
            *(unsigned int *)empty_img = *(unsigned int *)texture_img; /// 2;
        else
            *(unsigned int *)empty_img = *(unsigned int *)texture_img;
		y++;
	}
}

void	putcolor(t_data *data, int x, int y1, int y2, int color)
{
	int		y;
	char	*dst;
	
	y = y1;
	while (y < y2)
	{
		dst = data->img_data.addr + (y * data->img_data.line_length + x * (data->img_data.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		y++;
	}
}

void    init_param(t_data *data, t_ray_param *param, int x)
{
        double camera_plane;

        camera_plane = 2 * x / (double)(data->input.width) - 1;
        param->rayDirX = data->input.dirX + data->input.planeX * camera_plane;
        param->rayDirY = data->input.dirY + data->input.planeY * camera_plane;
        if (param->rayDirX == 0 && param->rayDirY == 0)
        {
            param->deltaDistX = 1;
            param->deltaDistY = 1;
        }
        else
        {
            param->deltaDistX = (param->rayDirX == 0) ? 0 : fabs(1 / param->rayDirX);
            param->deltaDistY = (param->rayDirY == 0) ? 0 : fabs(1 / param->rayDirY);
        }
        param->stepX = (param->rayDirX < 0) ? -1 : 1;
        param->stepY = (param->rayDirY < 0) ? -1 : 1;
        param->sideDistX = fabs(data->input.pos_x - ((int)(data->input.pos_x) + ((param->rayDirX < 0) ? 0 : 1))) * param->deltaDistX;
        param->sideDistY = fabs(data->input.pos_y - ((int)(data->input.pos_y) + ((param->rayDirY < 0) ? 0 : 1))) * param->deltaDistY;
}

double  ft_cal_dist(int mapX, int mapY, t_data *data, t_ray_param *param)
{
    double perpWallDist;

    //printf("mapx %d, mapy %d, posx %f, posy %f, stepx %d, stepy %d, rayDirx %f, rayDirY %f\n", mapX, mapY,
    //    data->input.pos_x, data->input.pos_y, param->stepX, param->stepY, param->rayDirX, param->rayDirY);
    if(param->side == 0)
        perpWallDist = (mapX - data->input.pos_x +\
                        (1 - param->stepX) / 2) / param->rayDirX;
	else
        perpWallDist = (mapY - data->input.pos_y +\
                        (1 - param->stepY) / 2) / param->rayDirY;
    return (perpWallDist);
}

void    ft_start_end(t_data *data, int lineHeight, int *drawStart, int *drawEnd)
{
    int h;

    h = data->input.height;
    //점프할 경우 여기서 조정
    *drawStart = -lineHeight / 2 + h / 2;
    if (*drawStart < 0)
        *drawStart = 0;
    *drawEnd = lineHeight / 2 + h / 2;
    if (*drawEnd >= h)
        *drawEnd = h - 1;
}

double     ft_dda(t_data *data, t_ray_param *param, int *x, int *y)
{
    int     mapX;
    int     mapY;
    
    mapX = (int)(data->input.pos_x);
    mapY = (int)(data->input.pos_y);
    while(data->input.map[mapX][mapY] != '1')
    {
        if(param->sideDistX < param->sideDistY)
        {
            param->sideDistX += param->deltaDistX;
            mapX += param->stepX;
            param->side = 0;
        }
        else
        {
            param->sideDistY += param->deltaDistY;
            mapY += param->stepY;
            param->side = 1;
        }
        if(data->input.map[mapX][mapY] == '2')
            add_sprite(data, mapX, mapY);
    }
    *x = mapX;
    *y = mapY;
    param->perpWallDist = ft_cal_dist(mapX, mapY, data, param);
    return ((int)(data->input.height / param->perpWallDist));
}

double distance(double x1, double y1, double x2, double y2)
{
    return (pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int     raycaster(t_data *data, double *dist_arr)
{
	int         x;
    int         texX;
    int         drawStart;
    int         drawEnd;
    double      wallX;
    t_ray_param param;

    x = -1;
    //init_img(data);
    while(++x < data->input.width)
    {
        int X, Y;
        init_param(data, &param, x);
        ft_start_end(data, ft_dda(data, &param, &X, &Y), &drawStart, &drawEnd);
        if(param.side == 0)
            wallX = data->input.pos_y + param.perpWallDist * param.rayDirY;
        else
            wallX = data->input.pos_x + param.perpWallDist * param.rayDirX;
        wallX -= floor(wallX);
        //printf("wallX %f\n", wallX);
        t_mlx_data text = choose_text(param.side, &param, &(data->texture), X, Y);
        int texWidth = text.x;
        texX = (int)(wallX * (double)(texWidth));
        if(param.side == 0 && param.rayDirX > 0)
            texX = texWidth - texX - 1;
        else if(param.side == 1 && param.rayDirY < 0)
            texX = texWidth - texX - 1;
        //printf("texX %d\n", texX);
        //putcolor(img, x, drawStart, drawEnd, color);
        //putcolor(data, x, 0, data->input.hight / 2, data->input.f_rgb);
        //putcolor(data, x, data->input.hight / 2, data->input.hight, data->input.c_rgb);
        verLine(&(data->img_data), &text, param.side, data->input.width - x, drawStart, drawEnd, texX);
        dist_arr[x] = distance(data->input.pos_x, data->input.pos_y, (double)X, (double)Y);
    }
    //mlx_put_image_to_window(data->input.mlx, data->input.win, data->img_data.img, 0, 0);
    return (1);
}

int decide_save_or_print(t_data *data)
{
    int re;
    double dist_arr[data->input.width];

    re = raycaster(data, dist_arr);
    draw_sprite(data, dist_arr);
    if(!(data->input.save_bmp))
        mlx_put_image_to_window(data->input.mlx, data->input.win, data->img_data.img, 0, 0);
    return (re);
}

void     init_data(t_data *data)
{
    data->input.mlx = mlx_init();
    data->img_data.img = mlx_new_image(data->input.mlx,\
            data->input.width, data->input.height);
    if(data->input.save_bmp)
        data->input.win = NULL;
    else
        data->input.win = mlx_new_window(data->input.mlx,\
            data->input.width, data->input.height, "Welcome to cub3d");
    data->img_data.addr = mlx_get_data_addr(data->img_data.img,\
            &(data->img_data.bits_per_pixel), &(data->img_data.line_length), &(data->img_data.endian));
    data->input.moveSpeed = 1 / 2.0;
    printf("bitperpixel %d\n", data->img_data.bits_per_pixel);
}

int check_arg(int argc, char **argv)
{
    int     len;

    len = 0;
    if(argc == 1)
    {
        printf("No argument\n");
        return (0);
    }
    else if(argc > 3)
    {
        printf("ERROR\n : Too many argument!");
        return (0);
    }
    else if(argc > 1)
    {
        len = ft_strlen(argv[1]);
        if(ft_strncmp(&argv[1][len - 4], ".cub", 4))
        {
            printf("Error\nYour file extension is not correct\n");
            return (0);
        }
    }
    return (1);
}

void init_img(t_data *data)
{
    int x;

    x = -1;
    while(++x < data->input.width)
    {
        putcolor(data, x, 0, data->input.height / 2,\
                        data->input.f_rgb);
        putcolor(data, x, data->input.height / 2,\
                        data->input.height, data->input.c_rgb);
    }
}

int main(int argc, char **argv)
{
    t_data      data;

    if(!check_arg(argc, argv))
        return (0);
    data.input.save_bmp = (argc == 3 &&\
            !ft_strncmp(argv[2], "--save", 6)) ? 1 : 0;
    get_data(argv[1], &data.input);
    printf("after %s\n", data.input.no);
    init_data(&data);
    if(!take_texture(&data.input, &data.texture))
    {
        printf("ERROR\nYou have wrong texture path\n");
        return (0);
    }
    printf("w %d, h %d\n", data.input.width, data.input.height);
    printf("posx:%f, posy: %f\n", data.input.pos_x, data.input.pos_y);
    printf("f_rgb %d, c_rgb %d\n", data.input.f_rgb, data.input.c_rgb);
    printf("no %s\n", data.input.no);
    printf("so %s\n", data.input.so);
    printf("we %s\n", data.input.we);
    printf("ea %s\n", data.input.ea);
    printf("sprite %s\n", data.input.sprite);
    printf("map\n");        
    int i = 0;
    while(data.input.map && data.input.map[i] != NULL)
    {
        printf("%s\n", data.input.map[i]);
        i++;
    }
    init_img(&data);
    if(data.input.save_bmp)
        make_bmp(&data);
    else
    {
        mlx_loop_hook(data.input.mlx, decide_save_or_print, &data);
        mlx_hook(data.input.win, 2, 1L<<0, change_dir, &data);

        int x = 0;
        int y = 0;
        //mlx_mouse_get_pos(img_data.win, &x, &y);
        printf("x: %d, y: %d\n", x, y);
        //mlx_key_hook(img_data.win, change_dir, &img_data);
        mlx_loop(data.input.mlx);
    }
    return (0);
}
