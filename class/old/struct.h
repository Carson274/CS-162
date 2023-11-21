#ifndef STRUCT_H
#define STRUCT_H 

#include <iostream>

using namespace std;

//define a struct, Book (data type)
struct Book
{
	int pages;
	string title;
	int num_authors;
	string* authors;
};

void populate_book (Book &b, string t, int p, int n);

void print_book (Book &b);

void delete_book(Book &b);


#endif
