#include "headers.h"
#include <stdio.h>
#include <stdlib.h>


void initialisation(File* file)
{
	file->premier = NULL;
	file->taille = 0;
}

void insertion(File* file,  char* str)
{
	Element* newElement = (Element*)malloc(sizeof(newElement));
	if (file == NULL || newElement == NULL)
	{
		exit(EXIT_FAILURE);
	}

	newElement->suivant = NULL;
    newElement->str = str;

	if (file->premier != NULL)
	{
		Element* elementActuel = file->premier;
		while (elementActuel->suivant != NULL)
		{
			elementActuel = elementActuel->suivant;
		}

		elementActuel->suivant = newElement;
	}
	else {
		file->premier = newElement;
	}

	file->taille++;
}

void suppression(File* file)
{
	if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (file->premier != NULL)
	{
		Element* suppr = file->premier;
		file->premier = suppr->suivant;
		free(suppr);
		file->taille--;
	}
}

void afficheFile(File* file)
{
    if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Element* elementActuel = file->premier;

	while(elementActuel != NULL)
    {
        printf("%s\n",elementActuel->str);
        elementActuel = elementActuel->suivant;
    }
}

void afficheTaille(File* file)
{
    if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

    printf("%d\n",file->taille);
}

void affichePremier(File* file)
{
    if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

    printf("%s\n",file->premier->str);
}

void afficheDernier(File* file)
{
    if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

    Element* elementActuel = file->premier;
		while (elementActuel->suivant != NULL)
		{
			elementActuel = elementActuel->suivant;
		}
    printf("%s\n",elementActuel->str);

}



//////////////////////////////////FILE SDL///////////////////////////



void initialisationSDL(FileSDL* file)
{
	file->premier = NULL;
	file->taille = 0;
}

void insertionSDL(FileSDL* file,  SDL_Texture* pTextureImage)
{
	ElementSDL* newElement = (ElementSDL*)malloc(sizeof(newElement));
	if (file == NULL || newElement == NULL)
	{
		exit(EXIT_FAILURE);
	}

	newElement->suivant = NULL;
    newElement->pTextureImage = pTextureImage;

	if (file->premier != NULL)
	{
		ElementSDL* elementActuel = file->premier;
		while (elementActuel->suivant != NULL)
		{
			elementActuel = elementActuel->suivant;
		}

		elementActuel->suivant = newElement;
	}
	else {
		file->premier = newElement;
	}

	file->taille++;
}

void afficheFileSDL(FileSDL* file)
{
    if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}
	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

	SDL_Rect dst={ 0, 0, 100, 100 };

	ElementSDL* elementActuel = file->premier;

	while(elementActuel != NULL)
    {
        SDL_RenderCopy(pRenderer, elementActuel->pTextureImage, NULL,&dst);
        elementActuel = elementActuel->suivant;
        dst.y += 100;
    }

    SDL_RenderPresent(pRenderer);
}
