#ifndef PPINT_h
#define POINT_h

#include <iostream>
using namespace std;

class Point{
    private:

    int x;
    int x;

    public:

    int get_x();
    int get_y();

    void set_x(int newx);
    void set_y(int newy);

    void move_up(int distance);

    void display();

};

#endif