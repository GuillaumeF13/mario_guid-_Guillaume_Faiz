#include <stdlib.h>
#include <stdio.h>

#include "charactere.h"
//Anotation Faiz:

void mario(Personnage* personnage) {
    if (personnage == NULL) {
        return;
    }

    personnage->image = NULL; 

}

void chargerMario(Personnage* mario /*, Map* map*/, SDL_Renderer *renderer)
{
	
    mario->image = NULL; // Pas d'images chargées au départ
    mario->position.x = 0; // Position initiale en x
    mario->position.y = 0; // Position initiale en y
    mario->position.w = WIDTH_MARIO; // Largeur de Mario
    mario->position.h = HEIGHT_MARIO; // Hauteur de Mario
    mario->jump = 0; // Mario ne saute pas
    mario->jumptime = 0; // Pas de temps de saut
    mario->gravite = 0; // Mario est au sol
    mario->direction = 0; // Pas de direction initiale
    mario->dernieredirection = 0; // Pas de dernière direction
    mario->temp = 0; // Pas d'animation encore
    mario->win = 0; // Mario n'a ni gagné ni perdu
    mario->invisible = 0; // Mario est visible
    mario->lvl = 1; // Niveau initial
    mario->lvlperdu = 0; // Aucun niveau perdu
}

void afficherPerso(Personnage* mario, int xscroll, int yscroll , SDL_Renderer *renderer) {

   
}


//retourne soit numéro1 soit numéro2 pour alterner entre 2 sprite sur un mouvement.
int chooseSpriteMovement(Personnage* mario, int numero1, int numero2) {
    
    return numero1;
}

void freePersonnage(Personnage* mario, Personnage **goomba, int nbGoomba) {
    
}

/*
using sdl_event  & sdl_waitevent sdlpollEvent with a case make so that when I press q arrow my character gose to left d goes to right
*/