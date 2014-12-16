#include "SpriteDef.h"
#include "Config.h"

SpriteDef::SpriteDef()//constructor de la clase//
{
	modulo[0].id = MODULO_MINAVE_NAVE;
	modulo[0].x=0;
	modulo[0].y=0;
	modulo[0].w=64;
	modulo[0].h=64;

	modulo[1].id=MODULO_MENU_FONDO;
	modulo[1].x=0;
	modulo[1].y=0;
	modulo[1].w=WIDTH_SCREEN;
	modulo[1].h=HEIGHT_SCREEN;

	modulo[2].id=MODULO_ENEMIGO_NAVE;
	modulo[2].x=0;
	modulo[2].y=0;
	modulo[2].w=54;
	modulo[2].h=61;

	modulo[3].id=MODULO_TEXTO_TITULO;
	modulo[3].x=22;
	modulo[3].y=63;
	modulo[3].w=209;
	modulo[3].h=58;

	modulo[4].id=MODULO_TEXTO_NOMBRE;
	modulo[4].x=20;
	modulo[4].y=20;
	modulo[4].w=436;
	modulo[4].h=40;

	modulo[5].id=MODULO_TEXTO_OPCION1;
	modulo[5].x=207;
	modulo[5].y=191;
	modulo[5].w=190;
	modulo[5].h=54;

	modulo[6].id=MODULO_TEXTO_OPCION2;
	modulo[6].x=207;
	modulo[6].y=257;
	modulo[6].w=154;
	modulo[6].h=50;

	modulo[7].id=MODULO_TEXTO_OPCION1_SELECCION;
	modulo[7].x=20;
	modulo[7].y=196;
	modulo[7].w=86;
	modulo[7].h=50;

	modulo[8].id=MODULO_TEXTO_OPCION2_SELECCION;
	modulo[8].x=25;
	modulo[8].y=257;
	modulo[8].w=152;
	modulo[8].h=50;

	modulo[9].id= MODULO_BALAS_BALA1;
	modulo[9].x=0;
	modulo[9].y=0;
	modulo[9].w=5;
	modulo[9].h=5;

} 