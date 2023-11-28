#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream>
#include <ncurses.h>
#include "cave.h"
#include "adventurer.h"

using namespace std;

//Game interface 
class Game
{
private:

	bool debug_view;	//debug mode or not
	Cave cave;
	Adventurer adventurer;
	int starting_position[3];
	bool wumpus_alive;

public:

	Game();
	~Game();

	void set_debug_view(const bool);
	bool get_debug_view() const;
	void set_wumpus_alive(const bool);
	bool get_wumpus_alive() const;

	void debug_prompt(bool&); //get the debug mode or not
	
	void randomize_starting_position();

	void set_starting_position(const int, const int, const int);

	void set_up(int, int, int, bool);

	void display_game(bool &, bool &, bool &, bool &, bool &, bool &);

	bool check_win();

	char get_dir();
	void wumpus_move();
	void fire_arrow();
	void fire_arrow_backwards();

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move_up_a_level();
	void move_down_a_level();
	void move(char);
	void check_confused(char, int&);

	char get_input();

	void teleport_player();

	bool check_loss(bool &);

	void game_loss(bool &);
	void game_win(bool &);

	void play_game(int, int, int, bool);

};


#endif