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

    void print_cave();

    void set_length(const int);
    void set_width(const int);
    void set_height(const int);
    int get_length() const;
    int get_width() const;
    int get_height() const;

};

#endif