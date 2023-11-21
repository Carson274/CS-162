#include <iostream>

using namespace std;

void function(int num, int ctr, int &r) {
  int i;
  for(i = 2;i <= num/2; i++){ //num = 7, 2 times
    if(num % i==0){
      ctr++; //ctr = 1
      break;
    }
  }
  if(ctr == 0 && num != 1)
    r = 1;
  
  else
    r = 0;
}

int main(){

  int num, ctr = 0, r = -1; //num = 0, counter = 0
  cout << "Input a number: ";
  cin >> num;
  
  function(num, ctr, r); //calls funtion with input, 0, and -1
  cout << r << endl;;

  return 0;
}

//Outputs for cases:
// 0: 0
// 1: 0
// 4: 0
// 5: 0
// 7: 1
// 9: 0
// 11: 1