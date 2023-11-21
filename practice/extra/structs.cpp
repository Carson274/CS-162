#include <iostream>

using namespace std;

struct Vehicle{
	int mpg;
	string color;
};

struct Garage{
	int num_of_vehicles;
	Vehicle* v;
};

int main(){
	Vehicle pontiac;
	pontiac.color = "White";
	pontiac.mpg = 18;

	cout << "Pontiac color: " << pontiac.color << endl;
	cout << "Pontiac mpg: " << pontiac.mpg << endl;

	Garage g;
	g.num_of_vehicles = 3;

	g.v = new Vehicle[g.num_of_vehicles];

	// for each vehicle in the garage, set its mpg and color
	for(int i = 0; i < g.num_of_vehicles; ++i){
		g.v[i].mpg = i + 9;
		g.v[i].color = "Purple";
	}

	// print each vehicle mpg and color
	for(int i = 0; i < g.num_of_vehicles; ++i){
		cout << "Vehicle " << i + 1 << ": " << endl;
        cout << "MPG: " << g.v[i].mpg << endl;
        cout << "Color: " << g.v[i].color << endl;
	}



	return 0;
}