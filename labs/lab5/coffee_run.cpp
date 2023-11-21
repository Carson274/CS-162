#include <iostream>
#include <cstdlib>
#include "coffee.h"

using namespace std;

int main(){
    Coffee c1;
    c1.set_name("Big Mocha");
    c1.set_small_cost(2.50);
    c1.set_medium_cost(4.00);
    c1.set_large_cost(5.50);

    c1.get_name();
    c1.get_small_cost();
    c1.get_medium_cost();
    c1.get_large_cost();

    c1.print_coffee();
    Coffee c2;


    return 0;
}