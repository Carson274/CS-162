#include <iostream>
#include "room.h"

using namespace std;

Room::Room() {
	this->event = NULL;
    this->has_player = false;
    this->emptiness = true;
}

Room::~Room() {
    delete this->event;
}

void Room::set_event(Event* event) {
    this->event = event;
}
void Room::set_emptiness(bool emptiness) {
    this->emptiness = emptiness;
}
Event* Room::get_event() const {
    return this->event;
}
bool Room::get_emptiness() const {
    return this->emptiness;
}
char Room::get_event_icon() {
    return this->event->get_icon();
}
int* Room::get_event_position() {
    return this->event->get_position();
}

void Room::encounter_event(bool &gold) {
    cout << this->event->get_name() << endl;
    cout << this->event->get_encounter_message() << endl;
    if(this->event->get_name() == "Gold") {
        gold = true;
    }
}

void Room::play_event_percept() {
    cout << this->event->get_percept_message() << endl;
}

bool Room::is_empty() {
    if(this->event == NULL && this->has_player == false) {
        set_emptiness(true);
    }
    else {
        set_emptiness(false);
    }
    return get_emptiness();
}