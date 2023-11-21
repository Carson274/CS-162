#include "fruit.h"

using namespace std;

Fruit::Fruit() : name(name)
{
    this->color = "";
    this->unit_price = 0.0;
}

Fruit::Fruit(string name, string color, double unit_price) : name(name)
{
    this->color = color;
    this->unit_price = unit_price;
}

Fruit::~Fruit(){
    cout << "Fruit destructor called" << endl;
}

string Fruit::get_name(){
    return this->name;
}
string Fruit::get_color(){
    return this->color;
}
float Fruit::get_unit_price(){
    return this->unit_price;
}

void Fruit::set_name(const string name){
    this->name = name;
}
void Fruit::set_color(const string color){
    this->color = color;
}
void Fruit::set_unit_price(const double unit_price){
    this->unit_price = unit_price;
}