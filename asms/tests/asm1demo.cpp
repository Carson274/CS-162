#include <iostream>
#include <cstdlib>

using namespace std;

int playerArray(int players){
	cout << "How many players are there? (Enter a positive integer): ";
	cin >> players;
	cout << endl;
	if(players > 0){
		return players;
	}
	else{
		cout << "Invalid input." << endl;
		playerArray(players);
		return 0;
	}
}

void userInput(int &num, int currentPlayer){
	cout << "Player " << currentPlayer << "!" << endl;
	cout << "Enter the rack number to wish to make your money ball rack: ";
	cin >> num;
	cout << endl;
}

void validateInput(int &num, int upper, int lower, string displayString){
	if(num >= lower && num <= upper){

	}
	else{
		cout << "Invalid input." << endl;
		cout << displayString;
		cin >> num;
		cout << endl;
		validateInput(num, upper, lower, displayString);
	}
}

void playAgain(bool &tryAgain){
	int upperBound = 1, lowerBound = 0, num;
	string displayString = "Would you like to play again? (1-yes, 0-no): ";
	cout << displayString;
	cin >> num;
	cout << endl;
	validateInput(num, upperBound, lowerBound, displayString);
	if(num == 1){
		tryAgain = true;
	}
	else{
		tryAgain = false;
		cout << "Thanks for playing!" << endl << endl;
	}
}

void adjustUserNum(int &num){
	if(num < 3){
		num -= 1;
	}
	else if(num > 3){
		num += 1;
	}
	else{

	}
}

// void simulateGame(int &num, int *rackArray, int rackSize, int &rackScore, int *scoresArray, int &currentPlayer){
// 	adjustUserNum(num);
// 	int i;
// 	// for(i = 0; i < numRacks; i++){
// 	// 	if(i == num){
// 	// 		moneyballRack(rackArray, rackSize);
// 	// 	}
// 	// 	else if(i == 2 || i == 4){
// 	// 		starryRack(rackArray, rackSize);
// 	// 	}
// 	// 	else{
// 	// 		normalRack(rackArray, rackSize);
// 	// 	}
// 	// 	calculateScore(rackArray, rackSize, rackScore, scoresArray, currentPlayer);
// 	// 	displayRack(rackArray, rackSize, rackScore, i);
// 	// }
// 	// displayTotal(scoresArray, currentPlayer);
// 	// currentPlayer += 1;
// }

int main() {
	cout << endl << "Welcome to the basketball shooting contest!" << endl << endl;
	bool tryAgain = false;
	srand(time(NULL));
	do{
		int userNum = 1, currentPlayer = 1, rackScore = 0, rackSize = 5, upperBound = 5, lowerBound = 1, maxPlayers = 0;
		maxPlayers = playerArray(maxPlayers);
		int *scoresArray = new int[maxPlayers]();
		int rackArray[rackSize];

		cout << "Dynamic array: ";
		for(int k = 0; k < maxPlayers; k++){
			cout << scoresArray[k] << " ";
		}

		string displayString = "Where do you want to put your moneyball rack? (1-5): ";
		do{
			userInput(userNum, currentPlayer);
			validateInput(userNum, upperBound, lowerBound, displayString);
			// simulateGame(userNum, rackArray, rackSize, rackScore, scoresArray, currentPlayer);
		}
		while(currentPlayer <= maxPlayers);
		playAgain(tryAgain);
	}
	while(tryAgain);
}