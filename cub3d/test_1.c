#include <mlx.h>
#include <stdio.h>

void verLine(char *empty_img, char *texture_img, int bits_per_pixel1, int line_length1, int bits_per_pixel2, int line_length2)
{
    int width = -1;
    int hight = -1;
    double stepx = 32.0 / 1000.0;
    double stepy = 32.0 / 1000.0;
    char *dst1;
    char *dst2;

    while(++width < 1000)
    {
        hight = -1;
        while(++hight < 1000)
        {
            //printf("w: %d h: %d\n", width, hight);
            dst1 = (empty_img + (hight * line_length1 + width * (bits_per_pixel1 / 8)));
            dst2 = (texture_img + (int)(hight * stepy) * line_length2 + (int)(width * stepx) * (bits_per_pixel2 / 8));
            printf("hight: %d, width: %d, stepx: %f, stepy: %f, *y: %d *x: %d\n", hight, width, stepx, stepy, (int)(hight * stepy), (int)(width * stepx));
            *(unsigned int *)dst1 = *(unsigned int *)dst2; //0x00FF0000;////
            //printf("%x  ", *(unsigned int *)dst2);
            //printf("---2 L 1:%x 2: %x\n", *(unsigned int *)dst1, *(unsigned int *)dst2);
        }
        printf("\n");
    }
}

int main()
{
    int x, y, bits_per_pixel1, line_length1, bits_per_pixel2, line_length2, endian1, endian2;
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1980, 1080, "Hello world!");

    void *IMG = mlx_new_image(mlx, 1000, 1000);
    char *IMG_add = mlx_get_data_addr(IMG, &(bits_per_pixel1), &(line_length1), &(endian1));
    
    void *img = mlx_xpm_file_to_image(mlx, "./texture/north.xpm", &x, &y);
    char *img_add = mlx_get_data_addr(img, &(bits_per_pixel2), &(line_length2), &(endian2));
    //printf("1: %x 2: %x\n", *(unsigned int *)IMG_add, *(unsigned int *)img_add);
    verLine(IMG_add, img_add, bits_per_pixel1, line_length1, bits_per_pixel2, line_length2);
    //printf("1: %x 2: %x\n", *(unsigned int *)IMG_add, *(unsigned int *)img_add);
    mlx_put_image_to_window(mlx, win, IMG, 0, 0);
    mlx_loop(mlx);
}