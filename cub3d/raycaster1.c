#include <math.h>
#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
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

int main(int argc, char *argv[])
{
    int     sw = 1920, sy = 1080;
    int     cnt = 0;
    double  posX = 22,  posY = 12;  //x and y start position
    double  dirX = -1,  dirY = 0; //initial direction vector
    double  planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame
    t_data  img;
    img.mlx = mlx_init();
    img.img = mlx_new_image(img.mlx, 1920, 1080);
    img.win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
    //my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
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
    while(!done)
    {
        int w = sw;
        int h = sy;
        int mapX = (int)posX;
        int mapY = (int)posY;
        x = -1;
        while (++x < w)
        {
			hit = 0;
			mapX = (int)posX;
			mapY = (int)posY;
            cameraX = 2 * x / (double)w - 1;
            rayDirX = dirX + planeX * cameraX;
            rayDirY = dirY + planeY * cameraX;

            if (rayDirX == 0 && rayDirX == 0)
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

            sideDistX = (posX - mapX + ((rayDirX < 0) ? 0 : 1)) * deltaDistX;
            sideDistY = (posX - mapY + ((rayDirY < 0) ? 0 : 1)) * deltaDistY; 
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
			/*if (planeX == 0)
                perpWallDist = fabs(sideDistX - posX);
            else
            {
                int gradient = planeY / planeX;
                double c = posY - gradient * posX;
                perpWallDist = fabs(gradient * (sideDistX + posX) - (sideDistY + posY) + c) / sqrt(pow(sideDistX + posX, 2) + pow(sideDistY + posY, 2));
            }*/
			if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
            lineHeight = (int)(h / perpWallDist);
			printf("h %d, perpWallDist %f, lineHeight: %d\n", h, perpWallDist, lineHeight);
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
            verLine(&img, x, drawStart, drawEnd, color);
		}
        mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
        //
        //mlx_key_hook(img.win, close, &img);
		done = 1;
    }
    mlx_loop(img.mlx);
}

