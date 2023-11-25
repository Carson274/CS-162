#include <iostream>
#include "game.h"

using namespace std;

Game::Game(){
	this->debug_view = false;
	this->cave = Cave();
	this->adventurer = Adventurer();
	this->starting_position[0] = 0;
	this->starting_position[1] = 0;
	this->starting_position[2] = 0;
	this->wumpus_alive = true;
}

Game::~Game(){
	//Game destructor
	//Your code here:

}

void Game::set_debug_view(bool d){
	this->debug_view = d;
	return;
}
bool Game::get_debug_view() const{
	return this->debug_view;
}
void Game::set_wumpus_alive(bool wumpus_alive){
	this->wumpus_alive = wumpus_alive;
}
bool Game::get_wumpus_alive() const{
	return this->wumpus_alive;
}

void Game::size_prompt(int& w, int& l, int& h){
	//get the size of the board
	cout << "Enter cave width (must be between 4 and 50 inclusive): " << endl;
	cin >> w;
	cout << "Enter cave length (must be between 4 and 50 inclusive): " << endl;
	cin >> l;
	cout << "Enter cave height (must be  at least 1): " << endl;
	cin >> h;
	return;
}

void Game::debug_prompt(bool& d){
	//get the debug mode or not
	cout << "Enter debug mode (1-yes, 0-no): " << endl;
	cin >> d;
	return;
}

void Game::set_starting_position(const int x, const int y, const int z){
	this->starting_position[0] = x;
	this->starting_position[1] = y;
	this->starting_position[2] = z;
	return;
}

void Game::randomize_starting_position(){
	int x, y, z;
	x = rand() % this->cave.get_length();
	y = rand() % this->cave.get_width();
	z = rand() % this->cave.get_height();
	set_starting_position(x,y,z);
	this->adventurer.set_position(x,y,z);
	this->cave.place_adventurer(x,y,z);
	return;
}

void Game::set_up(int l, int w, int h, bool b){

	// set cave dimensions
	this->cave.set_length(l);
	this->cave.set_width(w);
	this->cave.set_height(h);

	// set debug mode
	this->set_debug_view(b);

	// create cave
	this->cave.setup_cave();

	// place player
	randomize_starting_position();

	// place events
	this->cave.place_events();
}

//Note: you need to modify this function
void Game::display_game(){
	cout << endl << endl;
	
	cout << "Arrows remaining: " << this->adventurer.get_num_arrows() << endl;

	this->cave.print_cave(this->adventurer.get_position(), this->starting_position, this->get_debug_view());
}

bool Game::check_win() {
	//check if game over/win
	if(this->adventurer.get_gold() == true && (this->adventurer.get_position()[0] == this->starting_position[0] && this->adventurer.get_position()[1] == this->starting_position[1] && this->adventurer.get_position()[2] == this->starting_position[2])) {
		cout << "Congratulations, you win!" << endl;
		return true;
	} else if(get_wumpus_alive() == false) {
		cout << "Congratualtions, you win!" << endl;
		return true;
	} 
	return false;
}

void Game::move_up() {
	//move player up
	if(this->adventurer.get_position()[0] == 0) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0] - 1, this->adventurer.get_position()[1], this->adventurer.get_position()[2]);
	}
	return;
}

void Game::move_down() {
	//move player down
	if(this->adventurer.get_position()[0] == this->cave.get_length() - 1) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0] + 1, this->adventurer.get_position()[1], this->adventurer.get_position()[2]);
	}
	return;
}

void Game::move_left() {
	//move player left
	if(this->adventurer.get_position()[1] == 0) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0], this->adventurer.get_position()[1] - 1, this->adventurer.get_position()[2]);
	}
	return;
}

void Game::move_right() {
	//move player right
	if(this->adventurer.get_position()[1] == this->cave.get_width() - 1) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0], this->adventurer.get_position()[1] + 1, this->adventurer.get_position()[2]);
	}
	return;
}

void Game::move_up_a_level() {
	//move player up a level
	if(this->adventurer.get_position()[2] == this->cave.get_height() - 1) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2] + 1);
	}
	return;
}

void Game::move_down_a_level() {
	//move player down a level
	if(this->adventurer.get_position()[2] == 0) {
		return;
	} else {
		this->adventurer.set_position(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2] - 1);
	}
	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move
	int random = rand() % 4;
	cout << "Random number: " << random << endl;
	if(random != 0) {
		this->cave.replace_wumpus();
	}

	return;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	if(this->adventurer.get_num_arrows() > 0) {
		char dir = get_dir();

		set_wumpus_alive(this->cave.arrow_path(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2], dir));

		this->adventurer.set_num_arrows(this->adventurer.get_num_arrows() - 1);

		// if the wumpus is still alive, move it
		if(get_wumpus_alive() == true) {
			wumpus_move();
		}
	} else {
		cout << "You have no arrows left!" << endl;
	}

	return;

}

void Game::fire_arrow_backwards(){
	// The player may fire arrow...
	if(this->adventurer.get_num_arrows() > 0) {
		char dir = get_dir();

		if(dir == 'w') {
			dir = 's';
		} else if(dir == 'a') {
			dir = 'd';
		} else if(dir == 's') {
			dir = 'w';
		} else if(dir == 'd') {
			dir = 'a';
		}

		set_wumpus_alive(this->cave.arrow_path(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2], dir));

		this->adventurer.set_num_arrows(this->adventurer.get_num_arrows() - 1);

		// if the wumpus is still alive, move it
		if(get_wumpus_alive() == true) {
			wumpus_move();
		}
	} else {
		cout << "You have no arrows left!" << endl;
	}

	return;

}

void Game::move(char c) {
	if (c == 'f'){
		Game::fire_arrow();
	} else if (c == 'v') {
		Game::fire_arrow_backwards();
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
		case 'u':
			Game::move_up_a_level();
			break;
		case 'j':
			Game::move_down_a_level();
			break;
	}
	return;
}

void Game::check_confused(char c, int &confused_timer) {
	// Handle player's action: move or fire an arrow
	if(confused_timer == 0) {
		move(c);
	}
	else {
		if(c == 'w') {
			move('s');
		} else if(c == 'a') {
			move('d');
		} else if(c == 's') {
			move('w');
		} else if(c == 'd') {
			move('a');
		} else if(c == 'u') {
			move('j');
		} else if(c == 'j') {
			move('u');
		} else if (c == 'f') {
			move('v');
		}
		confused_timer--;
	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "U-up a level" << endl;
	cout << "J-down a level" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int w, int l, int h, bool b){

	set_up(w, l, h, b);

	bool gold = false, player_alive = true, confused = false;
	int confused_timer = 0;;

	while (check_win() == false){
		// print caves
		display_game();
		
		//display percerts around player's location
		//Your code here:
		this->cave.check_for_percepts(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2]);

		//Player move...
		//1. get input
		//2. move player
		check_confused(get_input(), confused_timer);

		//3. may or may not encounter events
		//Your code here:
		this->cave.check_for_events(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2], gold, player_alive, confused);

		//4. if the player has the gold, add it
		this->adventurer.set_gold(gold);

		//5. check if the player is still alive
		if(player_alive == false) {
			cout << "You died!" << endl;
			return;
		}
		if(confused) {
			confused_timer = 5;
			confused = false;
		}
	}

	return;

}