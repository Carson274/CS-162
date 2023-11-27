#include <iostream>
#include <ncurses.h>
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

void Cave::display_level(WINDOW *win, int level){
	noecho();
	mvwprintw(win, 4, 94, "______ _     _____  ___________   ");
	mvwprintw(win, 5, 90, "    |  ___| |   |  _  ||  _  | ___ \\   _");
	mvwprintw(win, 6, 90, "    | |_  | |   | | | || | | | |_/ /  (_)");
	mvwprintw(win, 7, 90, "    |  _| | |   | | | || | | |    /   ");
	mvwprintw(win, 8, 90, "    | |   | |___\\ \\_/ /\\ \\_/ / |\\ \\    _");
	mvwprintw(win, 9, 90, "    \\_|   \\_____/\\___/  \\___/\\_| \\_|  (_)");
	if(level == 1) {
		mvwprintw(win, 4, 140, " __         __  _____ ");
		mvwprintw(win, 5, 140, "/  |       / / |____ |");
		mvwprintw(win, 6, 140, "`| |      / /      / /");
		mvwprintw(win, 7, 140, " | |     / /       \\ \\");
		mvwprintw(win, 8, 140, "_| |_   / /    .___/ /");
		mvwprintw(win, 9, 140, "\\___/  /_/     \\____/ ");
	} else if(level == 2) {
		mvwprintw(win, 4, 140, " _____       __  _____ ");
		mvwprintw(win, 5, 140, "/ __  \\     / / |____ |");
		mvwprintw(win, 6, 140, "`' / /'    / /      / /");
		mvwprintw(win, 7, 140, "  / /     / /       \\ \\");
		mvwprintw(win, 8, 140, "./ /___  / /    .___/ /");
		mvwprintw(win, 9, 140, "\\_____/ /_/     \\____/ ");
	} else if(level == 3) {
		mvwprintw(win, 4, 140, " _____       __  _____ ");
		mvwprintw(win, 5, 140, "|____ |     / / |____ |");
		mvwprintw(win, 6, 140, "    / /    / /      / /");
		mvwprintw(win, 7, 140, "    \\ \\   / /       \\ \\");
		mvwprintw(win, 8, 140, ".___/ /  / /    .___/ /");
		mvwprintw(win, 9, 140, "\\____/  /_/     \\____/ ");
	}
}

void Cave::display_health(WINDOW *win, int num_lives) {
	noecho();
	if(num_lives == 3) {
		mvwprintw(win, 12, 94, "  _     _____     _______ ____        _____   _______ ");
		mvwprintw(win, 13, 94, " | |   |_ _\\ \\   / / ____/ ___|   _  |___ /  / /___ / ");
		mvwprintw(win, 14, 94, " | |    | | \\ \\ / /|  _| \\___ \\  (_)   |_ \\ / /  |_ \\ ");
		mvwprintw(win, 15, 94, " | |___ | |  \\ V / | |___ ___) |  _   ___) / /  ___) |");
		mvwprintw(win, 16, 94, " |_____|___|  \\_/  |_____|____/  (_) |____/_/  |____/ ");
	} else if(num_lives == 2) {
		mvwprintw(win, 12, 94, "  _     _____     _______ ____        ____     _______ ");
		mvwprintw(win, 13, 94, " | |   |_ _\\ \\   / / ____/ ___|   _  |___ \\   / /___ / ");
		mvwprintw(win, 14, 94, " | |    | | \\ \\ / /|  _| \\___ \\  (_)   __) | / /  |_ \\ ");
		mvwprintw(win, 15, 94, " | |___ | |  \\ V / | |___ ___) |  _   / __/ / /  ___) |");
		mvwprintw(win, 16, 94, " |_____|___|  \\_/  |_____|____/  (_) |_____/_/  |____/ ");
	} else if(num_lives == 1) {
		mvwprintw(win, 12, 94, "  _     _____     _______ ____        _    _______ ");
		mvwprintw(win, 13, 94, " | |   |_ _\\ \\   / / ____/ ___|   _  / |  / /___ / ");
		mvwprintw(win, 14, 94, " | |    | | \\ \\ / /|  _| \\___ \\  (_) | | / /  |_ \\ ");
		mvwprintw(win, 15, 94, " | |___ | |  \\ V / | |___ ___) |  _  | |/ /  ___) |");
		mvwprintw(win, 16, 94, " |_____|___|  \\_/  |_____|____/  (_) |_/_/  |____/ ");
	}
}

void Cave::display_instructions(bool &arrow_controls, WINDOW *win, int level, int num_lives) {
	noecho();
	display_level(win, level);
	display_health(win, num_lives);
	WINDOW *controls = derwin(win, 12, 40, 34, 128);
	box(controls, 0, 0);
	if(arrow_controls == false) {
		mvwprintw(win, 35, 130, "          -Player Controls-");
		mvwprintw(win, 37, 130, "        w               ^");
		mvwprintw(win, 38, 130, "      a s d           < v >");
		mvwprintw(win, 40, 130, "        u           up a level");
		mvwprintw(win, 41, 130, "        j          down a level");
		mvwprintw(win, 43, 130, "        f           fire arrow");
	} else {
		mvwprintw(win, 35, 130, "           -Fire an Arrow-");
		mvwprintw(win, 37, 130, "           Pick a Direction");
		mvwprintw(win, 40, 130, "        w               ^");
		mvwprintw(win, 41, 130, "      a s d           < v >");
	}
	delwin(controls);
}

void Cave::check_for_percepts(WINDOW *win, int x, int y, int z) {
	noecho();
	//check for percepts around player's location
	int i = 0;
	if(x > 0 && this->rooms[x - 1][y][z].get_event() != NULL) {
		this->rooms[x - 1][y][z].play_event_percept(win, i);
		i++;
	} 
	if(x < get_length() - 1 && this->rooms[x + 1][y][z].get_event() != NULL) {
		this->rooms[x + 1][y][z].play_event_percept(win, i);
		i++;
	} 
	if (y > 0 && this->rooms[x][y - 1][z].get_event() != NULL) {
		this->rooms[x][y - 1][z].play_event_percept(win, i);
		i++;
	} 
	if(y < get_width() - 1 && this->rooms[x][y + 1][z].get_event() != NULL) {
		this->rooms[x][y + 1][z].play_event_percept(win, i);
		i++;
	} 
	if(z > 0 && this->rooms[x][y][z - 1].get_event() != NULL) {
		this->rooms[x][y][z - 1].play_event_percept(win, i);
		i++;
	} 
	if(z < get_height() - 1 && this->rooms[x][y][z + 1].get_event() != NULL) {
		this->rooms[x][y][z + 1].play_event_percept(win, i);
		i++;
	}
	return;
}

void Cave::print_cave(bool &arrow_controls, bool &gold, bool &player_alive, bool &confused, int adventurer_lives, int *adventurer_pos, int *starting_pos, bool debug_mode) {
	noecho();
	WINDOW *win = newwin(47, 170, 3, 6);
	box(win, 0, 0);
	// print the cave so far
	int i = adventurer_pos[2]; // Current level of the adventurer
	display_instructions(arrow_controls, win, i + 1, adventurer_lives);
	for(int j = 0; j < get_length(); ++j) {
		for(int k = 0; k < get_width(); ++k) {
			WINDOW *cell = derwin(win, 9, 17, j * 9 + 1, k * 17 + 2);
			box(cell, 0, 0);
			int midY = getmaxy(cell) / 2;
			int midX = getmaxx(cell) / 2;
			if(adventurer_pos[0] == j && adventurer_pos[1] == k && adventurer_pos[2] == i){
				mvwprintw(cell, midY, midX, "*");
			} else if(starting_pos[0] == j && starting_pos[1] == k && starting_pos[2] == i) {
				mvwprintw(cell, midY, midX, "X");
			} else if(rooms[j][k][i].get_event() == NULL) {
				mvwprintw(cell, midY, midX, " ");
			} else if(debug_mode) {
				mvwprintw(cell, midY, midX, "%c", this->rooms[j][k][i].get_event_icon());
			} else {
				mvwprintw(cell, midY, midX, " ");
			}
			delwin(cell); // delete the cell window
		}
	}
	//display percerts around player's location
	check_for_events(win, adventurer_pos[0], adventurer_pos[1], adventurer_pos[2], gold, player_alive, confused);
	check_for_percepts(win, adventurer_pos[0], adventurer_pos[1], adventurer_pos[2]);
	refresh();
	wrefresh(win);
	delwin(win);
}

void Cave::place_adventurer(int x, int y, int z) {
	// place the adventurer in the cave
	this->rooms[x][y][z].set_has_adventurer(true);
}

void Cave::place_events() {
	// place the events in the cave
	// for each room, 
	int row_idx = -1, col_idx = -1, hei_idx = -1;
	for(int i = 0; i < 2; ++i){
		do {
			row_idx = rand() % get_length();
			col_idx = rand() % get_width();
			hei_idx = rand() % get_height();
		} while(this->rooms[row_idx][col_idx][hei_idx].get_event() != NULL || this->rooms[row_idx][col_idx][hei_idx].get_has_adventurer() == true);

		if(i == 0) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Gold());
		} else if(i == 1) {
			this->rooms[row_idx][col_idx][hei_idx].set_event(new Wumpus());
		} 
	}
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 4; ++j) {
			do {
				row_idx = rand() % get_length();
				col_idx = rand() % get_width();
				hei_idx = i;
			} while(this->rooms[row_idx][col_idx][hei_idx].get_event() != NULL || this->rooms[row_idx][col_idx][hei_idx].get_has_adventurer() == true);
			
			if(j == 0 || j == 1) {
				this->rooms[row_idx][col_idx][hei_idx].set_event(new Stalactites());
			} else if(j == 2 || j == 3) {
				this->rooms[row_idx][col_idx][hei_idx].set_event(new Bats());
			}
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

void Cave::check_for_events(WINDOW *win, int x, int y, int z, bool &gold, bool &player_alive, bool& confused) {
	// check for event at player's location
	if(this->rooms[x][y][z].get_event() != NULL) {
		if(this->rooms[x][y][z].get_event_icon() == 'G') {
			this->rooms[x][y][z].encounter_event(win, gold);
		} else if(this->rooms[x][y][z].get_event_icon() == 'W' || this->rooms[x][y][z].get_event_icon() == 'S') {
			this->rooms[x][y][z].encounter_event(win, player_alive);
		} else if(this->rooms[x][y][z].get_event_icon() == 'B') {
			this->rooms[x][y][z].encounter_event(win, confused);
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
						return false;
					}
				}
			}
		}
	}
	return true;
}