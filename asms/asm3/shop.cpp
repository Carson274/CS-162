#include "shop.h"
#include "menu.h"

using namespace std;

Shop::Shop(){
	// cout << "Shop()" << endl;
	this->phone = "";
	this->address = "";
	this->revenue = 0.00;
	this->order_arr = NULL;
	this->num_orders = 0;
}

Shop::~Shop(){
	// cout << "~Shop()" << endl;
	if(this->order_arr != NULL){
		delete [] this->order_arr;
		this->order_arr = NULL;
	}
}

Shop::Shop(const Shop& s){
	cout << "Shop CC" << endl;
	this->phone = s.get_phone();
	this->address = s.get_address();
	this->revenue = s.get_revenue();
	this->num_orders = s.get_num_orders();
	this->order_arr = new Order [this->num_orders];
	for(int i = 0; i < this->num_orders; ++i){
		this->order_arr[i] = s.get_order_arr()[i];
	}
	this->m = s.get_menu();
}

Shop& Shop::operator=(const Shop& s){
	cout << "Shop AOO" << endl;
	if(this == &s){
		return *this;
	}
	if(this->order_arr != NULL){
		delete [] this->order_arr;
	}

	this->phone = s.phone;
	this->address = s.address;
	this->revenue = s.revenue;
	this->num_orders = s.num_orders;
	this->order_arr = new Order [this->num_orders];
	for(int i = 0; i < num_orders; ++i){
		this->order_arr[i] = s.order_arr[i];
	}

	return *this;
}

string Shop::get_phone() const{
	return phone;
}

string Shop::get_address() const{
	return address;
}

float Shop::get_revenue() const{
	return revenue;
}

int Shop::get_num_orders() const{
	return num_orders;
}

Order* Shop::get_order_arr() const{
	return order_arr;
}

Menu Shop::get_menu() const{
	return m;
}

void Shop::set_phone(const string phone){
	this->phone = phone;
	return;
}

void Shop::set_address(const string address){
	this->address = address;
	return;
}

void Shop::set_num_orders(const int num_orders){
	this->num_orders = num_orders;
	return;
}

void Shop::set_revenue(const float revenue){
	this->revenue = revenue;
	return;
}

bool Shop::load_menu(ifstream &fin){
	string phone, address;
	getline(fin, phone);
	getline(fin, address);
	
	this->set_phone(phone);
	this->set_address(address);

	//populate menu: this->m; return 0 if error opening file
	if(!this->m.populate_menu()){
		return 0;
	}
	return 1;
}

void Shop::load_orders(ifstream &fin){
	// get the number of orders
	fin >> this->num_orders;

	// allocate an array of orders, with size: num_orders
	if(num_orders > 0){
		this->order_arr = new Order[this->num_orders];
		for(int i = 0; i < this->num_orders; ++i){
			this->order_arr[i].create_order(fin);
			this->revenue += (this->order_arr[i].get_quantity()) * (this->m.get_coffee_cost(this->order_arr[i].get_coffee_name(), this->order_arr[i].get_coffee_size()));
		}
	}
	return;
}

bool Shop::load_data(){
	ifstream fin;
	fin.open("shop_info.txt");

	// error handling opening the file
	if(!fin.is_open()){
		cout << "Error opening file..." << endl;
		return 0;
	}

	if(!load_menu(fin)){
		return 0;
	}

	fin.close();

	// load orders
    fin.open("orders.txt");
    if(!fin.is_open()){
        cout << "Error opening orders file..." << endl;
        return 0;
    }

	load_orders(fin);

    fin.close();

	return 1;
}

void Shop::view_shop_detail(){
	// print shop address, phone number, and revenue
	cout << endl << "Address: " << this->address << endl;
	cout << "Phone: " << this->phone << endl;
	cout << "The shop revenue is: $" << fixed << setprecision(2) << this->revenue << endl << endl;

	// print menu
	cout << "Here is our menu: " << endl;
	this->m.display_menu(this->order_arr, this->num_orders);

	return;
}

float Shop::validate_price() {
    float price;
	bool is_valid = false;

	// validate price
    do{
        cin >> price;
        if(price <= 0){
            cout << "Invalid input. Please enter a decimal value above 0: ";
        } else {
            break;
        }
    }while(!is_valid);
    return price;
}

bool Shop::validate_name(string name) {
	// validate name
    for (int i = 0; i < this->m.get_num_coffee(); i++) {
        if (this->m.get_coffee_at_index(i).get_name() == name) {
			cout << "Error: Coffee name already exists." << endl;
            return false;
        }
    }
    return true;
}

void Shop::prompt_for_new_menu_item(string &name, float &small_cost, float &medium_cost, float &large_cost){
    // prompt for new menu item
    do {
        cout << "Enter the name of the new coffee drink (in 1 word): ";
        cin >> name;
    } while (!validate_name(name));

    cout << "Enter price of small size (8oz): ";
    small_cost = validate_price();

    cout << "Enter price of medium size (12oz): ";
    medium_cost = validate_price();

    cout << "Enter price of large size (16oz): ";
    large_cost = validate_price();

    return;
}

void Shop::add_to_menu(){
	// declare variables
	string name;
	float small_cost, medium_cost, large_cost;

	// declare coffee object
	Coffee coffee_to_add;

	// prompt for new menu item
	prompt_for_new_menu_item(name, small_cost, medium_cost, large_cost);

	// set coffee member variables to user input
	coffee_to_add.set_name(name);
	coffee_to_add.set_small_cost(small_cost);
	coffee_to_add.set_medium_cost(medium_cost);
	coffee_to_add.set_large_cost(large_cost);

	// call menu member function add item
	this->m.add_to_menu(coffee_to_add);

	// update menu.txt
	this->m.update_menu();

	return;
}

void Shop::remove_from_menu(){
	int index_of_coffee_on_menu;

	this->m.print_coffee_names();

	// prompt for index of coffee to remove
	do{
		cout << "Which of the drinks above from our menu would you like to remove?" << endl;
		cout << "Enter 1-" << this->m.get_num_coffee() << ": ";
		cin >> index_of_coffee_on_menu;
		if(index_of_coffee_on_menu < 1 || index_of_coffee_on_menu > this->m.get_num_coffee()){
			cout << "Error. Please enter a number between 1 and " << this->m.get_num_coffee() << " inclusive." << endl;
		}
	}while(index_of_coffee_on_menu < 1 || index_of_coffee_on_menu > this->m.get_num_coffee());

	this->m.remove_from_menu(index_of_coffee_on_menu);

	// update menu.txt
	this->m.update_menu();

	return;
}


void Shop::search_by_name(){
	string name;
	this->m.search_coffee_by_name(name);

	return;
}

void Shop::search_by_price(){
	float budget;
	bool valid_budget;

	// prompt for budget
	do{
		valid_budget = true;
		cout << "Enter your bugdet with a decimal: ";
		cin >> budget;

		if(budget <= 0){
			cout << "Error. Budget must be greater than 0.0." << endl;
			valid_budget = false;
		}
	}while(!valid_budget);

	// display budgeted menu
	Menu budget_menu = this->m.search_coffee_by_price(budget);
	budget_menu.display_budgeted_menu(budget);

	return;
}

void Shop::get_order_size(char &size){
	bool is_valid = false;

	// get and set the size of the order
	do{
		cout << "Enter the size of the order (s/m/l): ";
		cin >> size;
		if(size == 's' || size == 'm' || size == 'l'){
			is_valid = true;
		}
		else{
			cout << "Invalid input. Please enter s, m, or l." << endl;
		}
	}while(!is_valid);
	return;
}

void Shop::get_order_quantity(int &quantity){
	bool is_valid = false;

	// get and set the quantity of the order
	do{
		cout << "Enter the quantity of the order: ";
		cin >> quantity;
		if(quantity > 0){
			is_valid = true;
		}
		else{
			cout << "Invalid input. Please enter a number greater than 0." << endl;
		}
	}while(!is_valid);
	return;
}

int Shop::get_coffee_index(){
	int coffee_index;
	bool is_valid = false;

	// get and set the index of the coffee to order
	do{
		cout << "Enter the index of the coffee you would like to order: ";
		cin >> coffee_index;
		if(coffee_index >= 1 && coffee_index <= this->m.get_num_coffee()){
			is_valid = true;
		}
		else{
			cout << "Invalid input. Please enter a number between 1 and " << this->m.get_num_coffee() << " inclusive." << endl;
		}
	}while(!is_valid);
	return coffee_index;
}

void Shop::get_order_input(Coffee& user_coffee, char& size, int& quantity) {
	// display the menu items without prices
	this->m.display_menu_coffee_names();

	cout << endl << "Which of the drinks above from our menu would you like to order?" << endl;
	int coffee_index = get_coffee_index();

	user_coffee = this->m.get_coffee_at_index(coffee_index - 1);

	// display the menu item with prices
	cout << endl << user_coffee.get_name() << endl;
	cout << "   Small: " << fixed << setprecision(2) << user_coffee.get_small_cost() << endl;
	cout << "   Medium: " << fixed << setprecision(2) << user_coffee.get_medium_cost() << endl;
	cout << "   Large: " << fixed << setprecision(2) << user_coffee.get_large_cost() << endl << endl;

	// get and set the size of the order
	get_order_size(size);

	// get and set the quantity of the order
	get_order_quantity(quantity);
}

void Shop::truncate_order(float price, int quantity){
	// truncate order to file
	ofstream fout;
	fout.open("orders.txt");

	fout << this->num_orders << endl;

	// append each order to the file
	for(int i = 0; i < this->get_num_orders(); ++i){
		this->order_arr[i].append_order(fout);
	}

	fout.close();

	// add price to total shop revenue
	this->revenue += price * quantity;

	cout << "Your order has been placed. Your order number is " << this->get_num_orders() << "." << endl << endl;
}

bool Shop::show_cost_and_confirm(float price, int quantity){
    // Show total cost and ask for confirmation
	char confirmation = ' ';
    float total_cost = price * quantity;
    cout << "The total cost of your order is: $" << total_cost << endl;

	// ask for confirmation
    do{
		cout << "Would you like to place this order? (y/n): ";
		cin >> confirmation;
		if(confirmation != 'y' && confirmation != 'n'){
			cout << "Invalid input. Please enter y or n." << endl;
		}
		else if (confirmation == 'n') {
			cout << "Order cancelled." << endl;
			// decrease the number of orders by 1
			this->set_num_orders(this->num_orders - 1);
			return 0;
		}
	}while(confirmation != 'y' && confirmation != 'n');
	return 1;
}

void Shop::calculate_and_set_price(Coffee user_coffee, char &size, float &price){

	// calculate and set the price of the order
	if(size == 's'){
		this->order_arr[this->num_orders - 1].set_coffee_size('s');
		price = user_coffee.get_small_cost();
	}else if(size == 'm'){
		this->order_arr[this->num_orders - 1].set_coffee_size('m');
		price = user_coffee.get_medium_cost();
	}else if(size == 'l'){
		this->order_arr[this->num_orders - 1].set_coffee_size('l');
		price = user_coffee.get_large_cost();
	}
	return;
}

void Shop::update_order_array() {
	// create a temporary array of orders
    Order* temp_order_arr = new Order[this->num_orders];
    for(int i = 0; i < this->num_orders; ++i){
        temp_order_arr[i] = this->order_arr[i];
    }

    // increase the number of orders by 1
    this->set_num_orders(this->num_orders + 1);

    // clear up the old order array memory
    delete[] this->order_arr;
    this->order_arr = NULL;
    this->order_arr = new Order[this->num_orders];

    // copy the orders from the past array
    for(int i = 0; i < this->num_orders - 1; ++i){
        this->order_arr[i] = temp_order_arr[i];
    }

    // delete the temporary array
    delete[] temp_order_arr;
}

void Shop::place_order() {
	// add 1 element to order array (why does it take so much code to do this)
	update_order_array();

	// variable declarations
	Coffee user_coffee;
	char size;
	int quantity;
	float price;

	get_order_input(user_coffee, size, quantity);

	// set order array id
	this->order_arr[this->num_orders - 1].set_id(this->num_orders);

	// get and set the coffee name of the order
	this->order_arr[this->num_orders - 1].set_coffee_name(user_coffee.get_name());

	// calculate and set the price of the order
	calculate_and_set_price(user_coffee, size, price);

	this->order_arr[this->num_orders - 1].set_quantity(quantity);
	this->order_arr[this->num_orders - 1].set_price(price * quantity);

	if(!show_cost_and_confirm(price, quantity)){
		return;
	}

	truncate_order(price, quantity);

	return;
}

Shop Shop::clone_shop() {
	// big three implementation
	Shop cloned_shop;

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}

void Shop::initialize_coffee_name_arr(Order* coffee_name_arr) {
    int index = 0;

	// initialize the coffee name array
    for(int i = 0; i < this->m.get_num_coffee(); ++i){
        // for size 's'
        coffee_name_arr[index].set_coffee_name(this->m.get_coffee_at_index(i).get_name());
        coffee_name_arr[index].set_coffee_size('s');
        coffee_name_arr[index].set_num_occurrences(0);
        index++;

        // for size 'm'
        coffee_name_arr[index].set_coffee_name(this->m.get_coffee_at_index(i).get_name());
        coffee_name_arr[index].set_coffee_size('m');
        coffee_name_arr[index].set_num_occurrences(0);
        index++;

        // for size 'l'
        coffee_name_arr[index].set_coffee_name(this->m.get_coffee_at_index(i).get_name());
        coffee_name_arr[index].set_coffee_size('l');
        coffee_name_arr[index].set_num_occurrences(0);
        index++;
    }
}

void Shop::count_coffee_occurrences(Order* coffee_name_arr, int index) {
	// count the number of occurrences of each coffee
    for(int i = 0; i < this->num_orders; ++i){
        for(int j = 0; j < index; ++j){
            if(this->order_arr[i].get_coffee_name() == coffee_name_arr[j].get_coffee_name() && this->order_arr[i].get_coffee_size() == coffee_name_arr[j].get_coffee_size()){
                coffee_name_arr[j].set_num_occurrences(coffee_name_arr[j].get_num_occurrences() + this->order_arr[i].get_quantity());
            }
        }
    }
}

int Shop::find_max_index(Order* coffee_name_arr, int index) {
    int max_index = 0;

	// find the index of the coffee with the most occurrences
    for(int i = 1; i < index; ++i){
        if(coffee_name_arr[i].get_num_occurrences() > coffee_name_arr[max_index].get_num_occurrences()){
            max_index = i;
        }
    }
    return max_index;
}

void Shop::find_best_seller(){
	if(this->num_orders > 0){
		// create a temporary array of orders
		Order* coffee_name_arr = new Order[this->m.get_num_coffee() * 3]; // multiplied by 3 for small, medium, large sizes

		initialize_coffee_name_arr(coffee_name_arr);
		count_coffee_occurrences(coffee_name_arr, this->m.get_num_coffee() * 3);
		int max_index = find_max_index(coffee_name_arr, this->m.get_num_coffee() * 3);

		// print the top seller
		
		cout << "The top seller is " << coffee_name_arr[max_index].get_coffee_name() << " of size " << coffee_name_arr[max_index].get_coffee_size() << ", which was ordered " << coffee_name_arr[max_index].get_num_occurrences() << " times." << endl;

		// delete the temporary array
		delete[] coffee_name_arr;
	}
	else{
		cout << "No orders have been placed yet." << endl;
	}

    return;
}