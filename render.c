#include <stdio.h>
#include "render.h"

void camera(int x, int y, char a[y][x])
{
    for(int i = 0; i < y * x; i++)
    {
        if(i % x == 0 && i != 0)
        {
            printf("\n");
        }
        printf("%c", a[0][i]);
    }
}