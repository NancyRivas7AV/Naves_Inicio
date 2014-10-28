#include "Sprite.h"
#include "SDL.h"



void Sprite::CargarImagen(char * path){
image = SDL_LoadBMP(path);

}
	Sprite::Sprite(SDL_Surface * screen){
	this->screen = screen;
};
Sprite::~Sprite(){
SDL_FreeSurface(image);
};

void Sprite::PintarModulo(int nombre, int x, int y){
	SDL_Rect src;
	src.x = spriteDef.modulos[nombre].x;
	src.y = spriteDef.modulos[nombre].y;
	src.w = spriteDef.modulos[nombre].w;
	src.h = spriteDef.modulos[nombre].h;
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	SDL_BlitSurface(image, &src, screen, &dest);
};