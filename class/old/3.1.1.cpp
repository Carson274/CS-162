#include <iostream>

#include "struct.h"

using namespace std;

// definition of a Book struct
struct Book{
    int pages;
    string title; // a string inside the struct
    int num_authors;
    string* authors; // a pointer to a string
};

void populate_book(Book &b, string t, int p, int n){
    b.pages = p;
    b.title = t;
    b.num_authors = n;
    b.authors = new string [b.num_authors];
    for(int j = 0; j < b.num_authors; j ++){
       b.authors[j] = "author";
    }
}

void print_book(Book b){
    cout << "---------------------------" << endl;
    cout << "Title: " << b.title << endl;
    cout << "Pages: " << b.pages << endl;
    for(int i = 0; i < b.num_authors; i++){
        cout << "Author " << i + 1 << ": ";
        cout << b.authors[i] << endl;
    }
    cout << "---------------------------" << endl;
}

void delete_book(Book &b){
    delete [] b.authors;
    b.authors = nullptr;
}