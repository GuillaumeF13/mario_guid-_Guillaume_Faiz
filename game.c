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

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    Map* map = malloc(sizeof(Map));
    if (!map) {
        perror("Erreur d'allocation mémoire pour la structure Map");
        return EXIT_FAILURE;
    }
    //lire_dimensions_map("level/niveau0.lvl", map);
    printf("Carte chargée : largeur = %d, hauteur = %d\n", map->width, map->height);

    // Création de Mario
    Personnage* mario = creerMario();

    // Chargement de l'image de Mario

    int continuer = 1;
    SDL_Event events;

    while (continuer) {
    while (SDL_PollEvent(&events)) {
        switch (events.type) {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                if (events.key.keysym.sym == SDLK_ESCAPE) {
                    continuer = 0;
                }
                int direction = getDirection(&events);
                if (direction == 1) {
                    mario->position.x += 10; // Déplace Mario vers la droite
                    printf("Mario se déplace vers la droite\n");
                } else if (direction == 2) {
                    mario->position.x -= 10; // Déplace Mario vers la gauche
                    printf("Mario se déplace vers la gauche\n");
                } else if (direction == 3) {
                    printf("Mario saute\n");
                }
                break;
        }
    }

    SDL_RenderClear(renderer);
    afficherPerso(mario, 0, 0, renderer);
    SDL_RenderPresent(renderer);
}

    // Libération des ressources
    free(map);
    freePersonnage(mario);

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