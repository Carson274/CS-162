/***********************************************************************
 * Program: catalog.cpp
 * Author: Carson Secrest
 * 10/29/2023
 * Description: This program manages a catalog of teams. It first
 * 				reads the catalog of teams from an input file that
 * 				is determined by the user's input. It then offers
 * 				various possible operations to perform on the file such
 * 				as searching for a team by its name, displaying the top
 * 				scorer of each team, and searching for players based
 * 				on nationality. The user is then prompted to have the
 * 				results either displayed to the screen or appended to
 * 				user-specified file.
 * Input: input and output file names, user choices for search and
 * 		  display options, team names, nationalities
 * Output: depending on the user's choice: team data, top scorers,
 * 		   players by nationality, and/or teams sorted by total point
 * 		   per game, all of which is either displayed to the screen
 * 		   or appended to an output file
***********************************************************************/

#include <iostream>
#include <fstream>
#include "catalog.h"
#include "game.h"

using namespace std;

bool prompt_userfile(ifstream &file, string &userfile){
	cout << "Enter the team info file name: ";
	cin >> userfile;
	
	// attempt to open file
	file.open(userfile);

	// check to see if the file has opened successfully
	if(!file.is_open()){
		cout << "Error opening file..." << endl;
		return 0;
	}
	else{
		return 1;
	}
}

Team * create_teams(int numTeams){
	Team *teamArray = new Team[numTeams]{};
	return teamArray;
}

Player * create_players(int numPlayers){
	Player *playerArray = new Player[numPlayers]{};
	return playerArray;
}

void populate_player_data(Player* players, int index, ifstream &infile){
	infile >> players[index].name;
	infile >> players[index].age;
	infile >> players[index].nation;
	infile >> players[index].ppg;
	infile >> players[index].fg;
}

void populate_team_data(Team* teams, int index, ifstream &infile){
	infile >> teams[index].name;
	infile >> teams[index].owner;
	infile >> teams[index].market_value;
	infile >> teams[index].num_player;

	Player *playerArray = create_players(teams[index].num_player);
	teams[index].p = playerArray;

	for(int i = 0; i < teams[index].num_player; ++i){
		populate_player_data(playerArray, i, infile); 
	}
}

void print_teams_by_name_to_screen(Team *teamArray, int numTeams){
	string userTeam;
	bool isTeam = false;

	do{
		cout << endl << "Enter the team's name: ";
		cin >> userTeam;

		for(int i = 0; i < numTeams; ++i){
			if(teamArray[i].name == userTeam){
				isTeam = true;

				cout << endl << "Team Name: " << teamArray[i].name << endl <<
						"------------------------------" << endl <<
						"Owner: " << teamArray[i].owner << endl <<
						"Market Value: " << teamArray[i].market_value << endl <<
						"Number of Players: " << teamArray[i].num_player << endl;

				Player *players = teamArray[i].p;

				for(int j = 0; j < teamArray[i].num_player; ++j){
					cout << endl << "Player " << j + 1 << ": " << endl <<
							"Name: " << players[j].name << endl <<
							"Age: " << players[j].age << endl <<
							"Nationailty: " << players[j].nation << endl <<
							"Points Per Game: " << players[j].ppg << endl <<
							"Field Goal %: " << players[j].fg << endl;
				}
				cout << "------------------------------" << endl << endl;
			}
		}
		if(!isTeam){
			cout << endl << "That team does not exist within our dataset." << endl;
		}
	}while(!isTeam);
}

void print_top_scorers_to_screen(Team *teamArray, int numTeams){
	cout << endl;
	for(int i = 0; i < numTeams; ++i){
		Player *players = teamArray[i].p;

		Player topScorer = players[0];
		for(int j = 0; j < teamArray[i].num_player; ++j){
			if(players[j].ppg > topScorer.ppg){
				topScorer = players[j];
			}
		}
		cout << teamArray[i].name << ": " << topScorer.name << " " << topScorer.ppg << endl;
	}
}

void print_players_by_nationality_to_screen(Team *teamArray, int numTeams){
	string userNation;
	bool isNation = false;

	// do this while non existent nation entered
	do{
		cout << endl << "Enter the player's nationality: ";
		cin >> userNation;

		for(int i = 0; i < numTeams; ++i){
			Player *players = teamArray[i].p;

			for(int j = 0; j < teamArray[i].num_player; ++j){
				if(players[j].nation == userNation){
					isNation = true;

					cout << players[j].name << " " <<
							players[j].age << endl;
				}
			}
		}

		if(!isNation){
			cout << "None of the players have that nationality." << endl;
		}
	}while(!isNation);
}

void calculate_and_sort_teams_ppg(Team* teamArray, int numTeams){
	Team tempTeam;
	bool isSorted;

	for(int i = 0; i < numTeams; ++i){
		Player *players = teamArray[i].p;

		for(int j = 0; j < teamArray[i].num_player; ++j){
			teamArray[i].total_ppg += players[j].ppg;
		}
	}
	do{
		isSorted = true;
		for(int i = 1; i < numTeams; ++i){
			if(teamArray[i].total_ppg > teamArray[i-1].total_ppg){
				tempTeam = teamArray[i];
				teamArray[i] = teamArray[i-1];
				teamArray[i-1] = tempTeam;
				isSorted = false;
			}
		}
	}while(!isSorted);
}

void print_total_ppg_to_screen(Team* teamArray, int numTeams){
	// sort the teams
	calculate_and_sort_teams_ppg(teamArray, numTeams);

	// print the teams and total ppg
	for(int i = 0; i < numTeams; ++i){
		cout << endl << "Team " << teamArray[i].name << endl;
		cout << "Points Per Game: " << teamArray[i].total_ppg << endl;
	}

	// reset total scores
	for(int i = 0; i < numTeams; ++i){
		teamArray[i].total_ppg = 0;
	}
}

void print_to_screen(string choice1, Team* teamArray, int numTeams){
	
	// print requested information to screen depending on the user's first choice
	if(choice1 == "1"){
		print_teams_by_name_to_screen(teamArray, numTeams);
	}else if(choice1 == "2"){
		print_top_scorers_to_screen(teamArray, numTeams);
	}else if(choice1 == "3"){
		print_players_by_nationality_to_screen(teamArray, numTeams);
	}else{
		print_total_ppg_to_screen(teamArray, numTeams);
	}
}

void print_teams_by_name_to_file(Team* teamArray, int numTeams, ofstream &fout){
	string userTeam;
	bool isTeam = false;

	// do this while non existent team name entered
	do{
		cout << endl << "Enter the team's name: ";
		cin >> userTeam;

		for(int i = 0; i < numTeams; ++i){
			if(teamArray[i].name == userTeam){
				isTeam = true;

				fout << endl << "Team Name: " << teamArray[i].name << endl <<
						"------------------------------" << endl <<
						"Owner: " << teamArray[i].owner << endl <<
						"Market Value: " << teamArray[i].market_value << endl <<
						"Number of Players: " << teamArray[i].num_player << endl << endl;

				Player *players = teamArray[i].p;

				for(int j = 0; j < teamArray[i].num_player; ++j){
					fout << "Player " << j + 1 << ": " << endl << endl <<
							"Name: " << players[j].name << endl <<
							"Age: " << players[j].age << endl <<
							"Nationailty: " << players[j].nation << endl <<
							"Points Per Game: " << players[j].ppg << endl <<
							"Field Goal %: " << players[j].fg << endl;
				}
				fout << "------------------------------" << endl;
			}
		}
		if(!isTeam){
			cout << endl << "That team does not exist within our dataset." << endl;
		}
	}while(!isTeam);
}

void print_top_scorers_to_file(Team* teamArray, int numTeams, ofstream &fout){
		for(int i = 0; i < numTeams; ++i){
		Player *players = teamArray[i].p;

		Player topScorer = players[0];
		for(int j = 0; j < teamArray[i].num_player; ++j){
			if(players[j].ppg > topScorer.ppg){
				topScorer = players[j];
			}
		}
		fout << teamArray[i].name << ": " << topScorer.name << " " << topScorer.ppg << endl;
	}
}

void print_players_by_nationality_to_file(Team* teamArray, int numTeams, ofstream &fout){
	string userNation;
	bool isNation = false;

	// do this while non existent nation entered
	do{
		cout << endl << "Enter the player's nationality: ";
		cin >> userNation;

		for(int i = 0; i < numTeams; ++i){
			Player *players = teamArray[i].p;

			for(int j = 0; j < teamArray[i].num_player; ++j){
				if(players[j].nation == userNation){
					isNation = true;

					fout << players[j].name << " " <<
							players[j].age << endl;
				}
			}
		}

		if(!isNation){
			cout << "None of the players have that nationality." << endl;
		}
	}while(!isNation);
}

void print_total_ppg_to_file(Team* teamArray, int numTeams, ofstream &fout){
	calculate_and_sort_teams_ppg(teamArray, numTeams);

	for(int i = 0; i < numTeams; ++i){
		fout << endl << "Team " << teamArray[i].name << endl;
		fout << "Points Per Game: " << teamArray[i].total_ppg << endl;
	}

	// reset total scores
	for(int i = 0; i < numTeams; ++i){
		teamArray[i].total_ppg = 0;
	}
}

void print_to_file(string choice1, Team* teamArray, int numTeams, ofstream &fout){
	string userfile;

	cout << endl << "Please provide desired filename: ";
	cin >> userfile;

	fout.open(userfile, ios::app);
	if(!fout.is_open()){
		cout << "Error: Cannot open file." << endl;
		return;
	}

	// print requested information to file depending on the user's first choice
	if(choice1 == "1"){
		print_teams_by_name_to_file(teamArray, numTeams, fout);
	}else if(choice1 == "2"){
		print_top_scorers_to_file(teamArray, numTeams, fout);
	}else if(choice1 == "3"){
		print_players_by_nationality_to_file(teamArray, numTeams, fout);
	}else{
		print_total_ppg_to_file(teamArray, numTeams, fout);
	}

	fout.close();

	cout << "Appended requested information to file." << endl;
}

void print_destination(string choice1, string choice2, Team* teamArray, int numTeams, ofstream &fout){
	bool isValidInput;

	do{
		cout << endl << "How would you like the information displayed?" << endl <<
				"1. Print to screen (Press 1)" << endl <<
				"2. Print to file (Press 2)" << endl <<
				"Your choice: ";
		cin >> choice2;

		// deciding where to print based on user's second choice
		if(choice2 == "1" || choice2 == "2"){
			isValidInput = true;
			if(choice2 == "1"){
				print_to_screen(choice1, teamArray, numTeams);
			}else{
				print_to_file(choice1, teamArray, numTeams, fout);
			}
		}
		else{
			isValidInput = false;
			cout << endl << "Invalid input. Input must be an integer within 1 and 4 inclusive." << endl << endl;
		}
	}while(!isValidInput);
}

void ask_for_choice(string choice1, string choice2, Team* teamArray, int numTeams, ofstream &fout){
	// boolean to see if the user entered a valid number
	bool done = false;

	// do this while the user input is not a valid number
	do{
		cout << endl << "Which option would you like to choose?" << endl << 
				"1. Search team by its name" << endl << 
				"2. Display the top scorer of each team" << endl << 
				"3. Search players by nationality" << endl <<
				"4. Sort teams by total points per game" << endl <<
				"5. Simulate basketball shooting contest" << endl <<
				"6. Quit" << endl <<
				"Your Choice: ";
		cin >> choice1;

		// check is user input is valid; re-prompt if not
		if(choice1 == "1" || choice1 == "2" || choice1 == "3" || choice1 == "4"){
			print_destination(choice1, choice2, teamArray, numTeams, fout);
		}else if(choice1 == "5"){
			shootingContest(teamArray, numTeams);
		}else if(choice1 == "6"){
			done = true;
		}else{
			cout << endl << "Invalid input. Input must be an integer within 1 and 4 inclusive." << endl << endl;
		}
	}while(!done);
}

void delete_info(Team* teamArray, int numTeams){
	// for each team, delete the player array
	for(int i = 0; i < numTeams; i++){
		delete [] teamArray[i].p;
	}

	// delete the team array
	delete [] teamArray;
}