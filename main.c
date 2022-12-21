#include <stdio.h>

#include "render.h"

int main()
{
    int x, y, xpos, ypos;       // Dimension, player position
    unsigned int camfov;        // Camera fov



    // Creating world from file
    FILE *level;
    level = fopen("level", "r");

    // Value scanning and checking
    fscanf(level, "%i %i\n%i %i\n%u\n", &x, &y, &xpos, &ypos, &camfov);

    // Normalize
    ypos = y - ypos;
    xpos = xpos - 1;

    if((x <= 0 || y <= 0) || (xpos > x || ypos > y || xpos < 0 || ypos < 0) || (camfov == 0))
    {
        fclose(level);
        printf("\nInvalid input.\nPlease refer to SDK guide included with engine for valid values.");
        return -1;
    }
    
    // World input
    char world[y][x];
    for(int i = 0; i < y; i++)
    {
        fscanf(level, "%s", &world[i]);
    }

    fclose(level);
    

    // -> Input -> Update -> Render ->
    camera(x, y, world, xpos, ypos, camfov);   // Only height needed

    return 0;
}