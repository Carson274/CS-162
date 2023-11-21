#include <iostream>
#include "struct.h"

using namespace std;

//a function to populate a book object

//a file object has to be pass by reference!! 
void populate_book (Book* book_arr, int idx, ifstream& fin){
	//read from the file in order of: title pages num_authors authors
	fin >> book_arr[idx].title;
	fin >> book_arr[idx].pages;
	fin >> book_arr[idx].num_authors;
	book_arr[idx].authors = new string [book_arr[idx].num_authors];
	for (int i = 0; i < book_arr[idx].num_authors; ++i)
	{
		fin >> book_arr[idx].authors[i];
	}
}

//a function to print a single book object
void print_book (Book &b){
	cout << "--------------------------" << endl;
	cout << "Title: " << b.title << endl;
	cout << "Pages: " << b.pages << endl;
	for (int i = 0; i < b.num_authors; ++i)
	{
		cout << "Author " << i+1 << ": ";
		cout << b.authors[i] << endl;
	}

	cout << endl;
}


//a function to print a single book object
void print_book_to_file (Book &b, ofstream& fout){
	fout << "--------------------------" << endl;
	fout << "Title: " << b.title << endl;
	fout << "Pages: " << b.pages << endl;
	for (int i = 0; i < b.num_authors; ++i)
	{
		fout << "Author " << i+1 << ": ";
		fout << b.authors[i] << endl;
	}

	fout << endl;
}

//free memory for a single book
void delete_book(Book* book_arr, int size){
	for (int i = 0; i < size; ++i)
	{
		delete [] book_arr[i].authors;
	}
	delete [] book_arr;
}
