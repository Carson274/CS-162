// Member function version
#include <iostream>

using namespace std;

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() // defines a member function named print
    {
        cout << year << '/' << month << '/' << day << endl;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    today.day = 16; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)

    return 0;
}