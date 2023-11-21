#include <iostream>

using namespace std;

int main(){


    // Demo of stack vs. heap
    int x = 100;
    int *p = &x;

    cout << p << endl;
    cout << &p << endl;

    p = new int;

    cout << p << endl;

    delete p;


    int rack[5] = {1,1,1,1,1};

    cout << rack << endl;
    cout << &rack << endl;
    cout << &rack[0] << endl;

    // prints memory addresses of each element of rack array
    for(int i = 0; i < 5; i++){
        cout << &rack[i] << endl;
    }

    return 0;

}