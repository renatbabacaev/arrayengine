#include <stdio.h>

#include "render.h"

int x, y;                   // Dimension
int x_player, y_player;     // Player coordinates
unsigned int camfov;        // Camera fov

int main()
{
    // Creating world from file
    FILE *level;
    level = fopen("level", "r");

    // Value scanning and checking
    fscanf(level, "%i %i", &x, &y);
    fscanf(level, "%i %i", &x_player, &y_player);
    fscanf(level, "%u",    &camfov);

    // Normalize
    y_player = y - y_player;
    x_player = x_player - 1;

    if(x <= 0 || y <= 0)
    {
        fclose(level);
        printf("\nInvalid world dimensions.");
        return 0;
    }
    if(x_player > x || y_player > y || x_player < 0 || y_player < 0)
    {
        fclose(level);
        printf("\nOut of bounds position.");
        return 0;
    }
    if(camfov == 0)
    {
        fclose(level);
        printf("\nInvalid FOV value.");
        return 0;
    }

    // World input
    char world[y][x];
    for(int i = 0; i < y; i++)
    {
        fscanf(level, "%s", &world[i]);    
    }

    fclose(level);
    


    camera(world);   // Only height needed

    return 0;
}