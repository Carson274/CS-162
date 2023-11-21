/***********************************************************************
 * Program: Coffee++
 * Author: Carson Secrest
 * Date: 11/13/23
 * Description: This program simulates managinga coffee shop. It first
 *              loads the data from an input file. It then offers
 *              various possible options to perform such as adding a new
 *              coffee to the menu, removing a coffee from the menu, and
 *              managing orders. The user is then prompted to choose an
 *              option from the menu.
 * Input: input file name, user choices for options, coffee names, prices
 * Output: depending on the user's choice: coffee menu, order details,
 *         and/or updated coffee menu, all of which is either displayed to the screen
 *         or updated in the input file
***********************************************************************/

#include <iostream>
#include "display.h"
#include "menu.h"

using namespace std;

int main()
{
	// main function lives here
	cout << "Welcome to Coffee++" << endl;
	int choice = -1;
	Shop s;
	//populate your Shop:
	//your code here:
	if(!s.load_data()){
		return 0;
	}

	while (choice != QUIT){
		choice = get_choice();
		perform_action(s, choice);
	}

	cout << "Bye!" << endl;

	return 0;
}
