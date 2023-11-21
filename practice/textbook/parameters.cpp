#include <iostream>
using namespace std;

int doubleNumber(int num){

	return num * 2;
}

int getInput(){
	int num{};
	cout << "Enter a number: ";
	cin >> num;
	return num;
}

int main(){

	int num{getInput()};
	cout << doubleNumber(num) << endl;

	return 0;

}