#include <iostream>
using namespace std;

void printString(string& a){

	cout << a << endl;
}

int main(){

	string a {"DOES IT WORK?????"};

	printString(a);

	return 0;
}