#ifndef MENU_H
#define MENU_H 

#include <string>
#include <iomanip>
#include <fstream>
#include "coffee.h"
#include "order.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr = NULL;
  public:
    /**************************************************
    ** Name: Menu()
    ** Description: Default constructor for the Menu class
    ** Parameters: none
    ** Pre-conditions: none
    ** Post-conditions: a new Menu object is created with default values
    ***********************************************/
    Menu();

    /**************************************************
    ** Name: Menu(int)
    ** Description: Parameterized constructor for the Menu class
    ** Parameters: int - the number of items in the menu
    ** Pre-conditions: none
    ** Post-conditions: a new Menu object is created with the specified number of items
    ***********************************************/
    Menu(int);

    /**************************************************
    ** Name: ~Menu()
    ** Description: Destructor for the Menu class
    ** Parameters: none
    ** Pre-conditions: a Menu object exists
    ** Post-conditions: the Menu object is destroyed and its memory is freed
    ***********************************************/
    ~Menu();

    /**************************************************
     * Name: Menu(const Menu &)
    ** Description: Copy constructor for the Menu class
    ** Parameters: const Menu & - a reference to the Menu object to be copied
    ** Pre-conditions: a Menu object exists
    ** Post-conditions: a new Menu object is created as a copy of the existing one
    ***********************************************/
    Menu(const Menu &);

    /**************************************************
    ** Name: operator=()
    ** Description: Assignment operator for the Menu class
    ** Parameters: const Menu & - a reference to the Menu object to be assigned
    ** Pre-conditions: a Menu object exists
    ** Post-conditions: the existing Menu object is assigned the values of the specified one
    ***********************************************/
    Menu& operator=(const Menu &);

    /**************************************************
     ** Name: get_num_coffee()
    ** Description: This function will get the number of coffee items in the menu
    ** Parameters: none
    ** Pre-conditions: the number of coffee items is set
    ** Post-conditions: the number of coffee items is returned
    ***********************************************/
    int get_num_coffee() const;

    /**************************************************
     ** Name: search_coffee_by_name()
    ** Description: This function will search for a coffee item by its name
    ** Parameters: string - the name of the coffee
    ** Pre-conditions: the coffee items are set
    ** Post-conditions: the coffee item with the specified name is returned
    ***********************************************/
    Coffee search_coffee_by_name(string);

    /**************************************************
     ** Name: search_coffee_by_price()
    ** Description: This function will search for coffee items by their price
    ** Parameters: float - the price of the coffee
    ** Pre-conditions: the coffee items are set
    ** Post-conditions: the coffee items with the specified price are returned in a new menu
    ***********************************************/
    Menu search_coffee_by_price(float);

    /**************************************************
     ** Name: add_to_menu()
    ** Description: This function will add a coffee item to the menu
    ** Parameters: Coffee& - a reference to the coffee item to be added
    ** Pre-conditions: none
    ** Post-conditions: the coffee item is added to the menu
    ***********************************************/
    void add_to_menu(Coffee&);

    /**************************************************
     ** Name: remove_from_menu()
    ** Description: This function will remove a coffee item from the menu
    ** Parameters: int - the index of the coffee item to be removed
    ** Pre-conditions: the coffee item exists in the menu
    ** Post-conditions: the coffee item is removed from the menu
    ***********************************************/
    void remove_from_menu(int);

    /**************************************************
     ** Name: populate_menu()
    ** Description: This function will populate the menu from a data file
    ** Parameters: none
    ** Pre-conditions: a data file exists
    ** Post-conditions: the menu is populated with items from the data file
    ***********************************************/
    bool populate_menu();

    /**************************************************
     ** Name: update_menu()
    ** Description: This function will update the menu
    ** Parameters: none
    ** Pre-conditions: the menu is populated
    ** Post-conditions: the menu is updated
    ***********************************************/
    void update_menu();

    /**************************************************
     ** Name: display_menu()
    ** Description: This function will display the menu
    ** Parameters: Order* - an array of Order objects, int - the number of orders
    ** Pre-conditions: the menu is populated
    ** Post-conditions: the menu is displayed
    ***********************************************/
    void display_menu(Order*, int);

    /**************************************************
     ** Name: display_menu_coffee_names()
    ** Description: This function will display the names of the coffee items in the menu
    ** Parameters: none
    ** Pre-conditions: the menu is populated
    ** Post-conditions: the names of the coffee items in the menu are displayed
    ***********************************************/
    void display_menu_coffee_names();

    /**************************************************
     ** Name: display_budgeted_menu()
    ** Description: This function will display the menu items within a specified budget
    ** Parameters: float - the budget
    ** Pre-conditions: the menu is populated
    ** Post-conditions: the menu items within the specified budget are displayed
    ***********************************************/
    void display_budgeted_menu(float);

    /**************************************************
     ** Name: print_coffee_names()
    ** Description: This function will print the names of the coffee items in the menu
    ** Parameters: none
    ** Pre-conditions: the menu is populated
    ** Post-conditions: the names of the coffee items in the menu are printed
    ***********************************************/
    void print_coffee_names();

    /**************************************************
     ** Name: get_coffee_at_index()
    ** Description: This function will get the coffee item at a specified index in the menu
    ** Parameters: int - the index of the coffee item
    ** Pre-conditions: the menu is populated and the index is valid
    ** Post-conditions: the coffee item at the specified index is returned
    ***********************************************/
    Coffee get_coffee_at_index(int);

    /**************************************************
     ** Name: get_coffee_cost()
    ** Description: This function will get the cost of a specified coffee item
    ** Parameters: string - the name of the coffee item, char - the size of the coffee
    ** Pre-conditions: the menu is populated and the name and size are valid
    ** Post-conditions: the cost of the specified coffee item is returned
    ***********************************************/
    float get_coffee_cost(string, char);

    /**************************************************
     ** Name: search_for_order_coffee()
    ** Description: This function will search for a coffee item by its name
    ** Parameters: string - the name of the coffee item
    ** Pre-conditions: the menu is populated
    ** Post-conditions: the coffee item with the specified name is returned
    ***********************************************/
    Coffee search_for_order_coffee(string);
};

#endif