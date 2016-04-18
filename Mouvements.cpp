#include <SDL.h>
#include "Mobile.h"
#include <math.h>
Mobile vaisseau, projectile, ALIEN1, ALIEN2, ALIEN3, ALIEN4, ALIEN5, ALIEN6;
int Max = 1024;
int  Min = 0;
void Init_Vaisseau(void)
{
    vaisseau.x = 512;
    vaisseau.y = 600;
    vaisseau.vx = 0;
    vaisseau.vy = 0;

}

void Init_Projectile(void)
{
    projectile.x = 512;
    projectile.y = 600;
    projectile.vx = 0;
    projectile.vy = 0;
}

void Init_ALIEN1 (void) /* en haut droite */
{

    ALIEN1.x = rand()%(Max - Min)+Min;
    ALIEN1.y = -25;
    ALIEN1.vx= 0;
    ALIEN1.vy= 3;

}

void Init_ALIEN2 (void) /* en haut milieu */
{

    ALIEN2.x = rand()%(Max  -Min)+Min;
    ALIEN2.y = -125;
    ALIEN2.vx= 0;
    ALIEN2.vy= 3;

}

void Init_ALIEN3 (void) /* en haut gauche */
{
    ALIEN3.x = rand()%(Max  -Min)+Min;
    ALIEN3.y = 0;
    ALIEN3.vx= 0;
    ALIEN3.vy= 3;

}

void Init_ALIEN4 (void) /* en bas gauche */
{
    ALIEN4.x = rand()%(Max  -Min)+Min;
    ALIEN4.y = -9;
    ALIEN4.vx= 0;
    ALIEN4.vy= 3;
}

void Init_ALIEN5 (void) /* en bas milieu */
{
    ALIEN5.x = rand()%(Max  -Min)+Min;
    ALIEN5.y = -7;
    ALIEN5.vx= 0;
    ALIEN5.vy= 3;
}

void Init_ALIEN6 (void) /* en bas droite */
{
    ALIEN6.x = rand()%(Max  -Min)+Min;
    ALIEN6.y = -10;
    ALIEN6.vx= 0;
    ALIEN6.vy= 3;
}


void Gestion_Mvt(void)
{
SDL_Event event;

    while (SDL_PollEvent(&event))   // On boucle tant qu'il reste des événements à gérer
    {
        switch (event.type)   // Traitement selon le type d'événement
        {
        case SDL_KEYDOWN: // Une touche du clavier a été enfoncée
            switch (event.key.keysym.sym)   // Traitement selon la touche appuyée
            {
            case SDLK_RIGHT: // Flèche vers la droite
                vaisseau.vx = 4;
                if (vaisseau.x > 970)
                vaisseau.vx = 0;
                if (projectile.y > 970)
                projectile.x = vaisseau.x;

                break;
            case SDLK_LEFT: // Flèche vers la gauche
                vaisseau.vx = -4;
                if (vaisseau.x < 0)
                vaisseau.vx = 0;

                break;
            case SDLK_SPACE: // Espace pour tirer
                projectile.vy = -15;

                break;
            default:
                    // Rien à faire par défaut, mais on évite les "warnings du compilateur"
                break;
            }
            break;
        case SDL_KEYUP: // Une touche du clavier a été relâchée
            switch (event.key.keysym.sym)   // Traitement selon la touche appuyée
            {
            case SDLK_RIGHT: // Flèche vers la droite
                vaisseau.vx = 0;
                break;
            case SDLK_LEFT: // Flèche vers la gauche
                vaisseau.vx = 0;
                break;
            case SDLK_DOWN: // Flèche vers le bas

                break;

            default:
                // Rien à faire par défaut, mais on évite les "warnings du compilateur"
                break;
            }
            break;
        } // Fin de traitement selon le type d'événement
    } // Fin du traitement des événements

// Gestion du mouvement de la vaisseau
{
    vaisseau.x = vaisseau.x + vaisseau.vx;
    vaisseau.y = vaisseau.y + vaisseau.vy;
    if (vaisseau.x > 970)
     vaisseau.vx = 0;
    if (vaisseau.x < 0)
     vaisseau.vx = 0;
}
// Gestion du projectile
{
    projectile.x = projectile.x + projectile.vx;
    projectile.y = projectile.y + projectile.vy;

// Mouvement du projectile

    if (projectile.x > 970)
        projectile.x = vaisseau.x;
    if (projectile.x < 0)
        projectile.x = vaisseau.x;
    if (projectile.y < 0)
        projectile.y = 600, projectile.vy = 0;
    if (projectile.y > 500)
        projectile.x = vaisseau.x;

}
// Contact entre projectiles et aliens.
{
    if (projectile.x < ALIEN1.x +80 && projectile.x > ALIEN1.x -80)
    if (projectile.y == ALIEN1.y)
        ALIEN1.x = 1100, projectile.y = 600, projectile.vy = 0;

    if (projectile.x < ALIEN2.x +80 && projectile.x > ALIEN2.x -80)
    if (projectile.y == ALIEN2.y)
        ALIEN2.x = 1100, projectile.y = 600, projectile.vy = 0;

    if (projectile.x < ALIEN3.x +80 && projectile.x > ALIEN3.x -80)
    if (projectile.y == ALIEN3.y)
        ALIEN3.x = 1100, projectile.y = 600, projectile.vy = 0;

    if (projectile.x < ALIEN4.x +80 && projectile.x > ALIEN4.x -80)
    if (projectile.y == ALIEN4.y)
        ALIEN4.x = 1100, projectile.y = 600, projectile.vy = 0;

    if (projectile.x < ALIEN5.x +80 && projectile.x > ALIEN5.x -80)
    if (projectile.y == ALIEN5.y)
        ALIEN5.x = 1100, projectile.y = 600, projectile.vy = 0;

    if (projectile.x < ALIEN6.x +80 && projectile.x > ALIEN6.x -80)
    if (projectile.y == ALIEN6.y)
        ALIEN6.x = 1100, projectile.y = 600, projectile.vy = 0;
}
// Gestion mouvement alien
{
    ALIEN1.x = ALIEN1.x + ALIEN1.vx;
    ALIEN1.y = ALIEN1.y + ALIEN1.vy;

    ALIEN2.x = ALIEN2.x + ALIEN2.vx;
    ALIEN2.y = ALIEN2.y + ALIEN2.vy;


    ALIEN3.x = ALIEN3.x + ALIEN3.vx;
    ALIEN3.y = ALIEN3.y + ALIEN3.vy;

    ALIEN4.x = ALIEN4.x + ALIEN4.vx;
    ALIEN4.y = ALIEN4.y + ALIEN4.vy;

    ALIEN5.x = ALIEN5.x + ALIEN5.vx;
    ALIEN5.y = ALIEN5.y + ALIEN5.vy;

    ALIEN6.x = ALIEN6.x + ALIEN6.vx;
    ALIEN6.y = ALIEN6.y + ALIEN6.vy;

}

if ( ALIEN1.y >= 740){
    ALIEN1.y = -25;
    ALIEN1.x =rand()%(Max  -Min)+Min;
}
if (ALIEN2.y >= 740){
    ALIEN2.y = -50;
    ALIEN2.x = rand()%(Max  -Min)+Min;
    }

if (ALIEN3.y>= 740){
    ALIEN3.y = -45;
    ALIEN3.x = rand()%(Max  -Min)+Min;
    }

if(ALIEN4.y>=740){
    ALIEN4.y = -70;
    ALIEN4.x = rand()%(Max  -Min)+Min;
    }

if ( ALIEN5.y >=740){
    ALIEN5.y=-90;
    ALIEN5.x =rand()%(Max  -Min)+Min;
    }
if ( ALIEN6.y >=740){

    ALIEN6.y=-178;
    ALIEN6.x = rand()%(Max  -Min)+Min;
}



}




