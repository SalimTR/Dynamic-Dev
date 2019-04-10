#include "enemy.h"

#define LARGEUR 1280
#define HAUTEUR 705
#define bpp 32

void deplacement(int direction,SDL_Rect *pos);

int main()
{   SDL_Init(SDL_INIT_EVERYTHING);
    ennemie E;
    char image_name[20]="./assets/pics/1.png";
    E.image=NULL;
    SDL_Surface *screen = NULL, *background=NULL;
    SDL_Event event;
    SDL_Rect background_Rect;
    //varGameLoop /        VarsOfFPS        / VarPosImage
    int ProgRun=1,now=0,ex=0,periodFPS=33,dt=0,x,y;
    int direction=1;
    screen=SDL_SetVideoMode(LARGEUR,HAUTEUR,bpp,SDL_HWSURFACE| SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Ennemie",NULL);
    //Initialisation background:
    SDL_Surface* tmp=NULL;
    tmp=IMG_Load("./assets/pics/background.bmp");
    background=SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    background_Rect.y=HAUTEUR/4;
    //fin init background:

    //affichage background:
  	SDL_BlitSurface(background,NULL,screen,&background_Rect);
    SDL_Flip(screen);

    //Initialisation ennemie:
    Initialiser_Ennemie(&E,screen,image_name);
    //GameLOOP:
    while(ProgRun)
       {
	 	 now=SDL_GetTicks();
		 dt=now-ex;
         if(dt>periodFPS){
            SDL_PollEvent(&event);
            switch(event.type)
	        {
	           case SDL_QUIT:
	           ProgRun=0;
	           break;
	           case SDL_KEYDOWN:
	           switch(event.key.keysym.sym)
		       {
			   case SDLK_ESCAPE:
		       	   ProgRun=0;
			   break;
			   }
	           break;
	           case SDL_KEYUP:
	           break;
	           default:
	           break;
			}
        deplacement(direction,&E.PositionImage);
        if(E.PositionImage.x==590)
            direction=2;
        if(E.PositionImage.x==10)
            direction=1;
			SDL_FillRect(screen,NULL,0);
		   	SDL_BlitSurface(background,NULL,screen,&background_Rect);    		
            Afficher_Ennemie(&E,screen);
            SDL_Flip(screen);
    	 	ex=now;}
	else SDL_Delay(periodFPS-dt);
    	}
    //Fonction FREE:
    SDL_FreeSurface(background);
    SDL_FreeSurface(E.image);

    SDL_Quit();
    return EXIT_SUCCESS;
}
void deplacement(int direction,SDL_Rect *pos)
{
if(direction==1)
    pos->x++;
else
    pos->x--;
}