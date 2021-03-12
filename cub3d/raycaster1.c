#include <math.h>
#include <mlx.h>
#include <stdio.h>
#define PI 3.14159265

typedef struct s_data {
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
        angle = (keycode == 0) ? 1 * 180 / PI : -1 * 180 / PI;
        
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
    
        new_x = param->posX + param->dirX * param->moveSpeed * sign;
        new_y = param->posY + param->dirY * param->moveSpeed * sign;
        printf("posX %f, posY %f, moveSpeed %d, sign %d\n", param->posX, param->posY, param->moveSpeed, sign);
        printf("dirX %f, dirY %f\n", param->dirX, param->dirY);
        old_posX = param->posX;
        printf("newx: %f, new_y: %f, worldMap[new_x][new_y]: %d\n", new_x, new_y, worldMap[(int)new_x][(int)new_y]);
        if (new_x > 0 && new_x < mapWidth - 1 &&  new_y > 0 && new_y < mapHeight - 1)
        {
            if (worldMap[(int)new_x][(int)param->posY] == 0)
                param->posX = new_x;
            if (worldMap[(int)old_posX][(int)new_y] == 0)
                param->posY = new_y;
        }

    }
    //space 점프 shift 달리기
    else if (keycode == 53)
    {
        mlx_destroy_image(param->mlx, param->img);
        mlx_destroy_window(param->mlx, param->win);
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
    int done = 0;
	int x;

    w = img->sw;
    h = img->sy;
    x = -1;
    while (++x < w)
    {
		hit = 0;
		mapX = (int)(img->posX);
		mapY = (int)(img->posY);
        cameraX = 2 * x / (double)w - 1;
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
        sideDistX = fabs(img->posX - (mapX + ((rayDirX < 0) ? 0 : 1))) * deltaDistX;
        sideDistY = fabs(img->posY - (mapY + ((rayDirY < 0) ? 0 : 1))) * deltaDistY;
        w
		while (hit == 0)
        {
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
			if (worldMap[mapX][mapY] > 0)
                hit = 1;
        }
		if (side == 0)
            perpWallDist = (mapX - img->posX + (1 - stepX) / 2) / rayDirX;
		else
            perpWallDist = (mapY - img->posY + (1 - stepY) / 2) / rayDirY;
        lineHeight = (int)(h / perpWallDist);
        //printf("mapX: %d, posX: %f, rayDirX %f\n", mapX, img->posX, rayDirX);
        //printf("mapY: %d, posY: %f, rayDirY %f\n", mapY, img->posY, rayDirY);
		//printf("side : %d, h: %d, perpWallDist: %f, lineHeight: %d\n", side, h, perpWallDist, lineHeight);
        int drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h)
            drawEnd = h - 1;
        int color;
		//printf("worldMap : %d\n", worldMap[mapX][mapY]);
        if (worldMap[mapX][mapY] == 1)
            color = 0x00FF0000;
        else if (worldMap[mapX][mapY] == 2)
            color = 0x0000FF00;
        else if (worldMap[mapX][mapY] == 3)
            color = 0x007C7C00;
        else if (worldMap[mapX][mapY] == 4)
            color = 0x00FFC700;
        if (side == 1)
            color = color / 2;
        verLine(img, x, drawStart, drawEnd, color);
    }
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
    return (1);
}

void     init_data(t_data *img)
{
    img->mlx = mlx_init();
    img->img = mlx_new_image(img->mlx, 1920, 1080);
    img->win = mlx_new_window(img->mlx, 1920, 1080, "Hello world!");
    img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
    img->sw = 1920;
    img->sy = 1080;
    img->posX = 22;
    img->posY = 12;
    img->dirX = -1;
    img->dirY = 0;
    img->planeX = 0;
    img->planeY = 0.66;
    img->moveSpeed = 1;
}

int main(int argc, char *argv[])
{
    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame
    t_data  img;
    init_data(&img);
    //my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
 
    mlx_loop_hook(img.mlx, raycaster, &img);
    mlx_key_hook(img.win, change_dir, &img);
    mlx_loop(img.mlx);
}

