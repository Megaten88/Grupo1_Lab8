#include "Soldier.h"
#include "Squad.h"
#include <ncurses.h>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	initscr();
	start_color();
	addstr("Goodbye");
	refresh();
	getch();
    endwin();
	return 0;
}