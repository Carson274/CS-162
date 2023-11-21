#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

class Coffee {
  private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    
  public:
    /**************************************************
     ** Name: Coffee()
    ** Description: Default constructor for the Coffee class
    ** Parameters: none
    ** Pre-conditions: none
    ** Post-conditions: a new Coffee object is created with default values
    ***********************************************/
    Coffee();

    /**************************************************
     ** Name: ~Coffee()
    ** Description: Destructor for the Coffee class
    ** Parameters: none
    ** Pre-conditions: a Coffee object exists
    ** Post-conditions: the Coffee object is destroyed and its memory is freed
    ***********************************************/
    ~Coffee();

    /**************************************************
    ** Name: populate_coffee()
    ** Description: This function will populate the coffee data from the file
    ** Parameters: ifstream - an input file object
    ** Pre-conditions: none
    ** Post-conditions: coffee data is populated
    ***********************************************/
    void populate_coffee(ifstream&);

    /**************************************************
    ** Name: display_coffee()
    ** Description: This function will display the coffee data
    ** Parameters: none
    ** Pre-conditions: coffee data is populated
    ** Post-conditions: coffee data is displayed
    ***********************************************/
    void display_coffee();
    
    /**************************************************
    ** Name: display_small_and_medium_coffee_only()
    ** Description: This function will display the details of only small and medium coffees
    ** Parameters: none
    ** Pre-conditions: coffee data is populated
    ** Post-conditions: details of small and medium coffees are displayed
    ***********************************************/
    void display_small_and_medium_coffee_only();

    /**************************************************
    ** Name: display_small_coffee_only()
    ** Description: This function will display the details of only small coffees
    ** Parameters: none
    ** Pre-conditions: coffee data is populated
    ** Post-conditions: details of small coffees are displayed
    ***********************************************/
    void display_small_coffee_only();

    /**************************************************
    ** Name: display_coffee_names()
    ** Description: This function will display the names of all coffees
    ** Parameters: none
    ** Pre-conditions: coffee data is populated
    ** Post-conditions: names of all coffees are displayed
    ***********************************************/
    void display_coffee_names();

    // coffee setters
    /**************************************************
    ** Name: set_name()
    ** Description: This function will set the name of the coffee
    ** Parameters: const string - the name of the coffee
    ** Pre-conditions: none
    ** Post-conditions: the name of the coffee is set
    ***********************************************/
    void set_name(const string);

    /**************************************************
    ** Name: set_small_cost()
    ** Description: This function will set the cost of the small coffee
    ** Parameters: const float - the cost of the small coffee
    ** Pre-conditions: none
    ** Post-conditions: the cost of the small coffee is set
    ***********************************************/
    void set_small_cost(const float);

    /**************************************************
    ** Name: set_medium_cost()
    ** Description: This function will set the cost of the medium coffee
    ** Parameters: const float - the cost of the medium coffee
    ** Pre-conditions: none
    ** Post-conditions: the cost of the medium coffee is set
    ***********************************************/
    void set_medium_cost(const float);

    /**************************************************
    ** Name: set_large_cost()
    ** Description: This function will set the cost of the large coffee
    ** Parameters: const float - the cost of the large coffee
    ** Pre-conditions: none
    ** Post-conditions: the cost of the large coffee is set
    ***********************************************/
    void set_large_cost(const float);

    // coffee getters
    /**************************************************
    ** Name: get_name()
    ** Description: This function will get the name of the coffee
    ** Parameters: none
    ** Pre-conditions: the name of the coffee is set
    ** Post-conditions: the name of the coffee is returned
    ***********************************************/
    string get_name() const;

    /**************************************************
    ** Name: get_small_cost()
    ** Description: This function will get the cost of the small coffee
    ** Parameters: none
    ** Pre-conditions: the cost of the small coffee is set
    ** Post-conditions: the cost of the small coffee is returned
    ***********************************************/
    float get_small_cost() const;

    /**************************************************
    ** Name: get_medium_cost()
    ** Description: This function will get the cost of the medium coffee
    ** Parameters: none
    ** Pre-conditions: the cost of the medium coffee is set
    ** Post-conditions: the cost of the medium coffee is returned
    ***********************************************/
    float get_medium_cost() const;

    /**************************************************
    ** Name: get_large_cost()
    ** Description: This function will get the cost of the large coffee
    ** Parameters: none
    ** Pre-conditions: the cost of the large coffee is set
    ** Post-conditions: the cost of the large coffee is returned
    ***********************************************/
    float get_large_cost() const;

    /**************************************************
    ** Name: get_coffee_cost()
    ** Description: This function will get the cost of the coffee based on the size
    ** Parameters: char - the size of the coffee
    ** Pre-conditions: the cost of the coffee for the given size is set
    ** Post-conditions: the cost of the coffee for the given size is returned
    ***********************************************/
    float get_coffee_cost(char) const;
};

#endif