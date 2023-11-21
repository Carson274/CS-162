#include "Granny_Smith.h"
#include <iostream>

using namespace std;

Granny_Smith::Granny_Smith(string name, string color, double unit_price, float weight) : Apple(name, color, unit_price, weight, false)
{}

//Setters
void Granny_Smith::set_sweetness(const bool sweetness)
{
    cout << "You can't set this to true... haha";
}


