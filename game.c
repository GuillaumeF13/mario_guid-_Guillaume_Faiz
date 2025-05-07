#include "game.h"
#include "file.h"
#include "charactere.h"
#include "event.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

// Fonction pour initialiser une fenêtre blanche
int initialiserFenetre(SDL_Window** window, SDL_Renderer** renderer) {


    *window = SDL_CreateWindow(
        "Mario 2D",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );



    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

    // Remplir l'écran avec une couleur blanche
    SDL_SetRenderDrawColor(*renderer, 255, 255, 255, 255);
    SDL_RenderClear(*renderer);
    SDL_RenderPresent(*renderer);

    return 0;
}

int jouer(SDL_Renderer* renderer) {
    SDL_Window* window = NULL;

    // Initialiser la fenêtre et le renderer
    if (initialiserFenetre(&window, &renderer) != 0) {
        return -1;
    }
}

int main() {
    SDL_Renderer* renderer = NULL;
    IMG_Init(IMG_INIT_PNG);

    // Appeler la fonction jouer()
    if (jouer(renderer) != 0) {
        printf("Erreur lors de l'exécution du jeu.\n");
        return -1;
    }

    return 0;
}






    //Fenetre précédente creer parce que github ne fonctionner pas
/*
    while (continuer) { // Boucle principale du jeu
        while (SDL_PollEvent(&events)) {
            switch (events.type) {
                case SDL_QUIT:
                    continuer = 0;
                    break;
            }
        }
        // Effacer l'écran (fond blanc)

        // Afficher Mario
        

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // Limiter la boucle à environ 60 FPS
    }
    //Nettoyage des ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
*/