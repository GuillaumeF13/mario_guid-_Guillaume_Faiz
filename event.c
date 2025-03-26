#include "event.h"

void mapScroll(Map* map, Personnage* mario)
{
	
}


void deplacement(Map* map, Personnage* mario, Sprites* imageDecors, Personnage** goombas, int nbGoomba) {
    //on effectue les modifications dans un carré temporaire, si il n'y a pas de collision, on change la position de Mario.
    
}


/* Regarde si le personnage sort du décors, renvoie 1 si il sort à droite/gauche/haut, 
-1 si il sort en bas (condition de défaite) et 0 sinon
*/
int sortiDecors(Map* map, SDL_Rect perso) {
    
    return 0;
}

/*Regarde si il n'y a pas de sol en desous ou au dessus (title qu'on ne peut pas traverser),
retourne 1 si il y a un obstacle au dessus, -1 si en dessous, sinon retourne 0 */
int collisionHautBas(Map* map, SDL_Rect perso, Sprites* imageDecors) {
    
    return 0;   
}



//retourne 1 si il y a une collision entre le perso et le décor, et 0 si non
int collisionDecor(Map* map, SDL_Rect perso, Sprites* imageDecors, Personnage* mario) {
    //Vous pouvez utiliser SDL_HasIntersection pour voir si il y a une intersection avec le décors
	
	
    return 0;
}

int niveauFini(SDL_Renderer *renderer, Personnage *mario){
    int continuer = 1;
    SDL_Event event;

    
    return continuer;
}