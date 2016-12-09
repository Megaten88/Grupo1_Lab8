#include "Soldier.h"
#include "Squad.h"
#include "Assassin.h"
#include "Archer.h"
#include "HardArmor.h"
#include <ncurses.h>
#include <vector>
using namespace std;

vector<Squad*> escuadrones;

int main(int argc, char const *argv[]){
	initscr();
	start_color();
	int option = 0 ;
			char temp[1];
			while (option != 3) {
				addstr("SIMULACIÓN : Guerras Punicas\n");
				refresh();
				addstr("1) Agregar escuadrón\n");
				refresh();
				addstr("2) Agregar soldado a escuadron\n");
				refresh();
				addstr("3) Salir \n");
				refresh();
				scanw("%d",&option);
				char nombre[25];
				int edad;
				char ciudad[25];
				if (option == 1) {
					addstr("Ingrese el nombre de su escuadron: \n");
					refresh();
					getstr(nombre);
					escuadrones.push_back(new Squad(nombre));
					addstr("Su escuadron ha sido agregado exitosamente\n");
					refresh();
				}

				if (option == 2){
					int selectSquad=0;
					int select=0;
					int repeat=0;

					if (escuadrones.size()> 0) {
						addstr("Seleccione su escuadron: \n");
						refresh();
							stringstream ss;
							for (size_t i = 0; i < escuadrones.size(); i++) {
								ss<<i <<" : " << escuadrones.at(i)->toString() << "\n";
							}
							string menu = ss.str();
							addstr(menu.c_str());
							refresh();
						 scanw("%d",&selectSquad);

						 addstr("¿Qué desea agregar a su escuadron?\n");
						 refresh();
						 addstr("1) Arquero \n");
						 refresh();
						 addstr("2) Coraza Dura\n");
						 refresh();
						 addstr("3) Asesino Oculto \n");
						 refresh();

						 scanw("%d",&select);

						 if (select == 1 ) {
							 	int flechas=0;
							 	int presicion=0;
							 	addstr("¿Cuantos arqueros desea agregar?\n");
							 	refresh();
								scanw("%d",&repeat);

								while (repeat > 0 ) {
									addstr("Ingrese el nombre: \n");
									refresh();
									getstr(nombre);
									addstr("Ingrese la edad:\n");
									refresh();
									scanw("%d",&edad);
									addstr("Ingrese el nombre de la ciudad de origen\n");
									refresh();
									getstr(ciudad);
									addstr("Cantidad de flechas: \n");
									refresh();
									scanw("%d",&flechas);
									addstr("Rango de presicion; \n");
									refresh();
									scanw("%d",&presicion);
									escuadrones.at(selectSquad)->addSoldier(new Archer(nombre,edad,ciudad,flechas,presicion));

									repeat--;
								}

						 }

						 if (select == 2 ) {
							 int dureza=0;
							 int lanzas=0;

							 addstr("¿Cuantos Coraza dura desea agregar?\n");
							 refresh();
							 scanw("%d",&repeat);
							 while (repeat > 0 ) {
								 addstr("Ingrese el nombre: \n");
								 refresh();
								 getstr(nombre);
								 addstr("Ingrese la edad:\n");
								 refresh();
								 scanw("%d",&edad);
								 addstr("Ingrese el nombre de la ciudad de origen\n");
								 refresh();
								 getstr(ciudad);
								 addstr("Nivel de dureza: \n");
								 refresh();
								 scanw("%d",&dureza);;
								 addstr("Numero de lanzas: \n");
								 refresh();
								 scanw("%d",&lanzas);

								 escuadrones.at(selectSquad)->addSoldier(new HardArmor(nombre,edad,ciudad,dureza,lanzas));

								 repeat--;
							 }

						 }

						 if (select == 3 ) {
							 int victimas=0;
							 int presencia=0;
							 addstr("¿Cuantos Asesinos Ocultos desea agregar?\n");
							 refresh();
							 scanw("%d", &repeat);
							 while (repeat > 0 ) {
								 addstr("Ingrese el nombre: \n");
								 refresh();
								 getstr(nombre);
								 addstr("Ingrese la edad:\n");
								 refresh();
								 scanw("%d",&edad);
								 addstr("Ingrese el nombre de la ciudad de origen\n");
								 refresh();
								 getstr( ciudad);
								 addstr("Numero de nictimas: \n");
								 refresh();
								 scanw("%d",&victimas);
								 addstr("Nivel de presencia; \n");
								 refresh();
								 scanw("%d",&presencia);;
								 escuadrones.at(selectSquad)->addSoldier(new Assassin(nombre,edad,ciudad,victimas,presencia));
								 repeat--;
							 }
						 }
					}else{
						addstr("Almenos ocupa un escuadron al cual agregar soldados.\n");
					}
				}

			}
		refresh();
		getch();
    	endwin();
		for (int i = 0; i < escuadrones.size(); ++i){
	    	escuadrones.erase(escuadrones.begin() + i);
		}
    	escuadrones.clear();

	return 0;
}
