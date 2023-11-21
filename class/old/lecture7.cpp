#include <iostream>

using namespace std;

// void initialize_2d_static(int array[][4], int row){
//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < 4; i++){
//             array[i][j] = i + j;
//         }
//     }
// }

void initialize_2d_dynamic(double **array, int row,  int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; i++){
            array[i][j] = i * j * 3.14;
        }
    }
}

// void print_2d_static(int array[][4], int row){
//     for(int i = 0; i < row; i++){
//         for(int j = 0; j < 4; i++){
//             array[i][j] = i + j;
//         }
//     }
// }

void print_2d_dynamic(double **array, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; i++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int row = 5, col = 4;

    int stack_array[7][4];

    // initialize_2d_static(stack_array, 7);
    // print_2d_static(stack_array, 7);


    double** heap_array;
    // allocate memory for row pointers
    heap_array = new double* [row];

    // for each row pointer, we need to allocate memory for doubles
    for(int i = 0; i < row; i++){
        heap_array[i] = new double [col];
    }

    initialize_2d_dynamic(heap_array, row, col);
    print_2d_dynamic(heap_array, row, col);

    // // initialize 2D dynamic array
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //     heap_array[i][j] = i * j * 3.14;
    //     }
    // }

    // // print 2D dynamic array
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //     cout << heap_array[i][j] << " ";
    //     }
    //     cout << endl;
    // }

}