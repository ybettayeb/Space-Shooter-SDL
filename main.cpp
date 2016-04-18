// Inclusions de biblioth�ques
#include <stdlib.h>
#include <SDL.h>
#include <math.h>

// Inclusion de fichiers personnels
#include "ModeGraphique.h"
#include "Mobile.h"
#include "Mouvements.h"

extern Mobile vaisseau, projectile, ALIEN1, ALIEN2, ALIEN3, ALIEN4, ALIEN5, ALIEN6;

//=============================================================================
int main ( int argc, char** argv )
{
SDL_Surface *ecran;
SDL_Surface *image_vaisseau, *image_terrain, *image_projectile, *image_ALIEN1, *image_ALIEN2, *image_ALIEN3,*image_ALIEN4, *image_ALIEN5, *image_ALIEN6;

    ecran = Init_Mode_Graphique();

    // Charge l'image du fond d'�cran
    image_terrain = SDL_LoadBMP("moment-in-space-cvi.bmp");

    // Charge l'image de la vaisseau
    Init_Vaisseau();
    // Charge l'image du projectile
    Init_Projectile();
    // Charge l'image de l'Alien1
    Init_ALIEN1();
    // Charge l'image de l'Alien2
    Init_ALIEN2();
    // Charge l'image de l'Alien3
    Init_ALIEN3();
    // Charge l'image de l'Alien4
    Init_ALIEN4();
    // Charge l'image de l'Alien5
    Init_ALIEN5();
    // Charge l'image de l'Alien6
    Init_ALIEN6();
    // Charge l'image de la vaisseau
    image_vaisseau = SDL_LoadBMP("rsz_playership1_blue.bmp");
    // Charge l'image du projectile
    image_projectile = SDL_LoadBMP("laserBlue03.bmp");
    //Charge l'image de l'Alien1
    image_ALIEN1 = SDL_LoadBMP("rsz_enemyblack2.bmp");
    //Charge l'image de l'Alien2
    image_ALIEN2 = SDL_LoadBMP("rsz_enemyblack2.bmp");
    //Charge l'image de l'Alien3
    image_ALIEN3 = SDL_LoadBMP("rsz_enemyblack2.bmp");
    //Charge l'image de l'Alien4
    image_ALIEN4 = SDL_LoadBMP("rsz_enemyblack2.bmp");
    //Charge l'image de l'Alien5
    image_ALIEN5 = SDL_LoadBMP("rsz_enemyblack2.bmp");
    //Charge l'image de l'Alien6
    image_ALIEN6 = SDL_LoadBMP("rsz_enemyblack2.bmp");


    // R�p�tition de touche enfonc�e
    SDL_EnableKeyRepeat(1, 200);

    //=== Boucle principale du programme ===...................................
    while (1)
    {
        //--- Gestion des �v�nements ---
        Gestion_Mvt();
        // Affichage
        Dessine_Fond( ecran, image_terrain );
        Dessine_Vaisseau( ecran, image_vaisseau, vaisseau );
        Dessine_Projectile( ecran, image_projectile, projectile);
        Dessine_ALIEN1 ( ecran, image_ALIEN1, ALIEN1);
        Dessine_ALIEN2 ( ecran, image_ALIEN2, ALIEN2);
        Dessine_ALIEN3 ( ecran, image_ALIEN3, ALIEN3);
        Dessine_ALIEN4 ( ecran, image_ALIEN4, ALIEN4);
        Dessine_ALIEN5 ( ecran, image_ALIEN5, ALIEN5);
        Dessine_ALIEN6 ( ecran, image_ALIEN6, ALIEN6);
        // Fin du dessin : actualisation
        SDL_Flip(ecran);

        // Temporisation
        SDL_Delay(1);

    }


    // Fermeture de la biblioth�que
    SDL_Quit();
    return 0;
}
