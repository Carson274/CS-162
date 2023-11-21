#include <iostream>

using namespace std;

int main(){
    int** nums = new int*[10];
    for (int i = 0; i < 10; i++) {
        nums[i] = new int;
    }
    //some code here... 

    
    for (int i = 0; i < 10; i++) {
        delete nums[i];
        nums[i] = NULL;
    }
    delete [] nums;
    nums = NULL;
    
    return 0;
}