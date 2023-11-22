#include <iostream>
#include "room.h"

using namespace std;

Room::Room() {
	this->event = NULL;
}

Room::~Room() {
}

void Room::set_event(Event* event) {
    this->event = event;
}

Event* Room::get_event() const {
    return this->event;
}