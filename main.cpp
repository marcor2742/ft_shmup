#include <iostream>
#include <ncurses.h>
using namespace std;

int main() {
    initscr();

    noecho();
    curs_set(0);
    
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