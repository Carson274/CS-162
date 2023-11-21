/* CS162- Lab 1 - Q. 1*
 * Solution description: check the properties, like value and address, of pointer
 */
 
#include <iostream>

using namespace std;


void fooA(int* iptr){

    cout << "*iptr: " << *iptr << endl;

    cout << "itpr: " << iptr << endl;

    cout << "&iptr: " << &iptr << endl;
}

int main(){
    
    int x = 0;
    
    cout << "&x: " << &x << endl;
    
    fooA(&x);
    
    cout << "x: " << x << endl;

    return 0;
}
