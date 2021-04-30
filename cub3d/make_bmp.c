#include <cub3d.h>

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
    *(int *)(bitmap + *idx) = data->input.height;
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
    while(++y < data->img_data.y)
    {
        while(++x < data->img_data.x)
            bitmap[(*idx)++] = data->img_data.addr + (y * data->img_data.line_length + x * (data->img_data.bits_per_pixel / 8));
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
    reserved_field(bitmap, idx)
    // offset of pixel data inside the image
    offset(bitmap, idx);
    // -- BITMAP HEADER -- //
    bmp_info_header(bitmap, data, idx);
    pixel_data(bitmap, data, idx);
}

void bmp_write(char *bitmap, int *idx)
{
    int fd;

    fd = open("bitmap.bmp", O_WRONLY);
    if(fd == NULL)
    {
        printf("ERROR\nWhen \"bitmap.bmp\" open");
        return (0);
    }
    wrtie(fd, &bitmap, idx);
    close(fd);
    return (0);
}

int     make_bmp(t_data *data)
{
    char    bitmap[54 + data->input.width * data->input.hight];
    int idx;
    int result;

    idx = 0;
    raycaster(data);
    bmp_make(bitmap, data, &idx);
    result = bmp_wirte(bitmap, idx);
    if(result == 0)
        return (0);
    return (1);
}