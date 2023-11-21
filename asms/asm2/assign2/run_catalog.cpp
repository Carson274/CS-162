#include <iostream>
#include <fstream>
#include "catalog.h"
#include "game.h"

using namespace std;

int main(){
	// define variables to be used throughout the program
	string userfile, choice1, choice2;
	int numTeams;

	// create an input only file object and an output only file object
	ifstream infile;
	ofstream outfile;

	// get user file name and end program if file name is invalid
	if(!prompt_userfile(infile, userfile)){
		return 1;
	}

	// read in number of teams from file to numTeams
	infile >> numTeams;

	// create an array of teams
	Team *teamArray = create_teams(numTeams);

	// for each team, populate the team data
	for(int i = 0; i < numTeams; ++i){
		populate_team_data(teamArray, i, infile);
	}

	// prompt user for choice
	ask_for_choice(choice1, choice2, teamArray, numTeams, outfile);
	
	// deallocate memory
	delete_info(teamArray, numTeams);

	cout << endl << "Bye!" << endl;
	return 0;
}