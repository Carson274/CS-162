#include <iostream>

using namespace std;

//pass by pointers
void swap_ref (int* x , int* y) {
	int temp = x;
	*x = *y;
	*y = temp;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl; 

	cout << "addr of x: " << &x << endl;
	cout << "addr of y: " << &y << endl; 

    cout << "deref. of x: " << *x << endl;
	cout << "deref. of y: " << *y << endl; 
}

//pass by ref
// void swap_ref (int& x , int& y) {
// 	int temp = x;
// 	x = y;
// 	y = temp;

// 	cout << "x: " << x << endl;
// 	cout << "y: " << y << endl; 

// 	cout << "addr of x: " << &x << endl;
// 	cout << "addr of y: " << &y << endl; 
// }

//pass by value
// void swap (int x , int y) {
// 	int temp = x;
// 	x = y;
// 	y = temp;

// 	cout << "x: " << x << endl;
// 	cout << "y: " << y << endl; 

// 	cout << "addr of x: " << &x << endl;
// 	cout << "addr of y: " << &y << endl; 
// }

int main()
{
	int a = 5, b = 10;
	//swap(a, b);
	swap_ref(*a, *b);

	// cout << "a: " << a << endl;
	// cout << "b: " << b << endl; 

	// cout << "addr of a: " << &a << endl;
	// cout << "addr of b: " << &b << endl; 


	//C++ references 
	// int a = 7, b = 2;
	// int &ref = a;

	// cout << "a: " << a << endl;
	// cout << "ref: " << ref << endl;

	// ref = b;
	// cout << "a: " << a << endl;
	// cout << "ref: " << ref << endl;


	return 0;
}