#include "enemy.h"

void Initialiser_Ennemie(ennemie *E,SDL_Surface *screen,char image_name[])
{
    SDL_Rect imagePos;
    E->image=NULL;
    SDL_Surface* tmp=NULL;
    tmp=IMG_Load(image_name);
    E->image=SDL_DisplayFormatAlpha(tmp);
    SDL_FreeSurface(tmp);
    if(E->image==NULL){
            fprintf(stderr,"Unable to load image: %s\n",SDL_GetError());
            exit(EXIT_FAILURE);
        }
    E->PositionImage.x=10;
	E->PositionImage.y=350;
}
void Afficher_Ennemie(ennemie *E, SDL_Surface *screen)
{
	SDL_BlitSurface(E->image,NULL,screen,&E->PositionImage);
}