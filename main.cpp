#include "Soldier.h"
#include "Squad.h"
#include "Assassin.h"
#include "Archer.h"
#include "HardArmor.h"
#include <ncurses.h>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]){
	initscr();
	start_color();
	addstr("Goodbye");
	refresh();
	getch();
    endwin();

	return 0;
}