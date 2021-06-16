#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
SDL_Window *pWindow;
SDL_Renderer *pRenderer;



typedef struct Element {

	 char* str;
	struct Element* suivant;

}Element;

typedef struct ElementSDL {

	 SDL_Texture* pTextureImage;
	struct ElementSDL* suivant;

}ElementSDL;


typedef struct File {

	Element* premier;
	int taille;

}File;

typedef struct FileSDL {

	ElementSDL* premier;
	int taille;

}FileSDL;


extern void initialisation(File* file); //initialise la file
extern void insertion(File* file,  char* str);//insertion d'element en fin de file
extern void suppression(File* file);//suppression du premiere element de la file
extern void afficheFile(File* file);//affiche la file
extern void afficheTaille(File* file);//affiche le nombre d'element dans la file
extern void affichePremier(File* file);//affiche le premiere element de la file
extern void afficheDernier(File* file);//affiche le derniere element de la file


extern void initialisationSDL(FileSDL* file);//initialise la file de texture
extern void insertionSDL(FileSDL* file,  SDL_Texture* pTextureImage);//insertion element type texture dans la file
extern void afficheFileSDL(FileSDL* file);//affiche la file de texture

#endif // HEADERS_H_INCLUDED
