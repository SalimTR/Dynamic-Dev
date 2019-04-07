#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>_
int main(int argc, char *argv[])
{
 
    SDL_Surface *ecran=NULL,*map=NULL,*perso=NULL;
    SDL_Rect posmap,morceau,posperso,posaux;
    SDL_Event event;
    int continuer = 1;
 
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(400, 400, 32, SDL_HWSURFACE);
 
    perso = IMG_Load("detective.png");
    map=SDL_LoadBMP("background.bmp");
 
    posmap.x=0;
    posmap.y=0;
 
    posperso.x=150;
    posperso.y=150;
 
    
morceau.h=400;
    morceau.w=400;
 
   SDL_BlitSurface(map, &morceau, ecran, &posmap);
    SDL_BlitSurface(perso, NULL, ecran, &posperso);
    SDL_Flip(ecran);
 
    SDL_EnableKeyRepeat(10, 10);
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT: // Flèche droite
                    posperso.x++;
                        break;
                    case SDLK_LEFT: // Flèche gauche
                         posperso.x--;
                        break;
                }
                break;
 
        }
posaux.y = posperso.y;
morceau.x=posperso.x-150;
morceau.y=0;
 
    if(morceau.x<0)
    {
     morceau.x=0;
     posaux.x = posperso.x;
     }
     else
     {
        posaux.x = 150;
     }

        SDL_BlitSurface(map, &morceau, ecran, &posmap);
        SDL_BlitSurface(perso, NULL, ecran, &posaux);
        SDL_Flip(ecran);
                }
 
    SDL_FreeSurface(map);
    SDL_FreeSurface(perso);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}







