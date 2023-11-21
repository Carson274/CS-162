#include <iostream>

using namespace std;

void createRack(int *rack, int size){
    for(int i = 0; i < size-1; i++){

    }
    rack[size] = 2;
}

void calculateScore(int &score){
    
}

int main(){

    int size = 5;
    int rack[size];
    int score = 0;

    createRack(rack,size);

    calculateScore(score);

    cout << "Rack score: ";
    for(int i = 0; i < size; i ++){
        cout << score << " ";
    }

}