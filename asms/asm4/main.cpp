#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	
	int wid = 5, len = 5, hig = 3;
	bool debug = true;
	
	Game g;

	//get three inputs: size of the cave(wid, len, and hig)
	// g.size_prompt(wid, len, hig);

	//get the 4th input --> debug mode or not
	// g.debug_prompt(debug);

	//Play game
	g.play_game(wid, len, hig, debug);

	return 0;
}