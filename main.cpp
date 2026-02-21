#include <iostream>
#include <ncurses.h>
using namespace std;

// defined in ncurses
// COLOR_BLACK   0
// COLOR_RED     1
// COLOR_GREEN   2
// COLOR_YELLOW  3
// COLOR_BLUE    4
// COLOR_MAGENTA 5
// COLOR_CYAN    6
// COLOR_WHITE   7

//keyboard input
// KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
//wasd: w=119, a=97, s=115, d=100
// shoot (space and keypad 0): 32 and 48

//controlla se ci sono piu player con lo stesso playerNum. e non deve essere maggiore di 2

int main() {
    initscr();

    noecho(); //don't print input characters
    nodelay(stdscr, TRUE); // make getch non-blocking
    keypad(stdscr, TRUE); // enable arrow keys
    curs_set(0); // hide cursor
    
    int h, w;
    getmaxyx(stdscr, h, w);
    
    int w_game = 40;
    int h_game = 40;
    // int w_score = 20;    

    WINDOW *winGame = newwin(h_game, w_game, 0, 0);
    box(winGame, 0, 0);
    wrefresh(winGame);
    
    WINDOW *winScore = newwin(h_game, w-w_game, 0, w_game);
    box(winScore, 0, 0);
    wrefresh(winScore);
    
    
    
    while (true) {
        wborder(winGame, ACS_VLINE,  ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
        box(winGame, 0, 0);
        mvwprintw(winGame, 1, 2, "wingame %dx%d @ (%d,%d)", h_game, w_game, 0, 0);
        mvwprintw(winScore, 1, 2, "winscore %dx%d @ (%d,%d)", h_game, w-w_game, 0, w_game);  
        wrefresh(winGame);
        wrefresh(winScore);
    }
    delwin(winGame);
    // delwin(winScore);
    curs_set(1);
    endwin();
}