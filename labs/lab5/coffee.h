#include <iostream>
#include <cstdlib>

using namespace std;

class Coffee {
    private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;

    public:
    Coffee();

    void set_name (const string);
    void set_small_cost(const float);
    void set_medium_cost(const float);
    void set_large_cost(const float);

    string get_name() const;
    float get_small_cost() const;
    float get_medium_cost() const;
    float get_large_cost() const;

    void print_coffee() const; //print the coffee object
};