#ifndef CAVE_H
#define CAVE_H 

#include <vector>
#include <iostream>
#include "room.h"

using namespace std;

class Cave 
{
private:
    int length;
    int width;
    int height;
    vector<vector<vector<Room > > > rooms;
public:
    Cave();
    ~Cave();

    void setup_cave();

    void display_level(WINDOW *, int);

    void display_health(WINDOW *, int);

    void display_instructions(bool &, WINDOW *, int, int);

    void check_for_percepts(WINDOW *, int, int, int);

    void print_cave(bool &, int, int *, int *, bool);

    void place_adventurer(int, int, int);

    void place_events();

    void replace_wumpus();

    void check_for_events(int, int, int, bool&, bool&, bool&);

    bool arrow_path(int, int, int, char);

    void set_length(const int);
    void set_width(const int);
    void set_height(const int);
    int get_length() const;
    int get_width() const;
    int get_height() const;

};

#endif