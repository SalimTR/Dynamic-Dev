#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include <time.h> 
#include <unistd.h>
#include "function.h"
#include "fgifsdl.h"

int main()
{
    const unsigned int windowWidth = 1900;
    const unsigned int windowHeight = 3900;

	// ------------------Declaration image_names------------------//

		SDL_Surface *new,*ecran=NULL,*background=NULL,*gestion=NULL,*flor=NULL;
		SDL_Surface *box=NULL,*hit=NULL;
		SDL_Surface *rock=NULL;
		SDL_Surface *coin1=NULL,*coin2=NULL,*coin3=NULL,*coin4=NULL,*coin5=NULL,*coin6=NULL,*coin7=NULL,*coin8=NULL,*coin9=NULL,*coin10=NULL,*coin11=NULL,*coin12=NULL,*coin13=NULL,*coin14=NULL,*coin15=NULL,*coin16=NULL,*coin17=NULL,*coin18=NULL;
		SDL_Surface *key=NULL,*gkey=NULL;
		SDL_Surface *cactus1=NULL,*cactus2=NULL,*cactus3=NULL,*cactus4=NULL;
		SDL_Surface *heart3=NULL,*heart2=NULL,*heart1=NULL,*heart0=NULL;
		SDL_Surface *r1=NULL,*r2=NULL,*r3=NULL,*r4=NULL,*r5=NULL,*r6=NULL,*r7=NULL,*r8=NULL,*r9=NULL,*r10=NULL,*r11=NULL,*r12=NULL,*rx=NULL,*test1=NULL,*test2=NULL;
		SDL_Surface *ur1=NULL,*ur2=NULL,*ur3=NULL,*ur4=NULL,*ur5=NULL,*ur6=NULL,*ur7=NULL,*ur8=NULL,*ur9=NULL,*ur10=NULL,*ur11=NULL,*ur12=NULL,*urx=NULL;

	// ------------------Declaration image_positions------------------//

		SDL_Rect positionecran,rx_pos,urx_pos,positiongestion,positionflor;
		SDL_Rect positionbox;
		SDL_Rect positionrock;
		SDL_Rect positionkey,positiongkey;
		SDL_Rect positioncactus1,positioncactus2,positioncactus3,positioncactus4;
		SDL_Rect positionheart3,positionheart2,positionheart1,positionheart0;
		SDL_Rect positioncoin1,positioncoin2,positioncoin3,positioncoin4,positioncoin5,positioncoin6,positioncoin7,positioncoin8,positioncoin9,positioncoin10,positioncoin11,positioncoin12,positioncoin13,positioncoin14,positioncoin15,positioncoin16,positioncoin17,positioncoin18;

	// ------------------Declaration events------------------//

		SDL_Event event;

	// ------------------Declaration variables------------------//

		int continuer=1;
		int x,y,i=0,j=0,run=0,ht=0;
		int pl,bx,R,G,B;

	// ------------------Declaration music et son------------------//

		Mix_Music *music;
		Mix_Chunk *son;

	// ------------------Initialisatis des images------------------//
	
		initialisation_background(&background,&positionecran);
		initialisation_player(&test1,&test2,&rx,&r1,&r2,&r3,&r4,&r5,&r6,&r7,&r8,&r9,&r10,&r11,&r12,&ur1,&ur2,&ur3,&ur4,&ur5,&ur6,&r7,&ur8,&ur9,&ur10,&ur11,&ur12,&rx_pos,&urx_pos);
		positionbox=initialiser_img(4400,430,&box,"objets/wood_box.png");
		positioncoin1=initialiser_img(1000,500,&coin1,"objets/coin.png");
		positioncoin2=initialiser_img(1200,500,&coin2,"objets/coin.png");
		positioncoin3=initialiser_img(1400,500,&coin3,"objets/coin.png");
		positioncoin4=initialiser_img(1600,500,&coin4,"objets/coin.png");
		positioncoin5=initialiser_img(1800,500,&coin5,"objets/coin.png");
		positioncoin6=initialiser_img(2000,500,&coin6,"objets/coin.png");
		positioncoin7=initialiser_img(2800,500,&coin7,"objets/coin.png");
		positioncoin8=initialiser_img(3000,500,&coin8,"objets/coin.png");
		positioncoin9=initialiser_img(3200,500,&coin9,"objets/coin.png");
		positioncoin10=initialiser_img(3800,500,&coin10,"objets/coin.png");
		positioncoin11=initialiser_img(4000,500,&coin11,"objets/coin.png");
		positioncoin12=initialiser_img(4200,500,&coin12,"objets/coin.png");
		positioncoin13=initialiser_img(5100,100,&coin13,"objets/coin.png");
		positioncoin14=initialiser_img(5200,100,&coin14,"objets/coin.png");
		positioncoin15=initialiser_img(5300,100,&coin15,"objets/coin.png");
		positioncoin16=initialiser_img(5500,500,&coin16,"objets/coin.png");
		positioncoin17=initialiser_img(5600,500,&coin17,"objets/coin.png");
		positioncoin18=initialiser_img(5700,500,&coin18,"objets/coin.png");
		positiongestion=initialiser_img(10,10,&gestion,"objets/gestion.png");
		positionheart3=initialiser_img(1200,20,&heart3,"objets/heart3.png");
		positionheart2=initialiser_img(1200,20,&heart2,"objets/heart2.png");
		positionheart1=initialiser_img(1200,20,&heart1,"objets/heart1.png");
		positionheart0=initialiser_img(1200,20,&heart0,"objets/heart0.png");
		positioncactus1=initialiser_img(2400,400,&cactus1,"objets/cactus1.png");
		positioncactus2=initialiser_img(5900,390,&cactus2,"objets/cactus2.png");
		positioncactus3=initialiser_img(6400,420,&cactus3,"objets/cactus3.png");
		positioncactus4=initialiser_img(6800,400,&cactus4,"objets/cactus4.png");
		positionflor=initialiser_img(5000,200,&flor,"objets/flor.png");
        	hit=IMG_Load("Running/hit.png");
	
	// ------------------Start Section------------------//	

		SDL_Init(SDL_INIT_VIDEO);
	    	ecran = SDL_SetVideoMode(1536, 768, 32, SDL_HWSURFACE );
	

	


 SDL_EnableKeyRepeat(10, 10);
while(continuer)
{
run=0;
SDL_PollEvent(&event);
SDL_GetMouseState(&x,&y);
switch(event.type)
{
case SDL_QUIT:
continuer = 1;
break;

case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{case SDLK_ESCAPE://appuyer sur echap
continuer = 0;
break;
 case 
SDLK_LEFT:
if(j%6==0)
{urx=ur1;}
else if(j%6==1)
{urx=ur2;}
else if(j%6==2)
{urx=ur3;}
else if(j%6==3)
{urx=ur4;}
else if(j%6==4)
{urx=ur5;}
else if(j%6==5)
{urx=ur6;}
j++;
run=1;
if(positionecran.x<=0)
positionecran.x=0;
else
{
positionecran.x-=10;
positionbox.x+=10;
positionflor.x+=10;
positioncoin1.x+=10;
positioncoin2.x+=10;
positioncoin3.x+=10;
positioncoin4.x+=10;
positioncoin5.x+=10;
positioncoin6.x+=10;
positioncoin7.x+=10;
positioncoin8.x+=10;
positioncoin9.x+=10;
positioncoin10.x+=10;
positioncoin11.x+=10;
positioncoin12.x+=10;
positioncoin13.x+=10;
positioncoin14.x+=10;
positioncoin15.x+=10;
positioncoin16.x+=10;
positioncoin17.x+=10;
positioncoin18.x+=10;
positioncactus1.x+=10;
positioncactus2.x+=10;
positioncactus3.x+=10;
positioncactus4.x+=10;
}
break;
case
SDLK_RIGHT:
if(i%6==0)
{rx=r1;}
else if(i%6==1)
{rx=r2;}
else if(i%6==2)
{rx=r3;}
else if(i%6==3)
{rx=r4;}
else if(i%6==4)
{rx=r5;}
else if(i%6==5)
{rx=r6;}
i++;
if (rx_pos.x<=400)
{
rx_pos.x+=20;
}
else
{
positionecran.x+=10;
positionbox.x-=10;
positionflor.x-=10;
positioncoin1.x-=10;
positioncoin2.x-=10;
positioncoin3.x-=10;
positioncoin4.x-=10;
positioncoin5.x-=10;
positioncoin6.x-=10;
positioncoin7.x-=10;
positioncoin8.x-=10;
positioncoin9.x-=10;
positioncoin10.x-=10;
positioncoin11.x-=10;
positioncoin12.x-=10;
positioncoin13.x-=10;
positioncoin14.x-=10;
positioncoin15.x-=10;
positioncoin16.x-=10;
positioncoin17.x-=10;
positioncoin18.x-=10;
positioncactus1.x-=10;
positioncactus2.x-=10;
positioncactus3.x-=10;
positioncactus4.x-=10;
}
run=2;
break;
case
SDLK_UP:
	
default:
break;
}
break;
default:
break;}

		R=0;
		G=0;
		B=0;
		if (trigooo(positionbox,box,rx_pos,rx))
		{
			positionbox.x+=10;
			R = 200;
			G = 45;
			B = 69;
		}
		/*if (trigooo(positioncactus1,cactus1,rx_pos,rx))
		{
			ht++;
			if(ht>3){ht=0;}
			rx_pos.x-=50;
		}
		if (trigooo(positioncactus2,cactus2,rx_pos,rx))
		{
			ht++;
			if(ht>3){ht=0;}
			rx_pos.x-=50;
		}
		if (trigooo(positioncactus3,cactus3,rx_pos,rx))
		{
			ht++;
			if(ht>3){ht=0;}
			rx_pos.x-=50;
		}
		if (trigooo(positioncactus4,cactus4,rx_pos,rx))
		{
			ht++;
			if(ht>3){ht=0;}
			rx_pos.x-=50;
		}*/
		if (trigooo(positioncoin1,coin1,rx_pos,rx))
		{
			//coin1=NULL;
		}

	// ------------------Affichage des images------------------//	

		SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,R,G,B));
		affichage_background(ecran,background,positionecran);
		affichage_img(ecran,flor,positionflor);
		affichage_img(ecran,box,positionbox);
		affichage_img(ecran,coin1,positioncoin1);
		affichage_img(ecran,coin2,positioncoin2);
		affichage_img(ecran,coin3,positioncoin3);
		affichage_img(ecran,coin4,positioncoin4);
		affichage_img(ecran,coin5,positioncoin5);
		affichage_img(ecran,coin6,positioncoin6);
		affichage_img(ecran,coin7,positioncoin7);
		affichage_img(ecran,coin8,positioncoin8);
		affichage_img(ecran,coin9,positioncoin9);
		affichage_img(ecran,coin10,positioncoin10);
		affichage_img(ecran,coin11,positioncoin11);
		affichage_img(ecran,coin12,positioncoin12);
		affichage_img(ecran,coin13,positioncoin13);
		affichage_img(ecran,coin14,positioncoin14);
		affichage_img(ecran,coin15,positioncoin15);
		affichage_img(ecran,coin16,positioncoin16);
		affichage_img(ecran,coin17,positioncoin17);
		affichage_img(ecran,coin18,positioncoin18);
		affichage_img(ecran,cactus1,positioncactus1);
		affichage_img(ecran,cactus2,positioncactus2);
		affichage_img(ecran,cactus3,positioncactus3);
		affichage_img(ecran,cactus4,positioncactus4);
		affichage_img(ecran,gestion,positiongestion);
		if (ht==1)
		{
		affichage_img(ecran,heart2,positionheart2);
		SDL_BlitSurface(hit, NULL, ecran, &rx_pos);
		ht=0;
		}
		else
		if (ht==2)
		{
		affichage_img(ecran,heart1,positionheart1);
		SDL_BlitSurface(hit, NULL, ecran, &rx_pos);
		ht=0;
		}
		else
		if (ht==3)
		{
		affichage_img(ecran,heart0,positionheart0);
		SDL_BlitSurface(hit, NULL, ecran, &rx_pos);
		ht=0;
		}
		else
		{affichage_img(ecran,heart3,positionheart3);}
		affichage_player(test1,test2,ecran,rx,urx,rx_pos,urx_pos,run);
		
				SDL_Flip(ecran);
                  SDL_Delay(0);
		printf("%d \t %d \n",x,y);


	}


return 0;

}
