#include <iostream>

using namespace std;



void printArray(int *array, int &size){
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
}

int main(){
	int size = 5;
	int array[5] = {1,2,3,4,5};
	printArray(array, size);
}