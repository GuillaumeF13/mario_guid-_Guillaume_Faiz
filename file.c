#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> // <-- Ajoute cette ligne

#include "file.h"
//Anotation Faiz:
//Anotation Guillaume:

void lire_dimensions_map(const char* nom_fichier, int* largeur, int* hauteur) {
    FILE* fichier = fopen("niveau0.lvl", "r");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char ligne[256];

    // Lire et ignorer la première ligne
    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        fprintf(stderr, "Erreur lors de la lecture de la première ligne\n");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }

    // Lire la ligne suivante contenant largeur et hauteur
    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if (sscanf(ligne, "%d %d", largeur, hauteur) != 2) {
            fprintf(stderr, "Erreur : format de dimensions invalide\n");
            fclose(fichier);
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Erreur : dimensions manquantes\n");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }

    fclose(fichier);
}

int main() {
    int largeur, hauteur;
    lire_dimensions_map("niveau0.lvl", &largeur, &hauteur);
    printf("Largeur : %d, Hauteur : %d\n", largeur, hauteur);
    return 0;
}

