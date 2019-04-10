#ifndef ENEMY_H_
#define ENEMY_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>

#define LARGEUR 1280
#define HAUTEUR 705
#define bpp 32

typedef struct
{
	SDL_Rect PositionImage;
	SDL_Surface *image;
}ennemie;

void Initialiser_Ennemie(ennemie *E,SDL_Surface *screen,char image_name[]);
void Afficher_Ennemie(ennemie *E,SDL_Surface* screen);




#endif 