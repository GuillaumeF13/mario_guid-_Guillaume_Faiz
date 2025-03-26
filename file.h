/*
Gère les divers fichiers pour faire fonctionner le jeu, dont entre autres les diverses images avec la méthode load_image
et la map. 
*/
//Anotation Faiz:

#ifndef DEF_FILE
#define DEF_FILE
    
    #include <SDL2/SDL.h>

    #define NbSprites 10 // À modifier si on ajouter des sprites
    #define Size_Sprite 40 // A modifier si on change taille sprite
    #define LARGEUR_FENETRE 1200 //taille de la fenetre
    #define HAUTEUR_FENETRE 1200 //taille de la fenetre

    typedef struct Map Map;
    struct Map
    {
        int width, height;
        int** LoadedMap; //contient les chiffres du niveau (charger depuis le fichier)
        int xscroll,yscroll; //contient les données de combien on a scrollé dans les 2 directions pour bien faire bouger la map
    };

    typedef struct Sprites Sprites;
    struct Sprites
    {
        SDL_Texture* sprite; //contient la texture
        int traverser; //signifie si on peut traverser ou non le bloc (0 = oui, 1 = non)
    };

    SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer);
    Sprites* chargerImages(SDL_Renderer *renderer);
    Map* ChargerMap(char* level);
    void afficherMap(Map* map, Sprites* sprites, SDL_Renderer *renderer);
    void LibererMap(Map* map, Sprites* sprites);

#endif