#include "Game.h"
#include  <stdlib.h>


int main(int argc, char *argv[]){
	CGame *navesGame = new CGame();

	if(navesGame->Start())   
		navesGame->Finalize(); 
    
    return EXIT_SUCCESS;
}
