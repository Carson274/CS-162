#include <iostream>
#include "adventurer.h"

using namespace std;

Adventurer::Adventurer() {
	this->num_arrows = 3;
	this->num_lives = 1;
}

Adventurer::~Adventurer() {
}

void Adventurer::set_num_arrows(const int num_arrows) {
    this->num_arrows = num_arrows;
}
void Adventurer::set_num_lives(const int num_lives) {
    this->num_lives = num_lives;
}
int Adventurer::get_num_arrows() const {
    return this->num_arrows;
}
int Adventurer::get_num_lives() const {
    return this->num_lives;
}
