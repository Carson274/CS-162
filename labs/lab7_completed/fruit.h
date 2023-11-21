#ifndef FRUIT_H
#define FRUIT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Fruit {
protected:
    const string name; //note the keyword ‘const’
    string color;
    double unit_price;
public:
    //Constructors
    Fruit();
    Fruit(string name, string color, double unit_price);
    virtual ~Fruit();

    //Getters
    string get_name() const;
    string get_color() const;
    double get_unitPrice() const;

    //Setters
    void set_color(const string color);
    void set_unitPrice(const double unit_price);

    virtual double calculate_price() = 0;
};

#endif