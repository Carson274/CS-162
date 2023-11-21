#include <iostream>

using namespace std;

void array_init_dyn(char* array[], int size){
    for(int i = 0; i < size; ++i){
        array[i] = " ";
    }
}

void print_array_dyn(char* array[], int size){
    for(int i = 0; i < size; ++i){
        cout << array[i];
    }
}

int main(){


    int rack[5]; // static array of 5 ints

    int size= -1;
    cout << "Enter size: ";
    cin >> size;

    char* rack_dyn = new char[size];

    array_init_dyn(rack_dyn, size);
    print_array_dyn(rack_dyn, size);

    cout << (int*) rack_dyn << endl;

    delete[] rack_dyn;

}