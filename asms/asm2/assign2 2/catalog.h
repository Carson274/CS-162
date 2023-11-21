#include <iostream>
#include <fstream>

using namespace std;

// a struct to hold info of a team
struct Team {
  string name;        //name of the team
  string owner;       //owner of the team
  int market_value;   //market value of the team
  int num_player;     //number of players in the team
  struct Player *p;   //an array that holds all players
  float total_ppg;    //total points per game
};

// a struct to hold info of a player
struct Player {
  string name;      //name of the player
  int age;          //age of the player
  string nation;    //nationality of the player
  float ppg;        //points per game of the player
  float fg;         //field goal percentage
};

/**************************************************
 ** Name: prompt_userfile()
 ** Description: This function will get the user input
                 for a file name and check if it exists.
                 If it does nto exist, function will return
                 1 and end the program.
 ** Parameters: ifstream - an input file object
 ** Pre-conditions: none
 ** Post-conditions: either the file is opened or an
                     error message is displayed and
                     the program ends
 ***********************************************/
bool prompt_userfile(ifstream &, string &);

/**************************************************
 ** Name: create_teams()
 ** Description: This function will dynamically allocate
                 an array of teams (of the requested size)
 ** Parameters: int - size of the array
 ** Pre-conditions: none
 ** Post-conditions: a Team array of requested size is created
                     and returned
 ***********************************************/
Team* create_teams(int);

/**************************************************
 ** Name: populate_team_data()
 ** Description: This function will fill a single team struct 
                 with information that is read in from the file
 ** Parameters:  Team* - pointer to the Team array
                 int - index of the Team in the array to be filled 
                 ifstream& - input file to get information from
 ** Pre-conditions: Team array has been allocated; 
                    provided index is less than the array size
 ** Post-conditions: a Team at provided index is populated
 ***********************************************/
void populate_team_data(Team*, int, ifstream &); 

/**************************************************
 ** Name: create_players()
 ** Description: This function will dynamically allocate
                 an array of players (of the requested size)
 ** Parameters: int - size of the array
 ** Pre-conditions: none
 ** Post-conditions: a Player array of requested size is created and return
 ***********************************************/
Player* create_players(int);

/**************************************************
 ** Name: populate_player_data()
 ** Description: This function will fill a single player struct 
                 with information that is read in from the file
 ** Parameters:  Player* - pointer to the Player array
                 int - index of the Player in the array to be filled 
                 ifstream& - input file to get information from
 ** Pre-conditions: Player array has been allocated; 
                    provided index is less than the array size
 ** Post-conditions: a Player at provided index is populated
 ***********************************************/
void populate_player_data(Player*, int, ifstream &);

/**************************************************
 ** Name: print_teams_by_name_to_screen()
 ** Description: This function will print to screen the requested
                 team's information to the screen, including
                 its players' information
 ** Parameters:  teamArray* - pointer to the Team array
                 int - number of teams
 ** Pre-conditions: choice1 is 1;
                    Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized
 ** Post-conditions: team information is printed to screen
 ***********************************************/
void print_teams_by_name_to_screen(Team *, int);

/**************************************************
 ** Name: print_top_scorers_to_screen()
 ** Description: This function will print the top scorers from each
                 team to the screen along with their points per game
 ** Parameters:  teamArray* - pointer to the Team array
                 int - number of teams
 ** Pre-conditions:  choice1 is 2;
                     Team and Player arrays have been allocated
                     and initialized;
                     numTeams has been initialized
 ** Post-conditions: top scorers are printed to screen
 ***********************************************/
void print_top_scorers_to_screen(Team *, int);

/**************************************************
 ** Name: print_top_scorers_to_screen()
 ** Description: This function will print to screen the players
                 that have the nationalities corresponding to user
                 input
 ** Parameters:  teamArray* - pointer to the Team array
                 int - number of teams
 ** Pre-conditions:  choice1 is 3;
                     Team and Player arrays have been allocated
                     and initialized;
 ** Post-conditions: player names and ages are printed to screen
 ***********************************************/
void print_players_by_nationality_to_screen(Team *, int);

/**************************************************
 ** Name: calculate_and_sort_teams_ppg()
 ** Description: This function will calculate each team's total
                 points per game and sort them in descending
                 order by points per game
 ** Parameters: teamArray* - pointer to the Team array
                int - number of teams
 ** Pre-conditions: Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized
 ** Post-conditions: teams are sorted by points per game in
                     descending order
 ***********************************************/
void calculate_and_sort_teams_ppg(Team *, int);

/**************************************************
 ** Name: print_total_ppg_to_screen()
 * Description: This function will take an array of teams and
                print the team name to screen along with the 
                corresponding points per game
 ** Parameters: teamArray* - pointer to the Team array
                int - number of teams
 ** Pre-conditions: choice1 is 4;
                    Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized;
                    teams have been sorted by points per game
 * Post-conditions: team names and points per game are printed
                    in descending order to screen
 ***********************************************/
void print_total_ppg_to_screen(Team *, int);

/**************************************************
 ** Name: print_total_ppg_to_screen()
 ** Description: This function will call a specific funtion
                 depending on the value of choice1
 ** Parameters: string - user's second choice
                teamArray* - pointer to the Team array
                int - number of teams
 ** Pre-conditions: choice2 is 1;
                    Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized;
 ** Post-conditions: either print_teams_by_name_to_screen(),
                     print_top_scorers_to_screen(),
                     print_players_by_nationality_to_screen(),
                     or print_total_ppg_to_screen() is called,
                     depending on the value of choice1
 ***********************************************/
void print_to_screen(string, Team *, int);

/**************************************************
 ** Name: print_teams_by_name_to_file()
 ** Description: This function will print the requested
                 team's information to a file, including
                 its players' information
 ** Parameters: teamArray* - pointer to the Team array
                int - number of teams
                ofstream& - output file object
 ** Pre-conditions: choice1 is 1;
                    Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized
 ** Post-conditions: team information is printed to output file
 ***********************************************/
void print_teams_by_name_to_file(Team *, int, ofstream &);


/**************************************************
 ** Name: print_top_scorers_to_file()
 ** Description: This function will print the top scorers from each
                 team to the a file along with their points per game
 ** Parameters: teamArray* - pointer to the Team array
                int - number of teams
                ofstream& - output file object
 ** Pre-conditions: choice1 is 2;
                    Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized
 ** Post-conditions: top scorers are printed to output file
 ***********************************************/
void print_top_scorers_to_file(Team *, int, ofstream &);

/**************************************************
 ** Name: print_top_scorers_to_file()
 ** Description: This function will print the players that
                 have the nationalities corresponding to user
                 input to a file
 ** Parameters: teamArray* - pointer to the Team array
                int - number of teams
                ofstream& - output file object
 ** Pre-conditions: choice1 is 3;
                    Team and Player arrays have been allocated
                    and initialized;
 ** Post-conditions: player names and ages are printed to output file
 ***********************************************/
void print_players_by_nationality_to_file(Team *, int, ofstream &);


/**************************************************
 ** Name: print_total_ppg_to_file()
 ** Description: This function will take an array of teams and
                 print the team name to a file along with the 
                 corresponding points per game
 ** Parameters: teamArray* - pointer to the Team array
                int - number of teams
                ofstream& - output file object
 ** Pre-conditions: choice1 is 4;
                    Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized;
                    teams have been sorted by points per game
 ** Post-conditions: team names and points per game are printed
                     in descending order to output file
 ***********************************************/
void print_total_ppg_to_file(Team *, int, ofstream &);

/**************************************************
 ** Name: print_total_ppg_to_file()
 ** Description: This function will call a specific funtion
                 depending on the value of choice1
 ** Parameters: string - user's second choice
                teamArray* - pointer to the Team array
                int - number of teams
                ofstream& - output file object
 ** Pre-conditions: choice2 is 1;
                    Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized;
 ** Post-conditions: either print_teams_by_name_to_file(),
                     print_top_scorers_to_file(),
                     print_players_by_nationality_to_file(),
                     or print_total_ppg_to_file() is called,
                     depending on the value of choice1
 ***********************************************/
void print_to_file(string, Team *, int, ofstream &);

/**************************************************
 ** Name: print_destination()
 ** Description: This function will prompt the user to choose
                 where they would like the requested information
                 to go; their options are print to screen or
                 append to file
 ** Parameters: string - user's first choice
                string - user's second choice
                teamArray* - pointer to the Team array
                int - number of teams
                ofstream& - output file object
 ** Pre-conditions: choice1 is initialized;
                    Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized;
                    fout has been delcared
 ** Post-conditions: calls print_to_screen() or print_to_file()
                     with choice1
 ***********************************************/
void print_destination(string, string, Team *, int, ofstream &);

/**************************************************
 ** Name: shootingContest()
 ** Description: This function will simulate a shooting contest
                 between n amount of players, with n being user
                 input.
 ** Parameters: teamArray* - pointer to the Team array
                int - number of teams
 ** Pre-conditions: Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized
 ** Post-conditions: game has been simulated
 ***********************************************/
void shootingContest(Team *, int);

/**************************************************
 ** Name: ask_for_choice()
 ** Description: This function will prompt the user to choose
                 what they want the program to do, whether that be
                 search for a team by its name, display the top
                 scorer of each team, search players by nationality,
                 sort teams by total points per game, or to quit
 ** Parameters: string - user's first choice
                string - user's second choice
                teamArray* - pointer to the Team array
                int - number of teams
                ofstream& - output file object
 ** Pre-conditions: Team and Player arrays have been allocated
                    and initialized;
                    numTeams has been initialized;
                    fout, choice1, and choice2 have been delcared
 ** Post-conditions: calls print_destination and returns 1 or
                     returns 0
 ***********************************************/
void ask_for_choice(string, string, Team *, int, ofstream &);

/**************************************************
 ** Name: delete_info()
 ** Description: This function will  delete all the memory that was dynamically allocated
 ** Parameters: Team* - the Team array
 ** Pre-conditions: the provided Team array hasn't been freed yet
 ** Post-conditions: the Team array, with all Players inside, is freed
 ***********************************************/
void delete_info(Team*, int);