#include <ncurses.h>

int main(void) {
    initscr();            // start curses mode
    printw("Hello, Lucedit! Press any key to exit."); 
    refresh();            // print it on the screen
    getch();              // wait for input
    endwin();             // end curses mode
    return 0;
}