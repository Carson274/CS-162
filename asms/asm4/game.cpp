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

	this->cave.print_cave(this->adventurer.get_position(), this->starting_position, this->debug_view);
}

bool Game::check_win() {
	//check if game over/win
	if(this->adventurer.get_gold() == true && (this->adventurer.get_position()[0] == this->starting_position[0] && this->adventurer.get_position()[1] == this->starting_position[1] && this->adventurer.get_position()[2] == this->starting_position[2])) {
		cout << "Congradulations, you win!" << endl;
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

	//Your code here:
	cout << "Game::wumpus_move() is not implemented..." << endl;
	
	return;
}

void Game::fire_arrow(){
	// The player may fire arrow...
	char dir = get_dir();
	//Your code here:
	cout << "Game::fire_arrow() is not implemented..." << endl;

	return;

}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
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

	int input;
	bool gold = false;
	
	while (check_win() == false){
		// print caves
		display_game();
		
		//display percerts around player's location
		//Your code here:
		this->cave.check_for_percepts(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2]);

		//Player move...
		//1. get input
		input = get_input();

		//2. move player
		move(input);

		//3. may or may not encounter events
		//Your code here:
		this->cave.check_for_events(this->adventurer.get_position()[0], this->adventurer.get_position()[1], this->adventurer.get_position()[2], gold);

		//4. if the player has the gold, add it
		this->adventurer.set_gold(gold);
	}
	
	
	return;

}