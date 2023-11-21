#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "coffee.h"

using namespace std;

Coffee::Coffee(){
    cout << "Coffee()" << endl;
    this->name = "";
    this->small_cost = 0.0;
    this->medium_cost = 0.0;
    this->large_cost = 0.0;
}

void Coffee::set_name(const string name){
    this->name = name;
}

void Coffee::set_small_cost(const float cost){
    this->small_cost = cost;
}

void Coffee::set_medium_cost(const float cost){
    this->medium_cost = cost;
}

void Coffee::set_large_cost(const float cost){
    this->large_cost = cost;
}

string Coffee::get_name() const{
    return name;
}

float Coffee::get_small_cost() const{
    return small_cost;   
}

float Coffee::get_medium_cost() const{
    return medium_cost;
}

float Coffee::get_large_cost() const{
    return large_cost;
}

void Coffee::print_coffee() const{
    cout << "Name: " << this->name << endl;
    cout << "Small: " << this->small_cost << endl;
    cout << "Medium cost: " << this->medium_cost << endl;
    cout << "Large cost: " << fixed << setprecision(2) << this->large_cost << endl;
}