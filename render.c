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

extern int x, y;
extern int x_player, y_player;
extern unsigned int camfov;

void print(int up, int down, int left, int right, char a[y][x])
{
    int i, j;

    for(j = up; j <= down; j++)
    {
        for(i = left; i <= right; i++)
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
    // If world is smaller than camera fov
    if(x <= camfov - 1 || y <= camfov - 1)
    {
        // + 1 in order to set correct matrix size
        print(0, y - 1, 0, x - 1, a);
        return;
    }
    
    // Math coordonates to array index
    x_player--;
    // ypos--;

    int up_bound, down_bound;
    int left_bound, right_bound;

    /*
        If camera FOV is positive (10x10 screen)
        then place coordonates in top-left pixel.

        In the future, if the player will be able
        to move, move camera if they leave the 
        middle 2x2 zone (center).
    */


    // Y bounds
    up_bound   = y_player - (camfov/2);
    down_bound = y_player + (camfov/2);
    // X bounds
    left_bound  = x_player - (camfov/2);
    right_bound = x_player + (camfov/2);

    if(camfov % 2 == 0)
    {
        up_bound++;
        left_bound++;
    }

    // Back to bounds math: Negative shift
    if(up_bound < 0)
    {
        down_bound = camfov - 1;
        up_bound = 0;
    }
    if(left_bound < 0)
    {
        right_bound = camfov - 1;
        left_bound = 0;
    }

    // Positive shift
    if(down_bound >= y)
    {
        up_bound = y - camfov + 1;
        down_bound = y;
    }
    if(right_bound >= x)
    {
        left_bound = x - camfov;
        right_bound = x;
    }

    print(up_bound, down_bound, left_bound, right_bound, a);

    return; 
}