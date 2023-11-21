#include "order.h"

using namespace std;


//function defintions from order.h goes here
// order constructor
Order::Order(){
    // cout << "Order()" << endl;
    this->id = 0;
    this->coffee_name = "";
    this->coffee_size = ' ';
    this->quantity = 0;
    this->price = 0.00;
}

Order::Order(int id, string coffee_name, char coffee_size, int quantity, float price){
    // cout << "Order(int,string,char,int,float)" << endl;
    this->id = id;
    this->coffee_name = coffee_name;
    this->coffee_size = coffee_size;
    this->quantity = quantity;
    this->price = price;
}

Order::~Order(){
	// Cout << "~Order()" << endl;
}

void Order::create_order(ifstream &fin){
    fin >> this->id >> this->coffee_name >> this->coffee_size >> this->quantity;
}

void Order::append_order(ofstream &fout){
    fout << this->id << " " << this->coffee_name << " " << this->coffee_size << " " << this->quantity << endl;
}

void Order::display_order(){
    cout << this->id << " " << this->coffee_name << " " << this->coffee_size << " " << this->quantity << endl;
}

int Order::get_id() const {
    return id;
}

string Order::get_coffee_name() const {
    return coffee_name;
}

char Order::get_coffee_size() const {
    return coffee_size;
}

int Order::get_quantity() const {
    return quantity;
}

float Order::get_price() const {
    return price;
}

int Order::get_num_occurrences() const {
    return num_occurences;
}

void Order::set_id(int new_id) {
    id = new_id;
}

void Order::set_coffee_name(const string new_coffee_name) {
    coffee_name = new_coffee_name;
}

void Order::set_coffee_size(const char new_coffee_size) {
    coffee_size = new_coffee_size;
}

void Order::set_quantity(const int new_quantity) {
    quantity = new_quantity;
}

void Order::set_price(const float new_price) {
    price = new_price;
}

void Order::set_num_occurrences(const int new_num_occurences) {
    num_occurences = new_num_occurences;
}

float Order::calculate_total() const {
    return quantity * price;
}