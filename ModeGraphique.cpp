#include <SDL.h>
#include <math.h>

// Inclusion de fichiers personnels
#include "parametres_graphiques.h"
#include "Mobile.h"

SDL_Surface* Init_Mode_Graphique( void )
{
SDL_Surface* ecran;
    //=== Initialisations ===..................................................
    // Graphismes
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Impossible d'initialiser le mode graphique: %s\n", SDL_GetError() );
        exit(-1);
    }
    // Création de la fenêtre graphique
    ecran = SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !ecran )
    {
        printf("Impossible de créer la fenêtre graphique : %s\n", SDL_GetError());
        exit(-1);
    }
    return ecran;
}

void Trace_Point( SDL_Surface* ecran, SDL_Rect M, Couleur couleur )
{
    M.w = 2;
    M.h = 2;
    SDL_FillRect(ecran, &M, SDL_MapRGB(ecran->format, couleur.R, couleur.V, couleur.B));
    // Fin du dessin : actualisation
    SDL_Flip(ecran);
}

void Trace_Segment( SDL_Surface* ecran, SDL_Rect A, SDL_Rect B, Couleur couleur )
{
SDL_Rect M;
float a, b;

    if( A.x == B.x)
    {
        M.x = A.x;
        for(M.y=A.y;M.y<=B.y;M.y++)
            Trace_Point(ecran, M, couleur);
        for(M.y=A.y;M.y>=B.y;M.y--)
            Trace_Point(ecran, M, couleur);
    }
    else
    {
        if( A.y == B.y)
        {
            M.y = A.y;
            for(M.x=A.x;M.x<=B.x;M.x++)
                Trace_Point(ecran, M, couleur);
            for(M.x=A.x;M.x>=B.x;M.x--)
                Trace_Point(ecran, M, couleur);
        }
        else
        {
            a = (float)(B.y-A.y)/(B.x-A.x);
            b = A.y - a*A.x;
            for(M.x=A.x;M.x<=B.x;M.x++)
            {
                M.y = a*M.x + b;
                Trace_Point(ecran, M, couleur);
            }
            for(M.x=A.x;M.x>=B.x;M.x--)
            {
                M.y = a*M.x + b;
                Trace_Point(ecran, M, couleur);
            }
            for(M.y=A.y;M.y<=B.y;M.y++)
            {
                M.x = (M.y-b)/a;
                Trace_Point(ecran, M, couleur);
            }
            for(M.y=A.y;M.y>=B.y;M.y--)
            {
                M.x = (M.y-b)/a;
                Trace_Point(ecran, M, couleur);
            }
        }
    }
}

void Trace_Cercle( SDL_Surface* ecran, SDL_Rect C, int R, Couleur couleur )
{
float Theta;
SDL_Rect M;

    for(Theta=0 ;Theta <= 2*M_PI; Theta = Theta + M_PI/180)
    {
        M.x = C.x + R*cos(Theta);
        M.y = C.y + R*sin(Theta);
        Trace_Point( ecran, M, couleur );
    }
}

void Dessine_Fond( SDL_Surface* ecran, SDL_Surface *image )
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = 0;
    position_sprite.y = 0;
    position_image_sprite.w = LARGEUR_ECRAN;
    position_image_sprite.h = HAUTEUR_ECRAN;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}


void Dessine_Vaisseau( SDL_Surface* ecran, SDL_Surface *image, Mobile mobile )
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = mobile.x;
    position_sprite.y = mobile.y;
    position_image_sprite.w = VAISSEAU_TAILLE_LARGEUR;
    position_image_sprite.h = VAISSEAU_TAILLE_HAUTEUR;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, COULEUR_TRANSPARENCE)); // Transparence
    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}

void Dessine_Projectile( SDL_Surface* ecran, SDL_Surface *image, Mobile mobile)
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = mobile.x;
    position_sprite.y = mobile.y;
    position_image_sprite.w = PROJECTILE_TAILLE_LARGEUR;
    position_image_sprite.h = PROJECTILE_TAILLE_HAUTEUR;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, COULEUR_TRANSPARENCE));
    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}

void Dessine_ALIEN1( SDL_Surface* ecran, SDL_Surface *image, Mobile mobile )
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = mobile.x;
    position_sprite.y = mobile.y;
    position_image_sprite.w = ALIEN1_TAILLE_LARGEUR;
    position_image_sprite.h = ALIEN1_TAILLE_HAUTEUR;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, COULEUR_TRANSPARENCE)); // Transparence
    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}

void Dessine_ALIEN2( SDL_Surface* ecran, SDL_Surface *image, Mobile mobile )
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = mobile.x;
    position_sprite.y = mobile.y;
    position_image_sprite.w = ALIEN2_TAILLE_LARGEUR;
    position_image_sprite.h = ALIEN2_TAILLE_HAUTEUR;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, COULEUR_TRANSPARENCE)); // Transparence
    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}

void Dessine_ALIEN3( SDL_Surface* ecran, SDL_Surface *image, Mobile mobile )
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = mobile.x;
    position_sprite.y = mobile.y;
    position_image_sprite.w = ALIEN3_TAILLE_LARGEUR;
    position_image_sprite.h = ALIEN3_TAILLE_HAUTEUR;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, COULEUR_TRANSPARENCE)); // Transparence
    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}

void Dessine_ALIEN4( SDL_Surface* ecran, SDL_Surface *image, Mobile mobile )
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = mobile.x;
    position_sprite.y = mobile.y;
    position_image_sprite.w = ALIEN4_TAILLE_LARGEUR;
    position_image_sprite.h = ALIEN4_TAILLE_HAUTEUR;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, COULEUR_TRANSPARENCE)); // Transparence
    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}

void Dessine_ALIEN5( SDL_Surface* ecran, SDL_Surface *image, Mobile mobile )
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = mobile.x;
    position_sprite.y = mobile.y;
    position_image_sprite.w = ALIEN5_TAILLE_LARGEUR;
    position_image_sprite.h = ALIEN5_TAILLE_HAUTEUR;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, COULEUR_TRANSPARENCE)); // Transparence
    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}

void Dessine_ALIEN6( SDL_Surface* ecran, SDL_Surface *image, Mobile mobile )
{
SDL_Rect position_image_sprite, position_sprite;

    position_sprite.x = mobile.x;
    position_sprite.y = mobile.y;
    position_image_sprite.w = ALIEN6_TAILLE_LARGEUR;
    position_image_sprite.h = ALIEN6_TAILLE_HAUTEUR;
    position_image_sprite.x = 0;
    position_image_sprite.y = 0;

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, COULEUR_TRANSPARENCE)); // Transparence
    SDL_BlitSurface(image, &position_image_sprite, ecran, &position_sprite);
}
