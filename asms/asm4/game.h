#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream>
#include "cave.h"
#include "adventurer.h"

using namespace std;

//Game interface 
class Game
{
private:

	//other member variables:
	bool debug_view;	//debug mode or not
	Cave cave;
	Adventurer adventurer;

	//feel free to add more variables...

public:

	//suggested functions:
	Game();
	~Game();

	void set_debug_view(const bool);
	bool get_debug_view() const;

	void size_prompt(int&, int&, int&); //get the size of the board

	void debug_prompt(bool&); //get the debug mode or not
	
	void set_up(int, int, int, bool);

	void display_game();

	bool check_win() const;

	char get_dir();
	void wumpus_move();
	void fire_arrow();

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);

	char get_input();

	void play_game(int, int, int, bool);

	//feel free (and you will need) to add more functions...




};


#endif