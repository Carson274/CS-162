#ifndef STRUCT_H
#define STRUCT_H 

#include <iostream>
#include <fstream> //don't forget to include the fstream library


using namespace std;

//define a struct, Book (data type)
struct Book
{
	int pages;
	string title;
	int num_authors;
	string* authors;
};

void populate_book (Book*, int, ifstream& fin);

void print_book (Book &b);

void print_book_to_file(Book &b, ofstream&);

void delete_book(Book*, int );


#endif
