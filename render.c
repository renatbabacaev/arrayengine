#include <stdio.h>
#include "render.h"

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

void camera(int x, int y, char a[y][x])
{
    printf("\e[1;1H\e[2J"); // Clear screen
    
    for(int i = 0; i < y * x; i++)
    {
        if(i % x == 0 && i != 0)
        {
            printf("\n");
        }
        switch (a[0][i])
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
            printf("  ");
            break;
        }
    }
}