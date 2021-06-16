#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define WINDOW_WIDTH 780
#define WINDOW_HEIGHT 400

SDL_Window *pWindow = NULL ;
SDL_Renderer *pRenderer= NULL;
//SDL_Surface* image = NULL;
//SDL_Texture* pTextureImage= NULL;




///////////////////////////////////// TRAVAIL 1 ////////////////////////////////////////////////////////////////////
/*int main()
{

	File* file = NULL;
	file = (File*)malloc(sizeof(file));

	  char* str = "hello" ;
	  char* str2 = "bonjour" ;


	initialisation(file);
	insertion(file, str);
	insertion(file, str2);

	str = "hola";
	insertion(file, str);
	str = "hi";
	insertion(file, str);
	str = "buenos";
	insertion(file, str);


	suppression(file);



	afficheTaille(file);
	affichePremier(file);
	afficheDernier(file);

	return 0;
}*/






///////////////////////////////////// TRAVAIL 2 ////////////////////////////////////////////////////////////////////




int main(int argc, char* argv[])
{

     if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
    {
        SDL_Log("unable to initialize SDL : %s", SDL_GetError());
        return 1;
    }else{
        pWindow = SDL_CreateWindow("an SDL2 window",250,255,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);

        if (pWindow)
        {
            pRenderer = SDL_CreateRenderer(pWindow,-1,SDL_RENDERER_PRESENTVSYNC);
        }
    }

   SDL_Event events;
   SDL_bool isOpen = SDL_TRUE;
   SDL_Texture* pTextureImage= NULL;


	FileSDL* file = NULL;
	file = (FileSDL*)malloc(sizeof(file));


	SDL_Surface* image = IMG_Load("./image/txt2.JPG");
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);


    initialisationSDL(file);

    insertionSDL(file,pTextureImage);

    image = IMG_Load("./image/txt3.PNG");
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    insertionSDL(file,pTextureImage);

    image = IMG_Load("./image/txt4.PNG");
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    insertionSDL(file,pTextureImage);

    image = IMG_Load("./image/txt1.PNG");
    pTextureImage =SDL_CreateTextureFromSurface(pRenderer, image);

    insertionSDL(file,pTextureImage);
    SDL_FreeSurface(image);











	  while (isOpen)
    {
         while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = SDL_FALSE ;
                break;
            }
        }
       afficheFileSDL(file) ;
    }






	return 0;
}

