#include "Sprite.h"
#include "SpriteDef.h"
#include "SDL.h"

void Sprite::CargarImagen(char*ruta){

		image= SDL_LoadBMP(ruta);
		SDL_SetColorKey(image, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(image->format,255,0,0));//nota lo cambie a rojo
		
}



Sprite::Sprite(SDL_Surface * screen){
	this->screen =screen;
}

Sprite::~Sprite(){
	SDL_FreeSurface(image);
};


void Sprite::PintarModulo(int id, int x, int y){
SDL_Rect src;
	src.x= spriteDef.modulo [id].x;
	src.y= spriteDef.modulo [id].y;
	src.w= spriteDef.modulo [id].w;
	src.h= spriteDef.modulo [id].h;
	SDL_Rect dest;
	dest.x =x;
	dest.y =y;
	SDL_BlitSurface(image, &src, screen, &dest);

}
int Sprite::WidthModule(int id){
	return spriteDef.modulo[id].w;
	
}

int Sprite::HeightModule(int id){
	return spriteDef.modulo[id].h;
	
}