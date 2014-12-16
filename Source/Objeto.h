#ifndef __OBJETO_H__  //para proteger 
#define __OBJETO_H__
#include "Sprite.h"

class Objeto
{
	//Todas las variables
	int x;
	int y;
	int w;
	int h;
	int posicionActual;//donde esta la nave
	int posicionFinal;//asta donde llegara
	int posicionBrinco;
	int stepsActual;
	int stepsFinal;
	int moduleUsing;//Modulo en uso
	bool isVisible;
	Sprite * sprite;
	


public:
	void SetVisible(bool isVisible);
	Objeto(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	~Objeto();
	//Aqui se crean todos los metodos//
	void Pintar();
	void Pintar(int module,int x, int y);
	void Mover(int brinco, int puntoFinal);
	
	void Objeto::Mover(int posicion);
	void Objeto::MoverIzquierda(int posicion);
	void Objeto::MoverArriba(int posicion);
	void Objeto::MoverAbajo(int posicion);
	void SetStep(int stepsFinal);
	void IncrementarStep();
	int ObtenerStepActual();
	void Actualizar();//Metodo de Actualizacion
	bool IsRunningAnimacion();
	void TerminarAnimacion();//fuerza a terminar la STRP actual de la nave//
	int obtenerX();//metodo para obtener el bvalor de x & y//
	int obtenerY();
	int obtenerW();
	int obtenerH();
	void ponerEn(int x, int y);


};

#endif