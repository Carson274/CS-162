#include "menu.h"
#include "coffee.h"
#include "order.h"

using namespace std;

Menu::Menu(){
	// cout << "Menu()" << endl;
	this->num_coffee = 0;
	this->coffee_arr = NULL;
}

Menu::Menu(int size){
	// cout << "Menu(int)" << endl;
	this->num_coffee = size;
	this->coffee_arr = new Coffee[size];
}

Menu::~Menu(){
	// cout << "~Menu()" << endl;
	if(this->coffee_arr != NULL){
		delete [] this->coffee_arr;
		this->coffee_arr = NULL;
	}
}

Menu::Menu(const Menu& m){
	cout << "Menu CC" << endl;
	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee [this->num_coffee];
	for(int i = 0; i < num_coffee; ++i){
		this->coffee_arr[i] = m.coffee_arr[i];
	}
}

Menu& Menu::operator=(const Menu& m){
	cout << "Menu AOO" << endl;
	if(this == &m){
		return *this;
	}
	if(this->coffee_arr != NULL){
		delete [] this->coffee_arr;
	}

	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee [this->num_coffee];
	for(int i = 0; i < num_coffee; ++i){
		this->coffee_arr[i] = m.coffee_arr[i];
	}

	return *this;
}

int Menu::get_num_coffee() const{
	return num_coffee;
}

Coffee Menu::search_coffee_by_name(string name) {
	Coffee found; 
	bool is_found = false;
	//search coffee with a specific name 
	//return the coffee if found 
	//Your code goes here: 

	do{
		cout << "Enter coffee name: ";
		cin >> name;
		cout << endl;
		for(int i = 0; i < num_coffee; i++){
			if(coffee_arr[i].get_name() == name){
				found.set_name(coffee_arr[i].get_name());
				found.set_small_cost(coffee_arr[i].get_small_cost());
				found.set_medium_cost(coffee_arr[i].get_medium_cost());
				found.set_large_cost(coffee_arr[i].get_large_cost());
				is_found = true;
			}
		}
		if(!is_found){
			cout << "Error! Coffee not found." << endl;
		}
	}while(!is_found);

	found.display_coffee();

	return found;
}

Menu Menu::search_coffee_by_price(float budget){
	Menu temp;
	//search coffee with a specific budget 
	//return all coffee that is under the budget
	//Hint: Since a Menu object contains an array of coffee
	//      You may return a Menu object that contains all valid coffees
	//Your code goes here: 
	int num_affordable = 0;
	for(int i = 0; i < this->num_coffee; ++i){
		if(budget >= this->coffee_arr[i].get_small_cost()){
			num_affordable++;
		}
	}
	temp.num_coffee = num_affordable;

	// search through menu for each coffee
	temp.coffee_arr = new Coffee[num_coffee];
	int temp_index = 0;
	for(int i = 0; i < this->num_coffee; ++i){
		if(budget >= this->coffee_arr[i].get_small_cost()){
			temp.coffee_arr[temp_index].set_name(this->coffee_arr[i].get_name());
			temp.coffee_arr[temp_index].set_small_cost(this->coffee_arr[i].get_small_cost());
			temp.coffee_arr[temp_index].set_medium_cost(this->coffee_arr[i].get_medium_cost());
			temp.coffee_arr[temp_index].set_large_cost(this->coffee_arr[i].get_large_cost());
			temp_index++;
		}
	}

	return temp;
}

void Menu::add_to_menu(Coffee& coffee_to_add){
	//1. create/allocate a temp array with size + 1
	Coffee* temp_arr = new Coffee [this->num_coffee + 1];

	//2. loop thru this->coffe_arr, copy them into new temp array
	for(int i = 0; i < this->num_coffee; ++i){
		temp_arr[i] = this->coffee_arr[i];
	}

	//3. put our coffee_to_add into the temp array at idx: 
	temp_arr[this->num_coffee] = coffee_to_add;

	//4. free memory of coffee_arr
	delete [] this->coffee_arr;
	this->coffee_arr = NULL;

	//5. assign coffee_arr to temp (new array)
	this->coffee_arr = temp_arr;
	temp_arr = NULL;

	//6. increment num_coffee
	this->num_coffee++;

	return;
} 


void Menu::remove_from_menu(int index_of_coffee_on_menu){
	//remove a coffee object from the Menu
	//Your code goes here: 
	
	//1. create/allocate a temp array with size + 1
	Coffee* temp_arr = new Coffee [this->num_coffee - 1];

	//2. loop thru this->coffe_arr until index, copy them into new temp array
	for(int i = 0; i < index_of_coffee_on_menu - 1; ++i){
		temp_arr[i] = this->coffee_arr[i];
	}

	//3. loop thru this->coffe_arr from index to end, copy them into new temp array
	for(int i = index_of_coffee_on_menu; i < this->num_coffee; ++i){
		temp_arr[i - 1] = this->coffee_arr[i];
	}

	//4. free memory of coffee_arr
	delete [] this->coffee_arr;
	this->coffee_arr = NULL;

	//5. assign coffee_arr to temp (new array)
	this->coffee_arr = temp_arr;

	//6. decrement num_coffee
	this->num_coffee--;

	return;
} 


bool Menu::populate_menu() {
	
	ifstream fin;
	fin.open("menu.txt");

	//error handling for opening the file 
	if(!fin.is_open()){
		return 0;
	}

	fin >> this->num_coffee;

	//allocate an array of coffee, with size: num_coffee
	//array will be stored into coffee_array
	this->coffee_arr = new Coffee [this->num_coffee];

	//loop thru coffee array, populate coffee one at a time 
	for (int i = 0; i < this->num_coffee; ++i)
	{
		//populate a single coffee obj
		this->coffee_arr[i].populate_coffee(fin);
	}

	fin.close();

	return 1;
}

void Menu::update_menu() {
	ofstream fout;
	
	// open menu.txt and check to ensure it's open
	fout.open("menu.txt");
	if(!fout.is_open()){
		cout << "Error: Cannot open file." << endl;
		return;
	}

	// truncate new menu to file
	fout << this->num_coffee << endl;
	for(int i = 0; i < this->num_coffee; ++i){
		fout << this->coffee_arr[i].get_name() << " "
		     << this->coffee_arr[i].get_small_cost() << " "
		     << this->coffee_arr[i].get_medium_cost() << " "
		     << this->coffee_arr[i].get_large_cost() << endl;
	}

	// close file
	fout.close();
}

void Menu::display_menu(Order* order_arr, int num_orders) {
	for (int i = 0; i < this->num_coffee; ++i)
	{
		//print out a single coffee object
		cout << i + 1 << ". ";
		this->coffee_arr[i].display_coffee();
	}

	// print out order info
	if(num_orders > 0){
		cout << "Order info:" << endl;
		for(int i = 0; i < num_orders; ++i){
			order_arr[i].display_order();
		}
	}
	else{
		cout << "(No orders yet)" << endl;
	}
}

void Menu::display_menu_coffee_names() {
	for (int i = 0; i < this->num_coffee; ++i)
	{
		//print out a single coffee object name
		cout << "   " << i + 1 << ". ";
		this->coffee_arr[i].display_coffee_names();
	}
}

void Menu::display_budgeted_menu(float budget) {
	
	// check to see if there's any coffee within the budget; if not, let the user know
	if(this->num_coffee == 0){
		cout << "No coffee fits your budget. Sorry!" << endl;
	}
	for (int i = 0; i < this->num_coffee; ++i)
	{
		//print out a single coffee obj
		cout << i + 1 << ". ";
		if(budget >= this->coffee_arr[i].get_large_cost()){
			this->coffee_arr[i].display_coffee();
		}
		else if(budget >= this->coffee_arr[i].get_medium_cost()){
			this->coffee_arr[i].display_small_and_medium_coffee_only();
		}
		else if(budget >= this->coffee_arr[i].get_small_cost()){
			this->coffee_arr[i].display_small_coffee_only();
		}
	}
}

void Menu::print_coffee_names() {
	for(int i = 0; i < this->num_coffee; ++i){
		cout << i + 1 << ". ";
		cout << this->coffee_arr[i].get_name();
		cout << endl;
	}
}

Coffee Menu::get_coffee_at_index(int index) {
	return this->coffee_arr[index];
}

Coffee Menu::search_for_order_coffee(string name){
	Coffee found;
	for(int i = 0; i < num_coffee; i++){
		if(coffee_arr[i].get_name() == name){
			found.set_name(coffee_arr[i].get_name());
			found.set_small_cost(coffee_arr[i].get_small_cost());
			found.set_medium_cost(coffee_arr[i].get_medium_cost());
			found.set_large_cost(coffee_arr[i].get_large_cost());
			break;
		}
	}
	return found;
}

float Menu::get_coffee_cost(string name, char size){
	return this->search_for_order_coffee(name).get_coffee_cost(size);
}