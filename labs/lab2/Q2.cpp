/* CS 162- Lab 1 - Q.2
 * Solution description: call the function foo using "reference" to see the values before and after the function
 */
 
#include <iostream>

using namespace std;

int foo(int* a, int& b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    /*Set b to half its original value*/
    b /= 2;
    /*Assign a+b to c*/
    c = *a + b;
    /*Return c*/
    return c;
    return 0;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x = 7, y = 8, z = 9;
    /*Print the values of x, y and z*/
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    cout << foo(&x,y,z) << endl;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;
    
    // There is no difference between the value of z
    // before and after the function call because we
    // aren't changing the value of z at all. Instead,
    // we're changing the value of c, which is only
    // accessible within the foo function's scope.

    return 0;
}
    
    
