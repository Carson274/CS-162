#include <iostream>
#include <iomanip>

using namespace std;

#include "multdiv.h"

multdiv_entry** create_table(int row, int col){
	multdiv_entry** table = new multdiv_entry*[row];
	for(int i = 0; i < row; i ++){
		table[i] = new multdiv_entry[col];
		for(int j = 0; j < col; j++){
			table[i][j].mult = (i + 1) * (j + 1);
			table[i][j].div = float(i + 1) / float(j + 1);
		}
	}
	return table;
}

void print_table(multdiv_entry** tables, int row, int col){
	cout << "Multipication table: " << endl;
	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j++){
			cout << tables[i][j].mult << "\t";
		}
		cout << endl;
	}

	cout << "Division table: " << endl;
	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j++){
			cout << fixed << setprecision(2) << tables[i][j].div << "\t";
		}
		cout << endl;
	}
}

void delete_table(multdiv_entry** tables, int row){
	for(int i = 0; i < row; i ++){
		delete[] tables[i];
	}
	delete[] tables;
	tables = nullptr;
}

void restart(bool &choice){
	cout << "Would you like to try again? (1 - Yes 0 - No): ";
	cin >> choice;
}