#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"


class CGame
{
public:

	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado
	{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZADO,
	};

private:
	void Iniciando();
	Uint8 *keys;
	SDL_Event event;
	SDL_Surface * screen;
	Sprite * nave;
	Estado estado;
};