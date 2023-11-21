#include <iostream>
#include <cstdlib>

using namespace std;

void playerArray(int &players){
	cout << "How many players are there? (Enter a positive integer): ";
	cin >> players;
	cout << endl;
    return;
}

void numRows(int &row){
    cout << "How many racks would you like? ";
    cin >> row;
    cout << endl;
    return;
}

void numCols(int &col){
    cout << "How many shots per rack would you like? ";
    cin >> col;
    cout << endl;
    return;
}

void userInput(int &num, int currentPlayer){
	cout << "Player " << currentPlayer << "!" << endl;
	cout << "Enter the rack number to wish to make your money ball rack: ";
	cin >> num;
	cout << endl;
}

void initializeRackArray(int**array, int row, int col){
    for(int i = 0; i < row; ++i){
        if(i % 2 == 0){
            for(int j = 0; j < col; ++j){
                if(j == col - 1){
                    array[i][j] = 2;
                }
                else{
                    array[i][j] = 1;
                }
            }
        }
        else{
            array[i][0] = 3;
        }
    }
    return;
}

void printRackArray(int**array, int row, int col){
    for(int i = 0; i < row; ++i){
    cout << "Row " << i+1 << ": ";
        if(i % 2 == 0){
            for(int j = 0; j < col; ++j){
                cout << array[i][j] << " ";
            }
        }
        else{
            cout << array[i][0];
        }
    cout << endl;
    }
    return;
}

int main() {
	cout << endl << "Welcome to the basketball shooting contest!" << endl << endl;

	bool tryAgain = false;
	srand(time(NULL));

	do{
		int userNum, currentPlayer = 1, maxPlayers, row, col;

		//playerArray(maxPlayers);
        numRows(row);
        numCols(col);

		int** rackArray = new int*[row];
        for(int i = 0; i < row; i++){
            rackArray[i] = new int[col];
        }
        initializeRackArray(rackArray,row,col);

		string displayString = "Where do you want to put your moneyball rack? (1-5): ";
		do{
			userInput(userNum, currentPlayer);
            
            printRackArray(rackArray,row,col);
		} while(currentPlayer <= maxPlayers);

	} while(tryAgain);
}