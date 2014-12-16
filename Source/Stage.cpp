#include "Game.h"


void CGame::InicializandoStage()
{

	niveles[0].nivel = 0;
	niveles[0].cantidadEnemigosaEliminar = 5;
	niveles[0].cantidadEnemigosenPantalla = 1;
	niveles[0].efectividadEnemigo = 10;
	niveles[0].limiteBalasPropias = 500;
	niveles[0].velocidadBalasEnemigo = 8;
	niveles[0].velocidadBalasPropia = 10;
	niveles[0].velocidadEnemigo =10;
	niveles[0].velocidadPropia = 10;

	niveles[1].nivel = 1;
	niveles[1].cantidadEnemigosaEliminar = 20;
	niveles[1].cantidadEnemigosenPantalla = 2;
	niveles[1].efectividadEnemigo = 5;
	niveles[1].limiteBalasPropias = 400;
	niveles[1].velocidadBalasEnemigo = 7;
	niveles[1].velocidadBalasPropia = 6;
	niveles[1].velocidadEnemigo = 15;
	niveles[1].velocidadPropia = 12;



}