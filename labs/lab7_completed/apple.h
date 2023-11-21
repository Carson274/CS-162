#ifndef APPLE_H
#define APPLE_H

#include <string>
#include <iostream>
#include "fruit.h"

using namespace std;

class Apple : public Fruit {
private:
    float weight;
    bool sweetness; // false for not sweet, true for sweet
public:
    
    //Constructors
    Apple();
    Apple(string name, string color, double unit_price, float weight, bool sweetness);

    //Getters
    float get_weight() const;
    bool get_sweetness() const;

    //Setters
    void set_weight(const float weight);
    void set_sweetness(const bool sweetness);

    double calculate_price();
};

#endif