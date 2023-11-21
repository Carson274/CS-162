#ifndef DISPLAY_H
#define DISPLAY_H

#include "shop.h"

#define QUIT 9

/**************************************************
 ** Name: print_options()
 ** Description: This function will print the available options to the user
 ** Parameters: none
 ** Pre-conditions: none
 ** Post-conditions: the available options are printed to the console
 ***********************************************/
void print_options();

/**************************************************
 ** Name: validate_input()
 ** Description: This function will validate the user's input, ensuring it is a number between 1 and 9 inclusive
 ** Parameters: none
 ** Pre-conditions: none
 ** Post-conditions: the user's input is validated and returned
 ***********************************************/
int validate_input();

/* Name: get_choice()
 * Description: This function gets an user input for option
 * Parameters: none
 * Pre-condition: none
 * Post-conditon: a choice (1-8) is returned
 */
int get_choice();

/* Name: perform_action()
 * Description: This function performs an action based on user input
 * Parameters: 	Shop &s - a reference to the Shop obj
 				int choice - user input for an option
 * Pre-condition: choice is 1-8
 * Post-conditon: an option is performed
 */
void perform_action(Shop &s, int choice);

#endif
