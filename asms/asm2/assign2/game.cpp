#include <iostream>
#include <cstdlib>
#include "catalog.h"
#include "game.h"

using namespace std;

int playerArray(int players){
	do{
		cout << "How many players are there? (Enter a positive integer): ";
		cin >> players;
		cout << endl;

		if(players > 0){
			return players;
		}else{
			cout << "Invalid input." << endl;
		}
	}while(players <= 0);

	return 0;
}

void userInput(int &num, int currentPlayer, Team *teamArray, int numTeams, string &playerName, float &playerPercentage){
	bool validName = false;
	cout << "Player " << currentPlayer << "!" << endl;

	// search for existing player with the same name
	do{
		cout << "What is your name? ";
		cin >> playerName;
		for(int i = 0; i < numTeams; ++i){
			Player *playerArray = teamArray[i].p;
			for(int j = 0; j < teamArray[i].num_player; ++j){
				if(playerArray[j].name == playerName){
					validName = true;
					playerPercentage = playerArray[j].fg;
					break;
				}
			if(validName) break;
			}
		}
		if(!validName){
			cout << "Invalid player name." << endl << endl;
		}
	}while(!validName);

	cout << "Enter the rack number to wish to make your money ball rack: ";
	cin >> num;
	cout << endl;
}

void validateInput(int &num, int upper, int lower, string displayString){
	if(num >= lower && num <= upper){
		// input is valid; no action needed
	}
	else{
		cout << "Invalid input." << endl;
		cout << displayString;
		cin >> num;
		cout << endl;

		// revalidate input by recursively calling funtion
		validateInput(num, upper, lower, displayString);
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

void moneyballRack(int *rackArray, int &size){
	size = 5;

	for(int i = 0; i < 5; i++){
		rackArray[i] = 2;
	}
}

void starryRack(int *rackArray, int &size){
	size = 1;
	rackArray[0] = 3;
}

void normalRack(int *rackArray, int &size){
	size = 5;

	for(int i = 0; i < 4; i++){
		rackArray[i] = 1;
	}

	rackArray[4] = 2;
}

void calculateScore(int *rackArray, int size, int &rackScore, int *scoresArray, int currentPlayer, float playerPercentage){
	rackScore = 0;
	for(int i = 0; i < size; i++){
		float shot = rand() / (float)RAND_MAX;
		if(shot <= playerPercentage){
			rackScore += rackArray[i];
		}
		else{
			rackArray[i] = 0;
		}
	}

	// update the current player's total score
	scoresArray[currentPlayer - 1] += rackScore;
}

void rackNumberDisplay(int i){
	if(i == 2 || i == 4){
		cout << "Starry: ";
	}
	else if(i == 0 || i == 1){
		cout << "Rack " << i + 1 << ": ";
	}
	else if(i == 5 || i == 6){
		cout << "Rack " << i - 1 << ": ";
	}
	else{
		cout << "Rack " << i << ": ";
	}
}

void displayRackScore(int size, int score){
	if(size == 5){
		cout << "| " << score << " pts" << endl;
	}
	else{
		cout << "        | " << score << " pts" << endl;
	}
}

void displayRack(int *rackArray, int size, int &score, int rackIndex){
	// display the current rack number
	rackNumberDisplay(rackIndex);

	// iterate through the rack and display the status of each shot
	for(int i = 0; i < size; i ++){
		if(rackArray[i] == 0){
			cout << "X";
		}
		else if(rackArray[i] == 1){
			cout << "O";
		}
		else if(rackArray[i] == 2){
			cout << "M";
		}
		else{
			cout << "W";
		}
		cout << " ";
	}

	// display the score for the rack
	displayRackScore(size, score);
}

void displayTotal(int *scoresArray, int currentPlayer){
	cout << endl << "Total: " << scoresArray[currentPlayer - 1] << " pts" << endl << endl;
}

void simulateGame(int &num, int *rackArray, int rackSize, int &rackScore, int *scoresArray, int &currentPlayer, Team *teamArray, int numTeams, float playerPercentage){
	// adjust the user's input number
	adjustUserNum(num);
	int i;

	// iterate through the racks
	for(i = 0; i < numRacks; i++){
		if(i == num){
			moneyballRack(rackArray, rackSize);
		}
		else if(i == 2 || i == 4){
			starryRack(rackArray, rackSize);
		}
		else{
			normalRack(rackArray, rackSize);
		}

		// calculate and update the player's score
		calculateScore(rackArray, rackSize, rackScore, scoresArray, currentPlayer, playerPercentage);

		// display the current rack's status and score
		displayRack(rackArray, rackSize, rackScore, i);
	}

	// display the current player's total score
	displayTotal(scoresArray, currentPlayer);

	// move to the next player
	currentPlayer += 1;
}

void declareWinner(int *winnersArray, int numWinners){
	
	// declare winner(s) based on number of winners
	if(numWinners == 1){
		cout << "Player " << winnersArray[0] + 1 << " wins!" << endl;
	}
	else if(numWinners == 2){
		cout << "It's a tie! Player " << winnersArray[0] + 1 << " and Player "
			 << winnersArray[1] + 1 << " win!" << endl;
	}
	else{
		cout << "It's a " << numWinners << " way tie!" << endl << "Winners: ";
		for(int i = 0; i < numWinners; i++){
			if(i == numWinners - 1){
				cout << "Player " << winnersArray[i] + 1 << "!" << endl;
			}
			else{
				cout << "Player " << winnersArray[i] + 1 << " and ";
			}
		}
	}
}

void findWinner(int *scoresArray, int maxPlayers){
	int highestScore = 0, i, winnerScore = 0, numWinners;
	int *winnersArray = new int[maxPlayers](); 

	// iterate through the scores to find the highest score and the winner(s)
	for(i = 0; i < maxPlayers; i++){
		if(scoresArray[i] > highestScore){
			highestScore = scoresArray[i];
			winnersArray[0] = i;
			numWinners = 1;
		}
		else if(scoresArray[i] == highestScore){
			winnersArray[numWinners] = i;
			numWinners += 1;
		}
	}

	// declare the winner(s)
	declareWinner(winnersArray, numWinners);

	// deallocate dynamic array memory
	delete[] winnersArray;
}

void playAgain(bool &tryAgain){
	// declare upper and lower bounds for user input
	int upperBound = 1, lowerBound = 0, num;
	
	// prompt user for input
	string displayString = "Would you like to play again? (1-yes, 0-no): ";
	cout << displayString;
	cin >> num;
	cout << endl;

	// validate user input to ensure it's within the bounds
	validateInput(num, upperBound, lowerBound, displayString);

	// set tryAgain depending on user input
	if(num == 1){
		tryAgain = true;
	}
	else{
		tryAgain = false;
		cout << "Thanks for playing!" << endl << endl;
	}
}