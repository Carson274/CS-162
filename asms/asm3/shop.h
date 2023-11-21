#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders
  public:
    /**************************************************
     ** Name: Shop()
    ** Description: Default constructor for the Shop class
    ** Parameters: none
    ** Pre-conditions: none
    ** Post-conditions: a new Shop object is created with default values
    ***********************************************/
    Shop();

    /**************************************************
     ** Name: Shop(int)
    ** Description: Parameterized constructor for the Shop class
    ** Parameters: int - the number of items in the shop
    ** Pre-conditions: none
    ** Post-conditions: a new Shop object is created with the specified number of items
    ***********************************************/
    Shop(int);

    /**************************************************
     ** Name: ~Shop()
    ** Description: Destructor for the Shop class
    ** Parameters: none
    ** Pre-conditions: a Shop object exists
    ** Post-conditions: the Shop object is destroyed and its memory is freed
    ***********************************************/
    ~Shop();

    /**************************************************
     ** Name: Shop(const Shop &)
    ** Description: Copy constructor for the Shop class
    ** Parameters: const Shop & - a reference to the Shop object to be copied
    ** Pre-conditions: a Shop object exists
    ** Post-conditions: a new Shop object is created as a copy of the existing one
    ***********************************************/
    Shop(const Shop &);

    /**************************************************
     ** Name: operator=()
    ** Description: Assignment operator for the Shop class
    ** Parameters: const Shop & - a reference to the Shop object to be assigned
    ** Pre-conditions: a Shop object exists
    ** Post-conditions: the existing Shop object is assigned the values of the specified one
    ***********************************************/
    Shop& operator=(const Shop &);

    /**************************************************
     ** Name: get_phone()
    ** Description: This function will get the phone number of the shop
    ** Parameters: none
    ** Pre-conditions: the phone number of the shop is set
    ** Post-conditions: the phone number of the shop is returned
    ***********************************************/
    string get_phone() const;

    /**************************************************
     ** Name: get_address()
    ** Description: This function will get the address of the shop
    ** Parameters: none
    ** Pre-conditions: the address of the shop is set
    ** Post-conditions: the address of the shop is returned
    ***********************************************/
    string get_address() const;

    /**************************************************
     ** Name: get_revenue()
    ** Description: This function will get the revenue of the shop
    ** Parameters: none
    ** Pre-conditions: the revenue of the shop is set
    ** Post-conditions: the revenue of the shop is returned
    ***********************************************/
    float get_revenue() const;

    /**************************************************
     ** Name: get_num_orders()
    ** Description: This function will get the number of orders in the shop
    ** Parameters: none
    ** Pre-conditions: the number of orders in the shop is set
    ** Post-conditions: the number of orders in the shop is returned
    ***********************************************/
    int get_num_orders() const;

    /**************************************************
     ** Name: get_order_arr()
    ** Description: This function will get the array of orders in the shop
    ** Parameters: none
    ** Pre-conditions: the array of orders in the shop is set
    ** Post-conditions: the array of orders in the shop is returned
    ***********************************************/
    Order* get_order_arr() const;

    /**************************************************
     ** Name: get_menu()
    ** Description: This function will get the menu of the shop
    ** Parameters: none
    ** Pre-conditions: the menu of the shop is set
    ** Post-conditions: the menu of the shop is returned
    ***********************************************/
    Menu get_menu() const;

    /**************************************************
     ** Name: set_phone()
    ** Description: This function will set the phone number of the shop
    ** Parameters: const string - the phone number of the shop
    ** Pre-conditions: none
    ** Post-conditions: the phone number of the shop is set
    ***********************************************/
    void set_phone(const string);

    /**************************************************
     ** Name: set_address()
    ** Description: This function will set the address of the shop
    ** Parameters: const string - the address of the shop
    ** Pre-conditions: none
    ** Post-conditions: the address of the shop is set
    ***********************************************/
    void set_address(const string);

    /**************************************************
     ** Name: set_num_orders()
    ** Description: This function will set the number of orders in the shop
    ** Parameters: const int - the number of orders in the shop
    ** Pre-conditions: none
    ** Post-conditions: the number of orders in the shop is set
    ***********************************************/
    void set_num_orders(const int);

    /**************************************************
     ** Name: set_revenue()
    ** Description: This function will set the revenue of the shop
    ** Parameters: const float - the revenue of the shop
    ** Pre-conditions: none
    ** Post-conditions: the revenue of the shop is set
    ***********************************************/
    void set_revenue(const float);

    /**************************************************
     ** Name: load_data()
    ** Description: This function will read from files to correctly populate coffee, menu, etc.
    ** Parameters: none
    ** Pre-conditions: the data files exist
    ** Post-conditions: the coffee, menu, etc. are populated
    ***********************************************/
    bool load_data();

    /**************************************************
     ** Name: view_shop_detail()
    ** Description: This function will display the details of the shop
    ** Parameters: none
    ** Pre-conditions: the shop exists
    ** Post-conditions: the details of the shop are displayed
    ***********************************************/
    void view_shop_detail();

    /**************************************************
     ** Name: add_to_menu()
    ** Description: This function will add an item to the menu
    ** Parameters: none
    ** Pre-conditions: the menu exists
    ** Post-conditions: an item is added to the menu
    ***********************************************/
    void add_to_menu();

    /**************************************************
     ** Name: remove_from_menu()
    ** Description: This function will remove an item from the menu
    ** Parameters: none
    ** Pre-conditions: the menu exists and is not empty
    ** Post-conditions: an item is removed from the menu
    ***********************************************/
    void remove_from_menu();

    /**************************************************
     ** Name: search_by_name()
    ** Description: This function will search for an item in the menu by its name
    ** Parameters: none
    ** Pre-conditions: the menu exists
    ** Post-conditions: the item with the specified name is returned
    ***********************************************/
    void search_by_name();

    /**************************************************
     ** Name: search_by_price()
    ** Description: This function will search for items in the menu by their price
    ** Parameters: none
    ** Pre-conditions: the menu exists
    ** Post-conditions: the items with the specified price are returned
    ***********************************************/
    void search_by_price();

    /**************************************************
     ** Name: truncate_order()
    ** Description: This function will truncate an order
    ** Parameters: float - the price of the order, int - the quantity of the order
    ** Pre-conditions: an order exists
    ** Post-conditions: the order is truncated
    ***********************************************/
    void truncate_order(float, int);

    /**************************************************
     ** Name: show_cost_and_confirm()
    ** Description: This function will show the cost of an order and ask for confirmation
    ** Parameters: float - the price of the order, int - the quantity of the order
    ** Pre-conditions: an order exists
    ** Post-conditions: the cost of the order is shown and confirmation is asked
    ***********************************************/
    bool show_cost_and_confirm(float, int);

    /**************************************************
     ** Name: place_order()
    ** Description: This function will place an order
    ** Parameters: none
    ** Pre-conditions: the shop exists
    ** Post-conditions: an order is placed
    ***********************************************/
    void place_order();

    /**************************************************
     ** Name: clone_shop()
    ** Description: This function will clone the shop
    ** Parameters: none
    ** Pre-conditions: the shop exists
    ** Post-conditions: a clone of the shop is returned
    ***********************************************/
    Shop clone_shop();

    /**************************************************
     ** Name: get_order_input()
    ** Description: This function will get the input for an order
    ** Parameters: Coffee & - a reference to the coffee, char & - a reference to the size of the coffee, int & - a reference to the quantity of the coffee
    ** Pre-conditions: none
    ** Post-conditions: the input for the order is obtained
    ***********************************************/
    void get_order_input(Coffee &, char &, int &);

    /**************************************************
     ** Name: find_best_seller()
    ** Description: This function will find the best seller
    ** Parameters: none
    ** Pre-conditions: the shop exists
    ** Post-conditions: the best seller is found
    ***********************************************/
    void find_best_seller();

    /**************************************************
     ** Name: load_orders_from_file()
    ** Description: This function will load orders from a file
    ** Parameters: none
    ** Pre-conditions: the file exists
    ** Post-conditions: the orders are loaded from the file
    ***********************************************/
    void load_orders_from_file();

    /**************************************************
     ** Name: prepare_for_new_order()
    ** Description: This function will prepare for a new order
    ** Parameters: none
    ** Pre-conditions: the shop exists
    ** Post-conditions: the shop is prepared for a new order
    ***********************************************/
    void prepare_for_new_order();

    /**************************************************
     ** Name: copy_past_orders()
    ** Description: This function will copy past orders
    ** Parameters: Order* - a pointer to the orders
    ** Pre-conditions: the orders exist
    ** Post-conditions: the past orders are copied
    ***********************************************/
    void copy_past_orders(Order*);

    /**************************************************
     ** Name: get_and_set_order_details()
    ** Description: This function will get and set the details of an order
    ** Parameters: Coffee& - a reference to the coffee, char& - a reference to the size of the coffee, int& - a reference to the quantity of the coffee, float& - a reference to the price of the order
    ** Pre-conditions: none
    ** Post-conditions: the details of the order are obtained and set
    ***********************************************/
    void get_and_set_order_details(Coffee&, char&, int&, float&);

    /**************************************************
     ** Name: confirm_order()
    ** Description: This function will confirm an order
    ** Parameters: float - the price of the order
    ** Pre-conditions: an order exists
    ** Post-conditions: the order is confirmed
    ***********************************************/
    bool confirm_order(float);

    /**************************************************
     ** Name: save_orders_to_file()
    ** Description: This function will save orders to a file
    ** Parameters: none
    ** Pre-conditions: orders exist
    ** Post-conditions: the orders are saved to a file
    ***********************************************/
    void save_orders_to_file();

    /**************************************************
     ** Name: initialize_coffee_name_arr()
    ** Description: This function will initialize an array with the names of the coffees in the orders
    ** Parameters: Order* - a pointer to the orders
    ** Pre-conditions: orders exist
    ** Post-conditions: an array with the names of the coffees in the orders is initialized
    ***********************************************/
    void initialize_coffee_name_arr(Order*);

    /**************************************************
     ** Name: count_coffee_occurrences()
    ** Description: This function will count the occurrences of each coffee in the orders
    ** Parameters: Order* - a pointer to the orders, int - the number of orders
    ** Pre-conditions: orders exist
    ** Post-conditions: the occurrences of each coffee in the orders are counted
    ***********************************************/
    void count_coffee_occurrences(Order*, int);

    /**************************************************
     ** Name: find_max_index()
    ** Description: This function will find the index of the coffee with the maximum number of occurrences in the orders
    ** Parameters: Order* - a pointer to the orders, int - the number of orders
    ** Pre-conditions: orders exist
    ** Post-conditions: the index of the coffee with the maximum number of occurrences in the orders is found
    ***********************************************/
    int find_max_index(Order*, int);

    /**************************************************
     ** Name: prompt_for_new_menu_item()
    ** Description: This function will prompt for the details of a new menu item
    ** Parameters: string & - a reference to the name of the item, float & - a reference to the price of the item, float & - a reference to the cost of the item, float & - a reference to the quantity of the item
    ** Pre-conditions: none
    ** Post-conditions: the details of the new menu item are obtained
    ***********************************************/
    void prompt_for_new_menu_item(string &, float &, float &, float &);

    /**************************************************
     ** Name: calculate_and_set_price()
    ** Description: This function will calculate and set the price of an order
    ** Parameters: Coffee - the coffee, char & - a reference to the size of the coffee, float & - a reference to the price of the order
    ** Pre-conditions: an order exists
    ** Post-conditions: the price of the order is calculated and set
    ***********************************************/
    void calculate_and_set_price(Coffee, char &, float &);

    /**************************************************
     ** Name: update_order_array()
    ** Description: This function will update the array of orders
    ** Parameters: none
    ** Pre-conditions: orders exist
    ** Post-conditions: the array of orders is updated
    ***********************************************/
    void update_order_array();

    /**************************************************
     ** Name: validate_price()
    ** Description: This function will validate the user's input, ensuring it is a number above 0
    ** Parameters: none
    ** Pre-conditions: none
    ** Post-conditions: the user's input is validated and returned
    ***********************************************/
    float validate_price();

    /**************************************************
     ** Name: validate_name(string)
    ** Description: This function will validate the user's input, ensuring the name does not already exist in the coffee array
    ** Parameters: string - the name to validate
    ** Pre-conditions: none
    ** Post-conditions: returns true if the name does not exist in the coffee array, false otherwise
    ***********************************************/
    bool validate_name(string);

    /**************************************************
     ** Name: get_order_size(char &)
    ** Description: This function will get the size of the order from the user
    ** Parameters: char & - a reference to the size of the order
    ** Pre-conditions: none
    ** Post-conditions: the size of the order is obtained from the user
    ***********************************************/
    void get_order_size(char &);

    /**************************************************
     ** Name: get_order_quantity(int &)
    ** Description: This function will get the quantity of the order from the user
    ** Parameters: int & - a reference to the quantity of the order
    ** Pre-conditions: none
    ** Post-conditions: the quantity of the order is obtained from the user
    ***********************************************/
    void get_order_quantity(int &);

    /**************************************************
     ** Name: get_coffee_index()
    ** Description: This function will get the index of the coffee from the user
    ** Parameters: ifstream & - a reference to the input file stream
    ** Pre-conditions: none
    ** Post-conditions: the index of the coffee is obtained from the user and returned
    ***********************************************/
    int get_coffee_index();

    /**************************************************
     ** Name: load_menu(ifstream &)
    ** Description: This function will load the menu from a file
    ** Parameters: ifstream & - a reference to the input file stream
    ** Pre-conditions: the input file stream is open
    ** Post-conditions: the menu is loaded from the file
    ***********************************************/
    bool load_menu(ifstream &);

    /**************************************************
     ** Name: load_orders(ifstream &)
    ** Description: This function will load the orders from a file
    ** Parameters: ifstream & - a reference to the input file stream
    ** Pre-conditions: the input file stream is open
    ** Post-conditions: the orders are loaded from the file
    ***********************************************/
    void load_orders(ifstream &);
};

#endif
