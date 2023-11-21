#include <iostream>
#include <string>

using namespace std;

void get_sentence(string *s){
	cout << "Enter a sentence: ";
	getline(cin, *s);
}

int main()
{
	string sentence;

	get_sentence(&sentence);
	cout << sentence << endl;

	return 0;
}
/*
	1. No, we cannot change the value of the string
	if we change the function progotype to what is shown
	in the example.
	
	2. We need to set the parameter to reference sentence
	so that when we createt a pointer in the argument, it
	can point to an address. Then, when we get the sentence
	in the function, we need to dereference s so that the
	value we collect replaces the value at s instead of the
	address.

	3. An ampersand uses the address of a variable to match
	the called variable's, while an aterisk changes the variable
	to hold the address of the called variable's. The difference
	is the first variable holds the value, while the second
	variable holds the address.
*/