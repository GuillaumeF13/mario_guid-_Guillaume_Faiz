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
// informations sur le personnage 
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
    mario->image = malloc(sizeof(SDL_Texture*) * NUMBER_IMAGE_MARIO);
    mario->image[0] = loadImage("img/Mario1.png", renderer);
    mario->image[1] = loadImage("img/Mario2.png", renderer);
    mario->image[2] = loadImage("img/Mario3.png", renderer);
    mario->image[3] = loadImage("img/Mario4.png", renderer);
    mario->image[4] = loadImage("img/Mario5.png", renderer);
    mario->image[5] = loadImage("img/Mario6.png", renderer);
}

// Crée et initialise un personnage (Mario) avec les valeurs par défaut
Personnage* creerMario() {
    Personnage* mario = malloc(sizeof(Personnage));
    if (!mario) {
        printf("Erreur d'allocation mémoire pour Mario\n");
        return NULL;
    }
    mario->image = NULL;

    mario->position.x = 0; // Position initiale en x
    mario->position.y = 0; // Position initiale en y
    mario->position.w = WIDTH_MARIO;
    mario->position.h = HEIGHT_MARIO;
    mario->jump = 0;
    mario->jumptime = 0;
    mario->gravite = 0;
    mario->direction = 0;
    mario->dernieredirection = 0;
    mario->temp = 0;
    mario->win = 0;
    mario->invisible = 0;
    mario->lvl = 1;
    mario->lvlperdu = 0;
    return mario;
}
void afficherPerso(Personnage* mario, int xscroll, int yscroll, SDL_Renderer *renderer) {
    if (mario == NULL || renderer == NULL) return;

    SDL_Rect rect;
    rect.x = mario->position.x - xscroll;
    rect.y = mario->position.y - yscroll;
    rect.w = mario->position.w;
    rect.h = mario->position.h;

    // Affichage d'un rectangle rouge pour Mario
    SDL_RenderCopy(renderer, mario->image[0], NULL, &rect);
}


//retourne soit numéro1 soit numéro2 pour alterner entre 2 sprite sur un mouvement.
int chooseSpriteMovement(Personnage* mario, int numero1, int numero2) {
    if (!mario) return numero1;
    return (mario->temp % 2 == 0) ? numero1 : numero2;
}


// libère la mémoire allouée pour le personnage et ses images
void freePersonnage(Personnage* mario) {
    if (mario != NULL) {
        if (mario->image != NULL) {
            for (int i = 0; i < NUMBER_IMAGE_MARIO; i++) {
                if (mario->image[i] != NULL) {
                    SDL_DestroyTexture(mario->image[i]);
                }
            }
            free(mario->image);
        }
        free(mario);
    freePersonnage(mario);
    }
    
}

