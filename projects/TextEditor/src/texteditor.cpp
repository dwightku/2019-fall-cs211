#include <iostream>
#include "curses.h"
#define PDC_DLL_BUILD 1

using namespace std;

int main(int argc, char** argv) {

	initscr();
	raw();
	int height, width, start_y, start_x;
	height = 30;
	width = 120;
	start_y = (LINES - height) / 2;
	start_x = (COLS - width) / 2;

	WINDOW* win = newwin(height, width, start_y, start_x); //creates a window 
	refresh();

	box(win, '*', '-'); //draws a border around the window
	mvwprintw(win, LINES - 29, COLS - 119, "File	Edit	View"); //prints this string to the screen at the entered coordinates
	wrefresh(win);

	getch();

	endwin();

	
	return 0;
}