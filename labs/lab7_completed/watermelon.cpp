#include "watermelon.h"
using namespace std;

Watermelon::Watermelon()
{
    this->seeds = false;
}

Watermelon::Watermelon(string name, string color, double unit_price, bool seeds) : Fruit(name, color, unit_price)
{
    this->seeds = seeds;
}

//Getters
bool Watermelon::get_seeds() const
{
    return this->seeds;
}

//Setters
void Watermelon::set_seeds(const bool seeds)
{
    this->seeds = seeds;
}

double Watermelon::calculate_price()
{
    if(this->seeds)
    {
        return ((this->unit_price) * 1.2);
    }
    else
    {
        return (this->unit_price);
    }
}

