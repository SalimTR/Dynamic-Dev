progs:main.o function.o
	gcc main.o function.o -o progs -lSDL -lSDL_image -lm -g
main.o:main.c
	gcc -c main.c -g 
Trigo.o:function.c
	gcc -c function.c -g 
gif.o:fgif.c
	gcc -c fgif.c -g 
giff.o:fgifdsl.c
	gcc -c fgifdsl.c -g 
