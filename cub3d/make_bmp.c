#include "cub3d.h"

void    signature(char *bitmap)
{
    bitmap[0] = 'B';
    bitmap[1] = 'M';
}

void    file_size(char *bitmap, t_data *data)
{
    *(int *)(bitmap + 2) = data->img_data.x * data->img_data.y\
                                * data->img_data.bits_per_pixel;
}

void    reserved_field(char *bitmap)
{
    int idx;

    idx = 6;
    while(idx < 10)
        bitmap[idx++] = 0;
}

void    offset(char *bitmap)
{
    bitmap[10] = 54;
    bitmap[11] = 0;
    bitmap[12] = 0;
    bitmap[13] = 0;
}

void    header_size(char *bitmap)
{
    int idx;

    idx = 15;
    bitmap[14] = 40;
    while(idx < 18)
        bitmap[idx++] = 0;
}

void    width_and_height_img(char *bitmap, t_data *data)
{
    *(int *)(bitmap + 18) = 4;//data->input.width;
    *(int *)(bitmap + 22) = 1;//data->input.hight;
}

void    info_reserved(char *bitmap)
{
    bitmap[26] = 1;
    bitmap[27] = 0;
}
void    bpp(char *bitmap, t_data *data)
{
    bitmap[28] = 32;//data->img_data.bits_per_pixel;
    bitmap[29] = 0;
}

void    compression(char *bitmap)
{
    int idx;

    idx = 30;
    while(idx < 34)
        bitmap[idx++] = 0;
}

void    image_size(t_data *data, char *bitmap)
{
    int idx;

    idx = 34;
    *(int *)(bitmap + 34) = 12;//data->input.width * data->input.hight *\
            data->img_data.bits_per_pixel / 8;
    //while(idx < 38)
    //    bitmap[idx++] = 0;
} //여기확인

void    ppm(char *bitmap)
{
    bitmap[38] = 0;
    bitmap[39] = 0;
    bitmap[40] = 0b00110000;
    bitmap[41] = 0b10110001;

    bitmap[42] = 0;
    bitmap[43] = 0;
    bitmap[44] = 0b00110000;
    bitmap[45] = 0b10110001;
}

void    color_pallette(char *bitmap)
{
    int idx;
    
    idx = 46;
    while(idx < 50)
        bitmap[idx++] = 0;
}

void    important_color(char *bitmap)
{
    int idx;

    idx = 50;
    while(idx < 54)
        bitmap[idx++] = 0;
}

void    pixel_data(char *bitmap, t_data *data)
{
    int x;
    int y;

    x = -1;
    y = -1;
    printf("x: %d y :%d\n", data->img_data.x, data->img_data.y);
    int cnt;

    cnt = -1;
    printf("%d\n", data->input.width * data->input.height * data->img_data.bits_per_pixel / 8);
    while(++cnt < data->input.width * data->input.height * data->img_data.bits_per_pixel / 8)
    {
        //printf("idx %d\n", *idx);
        bitmap[54 + cnt] = 0;//*(data->img_data.addr + cnt);
    }
}

void    bmp_info_header(char *bitmap, t_data *data)
{
    header_size(bitmap);
    width_and_height_img(bitmap, data);
    info_reserved(bitmap);
    bpp(bitmap, data);
    compression(bitmap);
    image_size(data, bitmap);
    ppm(bitmap);
    color_pallette(bitmap);
    important_color(bitmap);
}

void    bmp_make(char *bitmap, t_data *data)
{
    // -- FILE HEADER -- //
    // bitmap signature
    signature(bitmap);
    // file size
    file_size(bitmap, data);
    // reserved field (in hex. 00 00 00 00)
    reserved_field(bitmap);
    // offset of pixel data inside the image
    offset(bitmap);
    // -- BITMAP HEADER -- //
    bmp_info_header(bitmap, data);
    pixel_data(bitmap, data);
}

int     bmp_write(char *bitmap)
{
    int fd;

    fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_EXCL, 0666);
    if(fd == 0)//NULL)
    {
        printf("ERROR\nWhen \"bitmap.bmp\" open");
        return (0);
    }
    printf("first line %c %c\n", bitmap[0], bitmap[1]);
    //write(fd, "B", 1);
    write(fd, bitmap, 66);//idx);
    close(fd);
    return (1);
}

int     make_bmp(t_data *data)
{
    char    *bitmap;
    int result;
    
    bitmap = (char *)malloc(54 + (data->input.width) * (data->input.height) * data->img_data.bits_per_pixel);
    //bitmap[0] = 'z';
    //printf("num: %d %c\n", 54 + data->input.width * data->input.hight * data->img_data.bits_per_pixel, bitmap[0]);
    decide_save_or_print(data);
    //printf("1111\n");
    bmp_make(bitmap, data);
    //printf("22222\n");
    result = bmp_write(bitmap);
    free(bitmap);
    if(result == 0)
        return (0);
    return (1);
}