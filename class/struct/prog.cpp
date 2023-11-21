//check for memory leaks and their location(s):
//1. compile the program with -g flag, i.e.,
//   g++ prog.cpp struct.cpp -g
//2. run valgrind with --leak-check=full flag, i.e.,
//   valgrind --leak-check=full ./a.out

#include <iostream>
#include "struct.h"


using namespace std;

int main()
{
	// //one single book object 
	// Book b1;
	// populate_book(b1, "Anothe book", 100, 2);
	// print_book(b1);

	// delete [] b1.authors;
	// b1.authors = nullptr;

	int size = 10;
	Book *book_arr = new Book [10];

	//initialize the book array
	for (int i = 0; i < size; ++i)
	{
		populate_book(book_arr[i], "Some book", 100 + i*100, i+1);
	}

	//print out all books
	for (int i = 0; i < size; ++i)
	{
		//print the book at idx i: book_arr[i]
		print_book(book_arr[i]);
	}


	//free the memory of book_arr
	for (int i = 0; i < size; ++i)
	{
		delete_book(book_arr[i]);
	}
	delete [] book_arr;
	book_arr = nullptr;

	


	return 0;
}