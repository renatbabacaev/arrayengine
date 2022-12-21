#define bWHITE   "\x1b[48;2;255;255;255m"
#define bBLACK   "\x1b[48;2;0;0;0m"

#define bRED     "\x1b[41m"
#define bGREEN   "\x1b[48;2;60;176;74m"
#define bYELLOW  "\x1b[48;2;212;210;83m"
#define bBROWN   "\x1b[48;2;66;36;13m"
#define bPINK    "\x1b[48;2;252;177;202m"
#define bBLUE    "\x1b[44m"
#define bMAGENTA "\x1b[45m"
#define bCYAN    "\x1b[46m"

#define fWHITE   "\x1b[38;2;255;255;255m"
#define fBLACK   "\x1b[38;2;0;0;0m"

#define fRED     "\x1b[31m"
#define fGREEN   "\x1b[38;2;60;176;74m"
#define fYELLOW  "\x1b[38;2;212;210;83m"
#define fBROWN   "\x1b[38;2;66;36;13m"
#define fPINK    "\x1b[38;2;252;177;202m"
#define fBLUE    "\x1b[34m"
#define fMAGENTA "\x1b[35m"
#define fCYAN    "\x1b[36m"


#define RESET   "\x1b[0m"

/*
. - green color
, - yellow color
# - brown
@ - pink
~ - cyan

Maybe will make output as colored dots only
*/

char *background[] = { bBLACK, bWHITE, bRED, bGREEN, bYELLOW, bBROWN, bPINK, bCYAN };
char *foreground[] = { fBLACK, fWHITE, fRED, fGREEN, fYELLOW, fBROWN, fPINK, fCYAN };
