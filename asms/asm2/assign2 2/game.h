#include <iostream>
#include <cstdlib>

using namespace std;

const int numRacks = 7;

/*********************************************************************************
 ** Function: playerArray
 ** Description: Prompts user to enter number of players and collects input. 
				 Validates user input to ensure it is a positive integer.
 **	Parameters: int players
 ** Pre-Conditions: int maxPlayers has been defined and passed to playerArray
					as players
 ** Post-Conditions: players holds a positive integer values and is returned
********************************************************************************/
int playerArray(int);

/*********************************************************************************
 ** Function: userInput
 ** Description: Prompts user and gets input for where they would like to put the
 				 current player's moneyball rack.
 **	Parameters: int reference to userNum, int currentPlayer, pointer to teamArray,
 				int numTeams, reference to playerName
 ** Pre-Conditions: userNum defined but not yet initialized, currentPlayer is
 					a defined and initialized integer
 ** Post-Conditions: user input is collected and stored at the address of num,
 					 which is userNum; user's name found and stored in userName
********************************************************************************/
void userInput(int &, int, Team *, int, string &, float &);

/*********************************************************************************
 ** Function: validateInput
 ** Description: Uses an if-else statement to determine whether or not the user's
 				 input is within a valid range given by upper and lower bounds,
 				 and prompts the user to enter another number if not.
 **	Parameters: reference to user's number, upperBound and lowerBound, 
 				displayString
 ** Pre-Conditions: user's number has been stored at the address of the reference,
 					upper and lower bounds initialized, displayString initialized
 ** Post-Conditions: if input not within range, displayString is printed and num
 					 is updated
********************************************************************************/
void validateInput(int &, int, int, string);

/*********************************************************************************
 ** Function: adjustUserNum
 ** Description: Adjusts user's choice of rack so it corresponds to the correct
 				 rack number.
 **	Parameters: reference to user's number
 ** Pre-Conditions: num holds the address of the user's number, where the user's
 					number has been initialized
 ** Post-Conditions: user's number changed to correctly represent the index of
					 the rack they chose
********************************************************************************/
void adjustUserNum(int &);

/*********************************************************************************
 ** Function: moneyballRack
 ** Description: Sets the points of all 5 elements of the rack to equal 2.
 **	Parameters: pointer to rackArray, reference to size of the array
 ** Pre-Conditions: rackArray defined and initialized to accomodate a length of 5,
 					rack size defined
 ** Post-Conditions: rackArray filled with a 2 at every index, size initialzed to
 					 5
********************************************************************************/
void moneyballRack(int *, int &);

/*********************************************************************************
 ** Function: starryRack
 ** Description: Sets the points of the first element of the rack to 3.
 **	Parameters: pointer to rackArray, reference to size of the array
 ** Pre-Conditions: rackArray defined and initialized to accomodate a length of 1,
 					rack size defined
 ** Post-Conditions: rackArray filled with a 3 at index 0, size initalized to 1
********************************************************************************/
void starryRack(int *, int &);

/*********************************************************************************
 ** Function: normalRack
 ** Description: Sets the points of the first 4 elements of the rack equal to 1,
 				 and the last element equal to 2.
 **	Parameters: pointer to rackArray, reference to size of the array
 ** Pre-Conditions: rackArray defined and initialized to accomodate a length of 5,
 					rack size defined
 ** Post-Conditions: rackArray filled with a 1 at every index except the last,
 					 which is 2, size initialzed to 5
********************************************************************************/
void normalRack(int *, int &);

/*********************************************************************************
 ** Function: calculateScore
 ** Description: For each index of the array, determines whether the shot was made
 				 or missed. Adds the score at the corresponding index to the rack
 				 score if made. Otherwise, sets the index to equal 0. Adds the
 				 rack score to the current player's total score.
 **	Parameters: pointer to rackArray, size, reference to rackScore, pointer to
 				scoresArray, currentPlayer
 ** Pre-Conditions: rackArray initalized with points, size initialized with either
 					0 or 5, rackScore defined, scoresArray defined at
 					currentPlayer's index, currentPlayer initialized with the
 					current player's number
 ** Post-Conditions: shots simulated and added to rackScore, rackArray points
 					 updated depending on shots made, rackScore added to the
 					 player's index of scoresArray
********************************************************************************/
void calculateScore(int *, int , int &, int *, int, float);

/*********************************************************************************
 ** Function: rackNumberDisplay
 ** Description: Displays the number of the current rack being printed. If the
 				 current rack is the starry rack, then the function displays
 				 "Starry" instead.
 **	Parameters: int i
 ** Pre-Conditions: i holds the index of the current rack being displayed
 ** Post-Conditions: rack number or "Starry" printed
********************************************************************************/
void rackNumberDisplay(int);

/*********************************************************************************
 ** Function: displayRackScore
 ** Description: Displays the total score for the current rack.
 **	Parameters: int size, int score
 ** Pre-Conditions: size is either 5 or 0 and the score is accurate
 ** Post-Conditions: number of points from the rack printed
********************************************************************************/
void displayRackScore(int, int);

/*********************************************************************************
 ** Function: displayRack
 ** Description: This function displays the statuses of each ball on the rack
 				 after they have been shot, with a character representing each
 				 possible outcome.
 **	Parameters: pointer to rackArray, size of array, reference to rack score,
 				current rack number
 ** Pre-Conditions: rackArray is initialized with the correct points, rack
 					size corresponds to the rack type (5 or 1), rack score
 					holds the current rack's score, rackIndex has the number
 					of the current rack
 ** Post-Conditions: the letters X, O, M, and W are printed when appropriate
********************************************************************************/
void displayRack(int *, int, int &, int);

/*********************************************************************************
 ** Function: displayTotal
 ** Description: Displays the current player's total score.
 **	Parameters: pointer to scoresArray, number of the currentPlayer
 ** Pre-Conditions: scoresArray initialized and filled with the correct score
 					of each player
 ** Post-Conditions: total of the current player's score printed
********************************************************************************/
void displayTotal(int *, int);

/*********************************************************************************
 ** Function: simulateGame
 ** Description: This function encompasses all rack and shot-related functions of
 				 the program. It calls on several functions in order to correctly
 				 calculate and display the current player's game and scores.
 **	Parameters: reference to userNum, pointer to rackArray, rackSize, reference
				to rackScore, pointer to scoresArray, and the current player's
				number, pointer to teamArray, int numTeams, string userName
 ** Pre-Conditions: userNum collected from user, rackArray defined, rackSize
 					defined, rackScore defined, scoresArray initialized to
 					accomodate for the total amount of players, currentPlayer
 					holds the current player's number
 ** Post-Conditions: userNum adjusted, rackArray filled with points, rackArray
 					scores calculated, rackArray printed, scoresArray filled with
 					each player's total scores, scoreArray printed at current
 					player's index
********************************************************************************/
void simulateGame(int &, int *, int, int &, int *, int &, Team *, int, float);

/*********************************************************************************
 ** Function: declareWinner
 ** Description: Prints win message according to the number of winners.
 				 declaring them the winner.
 **	Parameters: pointer to winnersArray, numWinners
 ** Pre-Conditions: winnersArray correctly filled with the index of each winner,
 					numWinners holds the amount of winners
 ** Post-Conditions: winner message displayed to user
********************************************************************************/
void declareWinner(int *, int);

/*********************************************************************************
 ** Function: findWinner
 ** Description: Finds the highest score of the players and calls on declareWinner
 				 to display winner(s).
 **	Parameters: pointer to scoresArray, maxPlayers
 ** Pre-Conditions: scoresArray correctly filled with the scores of each player,
 					maxPlayers holds the amount of players selected
 ** Post-Conditions: highest score found and corresponding player declared winner
********************************************************************************/
void findWinner(int *, int);

/*********************************************************************************
 ** Function: playAgain
 ** Description: Prompts the user to play again. Causes the program to run again
 				 if the user chooses; else, displays farewell message.
 **	Parameters: reference to bool tryAgain
 ** Pre-Conditions: tryAgain is true
 ** Post-Conditions: depending on user input, tryAgain is true or false, and a
 					 farewell message may be displayed
********************************************************************************/
void playAgain(bool &);