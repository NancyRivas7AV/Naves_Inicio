#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Config.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "Objeto.h"

CGame::CGame(){
	frames=0;
	tiempoFrameInicio=0;
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);
}
void CGame::Iniciando(){
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Error %S ", SDL_GetError());
		exit (EXIT_FAILURE);
	}
	
	screen = SDL_SetVideoMode ( WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE | SDL_DOUBLEBUF );
	if (screen == NULL)
	{
		printf("Error %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip (screen);
	SDL_WM_SetCaption( "Mi primer juego", NULL);
	atexit(SDL_Quit);
	nave = new Nave(screen, "../Data/MiNave.bmp",(WIDTH_SCREEN / 2)/*-(w/2)*/,(HEIGHT_SCREEN-80)/*-(h)*/,MODULO_MINAVE_NAVE);
	menu = new Objeto(screen, "../Data/Texto.bmp",0,120,MODULO_TEXTO_TITULO	);
	fondomenu= new Objeto(screen,"../Data/Fondo.bmp",0,0,1);
	fondo=new Objeto(screen, "../Data/espacio.bmp",0,0,1);

	enemigoArreglo = new Nave*[10];

	for	(int i=0;i<10;i++)
	{
		enemigoArreglo[i] = new Nave(screen, "../Data/enemigo.bmp",i*65,0,MODULO_ENEMIGO_NAVE);
	}


	for (int i=0;i<10;i++)
	{
		enemigoArreglo[i]->GetNaveObjeto()->SetStep(4);
	}
	menuSeleccion=MODULO_TEXTO_OPCION1;

}


void CGame::Finalize(){
	SDL_Quit();
}

bool CGame::Start()
{
	
	int salirJuego = false;
          
	while (salirJuego == false){
            
		
		switch(estado)
		{
			case Estado::ESTADO_INICIANDO: 
			InicializandoStage();
				Iniciando();

				estado=ESTADO_MENU;

				break;
			case Estado::ESTADO_MENU:
			    fondomenu->Pintar();
				menu->Pintar(MODULO_TEXTO_TITULO,220,30);
				menu->Pintar(MODULO_TEXTO_OPCION1, 335,160);
				menu->Pintar(MODULO_TEXTO_OPCION2, 335, 250);
				menu->Pintar(MODULO_TEXTO_OPCION1_SELECCION, 150, 160);
				menu->Pintar(MODULO_TEXTO_OPCION2_SELECCION, 150, 250);
				menu->Pintar(MODULO_TEXTO_NOMBRE,120,400);
				

				SDL_Flip (screen); 
				keys = SDL_GetKeyState(NULL);
				
				if(keys[SDLK_UP]){
					estado=ESTADO_PREJUGANDO;
				}
				if (keys[SDLK_DOWN]){
					estado=ESTADO_FINALIZADO;
				}
			
			
			break;

			case Estado::ESTADO_PREJUGANDO:
			nivelActual = 0;
			vidas = 1;
			enemigosEliminados = 0;

			estado = ESTADO_JUGANDO;
			break;

			case Estado::ESTADO_JUGANDO://JUGAR
			SDL_FillRect(screen, NULL, 0x000000);
			keys = SDL_GetKeyState(NULL);

				for (int i=0;i< niveles[nivelActual].cantidadEnemigosenPantalla ;i++)
				{
					enemigoArreglo[i]->GetNaveObjeto()->Actualizar();
				}

			MoverEnemigo();
			if(keys[SDLK_SPACE]){
				nave->Disparar(NAVE_PROPIA, niveles[nivelActual].velocidadBalasPropia);
			}

			//*******************************sumular c************************
			if(keys[SDLK_x]){//NAVE NUESTRA Y BALA ENEMIGO
			 nave->estaColisionandoConBalas(nave);
			}
			if(keys[SDLK_c]){//NUESTRA BALA Y NAVE ENEMIGO
				int naveAEliminar = rand() % niveles[nivelActual].cantidadEnemigosenPantalla;
				enemigoArreglo[naveAEliminar]->ColisionarConBala(true);
				enemigoArreglo[naveAEliminar]->setVisible(false);
			}
			if(keys[SDLK_v]){//NUESTRA NAVE Y NAVE ENEMIGO

			}
			if(vidas <= 0){
		
				estado = ESTADO_PREJUGANDO; 
			}
			//COLICIONES
				for(int i = 0; i <=niveles[nivelActual].cantidadEnemigosenPantalla; i++){
					if(enemigoArreglo[i]->estaColisionandoConBalas(nave));{
					vidas--;
					}
					if(nave->estaColisionandoConBalas(enemigoArreglo[i])){
						enemigoArreglo[i]->setVisible(false);
						enemigosEliminados++;
					}

				}
				if(enemigosEliminados >= niveles[nivelActual].cantidadEnemigosaEliminar){
					enemigosEliminados = 0;
					////AQUI VA FONDO 2
					nivelActual++;
				}
		
			if(keys[SDLK_RIGHT]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_DERECHO)){
			nave->MoverDerecha(niveles[nivelActual].velocidadPropia);
			}
			if(keys[SDLK_LEFT]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_IZQUIERDO)){
			nave->MoverIzquierda(niveles[nivelActual].velocidadPropia);
			}
			if(keys[SDLK_UP]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_SUPERIOR)){
			nave->MoverArriba(niveles[nivelActual].velocidadPropia);
			}
			if(keys[SDLK_DOWN]&& !esLimitePantalla(nave->GetNaveObjeto(),BORDE_INFERIOR)){
			nave->MoverAbajo(niveles[nivelActual].velocidadPropia);
			}
			fondo->Pintar();
			nave->Pintar();
			nave->Actualizar(NAVE_PROPIA, niveles[nivelActual].velocidadBalasPropia);
			
				for(int i=0;i<niveles[nivelActual].cantidadEnemigosenPantalla;i++){
			    enemigoArreglo[i]->AutoDisparar(niveles[nivelActual].velocidadBalasEnemigo,  MAXIMO_BALAS);/////
				enemigoArreglo[i]->Pintar();
				enemigoArreglo[i]->Actualizar(NAVE_ENEMIGO, niveles[nivelActual].velocidadBalasEnemigo);
	      	}
			
			break;
			case Estado::ESTADO_TERMINADO:	//TERMINAR

			break;
			case Estado::ESTADO_FINALIZADO:  //SALIR

	
			salirJuego = true;
			break;
		};//------------Fin del switch
				while (SDL_PollEvent(&event))
				{
					if (event.type == SDL_QUIT){salirJuego =true;}//si se detecta una
						if (event.type == SDL_KEYDOWN){}
				}
		SDL_Flip(screen); //imprime en pantalla variable screen

		frames++;
		tiempoFrameFinal = SDL_GetTicks();
		while(tiempoFrameFinal<(tiempoFrameInicio + FPS_DELAY)){
			tiempoFrameFinal =SDL_GetTicks();
		SDL_Delay(1);
		}
		printf("Frame:%d Tiempo:%d TiempoPorFrame:%d FPS:%f\n",frames, tiempoFrameInicio, tiempoFrameFinal-tiempoFrameInicio,1000.0f /(float)(tiempoFrameFinal-tiempoFrameInicio));
		tiempoFrameInicio= tiempoFrameFinal;
    }
	return true;
}
bool CGame::esLimitePantalla(Objeto *objeto, int bandera){
	if(bandera & BORDE_IZQUIERDO) 
		if (objeto->obtenerX() <=0)
			return true;
	if(bandera & BORDE_SUPERIOR)
		if (objeto->obtenerY() <=0)
			return true;
	if(bandera & BORDE_DERECHO)
		if (objeto->obtenerX() >=(WIDTH_SCREEN-objeto->obtenerW()))
			return true;
	if(bandera & BORDE_INFERIOR)
		if (objeto->obtenerY() >=(HEIGHT_SCREEN-objeto->obtenerH()))
			return true;
	return false;
}
void CGame::MoverEnemigo(){

	for (int i=0;i<10;i++)
		switch(enemigoArreglo[i]->GetNaveObjeto()->ObtenerStepActual()){
	case 0:
		if(!enemigoArreglo[i]->GetNaveObjeto()->IsRunningAnimacion())
			 //  enemigo->IncrementarStep();
		enemigoArreglo[i]->GetNaveObjeto()->Mover(niveles[nivelActual].velocidadEnemigo,WIDTH_SCREEN-enemigoArreglo[i]->GetNaveObjeto()->obtenerW());
		
	

		if(esLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_DERECHO))
			enemigoArreglo[i]->GetNaveObjeto()->TerminarAnimacion();

		break;
	case 1:
		enemigoArreglo[i]->GetNaveObjeto()->IncrementarStep();
		break;
	case 2:
		 if (!enemigoArreglo[i]->GetNaveObjeto()->IsRunningAnimacion())
		  enemigoArreglo[i]->GetNaveObjeto()->Mover(-niveles[nivelActual].velocidadEnemigo,WIDTH_SCREEN-enemigoArreglo[i]->GetNaveObjeto()->obtenerW());
		

		if(esLimitePantalla(enemigoArreglo[i]->GetNaveObjeto(),BORDE_IZQUIERDO))
			enemigoArreglo[i]->GetNaveObjeto()->TerminarAnimacion();

		break;
	case 3:
		enemigoArreglo[i]->GetNaveObjeto()->IncrementarStep();
		break;
	}

}

void CGame::Menu(){
	for(int i = MODULO_TEXTO_OPCION1, j = 0; i <= MODULO_TEXTO_OPCION2; i++, j++)
	{
	/*	if(i=menuSeleccion){
		fondomenu->Pintar(MENU_NUMERO_ELEMENTOS,150,150+(j*50));
		}
		else
			fondomenu->Pintar(1,150,150+(j*50));*/
	}

}