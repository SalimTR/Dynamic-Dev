
#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>


SDL_Rect positionscreen,position;
SDL_Surface *image,*fond,*screen;
//ecran
int main()
{
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}

screen= SDL_SetVideoMode(1600,400,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}
positionscreen.x=0;
positionscreen.y=0;
fond =SDL_LoadBMP("background.bmp");
//images
image=IMG_Load("detective.png");
SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(image->format,255,255,255));
position.x=0;
position.y=220;


int continuer=1;
    SDL_Event event;
    SDL_Rect position;
    SDL_Rect positionaux;
SDL_EnableKeyRepeat(100, 100);
while(continuer==1)
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
                case SDLK_ESCAPE:
                  continuer = 0;
                   break;
                    case SDLK_UP:
                        position.y-=40;
                        break;
                    case SDLK_DOWN:
                        position.y+=40;
                        break;
                    case SDLK_RIGHT:
                        position.x+=40;
                        break;
                    case SDLK_LEFT:
                        position.x-=40;
                        break;

			SDL_Delay(500);
                	}
case SDL_MOUSEMOTION:

            position.x = event.motion.x;
	    position.y = event.motion.y;
	    SDL_Delay(50);
            break;




case SDL_MOUSEBUTTONUP:
if (event.button.button == SDL_BUTTON_RIGHT)
{

 positionaux.x = event.button.x;
 positionaux.y = event.button.y;

int nx,ny;
nx=positionaux.x % 10;
ny=positionaux.y % 10;

while(position.x < positionaux.x -nx )
{
position.x+=10;
SDL_Delay(100);
}
SDL_BlitSurface(image, NULL, screen ,&position);
SDL_Flip(screen);

while(position.x  >positionaux.x - nx)
{
position.x-=10;
SDL_Delay(100);
}
SDL_BlitSurface(image, NULL, screen ,&position);
SDL_Flip(screen);


while(position.y < positionaux.y - ny)
{
position.y+=10;
SDL_Delay(100);
}
SDL_BlitSurface(image, NULL, screen ,&position);
SDL_Flip(screen);

while(position.y >positionaux.y - ny)
{
position.y-=10;
SDL_Delay(100);
}
SDL_BlitSurface(image, NULL, screen ,&position);
SDL_Flip(screen);

}
break;
}


SDL_BlitSurface(fond, NULL, screen, &positionscreen);
SDL_BlitSurface(image, NULL, screen ,&position);
SDL_Flip(screen);
}


SDL_FreeSurface(screen);
SDL_FreeSurface(fond);
SDL_Quit;
return 0;
}
