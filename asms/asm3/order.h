#ifndef ORDER_H
#define ORDER_H 

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;
	float price;
    int num_occurences;

public:
    /**************************************************
     ** Name: Order()
    ** Description: Default constructor for the Order class
    ** Parameters: none
    ** Pre-conditions: none
    ** Post-conditions: a new Order object is created with default values
    ***********************************************/
    Order();

    /**************************************************
     ** Name: Order(int, string, char, int, float)
    ** Description: Parameterized constructor for the Order class
    ** Parameters: int - the order number, string - the name of the coffee, char - the size of the coffee, int - the quantity of the coffee, float - the total cost of the order
    ** Pre-conditions: none
    ** Post-conditions: a new Order object is created with the specified values
    ***********************************************/
    Order(int, string, char, int, float);

    /**************************************************
     ** Name: ~Order()
    ** Description: Destructor for the Order class
    ** Parameters: none
    ** Pre-conditions: an Order object exists
    ** Post-conditions: the Order object is destroyed and its memory is freed
    ***********************************************/
    ~Order();

    /**************************************************
     ** Name: get_id()
    ** Description: This function will get the ID of the order
    ** Parameters: none
    ** Pre-conditions: the ID of the order is set
    ** Post-conditions: the ID of the order is returned
    ***********************************************/
    int get_id() const;

    /**************************************************
     ** Name: get_coffee_name()
    ** Description: This function will get the name of the coffee in the order
    ** Parameters: none
    ** Pre-conditions: the name of the coffee in the order is set
    ** Post-conditions: the name of the coffee in the order is returned
    ***********************************************/
    string get_coffee_name() const;

    /**************************************************
     ** Name: get_coffee_size()
    ** Description: This function will get the size of the coffee in the order
    ** Parameters: none
    ** Pre-conditions: the size of the coffee in the order is set
    ** Post-conditions: the size of the coffee in the order is returned
    ***********************************************/
    char get_coffee_size() const;

    /**************************************************
     ** Name: get_quantity()
    ** Description: This function will get the quantity of the coffee in the order
    ** Parameters: none
    ** Pre-conditions: the quantity of the coffee in the order is set
    ** Post-conditions: the quantity of the coffee in the order is returned
    ***********************************************/
    int get_quantity() const;

    /**************************************************
     ** Name: get_price()
    ** Description: This function will get the price of the order
    ** Parameters: none
    ** Pre-conditions: the price of the order is set
    ** Post-conditions: the price of the order is returned
    ***********************************************/
    float get_price() const;

    /**************************************************
     ** Name: get_num_occurrences()
    ** Description: This function will get the number of occurrences of the order
    ** Parameters: none
    ** Pre-conditions: the number of occurrences of the order is set
    ** Post-conditions: the number of occurrences of the order is returned
    ***********************************************/
    int get_num_occurrences() const;

    /**************************************************
     ** Name: set_id()
    ** Description: This function will set the ID of the order
    ** Parameters: const int - the ID of the order
    ** Pre-conditions: none
    ** Post-conditions: the ID of the order is set
    ***********************************************/
    void set_id(const int id);

    /**************************************************
     ** Name: set_coffee_name()
    ** Description: This function will set the name of the coffee in the order
    ** Parameters: const string - the name of the coffee
    ** Pre-conditions: none
    ** Post-conditions: the name of the coffee in the order is set
    ***********************************************/
    void set_coffee_name(const string);

    /**************************************************
     ** Name: set_coffee_size()
    ** Description: This function will set the size of the coffee in the order
    ** Parameters: const char - the size of the coffee
    ** Pre-conditions: none
    ** Post-conditions: the size of the coffee in the order is set
    ***********************************************/
    void set_coffee_size(const char);

    /**************************************************
     ** Name: set_quantity()
    ** Description: This function will set the quantity of the coffee in the order
    ** Parameters: const int - the quantity of the coffee
    ** Pre-conditions: none
    ** Post-conditions: the quantity of the coffee in the order is set
    ***********************************************/
    void set_quantity(const int);

    /**************************************************
     ** Name: set_price()
    ** Description: This function will set the price of the order
    ** Parameters: const float - the price of the order
    ** Pre-conditions: none
    ** Post-conditions: the price of the order is set
    ***********************************************/
    void set_price(const float);

    /**************************************************
     ** Name: set_num_occurrences()
    ** Description: This function will set the number of occurrences of the order
    ** Parameters: const int - the number of occurrences of the order
    ** Pre-conditions: none
    ** Post-conditions: the number of occurrences of the order is set
    ***********************************************/
    void set_num_occurrences(const int);

    /**************************************************
     ** Name: calculate_total()
    ** Description: This function will calculate the total cost of the order
    ** Parameters: none
    ** Pre-conditions: the price and quantity of the coffee in the order are set
    ** Post-conditions: the total cost of the order is returned
    ***********************************************/
    float calculate_total() const;

    /**************************************************
     ** Name: create_order()
    ** Description: This function will create an order from a data file
    ** Parameters: ifstream & - a reference to the input file stream
    ** Pre-conditions: a data file exists
    ** Post-conditions: an order is created from the data file
    ***********************************************/
    void create_order(ifstream &);

    /**************************************************
     ** Name: append_order()
    ** Description: This function will append an order to a data file
    ** Parameters: ofstream & - a reference to the output file stream
    ** Pre-conditions: an order exists
    ** Post-conditions: the order is appended to the data file
    ***********************************************/
    void append_order(ofstream &);

    /**************************************************
     ** Name: display_order()
    ** Description: This function will display the order
    ** Parameters: none
    ** Pre-conditions: an order exists
    ** Post-conditions: the order is displayed
    ***********************************************/
    void display_order();

};
#endif