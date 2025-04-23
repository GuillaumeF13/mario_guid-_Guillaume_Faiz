#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "game.h"

//Anotation Faiz: 
//Anotation Guillaume: 

//ligne de compilation gcc main.c file.c game.c event.c charactere.c -o mario -lSDL2main -lSDL2_image -lSDL2

#define LARGEUR_FENETRE 1200
#define HAUTEUR_FENETRE 1200

int main(int argc, char *argv[]) {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        return 1;
    }

    // Initialisation de la SDL_image
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Erreur d'initialisation de SDL_image : %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // Création de la fenêtre
    SDL_Window *fenetre = SDL_CreateWindow("Fenêtre Mario",
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           LARGEUR_FENETRE,
                                           HAUTEUR_FENETRE,
                                           SDL_WINDOW_SHOWN);
    if (fenetre == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(fenetre);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Charger l'image
    SDL_Surface *image = IMG_Load("img/mario.png");
    if (image == NULL) {
        printf("Erreur lors du chargement de l'image : %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(fenetre);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Conversion de l'image en texture
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    if (texture == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(fenetre);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Boucle principale de l'application
    int running = 1;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Effacer l'écran avec une couleur (noir ici)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Afficher l'image
        SDL_RenderCopy(renderer, texture, NULL, NULL);

        // Présenter la scène
        SDL_RenderPresent(renderer);
    }

    // Libération des ressources
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
