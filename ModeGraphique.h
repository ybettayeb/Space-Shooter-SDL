#ifndef MODE_GRAPHIQUE_H
#define MODE_GRAPHIQUE_H

#include <SDL.h>
#include "parametres_graphiques.h"
#include "Mobile.h"

SDL_Surface* Init_Mode_Graphique( void );
void Trace_Point( SDL_Surface* ecran, SDL_Rect M, Couleur couleur );

void Trace_Segment( SDL_Surface* ecran, SDL_Rect A, SDL_Rect B, Couleur );
void Trace_Cercle( SDL_Surface* ecran, SDL_Rect C, int R, Couleur );

void Dessine_Fond( SDL_Surface* ecran, SDL_Surface *fond );
void Dessine_Vaisseau( SDL_Surface* ecran, SDL_Surface *image, Mobile);
void Dessine_Projectile( SDL_Surface* ecran, SDL_Surface *image, Mobile);
void Dessine_ALIEN( SDL_Surface* ecran, SDL_Surface *image, Alien);
void Dessine_ALIEN2( SDL_Surface* ecran, SDL_Surface *image, Mobile);
void Dessine_ALIEN3( SDL_Surface* ecran, SDL_Surface *image, Mobile);
void Dessine_ALIEN4( SDL_Surface* ecran, SDL_Surface *image, Mobile);
void Dessine_ALIEN5( SDL_Surface* ecran, SDL_Surface *image, Mobile);
void Dessine_ALIEN6( SDL_Surface* ecran, SDL_Surface *image, Mobile);
#endif
