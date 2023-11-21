//check for memory leaks and their location(s):
//1. compile the program with -g flag, i.e.,
//   g++ prog.cpp struct.cpp -g
//2. run valgrind with --leak-check=full flag, i.e.,
//   valgrind --leak-check=full ./a.out

#include <iostream>
#include <fstream>
#include "struct.h"


using namespace std;

int main()
{
	//create a file object, input only
	ifstream my_file;

	//open a file using the file object 
	my_file.open("book.txt");

	//check if the file is open successfully
	if (!my_file.is_open()){
		cout << "Error opening the file..." << endl;
		return 1;
	}

	//perform actions
	int size = -1;

	//read the first int (size) into variable 
	my_file >> size;

	//print out the size, see if we get it!
	//cout << "Size: " << size << endl;

	//create a array of books, of size
	Book *book_arr = new Book [size];

	//initialize the book array, using the file
	for (int i = 0; i < size; ++i)
	{
		populate_book(book_arr, i, my_file);
	}

	// //print out all books
	// for (int i = 0; i < size; ++i)
	// {
	// 	//print the book at idx i: book_arr[i]
	// 	print_book(book_arr[i]);
	// }

	//print out all books into a file;
	ofstream outfile;
	string filename; 
	cout << "Enter a file name: ";
	cin >> filename; //getline(cin, filename);


	//open(const char*, mode )
	outfile.open(filename.c_str(), ios::app);

	for (int i = 0; i < size; ++i)
	{
		//print the book at idx i: book_arr[i]
		print_book_to_file(book_arr[i], outfile);
	}

	//free the memory of book_arr
	delete_book(book_arr, size);
	book_arr = nullptr;

	my_file.close();


	return 0;
}