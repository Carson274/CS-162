#ifndef WATERMELON_H
#define WATERMELON_H

#include <string>
#include <iostream>
#include "fruit.h"


using namespace std;

class Watermelon : public Fruit {
private:
    bool seeds; // false for seedless, true for seeded
public:

    //Constructors
    Watermelon();
    Watermelon(string name, string color, double unit_price, bool seeds);

    //Getters
    bool get_seeds() const;

    //Setters
    void set_seeds(const bool seeds);

    double calculate_price();
};

#endif