#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>
#include <string>

using namespace std;

class Fruit {
    protected:
        const string name; //note the keyword ‘const’
        string color;
        double unit_price;
    public:

    
        string get_name() const;
        string get_color() const;
        double get_unit_price() const;

        void set_name(const string);
        void set_color(const string);
        void set_unit_price(const double);
};

#endif