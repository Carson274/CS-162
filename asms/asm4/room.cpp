#include <iostream>
#include "room.h"

using namespace std;

Room::Room() {
	this->event = NULL;
    this->has_adventurer = false;
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
void Room::set_has_adventurer(bool has_adventurer) {
    this->has_adventurer = has_adventurer;
}
void Room::set_event_position(const int x, const int y, const int z) {
    this->event->set_position(x, y, z);
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
bool Room::get_has_adventurer() const {
    return this->has_adventurer;
}

void Room::encounter_event(bool &b) {
    cout << this->event->get_name() << endl;
    cout << this->event->get_encounter_message() << endl;
    this->event->encounter(b);

    // clear event once it's been triggered
    this->event = NULL;
}

void Room::play_event_percept() {
    cout << this->event->get_percept_message() << endl;
}

bool Room::is_empty() {
    if(this->event == NULL && this->has_adventurer == false) {
        set_emptiness(true);
    }
    else {
        set_emptiness(false);
    }
    return get_emptiness();
}