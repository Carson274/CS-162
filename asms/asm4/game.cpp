#include <iostream>
#include "game.h"

using namespace std;

//Game Implementation

Game::Game(){
	this->debug_view = false;
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
	cout << "Num of arrows: " << this->adventurer.get_num_arrows() << endl;
}

//Note: you need to modify this function
void Game::display_game(){
	cout << endl << endl;
	
	cout << "Arrows remaining: " << this->adventurer.get_num_arrows() << endl;
	
	this->cave.print_cave();
}

bool Game::check_win() const{
	//check if game over/win
	//Your code here:

	cout << "Game::check_win() is not implemented..." << endl;
	return false;
}

void Game::move_up() {
	//move player up
	//Your code here:

	cout << "Game::move_up() is not implemented..." << endl;
	return;

}

void Game::move_down() {
	//move player down
	//Your code here:

	cout << "Game::move_down() is not implemented..." << endl;
	return;
}

void Game::move_left() {
	//move player left
	//Your code here:

	cout << "Game::move_left() is not implemented..." << endl;
	return;

}

void Game::move_right() {
	//move player right
	//Your code here:

	cout << "Game::move_right() is not implemented..." << endl;
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
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int w, int l, int h, bool b){

	this->set_up(w, l, h, b);

	display_game();

	// char input, arrow_input;
	
	// while (Game::check_win() == false){
	// 	//print game board
	// 	

	// 	//display percerts around player's location
	// 	//Your code here:

	// 	//Player move...
	// 	//1. get input
	// 	input = Game::get_input();

	// 	//2. move player
	// 	Game::move(input);

	// 	//3. may or may not encounter events
	// 	//Your code here:

	// }
	
	
	return;

}