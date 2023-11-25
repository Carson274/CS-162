#include <iostream>
#include "cave.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

using namespace std;

Cave::Cave() {
	this->length = 0;
	this->width = 0;
	this->height = 0;
}

Cave::~Cave() {
	// dont forget to delete the events
	
}

void Cave::setup_cave(){
	// setting the length
	this->rooms.resize(get_length());

	// for each row, set the width
	for (size_t i = 0; i < get_length(); ++i)
	{
		rooms[i].resize(get_width());
	}

	// for each room, set the height
	for (int i = 0; i < get_length(); ++i)
	{
		for (int j = 0; j < get_width(); ++j)
		{
			rooms[i][j].resize(get_height());
		}
	}

	// initialize each room object
	for (int i = 0; i < get_length(); ++i)
	{
		for (int j = 0; j < get_width(); ++j)
		{
			for (int k = 0; k < get_height(); ++k)
			{
				rooms[i][j][k] = Room();
			}
		}
	}
}

void Cave::set_length(const int length) {
	this->length = length;
}
void Cave::set_width(const int width) {
	this->width = width;
}
void Cave::set_height(const int height) {
	this->height = height;
}
int Cave::get_length() const {
	return this->length;
}
int Cave::get_width() const {
	return this->width;
}
int Cave::get_height() const {
	return this->height;
}

void Cave::print_cave(int *adventurer_pos, int *starting_pos, bool debug_mode) {
	// print the cave so far
	for(int i = 0; i < get_height(); ++i) {
		cout << "Level " << i + 1 << ": " << endl;
		cout << "┌---┬---┬---┬---┬---┐" << endl;
		for(int j = 0; j < get_length(); ++j) {
			for(int k = 0; k < get_width(); ++k) {
				cout << "|";
				if(rooms[j][k][i].get_event() == NULL) {
					if(adventurer_pos[0] == j && adventurer_pos[1] == k && adventurer_pos[2] == i){
						cout << " * ";
					} else if(starting_pos[0] == j && starting_pos[1] == k && starting_pos[2] == i) {
						cout << " X ";
					} else {
						cout << "   ";
					}
				} else if (debug_mode) {
					cout << " " << this->rooms[j][k][i].get_event_icon() << " ";
				}
				else {
					cout << "   ";
				}
			}
			cout << "|" << endl;
			if(j != get_length() - 1) {
				cout << "├---┼---┼---┼---┼---┤" << endl;
			}
		}
		cout << "└---┴---┴---┴---┴---┘" << endl;
	}
}

void Cave::place_adventurer(int x, int y, int z) {
	// place the adventurer in the cave
	this->rooms[x][y][z].set_has_adventurer(true);
}

void Cave::place_events() {
	// place the events in the cave
	// for each room, 
	int row_idx = -1, col_idx = -1, hei_idx = -1;
	for(int i = 0; i < 6; ++i){
		do {
			row_idx = rand() % get_length();
			col_idx = rand() % get_width();
			hei_idx = rand() % get_height();
		} while(this->rooms[row_idx][col_idx][hei_idx].get_event() != NULL || this->rooms[row_idx][col_idx][hei_idx].get_has_adventurer() == true);

		if(i == 0) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Gold());
		} else if(i == 1) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Wumpus());
		} else if(i == 2 || i == 3) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Stalactites());
		} else if(i == 4 || i == 5) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Bats());
		}
	}
}

void Cave::replace_wumpus() {
	// place the wumpus in the cave
	int row_idx = -1, col_idx = -1, hei_idx = -1;
	do {
		row_idx = rand() % get_length();
		col_idx = rand() % get_width();
		hei_idx = rand() % get_height();
	} while(this->rooms[row_idx][col_idx][hei_idx].get_event() != NULL || this->rooms[row_idx][col_idx][hei_idx].get_has_adventurer() == true);

	// get the wumpus
	for(int i = 0; i < get_length(); ++i) {
		for(int j = 0; j < get_width(); ++j) {
			for(int k = 0; k < get_height(); ++k) {
				if(this->rooms[i][j][k].get_event() != NULL) {
					if(this->rooms[i][j][k].get_event_icon() == 'W') {
						this->rooms[i][j][k].set_event(NULL);
						this->rooms[row_idx][col_idx][hei_idx].set_event(new Wumpus());
					}
				}
			}
		}
	}

}

void Cave::check_for_percepts(int x, int y, int z) {
	//check for percepts around player's location
	if(x > 0 && this->rooms[x - 1][y][z].get_event() != NULL) {
		this->rooms[x - 1][y][z].play_event_percept();
	} 
	if(x < get_length() - 1 && this->rooms[x + 1][y][z].get_event() != NULL) {
		this->rooms[x + 1][y][z].play_event_percept();
	} 
	if (y > 0 && this->rooms[x][y - 1][z].get_event() != NULL) {
		this->rooms[x][y - 1][z].play_event_percept();
	} 
	if(y < get_width() - 1 && this->rooms[x][y + 1][z].get_event() != NULL) {
		this->rooms[x][y + 1][z].play_event_percept();
	} 
	if(z > 0 && this->rooms[x][y][z - 1].get_event() != NULL) {
		this->rooms[x][y][z - 1].play_event_percept();
	} 
	if(z < get_height() - 1 && this->rooms[x][y][z + 1].get_event() != NULL) {
		this->rooms[x][y][z + 1].play_event_percept();
	}
	return;
}

void Cave::check_for_events(int x, int y, int z, bool &gold, bool &player_alive, bool& confused) {
	// check for event at player's location
	if(this->rooms[x][y][z].get_event() != NULL) {
		if(this->rooms[x][y][z].get_event_icon() == 'G') {
			this->rooms[x][y][z].encounter_event(gold);
		} else if(this->rooms[x][y][z].get_event_icon() == 'W' || this->rooms[x][y][z].get_event_icon() == 'S') {
			this->rooms[x][y][z].encounter_event(player_alive);
		} else if(this->rooms[x][y][z].get_event_icon() == 'B') {
			this->rooms[x][y][z].encounter_event(confused);
		}
	}
	return;
}

bool Cave::arrow_path(int current_x, int current_y, int current_z, char direction) {
	if(direction == 'w') {
		for(int x = 0; x < 4; ++x){
			if(current_x - 1 < 0 || x == 3) {
				cout << "You missed!" << endl;
				break;
			} 
			else {
				current_x--;
				if(this->rooms[current_x][current_y][current_z].get_event() != NULL) {
					if(this->rooms[current_x][current_y][current_z].get_event_icon() == 'W') {
						cout << "You killed the Wumpus!" << endl;
						return false;
					}
				}
			}
		}
	}
	else if(direction == 'a') {
		for(int y = 0; y < 4; ++y){
			if(current_y - 1 < 0 || y == 3) {
				cout << "You missed!" << endl;
				break;
			} 
			else {
				current_y--;
				if(this->rooms[current_x][current_y][current_z].get_event() != NULL) {
					if(this->rooms[current_x][current_y][current_z].get_event_icon() == 'W') {
						cout << "You killed the Wumpus!" << endl;
						return false;
					}
				}
			}
		}
	}
	else if(direction == 's') {
		for(int x = 0; x < 4; ++x){
			if(current_x + 1 > get_length() - 1 || x == 3) {
				cout << "You missed!" << endl;
				break;
			} 
			else {
				current_x++;
				if(this->rooms[current_x][current_y][current_z].get_event() != NULL) {
					if(this->rooms[current_x][current_y][current_z].get_event_icon() == 'W') {
						cout << "You killed the Wumpus!" << endl;
						return false;
					}
				}
			}
		}
	}
	else if(direction == 'd') {
		for(int y = 0; y < 4; ++y){
			if(current_y + 1 > get_height() - 1 || y == 3) {
				cout << "You missed!" << endl;
				break;
			} 
			else {
				current_y++;
				if(this->rooms[current_x][current_y][current_z].get_event() != NULL) {
					if(this->rooms[current_x][current_y][current_z].get_event_icon() == 'W') {
						cout << "You killed the Wumpus!" << endl;
						return false;
					}
				}
			}
		}
	}
	return true;
}

// void Cave::print_cave(){
//     string line = "";
// 	for (int i = 0; i < this->width; ++i)
// 		line += "-----";

// 	for (int i = 0; i < this->length; ++i)
// 	{
// 		cout << line << endl;
// 		for (int j = 0; j < this->width; ++j)
// 		{
// 			// The first char indicates whether there is a player in that room or not
// 			// if the room does not have the player, print space " "

// 			// else, print "*"

// 			// Fix the following
// 			cout << " ";
			

// 			// The next two chars indicate the event in the room
// 			// if the room does not have an event, print "  ||" (2 spaces + ||)
			
// 			// else, 
// 				// if debug_view is true
// 					// print the corresponding char of the event
// 				// else
// 					// print " " (1 space)
// 				// print " ||" (1 space + ||)

// 			//Fix the following...
// 			cout << "  ||";
// 		}
// 		cout << endl;
// 	}
// 	cout << line << endl;

// 	// example output (when finished): 
// 	// --------------------
// 	//  B || G || B ||   ||
// 	// --------------------
// 	//    || W ||   || S ||
// 	// --------------------   
// 	//    ||   ||   || S ||
// 	// --------------------   
// 	// *  ||   ||   ||   ||
// 	// --------------------
// }