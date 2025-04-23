#include <SDL2/SDL_image.h>
#include "file.h"
#include <stdio.h>
#include <stdlib.h>


void lire_dimensions(FILE *fichier, int *largeur, int *hauteur) {
    char ligne[256];


    fgets(ligne, sizeof(ligne), fichier);


    if (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if (sscanf(ligne, "%d %d", largeur, hauteur) != 2) {
            fprintf(stderr, "Erreur : format des dimensions invalide\n");
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Erreur : dimensions non trouvées dans le fichier\n");
        exit(EXIT_FAILURE);
    }
}


int **lire_map(FILE *fichier, int largeur, int hauteur) {
    int **map = malloc(hauteur * sizeof(int *));
    if (!map) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < hauteur; i++) {
        map[i] = malloc(largeur * sizeof(int));
        if (!map[i]) {
            perror("Erreur d'allocation mémoire");
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < largeur; j++) {
            if (fscanf(fichier, "%d", &map[i][j]) != 1) {
                fprintf(stderr, "Erreur de lecture à la ligne %d colonne %d\n", i, j);
                exit(EXIT_FAILURE);
            }
        }
    }

    return map;
}


void afficher_map(int **map, int largeur, int hauteur) {
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}


void liberer_map(int **map, int hauteur) {
    for (int i = 0; i < hauteur; i++) {
        free(map[i]);
    }
    free(map);
}

// Fonction principale
int main() {
    int largeur = 0, hauteur = 0;
    FILE *fichier = fopen("niveau0.lvl", "r");
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier");
        return EXIT_FAILURE;
    }

    lire_dimensions(fichier, &largeur, &hauteur);
    int **map = lire_map(fichier, largeur, hauteur);
    fclose(fichier);

    printf("Dimensions de la map : %d x %d\n", largeur, hauteur);
    printf("Contenu de la map :\n");
    afficher_map(map, largeur, hauteur);

    liberer_map(map, hauteur);
    return 0;
}





