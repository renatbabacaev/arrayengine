#include <stdio.h>
#include <stdlib.h>

#include "render.h"



int main()
{
    int x, y; // Coords



    // Creating world from file
    FILE *level;
    level = fopen("level", "r");
    fscanf(level, "%i %i", &x, &y);

    char world[y][x];
    for(int i = 0; i < y; i++)
    {
        fscanf(level, "%s", &world[i]);    
    }

    fclose(level);



    camera(x, y, world);   // Only height needed

    return 0;
}