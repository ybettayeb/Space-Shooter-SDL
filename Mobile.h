#ifndef MOBILE_H
#define MOBILE_H

#define VAISSEAU_TAILLE_LARGEUR          50
#define VAISSEAU_TAILLE_HAUTEUR          50
#define VAISSEAU_VITESSE_BASE_X          0
#define VAISSEAU_VITESSE_BASE_Y          0

#define PROJECTILE_TAILLE_LARGEUR        50
#define PROJECTILE_TAILLE_HAUTEUR        50
#define PROJECTILE_VITESSE_BASE_X        0
#define PROJECTILE_VITESSE_BASE_Y        1

#define ALIEN_TAILLE_LARGEUR            50
#define ALIEN_TAILLE_HAUTEUR            50
#define ALIEN_VITESSE_BASE_X            1
#define ALIEN_VITESSE_BASE_Y            1

#define ALIEN2_TAILLE_LARGEUR            50
#define ALIEN2_TAILLE_HAUTEUR            50
#define ALIEN2_VITESSE_BASE_X            1
#define ALIEN2_VITESSE_BASE_Y            1

#define ALIEN3_TAILLE_LARGEUR            50
#define ALIEN3_TAILLE_HAUTEUR            50
#define ALIEN3_VITESSE_BASE_X            1
#define ALIEN3_VITESSE_BASE_Y            1

#define ALIEN4_TAILLE_LARGEUR            50
#define ALIEN4_TAILLE_HAUTEUR            50
#define ALIEN4_VITESSE_BASE_X            1
#define ALIEN4_VITESSE_BASE_Y            1

#define ALIEN5_TAILLE_LARGEUR            50
#define ALIEN5_TAILLE_HAUTEUR            50
#define ALIEN5_VITESSE_BASE_X            1
#define ALIEN5_VITESSE_BASE_Y            1

#define ALIEN6_TAILLE_LARGEUR            50
#define ALIEN6_TAILLE_HAUTEUR            50
#define ALIEN6_VITESSE_BASE_X            1
#define ALIEN6_VITESSE_BASE_Y            1

typedef struct _mobile {
    float x, y;     // Coordonnées haut-gauche
    float vx, vy;   // Vitesses
} Mobile;

typedef struct _Alien {
    float x, y;
    float vx, vy;
    int n;

} Alien;



#endif
