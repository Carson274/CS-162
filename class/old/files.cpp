#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>

using namespace std;

struct Book
{
    int pages;
    string title;
    int num_authors;
    string* authors;
};


#endif