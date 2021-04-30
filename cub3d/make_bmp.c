#include "cub3d.h"

void    signature(char *bitmap, int *idx)
{
    bitmap[(*idx)++] = 'B';
    bitmap[(*idx)++] = 'M';
}

void    file_size(char *bitmap, t_data *data, int *idx)
{
    *(int *)(bitmap + *idx) = 14 + 54 +  data->input.width * data->input.hight;
    *idx += 6;
}

void    reserved_field(char *bitmap, int *idx)
{
    while(*idx < 10)
        bitmap[(*idx)++] = 0;
}

void    offset(char *bitmap, int *idx)
{
    while(*idx < 14)
        bitmap[(*idx)++] = 0;
}

void    header_size(char *bitmap, int *idx)
{
    *(int *)(bitmap + *idx) = 40;
    *idx += 5;
}

void    width_and_hight_img(char *bitmap, t_data *data, int *idx)
{
    *(int *)(bitmap + *idx) = data->input.width;
    *idx += 5;
    *(int *)(bitmap + *idx) = data->input.hight;
    *idx += 5;
}

void    info_reserved(char *bitmap, int *idx)
{
    *(short *)(bitmap + *idx) = 1;
    *idx += 2;
}
void    bpp(char *bitmap, t_data *data, int *idx)
{
    *(short *)(bitmap + *idx) = data->img_data.bits_per_pixel;
    *idx += 2;
}

void    compression(char *bitmap, int *idx)
{
    while(*idx < 34)
        bitmap[(*idx)++] = 0;
}

void    image_size(char *bitmap, int *idx)
{
    while(*idx < 38)
        bitmap[(*idx)++] = 0;
}

void    ppm(char *bitmap, int *idx)
{
    while(*idx < 42)
        bitmap[(*idx)++] = 0;
    while(*idx < 46)
        bitmap[(*idx)++] = 0;
}

void    color_pallette(char *bitmap, int *idx)
{
    while(*idx < 50)
        bitmap[(*idx)++] = 0;
}

void    important_color(char *bitmap, int *idx)
{
    while(*idx < 54)
        bitmap[(*idx)++] = 0;
}

void    pixel_data(char *bitmap, t_data *data, int *idx)
{
    int x;
    int y;

    x = -1;
    y = -1;
    printf("x: %d y :%d\n", data->img_data.x, data->img_data.y);
    //while(++x < data->img_data)
    int cnt;

    cnt = -1;
    printf("%d\n", data->input.width * data->input.hight * data->img_data.bits_per_pixel);
    while(++cnt < data->input.width * data->input.hight * data->img_data.bits_per_pixel)
    {
        //printf("idx %d\n", *idx);
        bitmap[(*idx)++] = *(data->img_data.addr + cnt);
    }
}

void    bmp_info_header(char *bitmap, t_data *data, int *idx)
{
    header_size(bitmap, idx);
    width_and_hight_img(bitmap, data, idx);
    info_reserved(bitmap, idx);
    bpp(bitmap, data, idx);
    compression(bitmap, idx);
    image_size(bitmap, idx);
    ppm(bitmap, idx);
    color_pallette(bitmap, idx);
    important_color(bitmap, idx);
}

void    bmp_make(char *bitmap, t_data *data, int *idx)
{
    // -- FILE HEADER -- //
    // bitmap signature
    signature(bitmap, idx);
    // file size
    file_size(bitmap, data, idx);
    // reserved field (in hex. 00 00 00 00)
    reserved_field(bitmap, idx);
    // offset of pixel data inside the image
    offset(bitmap, idx);
    // -- BITMAP HEADER -- //
    bmp_info_header(bitmap, data, idx);
    pixel_data(bitmap, data, idx);
}

int     bmp_write(char *bitmap, int idx)
{
    int fd;

    fd = open("bitmap.bmp", O_WRONLY);
    if(fd == 0)//NULL)
    {
        printf("ERROR\nWhen \"bitmap.bmp\" open");
        return (0);
    }
    write(fd, &bitmap, idx);
    close(fd);
    return (1);
}

int     make_bmp(t_data *data)
{
    char    *bitmap;
    int idx;
    int result;
    
    bitmap = (char *)malloc(54 + (data->input.width) * (data->input.hight) * data->img_data.bits_per_pixel);

    bitmap[0] = 'z';
    printf("num: %d %c\n", 54 + data->input.width * data->input.hight * data->img_data.bits_per_pixel, bitmap[0]);
    idx = 0;
    raycaster(data);
    printf("1111\n");
    bmp_make(bitmap, data, &idx);
    printf("22222\n");
    result = bmp_write(bitmap, idx);
    free(bitmap);
    if(result == 0)
        return (0);
    return (1);
}