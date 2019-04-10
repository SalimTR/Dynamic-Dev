progs:main.o function.o
	gcc main.o function.o -o progs -lSDL -lSDL_image -lSDL_mixer -lm -g
main.o:main.c
	gcc -c main.c -g 
Trigo.o:function.c
	gcc -c function.c -g 
