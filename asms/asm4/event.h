#ifndef EVENT_H
#define EVENT_H 

#include <vector>
#include <iostream>
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{
protected:
    string name;
    string percept;
    string encounter;
public:
	Event();
    ~Event();
	
};

#endif