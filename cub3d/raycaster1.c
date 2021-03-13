#include "cub3d.h"

/*typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     sw;
    int     sy;
    int     moveSpeed;
    double  posX;
    double  posY;  //x and y start position
    double  dirX;
    double  dirY; //initial direction vector
    double  planeX;
    double  planeY;
}               t_data;

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
*/
void	verLine(t_data *info, int x, int y1, int y2, int color)
{
	int		y;
	char	*dst;
	
	y = y1;
	while (y < y2)
	{
		dst = info->addr + (y * info->line_length + x * (info->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
		y++;
	}
}

int    change_dir(int keycode, t_data *param)
{
    double  angle;
    double  old_dirX;
    double  old_planeX;
    double  new_x;
    double  new_y;
    int     sign;
    double  old_posX;

    mlx_destroy_image(param->mlx, param->img);
    param->img = mlx_new_image(param->mlx, 1920, 1080);
    param->addr = mlx_get_data_addr(param->img, &(param->bits_per_pixel), &(param->line_length), &(param->endian));
    printf("keycode %d\n", keycode);
    if (keycode == 0 || keycode == 2)
    {
        angle = (keycode == 0) ? -1 * 180 / PI : 1 * 180 / PI;
        
        old_dirX = param->dirX;
        old_planeX = param->planeX;
        param->dirX = cos(angle) * param->dirX - sin(angle) * param->dirY;
        param->dirY = sin(angle) * old_dirX + cos(angle) * param->dirY;

        param->planeX = cos(angle) * param->planeX - sin(angle) * param->planeY;
        param->planeY = sin(angle) * old_planeX + cos(angle) * param->planeY;
    }
    else if (keycode == 13 || keycode == 1)
    {
        sign = (keycode == 13) ? 1 : -1;
    
        new_x = param->pos_x + param->dirX * param->moveSpeed * sign;
        new_y = param->pos_y + param->dirY * param->moveSpeed * sign;
        printf("posX %f, posY %f, moveSpeed %d, sign %d\n", param->pos_x, param->pos_y, param->moveSpeed, sign);
        printf("dirX %f, dirY %f\n", param->dirX, param->dirY);
        old_posX = param->pos_x;
        printf("newx: %f, new_y: %f, worldMap[new_x][new_y]: %c\n", new_x, new_y, param->map[(int)new_x][(int)new_y]);
        if (new_x > 0 && param->map[(int)new_x] &&  new_y > 0 && new_y < ft_strlen(param->map[(int)new_x]))
        {
            if (param->map[(int)new_x][(int)param->pos_y] == '0')
                param->pos_x = new_x;
            if (param->map[(int)old_posX][(int)new_y] == '0')
                param->pos_y = new_y;
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

int     raycaster(t_data *img)
{
    int w;
    int h;
    int mapX;
    int mapY;
    double cameraX;
    double rayDirX;
    double rayDirY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    double perpWallDist;
    int stepX;
    int stepY;
    int hit = 0; //was there a wall hit?
    int side; //was a NS or a EW wall hit?
    int lineHeight;
    //int done = 0;
	int x;

    w = img->x_size;
    h = img->y_size;
    x = -1;
    while (++x < w)
    {
		hit = 0;
		mapX = (int)(img->pos_x);
		mapY = (int)(img->pos_y);
        cameraX = 2 * x / (double)w - 1;
        //printf("dirx %f, diry %f, planex %f, planey %f\n", img->dirX, img->dirY, img->planeX, img->planeY);
        rayDirX = img->dirX + img->planeX * cameraX;
        rayDirY = img->dirY + img->planeY * cameraX;
        if (rayDirX == 0 && rayDirY == 0)
        {
            deltaDistX = 1;
            deltaDistY = 1;
        }
        else
        {
            deltaDistX = (rayDirX == 0) ? 0 : fabs(1 / rayDirX);
            deltaDistY = (rayDirY == 0) ? 0 : fabs(1 / rayDirY);
        }
        stepX = (rayDirX < 0) ? -1 : 1;
        stepY = (rayDirY < 0) ? -1 : 1;
        sideDistX = fabs(img->pos_x - (mapX + ((rayDirX < 0) ? 0 : 1))) * deltaDistX;
        sideDistY = fabs(img->pos_y - (mapY + ((rayDirY < 0) ? 0 : 1))) * deltaDistY;
        //printf("sideDistX %f, sideDistY %f\n", sideDistX, sideDistY);
		while (hit == 0)
        {
            //printf("\n");
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            //printf("mapX: %d, mapY: %d\n", mapX, mapY);
			//printf("worldMap %d\n", worldMap[mapX][mapY]);
			if (img->map[mapX][mapY] > '0')
            {
                hit = 1;
                //printf("maps:%s\n", img->map[mapX]);
                //printf("map:%c\n", img->map[mapX][mapY]);
            }
        }
        if(side == 0)
        {
            printf("%f, %f\n", rayDirX, rayDirY);
            printf("%d, %d\n", mapX, mapY);
            printf("Tlqkf!\n");
        }
        //printf("sideDistX %f, mapx: %d, sideDistY %f, mapy: %d\n", sideDistX, mapX, sideDistY, mapY);
        //printf("mapX %d, posX %f, stepX %d, rayDirX %f\n", mapX, img->pos_x, stepX, rayDirX);
        //printf("mapY %d, posY %f, stepY %d, rayDirY %f\n", mapY, img->pos_y, stepY, rayDirY);
		if (side == 0)
            perpWallDist = (mapX - img->pos_x + (1 - stepX) / 2) / rayDirX;
		else
            perpWallDist = (mapY - img->pos_y + (1 - stepY) / 2) / rayDirY;
        lineHeight = (int)(h / perpWallDist);
        //printf("mapX: %d, posX: %f, rayDirX %f\n", mapX, img->pos_x, rayDirX);
        //printf("mapY: %d, posY: %f, rayDirY %f\n", mapY, img->pos_y, rayDirY);
		//printf("side : %d, h: %d, perpWallDist: %f, lineHeight: %d\n\n", side, h, perpWallDist, lineHeight);
        int drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h)
            drawEnd = h - 1;
        int color;
		//printf("worldMap : %d\n", worldMap[mapX][mapY]);
        if (img->map[mapX][mapY] == '1')
            color = 0x00FF0000;
        else if (img->map[mapX][mapY] == '2')
            color = 0x0000FF00;
        else if (img->map[mapX][mapY] == '3')
            color = 0x007C7C00;
        else if (img->map[mapX][mapY] == '4')
            color = 0x00FFC700;
        if (side == 1)
            color = color / 2;
        verLine(img, x, drawStart, drawEnd, color);
    }
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
    return (1);
}

void     init_data(t_data *img_data)
{
    img_data->mlx = mlx_init();
    img_data->img = mlx_new_image(img_data->mlx,\
            img_data->x_size, img_data->y_size);
    printf("save_bmp %d", img_data->save_bmp);
    if(img_data->save_bmp)
        img_data->win = NULL;
    else
        img_data->win = mlx_new_window(img_data->mlx,\
            img_data->x_size, img_data->y_size, "Welcome to cub3d");
    printf("ptr %p\n", img_data->win);
    img_data->addr = mlx_get_data_addr(img_data->img,\
            &(img_data->bits_per_pixel), &(img_data->line_length), &(img_data->endian));
    img_data->moveSpeed = 1;
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

int main(int argc, char **argv)
{
    //int     len;
    //double time = 0; //time of current frame
    //double oldTime = 0; //time of previous frame
    t_data  img_data;

    if(!check_arg(argc, argv))
        return (0);
    img_data.save_bmp = (argc == 3 &&\
            !ft_strncmp(argv[2], "--save", 6)) ? 1 : 0;
    get_data(argv[argc - 1], &img_data);
    printf("x %d, y %d\n", img_data.x_size, img_data.y_size);
    printf("posx:%f, posy: %f\n", img_data.pos_x, img_data.pos_y);
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
    init_data(&img_data);

    mlx_loop_hook(img_data.mlx, raycaster, &img_data);
    mlx_hook(img_data.win, 2, 1L<<0, change_dir, &img_data);
    
    int x = 0;
    int y = 0;
    //mlx_mouse_get_pos(img_data.win, &x, &y);

    printf("x: %d, y: %d\n", x, y);
    //mlx_key_hook(img_data.win, change_dir, &img_data);
    mlx_loop(img_data.mlx);
    return (0);
}
