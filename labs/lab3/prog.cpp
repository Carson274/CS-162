#include <iostream>
#include <iomanip>

using namespace std;

#include "multdiv.h"

int main()
{
	int row;
	int col;
    bool tryAgain;

	do{
        //Your code here:
        cout << "Enter number of rows: ";
        cin >> row;
        cout << endl;
        cout << "Enter number of columns: ";
        cin >> col;
        cout << endl;

        multdiv_entry** table = create_table(row, col);

        print_table(table, row, col);

        delete_table(table, row);

        restart(tryAgain);
    }while(tryAgain);
        
	return 0;
}