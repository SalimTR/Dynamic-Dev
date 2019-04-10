prog:*.h *.c
	gcc *.h *.c -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -lm  -o salim -g
main.o:main.c
	gcc -c main.c -g
enemy.o:enemy.c
	gcc -c enemy.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog