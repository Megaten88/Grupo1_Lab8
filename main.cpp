#include <ncurses.h>

int main(int argc, char const *argv[])
{
	initscr();
	addstr("Goodbye");
	refresh();
	getch();
    endwin();
	return 0;
}