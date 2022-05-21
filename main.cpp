#include "Game.h"


using namespace sf;

int main()
{
	//Random seed
	srand(static_cast<unsigned>(time(0)));

	//Game object
	Game game;

	//Game loop
	while (game.running()) //kol game runnina
	{
		game.update();
		game.render();
	}

	return 0;
}