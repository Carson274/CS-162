#include "fruit.h"

using namespace std;

//Constructors
Fruit::Fruit() : name("")
{
    this->color = "";
    this->unit_price = 0.0;
}

Fruit::Fruit(string name, string color, double unit_price) : name(name)
{
    this->color = color;
    this->unit_price = unit_price;
}

Fruit::~Fruit()
{
    // cout << "Fruit Destructor" << endl;
}

//Getters
string Fruit::get_name() const
{
    return this->name;
}

string Fruit::get_color() const
{
    return this->color;
}

double Fruit::get_unitPrice() const
{
    return this->unit_price;
}

//Setters
void Fruit::set_color(const string color)
{
    this->color = color;
}

void Fruit::set_unitPrice(const double unit_price)
{
    this->unit_price = unit_price;
}

double Fruit::calculate_price()
{
    return 0.0;
}

