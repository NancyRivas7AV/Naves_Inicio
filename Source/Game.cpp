#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>
#include "Config.h"
#include "Sprite.h"

CGame::CGame(){
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
	SDL_Flip(screen);
	SDL_WM_SetCaption("Mi primer Juego", NULL);
	nave = new Sprite(screen);
	nave->CargarImagen("../Data/minave.bmp");

}
void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{

	int salirJuego = false; char menu;
	while (salirJuego == false)
	{
		switch (estado)
		{
		case Estado::ESTADO_INICIANDO:

				Iniciando();
			estado = ESTADO_MENU;
			break;

		case Estado::ESTADO_MENU:
		Iniciando();
		nave->PintarModulo(SPRITE_MODULE_MI_NAVE,100,100);
		estado = ESTADO_JUGANDO;
			break;
		case Estado::ESTADO_JUGANDO:
			break;
		case Estado::ESTADO_FINALIZADO:
			break;
		case Estado::ESTADO_TERMINANDO:
			salirJuego = true;
			break;
		};

		SDL_Flip(screen);
	}
	return true;
}
