
#include <SDL.h>
#include <SDL_image.h>
#include "Objeto.h"
#include "Nave.h"
#include "Stage.h"


class CGame 
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();  
	enum Estado{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_PREJUGANDO,
		ESTADO_JUGANDO,
		ESTADO_TERMINADO,
		ESTADO_FINALIZADO,
		};

private:
	void InicializandoStage();
	void Iniciando();
	void MoverEnemigo();//Metodo para mover al enemigo//
	bool esLimitePantalla(Objeto *objeto, int bandera);//metodo para limitar la pantalla//

	void Menu();///////////////
	int nivelActual;
	int enemigosEliminados;
	int vidas;

	int menuSeleccion;

	Uint8 *keys;//esta variable nos servira para ver las teclas//
	SDL_Event event;//La variable event de tipo evento de SDL nos sirve para//

	SDL_Surface *screen;
	Nave *nave;    
	Nave **enemigoArreglo;
	Stage niveles[4];

	Objeto *menu;
	Objeto *fondomenu;
	Objeto *fondo;




	Estado estado;
	
	float enemigoParabola;
	unsigned int frames;
	unsigned int tiempoFrameInicio;
	unsigned int tiempoFrameFinal;

};