// Inclusions de bibliothèques
#include <stdlib.h>
#include <SDL.h>
#include <math.h>
// Inclusion de fichiers personnels
#include "ModeGraphique.h"
#include "Mobile.h"
#include "Mouvements.h"
int i;
extern Mobile vaisseau, projectile; //ALIEN1, ALIEN2, ALIEN3, ALIEN4, ALIEN5, ALIEN6;
extern Alien ALIEN;

//=============================================================================
int main ( int argc, char** argv )
{
SDL_Surface *ecran;
SDL_Surface *image_vaisseau, *image_terrain, *image_projectile, *image_ALIEN; // *image_ALIEN2, *image_ALIEN3,*image_ALIEN4, *image_ALIEN5, *image_ALIEN6;

    ecran = Init_Mode_Graphique();

    // Charge l'image du fond d'écran
    image_terrain = SDL_LoadBMP("Space.bmp");

    // Charge l'image de la vaisseau
    Init_Vaisseau();
    // Charge l'image du projectile
    Init_Projectile();
    // Charge l'image de l'Alien1
    for (i=0; i< 5; i++)
        Init_ALIEN();
    }
    // Charge l'image de l'Alien2
    /*Init_ALIEN2();
    // Charge l'image de l'Alien3
    Init_ALIEN3();
    // Charge l'image de l'Alien4
    Init_ALIEN4();
    // Charge l'image de l'Alien5
    Init_ALIEN5();
    // Charge l'image de l'Alien6
    Init_ALIEN6();*/
    // Charge l'image de la vaisseau
    image_vaisseau = SDL_LoadBMP("triangle.bmp");
    // Charge l'image du projectile
    image_projectile = SDL_LoadBMP("projectile.bmp");
    //Charge l'image de l'Alien1
    image_ALIEN = SDL_LoadBMP("ALIEN.bmp");
    //Charge l'image de l'Alien2
/*    image_ALIEN2 = SDL_LoadBMP("ALIEN.bmp");
    //Charge l'image de l'Alien3
    image_ALIEN3 = SDL_LoadBMP("ALIEN.bmp");
    //Charge l'image de l'Alien4
    image_ALIEN4 = SDL_LoadBMP("ALIEN.bmp");
    //Charge l'image de l'Alien5
    image_ALIEN5 = SDL_LoadBMP("ALIEN.bmp");
    //Charge l'image de l'Alien6
    image_ALIEN6 = SDL_LoadBMP("ALIEN.bmp");*/


    // Répétition de touche enfoncée
    SDL_EnableKeyRepeat(1, 200);

    //=== Boucle principale du programme ===...................................
    while (1)
    {
        //--- Gestion des événements ---
        Gestion_Mvt();
        // Affichage
        Dessine_Fond( ecran, image_terrain );
        Dessine_Vaisseau( ecran, image_vaisseau, vaisseau );
        Dessine_Projectile( ecran, image_projectile, projectile);
        Dessine_ALIEN ( ecran, image_ALIEN, ALIEN);
       /* Dessine_ALIEN2 ( ecran, image_ALIEN2, ALIEN2);
        Dessine_ALIEN3 ( ecran, image_ALIEN3, ALIEN3);
        Dessine_ALIEN4 ( ecran, image_ALIEN4, ALIEN4);
        Dessine_ALIEN5 ( ecran, image_ALIEN5, ALIEN5);
        Dessine_ALIEN6 ( ecran, image_ALIEN6, ALIEN6);*/
        // Fin du dessin : actualisation
        SDL_Flip(ecran);

        // Temporisation
        SDL_Delay(5);

    }

    // Fermeture de la bibliothèque
    SDL_Quit();
    return 0;
}
