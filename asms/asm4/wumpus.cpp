#include "wumpus.h"

#include <iostream>

using namespace std;

Wumpus::Wumpus() {
    this->name = "Wumpus";
    this->is_alive = true;
    this->position[0] = 0;
    this->position[1] = 0;
    this->position[2] = 0;
    this->icon = 'W';
    this->percept_message = "You smell a terrible stench.";
    this->encounter_message = "You have encountered the Wumpus!";
}

Wumpus::~Wumpus() {
}

void Wumpus::set_alive(const bool alive) {
    this->is_alive = is_alive;
}
void Wumpus::set_position(const int x, const int y, const int z) {
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
bool Wumpus::get_alive() const {
    return this->is_alive;
}
int* Wumpus::get_position() {
    return this->position;
}
char Wumpus::get_icon() {
    return this->icon;
}
string Wumpus::get_name() {
    return this->name;
}
string Wumpus::get_percept_message() {
    return this->percept_message;
}
string Wumpus::get_encounter_message() {
    return this->encounter_message;
}