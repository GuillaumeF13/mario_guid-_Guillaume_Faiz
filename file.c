#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> // <-- Ajoute cette ligne

#include "file.h"
#include <stdio.h>
#include <stdlib.h>

//Anotation Faiz:
//Anotation Guillaume:

/* permet de charger une image dans une SDL_Texture avec l'option SDL_TEXTUREACCESS_TARGET
   pour pouvoir modifier la texture après. */
SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *surface = NULL; 
    SDL_Texture *tmp = NULL, *texture = NULL;
    surface = IMG_Load(path);
    if(NULL == surface)
    {
        fprintf(stderr, "Erreur IMG_Load : %s", SDL_GetError());
        return NULL;
    }
    tmp = SDL_CreateTextureFromSurface(renderer, surface);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        SDL_FreeSurface(surface); // Ajout pour éviter fuite mémoire
        return NULL;
    }
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                            SDL_TEXTUREACCESS_TARGET, surface->w, surface->h); 
    if(texture == NULL) 
    {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return NULL;
    }
    SDL_SetRenderTarget(renderer, texture); /* La cible de rendu est maintenant texture. */
    SDL_SetTextureBlendMode(tmp, SDL_BLENDMODE_NONE); /* gère la transparence du fond des images */
    SDL_RenderCopy(renderer, tmp, NULL, NULL); /* On copie tmp sur texture */
    SDL_DestroyTexture(tmp); // nettoyage
    SDL_FreeSurface(surface); // nettoyage
    SDL_SetRenderTarget(renderer, NULL); /* La cible de rendu est de nouveau le renderer. */
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

    
    map->LoadedMap = malloc(map->height * sizeof(int*));
    if (map->LoadedMap == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire (ligne)\n");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < map->height; i++) {
        map->LoadedMap[i] = malloc(map->width * sizeof(int));
        if (map->LoadedMap[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire colonne %d\n", i);
            fclose(fichier);
            exit(EXIT_FAILURE);
        }
    }

    
    for (int i = 0; i < map->height; i++) {
        if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
            fprintf(stderr, "Erreur : ligne %d manquante\n", i);
            fclose(fichier);
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < map->width; j++) {
            if (ligne[j] >= '0' && ligne[j] <= '9') {
                map->LoadedMap[i][j] = ligne[j] - '0';
            } else {
                fprintf(stderr, "Erreur : caractère invalide '%c' à (%d,%d)\n", ligne[j], i, j);
                fclose(fichier);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(fichier);
}
//creation de la map 

//faire un tableau de sprite 