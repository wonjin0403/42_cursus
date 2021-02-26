#include <mlx.h>
#include <stdio.h>

typedef struct s_vars {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_vars;

int    mouse(void)
{
    printf("mouse\n");
    return (0);
}

int    keybord()
{
    printf("key\n");
    return (0);
}

int     loop()
{
    printf("nothing");
    return (0);
}

int     close(int keycode, t_vars *vars)
{
    printf("close window\n");
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

void            my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
    char    *dst;
    printf("line_length: %d, bits_per_pixel : %d\n", data->line_length, data->bits_per_pixel);
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}



int     main(void)
{
    //void    *mlx;
    //void    *mlx_window;
    t_vars  img;
    //t_vars  vars;
    
    img.mlx = mlx_init();
    img.img = mlx_new_image(img.mlx, 1920, 1080);
    img.win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_key_hook(img.win, close, &img);
    mlx_loop(img.mlx);
    //mlx_window = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    //if (!mlx_window)
    //    printf("fail to open");
    //vars.mlx = mlx;
    //vars.win = mlx_window;
    
    //mlx_mouse_hook(mlx_window, mouse, &vars);
    //mlx_key_hook(mlx_window, keybord, &vars);
    //mlx_loop_hook (mlx_window, loop, &vars);
    //mlx_key_hook(mlx_window, close, &vars);
    //mlx_mouse_hook(mlx_window, close, &vars);
    //size_t b = 2;
    //unsigned int a = (size_t) b;
    //mlx_loop(mlx);
}