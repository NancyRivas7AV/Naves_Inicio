#ifndef __SPRITEDEF_H__
#define __SPRITEDEF_H__

class SpriteDef{
	struct Modulo{
		int id;
		int x;
		int y;
		int w;
		int h;
	};
public:
  //   tipo, nombre, espacio[1];//
	Modulo modulo[10];
	SpriteDef();//Constructor
};
#endif