/***********************************************************************
 * Program: Hunt the Wumpus
 * Author: Carson Secrest
 * Date: 11/29/23
 * Description: This program is an adventure game where the player
 *              navigates through a cave system to hunt down the Wumpus.
 *              The player can move to adjacent rooms, shoot arrows to kill
 *              the Wumpus, and avoid hazards such as stalactites and bats.
 * 			    The player wins if they either kill the Wumpus or brind the
 * 				gold to the exit, and loses if they get killed.
 * Input: user input for movement, shooting arrows, entering debug mode,
 *			   and replaying/exiting the game
 * Output: game messages and prompts displayed to the screen
***********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include "game.h"

using namespace std;

// over 15 lines needed to display title
int main()
{
	initscr();
	cbreak();
	noecho();

	// display title
	WINDOW *start_win = newwin(47, 170, 3, 6);
	box(start_win, 0, 0);
	refresh();
	int title_margin = 10;
	mvwprintw(start_win, 1, title_margin, "   SSSSSSSSSSSSSSS UUUUUUUU     UUUUUUUURRRRRRRRRRRRRRRRR   VVVVVVVV           VVVVVVVVIIIIIIIIIIVVVVVVVV           VVVVVVVVEEEEEEEEEEEEEEEEEEEEEE");
	mvwprintw(start_win, 2, title_margin, " SS:::::::::::::::SU::::::U     U::::::UR::::::::::::::::R  V::::::V           V::::::VI::::::::IV::::::V           V::::::VE::::::::::::::::::::E");
	mvwprintw(start_win, 3, title_margin, "S:::::SSSSSS::::::SU::::::U     U::::::UR::::::RRRRRR:::::R V::::::V           V::::::VI::::::::IV::::::V           V::::::VE::::::::::::::::::::E");
	mvwprintw(start_win, 4, title_margin, "S:::::S     SSSSSSSUU:::::U     U:::::UURR:::::R     R:::::RV::::::V           V::::::VII::::::IIV::::::V           V::::::VEE::::::EEEEEEEEE::::E");
	mvwprintw(start_win, 5, title_margin, "S:::::S             U:::::U     U:::::U   R::::R     R:::::R V:::::V           V:::::V   I::::I   V:::::V           V:::::V   E:::::E       EEEEEE");
	mvwprintw(start_win, 6, title_margin, "S:::::S             U:::::D     D:::::U   R::::R     R:::::R  V:::::V         V:::::V    I::::I    V:::::V         V:::::V    E:::::E              ");
	mvwprintw(start_win, 7, title_margin, " S::::SSSS          U:::::D     D:::::U   R::::RRRRRR:::::R    V:::::V       V:::::V     I::::I     V:::::V       V:::::V     E::::::EEEEEEEEEE   ");
	mvwprintw(start_win, 8, title_margin, "  SS::::::SSSSS     U:::::D     D:::::U   R:::::::::::::RR      V:::::V     V:::::V      I::::I      V:::::V     V:::::V      E:::::::::::::::E   ");
	mvwprintw(start_win, 9, title_margin, "    SSS::::::::SS   U:::::D     D:::::U   R::::RRRRRR:::::R      V:::::V   V:::::V       I::::I       V:::::V   V:::::V       E:::::::::::::::E   ");
	mvwprintw(start_win, 10, title_margin, "       SSSSSS::::S  U:::::D     D:::::U   R::::R     R:::::R      V:::::V V:::::V        I::::I        V:::::V V:::::V        E::::::EEEEEEEEEE   ");
	mvwprintw(start_win, 11, title_margin, "            S:::::S U:::::D     D:::::U   R::::R     R:::::R       V:::::V:::::V         I::::I         V:::::V:::::V         E:::::E              ");
	mvwprintw(start_win, 12, title_margin, "            S:::::S U::::::U   U::::::U   R::::R     R:::::R        V:::::::::V          I::::I          V:::::::::V          E:::::E       EEEEEE");
	mvwprintw(start_win, 13, title_margin, "SSSSSSS     S:::::S U:::::::UUU:::::::U RR:::::R     R:::::R         V:::::::V         II::::::II         V:::::::V         EE::::::EEEEEEEE:::::E");
	mvwprintw(start_win, 14, title_margin, "S::::::SSSSSS:::::S  UU:::::::::::::UU  R::::::R     R:::::R          V:::::V          I::::::::I          V:::::V          E::::::::::::::::::::E");
	mvwprintw(start_win, 15, title_margin, "S:::::::::::::::SS     UU:::::::::UU    R::::::R     R:::::R           V:::V           I::::::::I           V:::V           E::::::::::::::::::::E");
	mvwprintw(start_win, 16, title_margin, " SSSSSSSSSSSSSSS         UUUUUUUUU      RRRRRRRR     RRRRRRR            VVV            IIIIIIIIII            VVV            EEEEEEEEEEEEEEEEEEEEEE");
	mvwprintw(start_win, 20, title_margin, "                                 CCCCCCCCCCCCC   SSSSSSSSSSSSSSS        1111111           66666666    222222222222222                       ");
	mvwprintw(start_win, 21, title_margin, "                              CCC::::::::::::C SS:::::::::::::::S      1::::::1          6::::::6    2:::::::::::::::22                     ");
	mvwprintw(start_win, 22, title_margin, "                            CC:::::::::::::::CS:::::SSSSSS::::::S     1:::::::1         6::::::6     2::::::222222:::::2                    ");
	mvwprintw(start_win, 23, title_margin, "                           C:::::CCCCCCCC::::CS:::::S     SSSSSSS     111:::::1        6::::::6      2222222     2:::::2                    ");
	mvwprintw(start_win, 24, title_margin, "                          C:::::C       CCCCCCS:::::S                    1::::1       6::::::6                   2:::::2                    ");
	mvwprintw(start_win, 25, title_margin, "                         C:::::C              S:::::S                    1::::1      6::::::6                    2:::::2                    ");
	mvwprintw(start_win, 26, title_margin, "                         C:::::C               S::::SSSS                 1::::1     6::::::6                  2222::::2                     ");
	mvwprintw(start_win, 27, title_margin, "                         C:::::C                SS::::::SSSSS            1::::l    6::::::::66666        22222::::::22                      ");
	mvwprintw(start_win, 28, title_margin, "                         C:::::C                  SSS::::::::SS          1::::l   6::::::::::::::66    22::::::::222                        ");
	mvwprintw(start_win, 29, title_margin, "                         C:::::C                     SSSSSS::::S         1::::l   6::::::66666:::::6  2:::::22222                          ");
	mvwprintw(start_win, 30, title_margin, "                         C:::::C                          S:::::S        1::::l   6:::::6     6:::::62:::::2                                ");
	mvwprintw(start_win, 31, title_margin, "                          C:::::C       CCCCCC            S:::::S        1::::l   6:::::6     6:::::62:::::2                                ");
	mvwprintw(start_win, 32, title_margin, "                           C:::::CCCCCCCC::::CSSSSSSS     S:::::S     111::::::1116::::::66666::::::62:::::2       222222                   ");
	mvwprintw(start_win, 33, title_margin, "                            CC:::::::::::::::CS::::::SSSSSS:::::S     1::::::::::1 66:::::::::::::66 2::::::2222222:::::2                   ");
	mvwprintw(start_win, 34, title_margin, "                              CCC::::::::::::CS:::::::::::::::SS      1::::::::::1   66:::::::::66   2::::::::::::::::::2   ");
	mvwprintw(start_win, 35, title_margin, "                                 CCCCCCCCCCCCC SSSSSSSSSSSSSSS        111111111111     666666666     22222222222222222222     ");
	wattron(start_win, A_BLINK); // attempt to blink
	mvwprintw(start_win, 40, 70, "Press any key to continue...");
	wattroff(start_win, A_BLINK);
	wrefresh(start_win);
	move(0,0);
	getch();
	delwin(start_win);
	refresh();
	clear();
	refresh();

	// set the random seed
	srand(time(NULL));
	
	int wid = 5, len = 5, hig = 3;
	bool debug = true;
	
	Game g;

	// play game
	g.play_game(wid, len, hig, debug);

	move(0,0);
	clear();
	refresh();

	return 0;
}