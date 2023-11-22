#ifndef ROOM_H
#define ROOM_H 

#include <vector>
#include <iostream>
#include "event.h"

using namespace std;

class Room
{
private: 
    Event* event;	//event in the room
    bool has_player;
public:
    Room();
    ~Room();

    void set_event(Event*);	//set the event in the room
    Event* get_event() const;	//get the event in the room

};

#endif