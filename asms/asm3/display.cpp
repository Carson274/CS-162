#include <iostream>
#include "display.h"

using namespace std;

void print_options() {
	cout << endl; 
	cout << "What would you like to do: " << endl;
	cout << "  1. View shop info " << endl;
	cout << "  2. Add an item to menu " << endl;
	cout << "  3. Remove an item from menu " << endl;
	cout << "  4. Search by coffee name " << endl;
	cout << "  5. Search by price " << endl;
	cout << "  6. Place an order " << endl;
	cout << "  7. Clone a shop " << endl;
	cout << "  8. Find best seller " << endl;
	cout << "  9. Log out " << endl;
	cout << endl;
}

int validate_input(){
	bool is_valid = false;
	int choice = -1;
	do{
		cin >> choice;
		if(choice < 1 || choice > 9){
			cout << "Invalid input. Please enter a number between 1 and 9 inclusive: ";
		}
		else{
			is_valid = true;
		}
	}while(!is_valid);

	return choice;
}

int get_choice() {
	int choice = -1; 
	do {
		print_options();
		cout << "Selection: ";
		choice = validate_input();
	}while (!(choice >= 1 && choice <= QUIT));

	return choice; 
}

void perform_action(Shop& s, int choice) {
	switch (choice){
		case 1:
			s.view_shop_detail();
			break;
		case 2:
			s.add_to_menu();
			break;
		case 3:
			s.remove_from_menu();
			break;
		case 4:
			s.search_by_name();
			break;
		case 5:
			s.search_by_price();
			break;
		case 6:
			s.place_order();
			break;
		case 7:
			s.clone_shop();
			break;
		case 8:
			s.find_best_seller();
			break;
	}
	return;
}
