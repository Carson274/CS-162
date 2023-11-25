#include <ncurses.h>
#include <string>
using namespace std;

int main(int argc, char ** argv) {

    initscr();
    cbreak();
    noecho();


    int x = 4, y = 3; // Initial position of the asterisk

    // Create a window for the board
    WINDOW *win = newwin(40, 60, 3, 6);
    box (win, 0, 0); // Draw a box around the window

    while (true) {
        wclear(win); // Clear the window

        // Draw the board
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                // Draw a box for each cell
                WINDOW *cell = derwin(win, 7, 12, i * 6, j * 11);
                box(cell, 0, 0);
                if (i == y && j == x) {
                    mvwprintw(cell, 1, 1, "*");
                } else {
                    mvwprintw(cell, 1, 1, " ");
                }
                delwin(cell); // Delete the cell window
            }
        }

        wrefresh(win); // Refresh the window

        // Get user input and update the position of the asterisk
        switch (getch()) {
            case 'w':
                if (y > 0) --y;
                break;
            case 'a':
                if (x > 0) --x;
                break;
            case 's':
                if (y < 4) ++y;
                break;
            case 'd':
                if (x < 4) ++x;
                break;
            case 'q': // Quit the game
                endwin();
                return 0;
        }
    }
















    // int height, width, start_y, start_x;
    // height = 10;
    // width = 20;
    // start_y = 10;
    // start_x = 10;

    // WINDOW * win = newwin(height, width, start_y, start_x);
    // refresh();

    // box(win, 0, 0);
    // mvwprintw(win, 1, 1, "This is my box");

    // wrefresh(win);

    // int c = getch();

    // endwin();





    // // initializes the screen
    // // sets up memory and clears the screen
    // initscr();

    // int x, y;
    // x = y = 10;

    // // moves the cursor to the specified location
    // move(y, x);

    // // print a string(const char *) to a window
    // printw("Hello World!");

    // // refreshes the screen to match memory
    // refresh();

    // // waits for user input, returns int value of that key
    // int c = getch();

    // // clears the screen
    // clear();

    // printw(0, 0, "%d", c);

    // getch();

    // // deallocates memory and ends ncurses
    // endwin();

    return 0;
}