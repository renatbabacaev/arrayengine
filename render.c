//#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "render.h"
#include "color.h"



void camera(int x, int y, char a[y][x], int xpos, int ypos, unsigned int camfov)
{
    int up, down, left, right, i, j, colorb, colorf;

    /* Camera bound begin */
    
    // Math coordonates to array index
    // x_player--;
    // y_player--;

    up   = ypos - (camfov/2);   // Y bounds
    down = ypos + (camfov/2);   // Y
    left  = xpos - (camfov/2);  // X bounds
    right = xpos + (camfov/2);  // X

    // Even
    if(camfov % 2 == 0)
    {
        left += 1;
        up += 1;
    }

    // Check if Up and Down bounds are out of world
    if(up < 0)
    {
        down = camfov - 1;
        up = 0;
    }
    else if(down >= y)
    {
        up = y - camfov;
        down = y - 1;
    }
    // Check if Left and Right bounds are out of world
    if(left < 0)
    {
        right = camfov - 1;
        left = 0;
    }
    else if(right >= x)
    {
        left = x - camfov;
        right = x - 1;
    }

    // If camera FOV is bigger than world
    if(x <= camfov || y <= camfov)
    {
        right = x - 1;
        down = y - 1;
    }

    /*
        If camera FOV is positive (10x10 screen)
        then place coordonates in top-left pixel.

        In the future, if the player will be able
        to move, move camera if they leave the 
        middle 2x2 zone (center).
    */

    /* Camera bounds end */
    
    
    write(1, "\e[1;1H\e[2J", strlen("\e[1;1H\e[2J"));

    for(j = up; j <= down; j++)
    {
        for(i = left; i <= right; i++)
        {
            //Render part
            switch (a[j][i])
            {
                case '.':
                    colorb = colorf = 3;
                    break;
                case ',':
                    colorb = colorf = 4;
                    break;
                case '#':
                    colorb = colorf = 5;
                    break;
                case '@':
                    colorb = colorf = 6;
                    break;
                case '~':
                    colorb = colorf = 7;
                    break;
                
                default:
                    colorb = colorf = 0;
                    break;    
            }

            write(1, background[colorb], strlen(background[colorb]));
            write(1, "  "RESET, strlen("  "RESET));
        }
        write(1, "\n", strlen("\n")); 
    }
}