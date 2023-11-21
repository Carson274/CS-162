#include "coffee.h"

using namespace std;

// coffee constructor
Coffee::Coffee(){
    // cout << "Coffee()" << endl;
    this->name = "";
    this->small_cost = 0.0;
    this->medium_cost = 0.0;
    this->large_cost = 0.0;
}

Coffee::~Coffee(){
    // cout << "~Coffee()" << endl;
}

void Coffee::populate_coffee(ifstream& fin){
	//populate a single coffee object
	fin >> this->name >> this->small_cost >> this->medium_cost >> this->large_cost;
}

void Coffee::display_coffee(){
	cout << this->name << endl;
	cout << "Small  -  " << fixed << setprecision(2) << this->small_cost << endl;
	cout << "Medium -  " << fixed << setprecision(2) << this->medium_cost << endl;
	cout << "Large  -  " << fixed << setprecision(2) << this->large_cost << endl;
	cout << endl;
}

void Coffee::display_small_and_medium_coffee_only(){
	cout << this->name << endl;
	cout << "Small  -  " << fixed << setprecision(2) << this->small_cost << endl;
	cout << "Medium -  " << fixed << setprecision(2) << this->medium_cost << endl;
    cout << endl;
}

void Coffee::display_small_coffee_only(){
    cout << this->name << endl;
    cout << "Small  -  " << fixed << setprecision(2) << this->small_cost << endl;
    cout << endl;
}

void Coffee::display_coffee_names(){
    cout << this->name << endl;
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

float Coffee::get_coffee_cost(char size) const{
    float cost = 0.0;
    if(size == 's'){
        cost = this->get_small_cost();
    }
    else if(size == 'm'){
        cost = this->get_medium_cost();
    }
    else if(size == 'l'){
        cost = this->get_large_cost();
    }
    return cost;
}