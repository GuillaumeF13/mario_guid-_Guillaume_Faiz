#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"

int jouer(SDL_Renderer* renderer) {
    
	//charger image et personnage. 
	
    int continuer = 1;
    SDL_Event events;

    while(continuer){ //coeur du jeu ici, les actions seront repété pour faire le déplacement des différentes images, ...
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
				
            }
        }
        
		//on gère les divers events.
		
        SDL_RenderPresent(renderer); // affiche le tout
        
        
    }
    
	//a vous de compléter, au fur et à mesure, les deux fonctions en dessous pour bien faire le nettoyage. 
    //LibererMap(map, sprites);
    //freePersonnage(mario, goomba, nbGoomba);

    return continuer;
}