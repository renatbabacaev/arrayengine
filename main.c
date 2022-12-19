#include <stdio.h>
#include <stdlib.h>

#include "render.h"



int main()
{
    int x, y; // Dimension

    unsigned int camfov;        // Camera fov
    int x_player, y_player;     // Player coordinates



    // Creating world from file
    FILE *level;
    level = fopen("level", "r");
    fscanf(level, "%i %i", &x, &y);
    if(x <= 0 || y <= 0)
    {
        fclose(level);
        printf("\nInvalid world dimensions.");
        return 0;
    }

    fscanf(level, "%u", &camfov);

    char world[y][x];
    for(int i = 0; i < y; i++)
    {
        fscanf(level, "%s", &world[i]);    
    }

    fclose(level);

    printf("\nEnter starting point (x y): ");
    scanf("%i %i", &x_player, &y_player);

    // Normalize to top-right coordinate axis (Left-Bottom = (1, 1) )
    y_player = y - y_player;
    if(x_player > x || x_player <= 0 || y_player > y || y_player <= 0)
    {
        printf("\nOut of bounds position.");
        return 0;
    }

    camera(x, y, world, x_player, y_player, camfov);   // Only height needed

    return 0;
}