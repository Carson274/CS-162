#ifndef GRANNY_SMITH_H
#define GRANNY_SMITH_H

#include <string>
#include <iostream>
#include "apple.h"

using namespace std;

class Granny_Smith : public Apple {
public:
    
    //Constructors
    Granny_Smith(string name, string color, double unit_price, float weight);

    //Setters
    void set_sweetness(const bool sweetness);

};

#endif