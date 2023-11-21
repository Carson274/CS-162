#include <iostream>

using namespace std;

void change_me(int &val){

	val = 100;

}

void some_func(string str, int num){

	cout << str << endl;
	cout << num << endl;

}

int main(){

	int n = 13, m = 16;
	int* np = &n;
	np = &m;
	*np = 10;

	cout << "n: " << n << endl;
	cout << "m: " << m << endl;
	cout << "np: " << *np << endl;

	// int *ptr = 10;

	// cout << "ptr: " << *ptr << endl;

	int x = 0;
	cout << x << " ";
	change_me(x);
	cout << x << endl;

	some_func("Hello",5);

	return 0;
}