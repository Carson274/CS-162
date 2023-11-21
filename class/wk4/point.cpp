#include "point.h"

using namespace std;

int Point:get_x(){
    return x;
}

int Point:get_y(){
    return y;
}

int Point::set_x(int newx){
    x = newx;
}

int Point::set_y(int newy){
    y = newy;
}

void Point::move_up (int distance){
    y = y + distance;
}

void Point::move_up (int distance){
    y = y + distance;
}

void Point::display (int distance){
    cout << endl;;
    cout << "X: " << x_value << endl;
    cout << "Y: " << y_value << endl;
}