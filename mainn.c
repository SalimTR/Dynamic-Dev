#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void animation(SDL_Surface* sprite,SDL_Surface* screen, int x,int y,int test)
{
const int SHEET_WIDTH = x;
const int SHEET_HEIGHT = y;
SDL_Rect pos,pos1;
const int FPS = 30;
       Uint32 start;
pos.x=600;
pos.y=150;
pos1.x=0;
pos1.y=100;
int i=0;

int j=5;


    int quitProgram = 0;



SDL_Event event;

SDL_Rect clip[ 10 ];



//RIGHT



    clip[ 0 ].x = 0;

    clip[ 0 ].y = 0;

    clip[ 0 ].w = SHEET_WIDTH/4;

    clip[ 0 ].h = SHEET_HEIGHT/4;

    clip[ 1 ].x = SHEET_WIDTH/4;

    clip[ 1 ].y = 0;

    clip[ 1 ].w = SHEET_WIDTH/4;

    clip[ 1 ].h = SHEET_HEIGHT/4;

 



    clip[ 2 ].x =  SHEET_WIDTH/2;

    clip[ 2 ].y = 0;

    clip[ 2 ].w = SHEET_WIDTH/4;

    clip[ 2 ].h = SHEET_HEIGHT/4;

 

    clip[ 3 ].x = 3*(SHEET_WIDTH/4);
    clip[ 3 ].y = 0;

    clip[ 3 ].w = SHEET_WIDTH/4;
    clip[ 3 ].h = SHEET_HEIGHT/4;
   

    clip[4  ].x = 0;
    clip[ 4 ].y = 0;
    clip[ 4 ].w = SHEET_WIDTH/4;
    clip[ 4 ].h = SHEET_HEIGHT/4;
    
// LEFT
    clip[ 5 ].x = 0;
    clip[ 5 ].y =SHEET_HEIGHT/4 ;
    clip[ 5 ].w = SHEET_WIDTH/4;
    clip[ 5 ].h = SHEET_HEIGHT/4+2;
 

    clip[ 6 ].x = SHEET_WIDTH/4;
    clip[ 6 ].y = SHEET_HEIGHT/4;
    clip[ 6 ].w = SHEET_WIDTH/4;
    clip[ 6 ].h = SHEET_HEIGHT/4+2;
 

    clip[ 7 ].x =  SHEET_WIDTH/2;
    clip[ 7 ].y = SHEET_HEIGHT/4;
    clip[ 7 ].w = SHEET_WIDTH/4;
    clip[ 7 ].h = SHEET_HEIGHT/4+2;
 

    clip[ 8 ].x = 3*(SHEET_WIDTH/4);
    clip[ 8 ].y = SHEET_HEIGHT/4;
    clip[ 8 ].w = SHEET_WIDTH/4;
    clip[ 8 ].h = SHEET_HEIGHT/4+2;
     
    clip[9 ].x = 0;
    clip[9 ].y =SHEET_HEIGHT/4 ;
    clip[ 9 ].w = SHEET_WIDTH/4;
    clip[ 9 ].h = SHEET_HEIGHT/4+2;



     
 while (!quitProgram)
    {
 


      
         if(test==0)
          {
         SDL_BlitSurface( sprite,&clip[j], screen,&pos1);
         SDL_Flip(screen);
        
         SDL_Delay(300);
        j++;
         pos1.x+=3;
        if(j>10)
         quitProgram=1;
          }
else if(test==1)
{
   
         SDL_BlitSurface( sprite,&clip[i], screen,&pos);
         SDL_Flip(screen);
         SDL_Delay(300);
        i++;
         pos.x-=3;
        if(i>4)
         quitProgram=1;
}
}
    }
int main ( int argc, char** argv)
{
SDL_Init( SDL_INIT_VIDEO );
SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
 SDL_Surface * = IMG_Load("sprite.png");
 SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
 animation(sprite,screen,130,180,0);	
}




















