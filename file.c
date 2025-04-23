#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> // <-- Ajoute cette ligne

#include "file.h"
//Anotation Faiz:
//Anotation Guillaume:

/*permet de charger une image dans une SDL_Texture avec l'option SDL_TEXTUREACCESS_TARGET
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
        return NULL;
    }
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                            SDL_TEXTUREACCESS_TARGET, surface->w, surface->h); 
    if(texture == NULL) 
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    SDL_SetRenderTarget(renderer, texture); /* La cible de rendu est maintenant texture. */
    SDL_SetTextureBlendMode(tmp, SDL_BLENDMODE_NONE); /* gère la transparence du fond des images*/
    SDL_RenderCopy(renderer, tmp, NULL, NULL); /* On copie tmp sur texture */
    SDL_DestroyTexture(tmp); //nettoyage
    SDL_FreeSurface(surface); //nettoyage
    SDL_SetRenderTarget(renderer, NULL); /* La cible de rendu est de nouveau le renderer. */
    return texture;
}

Sprites* chargerImages(SDL_Renderer *renderer) {
    Sprites* sprites;
    
	
    return sprites;
}

Map* ChargerMap(char* level)
{
    Map* map = malloc(sizeof(Map));
	

	return map;
}

void afficherMap(Map* map, Sprites* sprites, SDL_Renderer *renderer) {

    
}

void LibererMap(Map* map, Sprites* sprites)
{
  
}