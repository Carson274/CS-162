#include <iostream>
#include "cave.h"

using namespace std;

Cave::Cave() {
	this->length = 0;
	this->width = 0;
	this->height = 0;
}

Cave::~Cave() {
}

void Cave::print_cave() {
	// print the cave so far
	for(int i = 0; i < get_height(); ++i) {
		cout << "Level " << i + 1 << ": " << endl;
		cout << "┌---┬---┬---┬---┬---┐" << endl;
		for(int j = 0; j < get_length(); ++j) {
			for(int k = 0; k < get_width(); ++k) {
				cout << "|";
				if(rooms[j][k][i].get_event() == NULL) {
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