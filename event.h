/*
Gère les différents évènements du jeu comme le mouvement des personnages et des ennemies, les collisions, le scroll de la map
et si le niveau est fini (win et loose). 
*/
//Anotation Faiz:
#ifndef DEF_EVENT
#define DEF_EVENT
    
    #include "file.h"
    #include "charactere.h"

    void deplacement(Map* map, Personnage* mario, Sprites* imageDecors, Personnage** goombas, int nbGoomba);
    int collisionHautBas(Map* map, SDL_Rect perso, Sprites* imageDecors);
    int collisionDecor(Map* map, SDL_Rect perso, Sprites* imageDecors, Personnage* mario);
    int sortiDecors(Map* map, SDL_Rect perso);
    void mapScroll(Map* map, Personnage* mario);
    int niveauFini(SDL_Renderer *renderer, Personnage *mario);
    int getDirection(SDL_Event *event);
    
#endif