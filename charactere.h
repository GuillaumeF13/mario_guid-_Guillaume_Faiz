/*
Contient la création du charactère (mario) et les divers caractéristique qui le compose, pareil pour les monstres.
Va aussi gérer l'affichage des personnages et mosntres. 
Attention la map doit déjà être chargé avant de créer un charactère. 
*/

#ifndef DEF_CHARACTERE
#define DEF_CHARACTERE
    
    #include <src/include/SDL2/SDL.h>
    #include "file.h"

    #define WIDTH_MARIO 30 //largeur des images mario
    #define HEIGHT_MARIO 40 //hauteur des images mario
    #define NUMBER_IMAGE_MARIO 6 //nombre d'image de mario en tout

    typedef struct Personnage Personnage;
    struct Personnage
    {
        SDL_Texture** image; //contient toutes les images nécessaire pour mario (différentes direction et saut)
        SDL_Rect position; //sa position à l'instant t
        int jump; //Si mario saute lors de la montée du saut jump = 1, sinon 0
        int jumptime; //correspond à la durée depuis quand mario fait un saut, à 70 on arrête
        int gravite; //vaut 1 si mario est dans les air, 0 sinon. 
        int direction, dernieredirection; //direction vers laquelle est dirigé mario, 1 : droite, 2 : gauche, 0 : statique) 
        int temp; //permet de faire varier les sprites de mario dans le temps.
        int win; //vaut 1 si le personnage gagne, -1 si il perd, 0 sinon. 
        int invisible; //utilisé pour les goombas quand il meurt vaut 1 dans ce cas, 0 si en vit.
        int lvl, lvlperdu;
    };

    void chargerMario(Personnage* mario, Map* map, SDL_Renderer *renderer);
    void afficherPerso(Personnage* mario, int xscroll, int yscroll , SDL_Renderer *renderer);
    int chooseSpriteMovement(Personnage* mario, int numero1, int numero2);
    void freePersonnage(Personnage* mario, Personnage **goomba, int nbGoomba);
    
#endif