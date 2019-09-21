#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "curses.h"
#define PDC_DLL_BUILD 1

using namespace std;

int main(int argc, char** argv[]) {

	initscr();

	noecho();

	keypad(stdscr, TRUE);

	WINDOW* win = stdscr;

	int term_rows = getmaxy(win);
	int term_cols = getmaxx(win);

	//dimensions for main and menu windows
	int main_height = term_rows - 3;
	int main_width = term_cols;
	int main_startY = 3;
	int main_startX = 0;

	int menu_height = 4;
	int menu_width = term_cols;
	int menu_startY = 0;
	int menu_startX = 0;

	//creation of main and menu windows
	WINDOW* main_win = newwin(main_height, main_width, main_startY, main_startX);
	WINDOW* menu_win = newwin(menu_height, menu_width, menu_startY, menu_startX);

	refresh();

	//draws borders around windows
	box(main_win, '*', '-'); //draws a border around the main window
	box(menu_win, 0, '-'); // draws a border around the menu window

	mvwprintw(menu_win, LINES - 29, COLS - 119, "File	Edit	View                 Press F9 to Quit"); //prints this string to the screen at the entered coordinates
	wrefresh(menu_win);
	wrefresh(main_win);

	keypad(main_win, TRUE);

	bool keep_going = true;

	wofstream output_file{ "edit_file.txt" };

	/*while (keep_going == true)
	{
		refresh();

		int input = wgetch(main_win);
		mvaddch(0, 0, input);
		output_file << (wchar_t)input;
	}
	*/
	
	getch();

	endwin();

	
	return 0;
}