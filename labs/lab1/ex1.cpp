#include <iostream>

using namespace std; 

void function (int x[], int n) {
    int i, t, j = n, s = 1;
    while (s) { //while true
        s = 0; //sets s to false
        for (i = 1; i < j; i++) { //from element at index 1 to j
            if (x[i] < x[i - 1]) { //if element at index is less than element to the left of it
                t = x[i]; //temporary variable set to the current element
                x[i] = x[i - 1]; //setting current element to element to the left
                x[i - 1] = t; //setting element to the left to temprorary
                s = 1; //sets s to true
            }
        }
        j--;
    }
}
 
int main () {
    int x[] = {15, 56, 12, -21, 1, 659, 3, 83, 51, 3, 135, 0};
    int n = sizeof(x) / sizeof(x[0]); //n = 48bits / 4bits = 12
    int i;
    for (i = 0; i < n; i++)
        cout << x[i] << " "; //prints each element of x with spaces between each number
    cout << endl;
    
    function(x, n); //calls function with x array n integer
    
    for (i = 0; i < n; i++) //prints the sorted array
        cout << x[i] << " ";
    cout << endl;
    
    return 0;
}

// Output:  15 56 12 -21 1 659 3 83 51 3 135 0
//          -21 0 1 3 3 12 15 51 56 83 135 659