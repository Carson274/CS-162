/*********************************************************************************
 ** Program Filename: assignment1.cpp
 ** Author: Carson Secrest
 ** Date: 10/29/23
 ** Description: This program simulates a basketball shooting game
				 between two players. There are 5 racks of 5 basketballs,
				 with 2 additional starry balls between racks 2 and 3 as 
				 well as 3 and 4. Each ball is worth 1 point, with the
				 exception of the last ball of each rack, which is worth
				 2 points, and the starry balls, which are worth 3 points.
				 It prompts the players to enter a number between 1 and 5 
				 inclusive. The rack associated with this number will be
				 the moneyball rack, and all the balls in this rack will
				 be set to 2 points instead. The program will then simulate
				 each player's shots, with an equal 50% chance of making each
				 one. The status of each shot will be printed, along with the
				 score of each rack and the current player's score. At the end
				 of the program, the player with the higher score will be
				 declared the winner and the user will be prompted to play again.
 ** Input: Player choices for racks and whether or not to play again.
 ** Output: Display the prompt for rack choice, ball shot statuses, 
 			scores per rack, total scores, winner results, and prompt
			to play again.
 ********************************************************************************/

#include <iostream>
#include <cstdlib>
#include "catalog.h"
#include "game.h"

using namespace std;

void shootingContest(Team *teamArray, int numTeams) {
	cout << endl << "Welcome to the basketball shooting contest!" << endl << endl;

	bool tryAgain = false;
	srand(time(NULL));

	do{
		int userNum = 1, currentPlayer = 1, rackScore = 0, 
			rackSize = 5, upperBound = 5, lowerBound = 1, maxPlayers = 0;
		string playerName;
		float playerPercentage;
		int rackArray[rackSize];

		// determine the number of players and set maxPlayers accordingly
		maxPlayers = playerArray(maxPlayers);

		// initialize scoresArray to be the length of maxPlayers during runtime
		int *scoresArray = new int[maxPlayers]();

		string displayString = "Where do you want to put your moneyball rack? (1-5): ";

		// get user input and simulate the game
		do{
			userInput(userNum, currentPlayer, teamArray, numTeams, playerName, playerPercentage);
			validateInput(userNum, upperBound, lowerBound, displayString);
			simulateGame(userNum, rackArray, rackSize, rackScore, scoresArray, currentPlayer, teamArray, numTeams, playerPercentage);
		} while(currentPlayer <= maxPlayers);

		// find and display winner(s)
		findWinner(scoresArray, maxPlayers);

		// ask if the user wants to play again
		playAgain(tryAgain);

		// deallocate dynamic array memory
		delete[] scoresArray;

	} while(tryAgain);
}