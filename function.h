#ifndef TRIGO_H_INCLUDED
#define TRIGO_H_INCLUDED

void initialisation_background(SDL_Surface **background,SDL_Rect *positionecran);
void affichage_background(SDL_Surface *ecran,SDL_Surface *background,SDL_Rect positionecran);
void initialisation_player(SDL_Surface **test1,SDL_Surface **test2,SDL_Surface **rx,SDL_Surface **r1,SDL_Surface **r2,SDL_Surface **r3,SDL_Surface **r4,SDL_Surface **r5,SDL_Surface **r6,SDL_Surface **r7,SDL_Surface **r8,SDL_Surface **r9,SDL_Surface **r10,SDL_Surface **r11,SDL_Surface **r12,SDL_Surface **ur1,SDL_Surface **ur2,SDL_Surface **ur3,SDL_Surface **ur4,SDL_Surface **ur5,SDL_Surface **ur6,SDL_Surface **ur7,SDL_Surface **ur8,SDL_Surface **ur9,SDL_Surface **ur10,SDL_Surface **ur11,SDL_Surface **ur12,SDL_Rect *rx_pos,SDL_Rect *urx_pos);
void affichage_player(SDL_Surface *test1,SDL_Surface *test2,SDL_Surface *ecran,SDL_Surface *rx,SDL_Surface *urx,SDL_Rect rx_pos,SDL_Rect urx_pos,int run);
void initialisation_box(SDL_Surface **box,SDL_Rect *positionbox);
void affichage_img(SDL_Surface *ecran,SDL_Surface *image,SDL_Rect positionimg);
void initialisation_coin(SDL_Surface **coin,SDL_Rect *positioncoin);
//void affichage_box(SDL_Surface *ecran,SDL_Surface *coin,SDL_Rect positioncoin);	
int trigooo(SDL_Rect pA,SDL_Surface *A,SDL_Rect pB,SDL_Surface *B);
SDL_Rect initialiser_img(int x,int y,SDL_Surface **image,char *imagename);
int bounding_box(SDL_Surface *obj1,SDL_Rect position_obj1,SDL_Surface *obj2,SDL_Rect position_obj2);

#endif
