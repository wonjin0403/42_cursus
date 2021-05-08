#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char bitmap[1000];

void BMPmake()
{
    // -- FILE HEADER -- //

    // bitmap signature
    bitmap[0] = 'B';
    bitmap[1] = 'M';

    // file size
    *(int *)(bitmap + 2) = 54 + 8 * 1 * 3;
    bitmap[3] = 0;
    bitmap[4] = 0;
    bitmap[5] = 0;

    // reserved field (in hex. 00 00 00 00)
    for(int i = 6; i < 10; i++) bitmap[i] = 0;

    // offset of pixel data inside the image
    //for(int i = 10; i < 14; i++)
    //{
    bitmap[10] = 54;
    bitmap[11] = 0;
    bitmap[12] = 0;
    bitmap[13] = 0;
    //}
    // -- BITMAP HEADER -- //

    // header size
    bitmap[14] = 40;
    bitmap[15] = 0;
    bitmap[16] = 0;
    bitmap[17] = 0;

    // width of the image
    *(int *)(bitmap + 18) = 8;
    *(int *)(bitmap + 19) = 0;
    *(int *)(bitmap + 20) = 0;
    *(int *)(bitmap + 21) = 0;

    // height
    *(int *)(bitmap + 22) = 1;
    *(int *)(bitmap + 23) = 0;
    *(int *)(bitmap + 24) = 0;
    *(int *)(bitmap + 25) = 0;

    // plane
    bitmap[26] = 1;
    bitmap[27] = 0;

    // number of bits per pixel
    bitmap[28] = 24; // 3 byte
    bitmap[29] = 0;

    // compression method (no compression here)
    for(int i = 30; i < 34; i++) bitmap[i] = 0;

    // size of pixel data (IMAGE SIZE)
    bitmap[34] = 0;
    bitmap[35] = 0;
    bitmap[36] = 0;
    bitmap[37] = 0;

    // horizontal resolution of the image - pixels per meter (2835)
    bitmap[38] = 0;
    bitmap[39] = 0;
    bitmap[40] = 0;
    bitmap[41] = 0;

    // vertical resolution of the image - pixels per meter (2835)
    bitmap[42] = 0;
    bitmap[43] = 0;
    bitmap[44] = 0;
    bitmap[45] = 0;

    // color pallette information
    for(int i = 46; i < 50; i++) bitmap[i] = 0;

    // number of important colors
    for(int i = 50; i < 54; i++) bitmap[i] = 0;

    // -- PIXEL DATA -- //
    for(int i = 54; i < 54 + 22 * 1 * 3; i++) bitmap[i] = 0;
}

void BMPwrite()
{
    FILE *file;
    file = fopen("final_bitmap.bmp", "w+");
    for(int i = 0; i < 66; i++)
    {
        fputc(bitmap[i], file);
    }
    fclose(file);
}

void BMPwrite1()
{
    int fd = open("final_bitmap.bmp", O_WRONLY | O_CREAT, O_EXCL, 0666);
    printf("%c %c\n", bitmap[0], bitmap[1]);
    write(fd, bitmap, 66);
    close(fd);
}

int main()
{
    BMPmake();
    BMPwrite();
    return (0);
}

