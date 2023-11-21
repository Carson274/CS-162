#include <iostream>

using namespace std;

int* create_array1(int size){

    int* array = new int[size];

    return array;

}

void create_array2(int *&array, int size){

    array = new int[size];

}

void create_array3(int **array, int size){

    *array = new int[size];

}

int main(){

    int size = 0;
    cout << "Enter a number: ";
    cin >> size;

    int *array = new int[size];
    delete[] array;

    array = create_array1(size);
    delete[] array;

    create_array2(array,size);
    delete[] array;

    create_array3(&array,size);
    delete[] array;


}