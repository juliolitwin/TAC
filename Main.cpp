#include <stdio.h>
#include "Game.h"

int main(int argc, char* args[])
{
	Game* game = new Game("Julio Cesar Litwin Lima | 160129443", 1024, 600);
	game->Run();

	delete game;

	return 0;
}