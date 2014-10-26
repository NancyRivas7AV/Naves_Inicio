#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>
#include "Config.h"
#include "Sprite.h"

CGame::CGame()
{
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);
}
void CGame::Iniciando(){


	if (SDL_Init(SDL_INIT_AUDIO)){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);

	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);

	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}

}
void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	int bandera = 0;
	int salirJuego = false; char menu;
	while (salirJuego == false)
	{
	
		switch (estado)
		{
		case Estado::ESTADO_INICIANDO:
			printf("\n1) ESTADO_INICIANDO");
			estado = ESTADO_MENU;
			break;

		case Estado::ESTADO_MENU:
			printf("\n2) ESTADO_MENU");
			if( bandera > 0)
			{estado = ESTADO_FINALIZADO;}
			else
			{estado = ESTADO_JUGANDO;}
			break;

		case Estado::ESTADO_JUGANDO:
			printf("\n3) ESTADO_JUGANDO");
			estado = ESTADO_TERMINANDO;
			break;

		case Estado::ESTADO_TERMINANDO:
			printf("\n4) ESTADO_TERMINANDO");
			bandera = bandera +1;
			estado = ESTADO_MENU;
			break;

		case Estado::ESTADO_FINALIZADO:
			printf("\n5) ESTADO_FINALIZADO");
			getchar();
			salirJuego = true;
			break;
		};

	}
	return true;
}