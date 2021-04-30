#include <stdio.h>

union {
    unsigned int bits32;
    unsigned char bytes[4];
} TheValue;

int main()
{
   TheValue.bits32 = 1;
   printf("%d\n", (int)TheValue.bytes[0]); 
}