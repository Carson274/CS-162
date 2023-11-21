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

int main(){

    // declare and initialize at the same time
    Book b1;
    populate_book(b1, "Anothe book", 100, 2);
    print_book(b1);

    b1.pages = 100;
    b1.title = "Harry Potter";
    b1.num_authors = 2;
    b1.authors = new string [b1.num_authors];
    b1.authors[0] = "Author 1";
    b1.authors[1] = "Author 2";

    print_book(b1);

    delete [] b1.authors;
    b1.authors = nullptr;

    int num_books = 10;
    Book *bookshelf = new Book [num_books];

    // initialize the book array
    for(int i = 0; i < num_books; i++){
        populate_book(bookshelf[i], "Some book", 100 + i * 100, i + 1);

        // bookshelf[i].pages = 100 + i*100;
        // bookshelf[i].title = "Some book";
        // bookshelf[i].num_authors = i + 1;
        // bookshelf[i].authors = new string [bookshelf[i].num_authors];
        // for(int j = 0; j < bookshelf[i].num_authors; j ++){
        //     bookshelf[i].authors[j] = "author";
        // }
    }

    // print out all books
    for(int i = 0; i < num_books; i ++){
        print_book(bookshelf[i]);
    }

    // free the memory of bookshelf
    for(int i = 0; i < num_books; i++){
        delete_book(bookshelf[i]);
    }
    delete [] bookshelf;
    bookshelf = nullptr;

    return 0;
}