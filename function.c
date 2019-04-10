#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "function.h"
#ifdef WIN32
#pragma comment(lib,"sdl.lib")
#pragma comment(lib,"sdlmain.lib")
#endif

#define STAT_SOL 0
#define STAT_AIR 1

// Initialisation background
void initialisation_background(SDL_Surface **background,SDL_Rect *positionecran)
{
	*background=IMG_Load("bck.png");
	positionecran->x=0;
	positionecran->y=0; 
       	positionecran->w=1536;
	positionecran->h=768;
}
// Affichage background
void affichage_background(SDL_Surface *ecran,SDL_Surface *background,SDL_Rect positionecran)
{
	SDL_BlitSurface(background, &positionecran, ecran, NULL);
}
// Initialisation player
void initialisation_player(SDL_Surface **test1,SDL_Surface **test2,SDL_Surface **rx,SDL_Surface **r1,SDL_Surface **r2,SDL_Surface **r3,SDL_Surface **r4,SDL_Surface **r5,SDL_Surface **r6,SDL_Surface **r7,SDL_Surface **r8,SDL_Surface **r9,SDL_Surface **r10,SDL_Surface **r11,SDL_Surface **r12,SDL_Surface **ur1,SDL_Surface **ur2,SDL_Surface **ur3,SDL_Surface **ur4,SDL_Surface **ur5,SDL_Surface **ur6,SDL_Surface **ur7,SDL_Surface **ur8,SDL_Surface **ur9,SDL_Surface **ur10,SDL_Surface **ur11,SDL_Surface **ur12,SDL_Rect *rx_pos,SDL_Rect *urx_pos)
{
        *test1=IMG_Load("uRunning/test1.png");
        *test2=IMG_Load("uRunning/test2.png");
        *r1=IMG_Load("Running/1.png");
        *r2=IMG_Load("Running/2.png");
        *r3=IMG_Load("Running/3.png");
        *r4=IMG_Load("Running/4.png");
        *r5=IMG_Load("Running/5.png");
        *r6=IMG_Load("Running/6.png");
        *ur1=IMG_Load("uRunning/1.png");
        *ur2=IMG_Load("uRunning/2.png");
        *ur3=IMG_Load("uRunning/3.png");
        *ur4=IMG_Load("uRunning/4.png");
        *ur5=IMG_Load("uRunning/5.png");
        *ur6=IMG_Load("uRunning/6.png");
	*rx=*r1;
	rx_pos->x=200;
        rx_pos->y=300;
	urx_pos->x=0;
        urx_pos->y=400;
}
// Affichage player
void affichage_player(SDL_Surface *test1,SDL_Surface *test2,SDL_Surface *ecran,SDL_Surface *rx,SDL_Surface *urx,SDL_Rect rx_pos,SDL_Rect urx_pos,int run)
{
	if(run==1)
	{
	SDL_BlitSurface(urx, NULL, ecran, &rx_pos);
	}
	else if (run==2)
	{
	SDL_BlitSurface(rx, NULL, ecran, &rx_pos);
	}
	else if (run==3)
	{
	SDL_BlitSurface(test1, NULL, ecran, &rx_pos);
	}
	else if (run==0)
	{
	SDL_BlitSurface(test1, NULL, ecran, &rx_pos);
        //SDL_Delay(300);
	SDL_Flip(ecran);
	SDL_BlitSurface(test2, NULL, ecran, &rx_pos);
	//SDL_Flip(ecran);
	}
}
// Initialisation box
void initialisation_box(SDL_Surface **box,SDL_Rect *positionbox)
{
	*box=IMG_Load("objets/wood_box.png");
	positionbox->x=1000;
	positionbox->y=430;
}
// Initialisation coin
void initialisation_coin(SDL_Surface **coin,SDL_Rect *positioncoin)
{
	*coin=IMG_Load("objets/coin.png");
	positioncoin->x=1300;
	positioncoin->y=515;
}
// Affichage image
void affichage_img(SDL_Surface *ecran,SDL_Surface *image,SDL_Rect positionimg)
{
	SDL_BlitSurface(image, NULL, ecran, &positionimg);
}
// Colision Trigo
float carree(float x)
{
	return x*x;
}
int trigooo(SDL_Rect pA,SDL_Surface *A,SDL_Rect pB,SDL_Surface *B)
{
	float AB,MA,MB;
	MA = A->h/2;
	MB = B->h/2;
	AB = sqrt(carree(pA.x+(A->w/2) - (pB.x+(B->w/2))) + carree(pA.y+(A->h/2) - (pB.y+(B->h/2))));
	if (AB <= (MA+MB))
		return 1;
	else 
		return 0;
}
// Initialisation image
SDL_Rect initialiser_img(int x,int y,SDL_Surface **image,char *imagename)
{
	*image=IMG_Load(imagename);
	SDL_Rect positionimg;
	positionimg.x=x;
	positionimg.y=y;
return positionimg;
}
// Banding box
int bounding_box(SDL_Surface *obj1,SDL_Rect position_obj1,SDL_Surface *obj2,SDL_Rect position_obj2)
{
int top1,top2;
int bottom1,bottom2;
int left1,left2;
int right1,right2;

int k=0;

top1=position_obj1.y;bottom1=top1+obj1->h;
top2=position_obj2.y;bottom2=top2+obj2->h;
left1=position_obj1.x;right1=left1+obj1->w;
left2=position_obj2.x;right2=left2+obj2->w;

if( bottom1 < top2 )
    {
	k=1;
        return(k);
    }
 
    if( top1 < bottom2 )
    {
	k=1;
        return(k);
    }
 
    if( right1 > left2 )
    {
	k=1;
        return(k);
    }
    if( left1 < right2 )
    {
	k=1;
        return(k);
    }
return(k);
}
































/*
void Evolue(Sprite* Sp,SDL_Event keys)
{
	float lateralspeed = 0.5f;
	float airlateralspeedfacteur = 1.0f;
	float maxhspeed = 3.0f;
	float adherance = 1.5f;
	float impulsion = 6.0f;
	float factgravite = 0.5f;
	float factsautmaintenu = 3.0f;
// controle lateral
	if (Sp->status == STAT_AIR) // (*2)
		lateralspeed*= airlateralspeedfacteur;
switch(keys.type)
{
case SDL_KEYDOWN:

	if (keys.key.keysym.sym ==SDLK_q) // (*1)
		Sp->vx-=lateralspeed;
	if (keys.key.keysym.sym ==SDLK_d) // (*1)
		Sp->vx+=lateralspeed;
	if (Sp->status == STAT_SOL && !(keys.key.keysym.sym ==SDLK_q) && !(keys.key.keysym.sym ==SDLK_d)) // (*3)
		Sp->vx/=adherance;
// limite vitesse
	if (Sp->vx>maxhspeed) // (*4)
		Sp->vx = maxhspeed;
	if (Sp->vx<-maxhspeed)
		Sp->vx = -maxhspeed;
// saut
	if ((keys.key.keysym.sym ==SDLK_SPACE) && Sp->status == STAT_SOL)
		Saute(Sp,impulsion);
}

	Gravite(Sp,factgravite,factsautmaintenu,keys);
	ControleSol(Sp);
// application du vecteur à la position.
	Sp->x +=Sp->vx;
	Sp->y +=Sp->vy;
}*/
