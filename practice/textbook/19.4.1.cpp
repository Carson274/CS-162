#include <iostream>

using namespace std;

int main(){
    // int num;
    // int* ptr;
    // int** ptrptr;

    // ptr = &num;
    // ptrptr = &ptr;

    // cout << "Enter a number: ";
    // cin  >> num;

    // cout << "Num: " << *ptr << endl;
    // cout << "Address of num: " << &num << endl;
    // cout << "Address of num: " << ptr << endl;
    // cout << "Address of ptr: " << &ptr << endl;
    // cout << "ptrptr: " << **ptrptr << endl;

    // int a,b,c,d,e,f,g,h,i,h;

    int width, height, input;

    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;

    int** array = new int*[height];

    for(int i = 0; i < height; i++){
        array[i] = new int[width];
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << "Enter number at row " << i + 1;
            cout << " column " << j + 1 << ": ";
            cin >> input;
            array[i][j] = input;
        }
    }

    for(int i = 0; i < height; i++){
        cout << "Row " << i + 1 << ": ";
        for(int j = 0; j < width; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}