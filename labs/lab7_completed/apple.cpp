#include "apple.h"
using namespace std;

Apple::Apple()
{
    this->weight = 0.0;
    this->sweetness = false;
}

Apple::Apple(string name, string color, double unit_price, float weight, bool sweetness) : Fruit(name, color, unit_price)
{
    this->weight = weight;
    this->sweetness = sweetness;
}

//Getters
float Apple::get_weight() const
{
    return this->weight;
}

bool Apple::get_sweetness() const
{
    return this->sweetness;
}

//Setters
void Apple::set_weight(const float weight)
{
    this->weight = weight;
}

void Apple::set_sweetness(const bool sweetness)
{
    this->sweetness = sweetness;
}

double Apple::calculate_price()
{
    return ((this->unit_price) * this->weight);
}


