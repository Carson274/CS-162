#ifndef ROOM_H
#define ROOM_H 

#include <vector>
#include <iostream>
#include "event.h"
#include "gold.h"
#include "wumpus.h"
#include "bats.h"
#include "stalactites.h"

using namespace std;

class Room
{
private: 
    Event* event;	//event in the room
    bool has_player;
    bool emptiness;
public:
    Room();
    ~Room();

    void set_event(Event*);	//set the event in the room
    void set_emptiness(bool);
    Event* get_event() const;	//get the event in the room
    bool get_emptiness() const;
    char get_event_icon();
    int* get_event_position();

    void encounter_event(bool &);

    void play_event_percept();

    bool is_empty();
};

#endif