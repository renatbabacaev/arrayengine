#include <stdio.h>
#include "render.h"

#define WHITE   "\x1b[48;2;255;255;255m"
#define BLACK   "\x1b[48;2;0;0;0m"

#define RED     "\x1b[41m"
#define GREEN   "\x1b[48;2;60;176;74m"
#define YELLOW  "\x1b[48;2;212;210;83m"
#define BROWN   "\x1b[48;2;66;36;13m"
#define PINK    "\x1b[48;2;252;177;202m"
#define BLUE    "\x1b[44m"
#define MAGENTA "\x1b[45m"
#define CYAN    "\x1b[46m"
#define RESET   "\x1b[0m"

char *color[] = { BLACK, WHITE, RED, GREEN, YELLOW, BROWN, PINK, CYAN };

/*
. - green color
, - yellow color
# - brown
@ - pink
~ - cyan

Maybe will make output as colored dots only
*/

// Maybe give an input value

// General variables
extern int x, y;
extern int x_player, y_player;
extern unsigned int camfov;

int up, down, left, right; 

void camera(char a[y][x])
{
    /* Camera bound begin */
    // Math coordonates to array index
    // x_player--;
    // y_player--;

    up   = y_player - (camfov/2);   // Y bounds
    down = y_player + (camfov/2);   // Y
    left  = x_player - (camfov/2);  // X bounds
    right = x_player + (camfov/2);  // X

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
    
    
    printf("\e[1;1H\e[2J");
    int i, j, colori;

    for(j = up; j <= down; j++)
    {
        for(i = left; i <= right; i++)
        {       
            //Render part
            switch (a[j][i])
            {
            case '.':
                colori = 3;
                break;
            case ',':
                colori = 4;
                break;
            case '#':
                colori = 5;
                break;
            case '@':
                colori = 6;
                break;
            case '~':
                colori = 7;
                break;
            
            default:
                colori = 0;
                break;
            }

            printf(color[colori]);
            printf("  "RESET);
        }
        printf("\n"); 
    }
}