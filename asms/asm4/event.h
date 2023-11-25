#ifndef EVENT_H
#define EVENT_H 

#include <vector>
#include <iostream>


using namespace std;

class Event
{
protected:
    string name;
    string percept_message;
    string encounter_message;
    int position[3];
    char icon;
public:
	Event();
    ~Event();

    void set_position(const int, const int, const int);
    
    virtual string get_name() = 0;
    virtual string get_encounter_message() = 0;
    virtual string get_percept_message() = 0;
    virtual int* get_position() = 0;
    virtual char get_icon() = 0;
};

#endif