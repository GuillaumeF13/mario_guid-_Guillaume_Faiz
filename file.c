#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> // <-- Ajoute cette ligne

#include "file.h"
//Anotation Faiz:
//Anotation Guillaume:

SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer) {
    SDL_Surface *surface = IMG_Load(path);
    if (!surface) return NULL;
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}


void lire_dimensions_map(const char* nom_fichier, Map* map) {
    FILE* fichier = fopen(nom_fichier, "r");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[256];

    
    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        fprintf(stderr, "Erreur : fichier vide ou ligne illisible\n");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }

    
    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if (sscanf(ligne, "%d %d", &map->width, &map->height) != 2) {
            fprintf(stderr, "Erreur : format de dimensions invalide\n");
            fclose(fichier);
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Erreur : dimensions manquantes dans le fichier\n");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }

    fclose(fichier);
}


