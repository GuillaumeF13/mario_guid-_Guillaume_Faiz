#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int largeur;
    int hauteur;
} MapDimensions;

int lireDimensions(const char* cheminFichier, MapDimensions* dimensions) {
    // Ouvre le fichier en mode lecture
    SDL_RWops* fichier = SDL_RWFromFile(cheminFichier, "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier : %s\n", cheminFichier);
        return -1; // Erreur lors de l'ouverture du fichier
    }

    // Sauter la première ligne (lire et ignorer)
    char ligne[256];
    if (SDL_RWread(fichier, ligne, 1, sizeof(ligne)) == 0) {
        printf("Erreur de lecture de la première ligne\n");
        SDL_RWclose(fichier);
        return -1; // Erreur de lecture
    }

    // Lire la deuxième ligne contenant la largeur et la hauteur
    if (SDL_RWread(fichier, ligne, 1, sizeof(ligne)) == 0) {
        printf("Erreur de lecture de la deuxième ligne\n");
        SDL_RWclose(fichier);
        return -1; // Erreur de lecture
    }

    // Analyser la ligne pour obtenir largeur et hauteur
    if (sscanf(ligne, "%d %d", &dimensions->largeur, &dimensions->hauteur) != 2) {
        printf("Erreur de format dans le fichier (largeur et hauteur attendus).\n");
        SDL_RWclose(fichier);
        return -1; // Erreur de format
    }

    // Fermer le fichier
    SDL_RWclose(fichier);
    return 0; // Succès
}

int main() {
    MapDimensions dimensions;

    // Appeler la fonction pour récupérer la taille du niveau
    if (lireDimensions("niveau0.lvl", &dimensions) == 0) {
        printf("Largeur: %d, Hauteur: %d\n", dimensions.largeur, dimensions.hauteur);
    } else {
        printf("Impossible de lire les dimensions du niveau.\n");
    }

    return 0;
}












