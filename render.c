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

/*
. - green color
, - yellow color
# - brown
@ - pink

Maybe will make output as colored dots only
*/

// Maybe give an input value

// General variables
extern int x, y;
extern int x_player, y_player;
extern unsigned int camfov;

int up, down, left, right; 

void print(char a[y][x])
{
    int i, j;

    for(j = up; j < down; j++)
    {
        for(i = left; i < right; i++)
        {       
            //Render part
            switch (a[j][i])
            {
            case '.':
                printf(GREEN "  " RESET);
                break;
            case ',':
                printf(YELLOW "  " RESET);
                break;
            case '#':
                printf(BROWN "  " RESET);
                break;
            case '@':
                printf(PINK "  " RESET);
                break;
            
            default:
                printf(BLACK "  " RESET);
                break;
            }
        }
        printf("\n"); 
    }
    
    return; 
}

void camera(char a[y][x])
{
    // Math coordonates to array index
    // x_player--;
    // y_player--;

    // Y bounds
    up   = y_player - (camfov/2);
    down = y_player + (camfov/2) + 1;
    // X bounds
    left  = x_player - (camfov/2) - 1;
    right = x_player + (camfov/2);

    /*
        If camera FOV is positive (10x10 screen)
        then place coordonates in top-left pixel.

        In the future, if the player will be able
        to move, move camera if they leave the 
        middle 2x2 zone (center).
    */
    if(camfov % 2 == 0)
    {
        up++;
        left++;
    }

    // Up and Down camera bounds
    if(up < 0)
    {
        down = camfov;
        up = 0;
    }
    else if(down >= y)
    {
        up = y - camfov;
        down = y;
    }
    // Left and Right camera bounds
    if(left < 0)
    {
        right = camfov;
        left = 0;
    }
    else if(right >= x)
    {
        left = x - camfov;
        right = x;
    }


    // If camera FOV is bigger than world
    if(x <= camfov - 1 || y <= camfov - 1)
    {
        print(a);
        return;
    }
    
    print(a);

    return; 
}