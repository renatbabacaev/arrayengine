game: main.c render.c
	gcc -o game -O2 main.c render.c
gameDEBUG: main.c render.c
	gcc -o gameDEBUG -g main.c render.c

gameX64: main.c render.c
	gcc -m64 -o gameX64 -O2 main.c render.c
gameX64DEBUG: main.c render.c
	gcc -m64 -o gameX64DEBUG -g main.c render.c

gameX32: main.c render.c
	gcc -m32 -o gameX32 -O2 main.c render.c
gameX32DEBUG: main.c render.c
	gcc -m32 -o gameX32DEBUG -g main.c render.c

all: gameX64 gameX64DEBUG gameX32 gameX32DEBUG game gameDEBUG
ready: gameX64 gameX32 game
debug: gameX64DEBUG gameX32DEBUG gameDEBUG

native: game gameDEBUG
x32: gameX32 gameX32DEBUG
x64: gameX64 gameX64DEBUG
