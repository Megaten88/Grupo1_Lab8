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
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	int option = 0 ;
	char temp[1];
	while (option != 4) {
		addstr("SIMULACIÓN : Guerras Punicas\n");
		refresh();
		addstr("1) Agregar escuadrón\n");
		refresh();
		addstr("2) Agregar soldado a escuadron\n");
		refresh();
		addstr("3) Inicar simulacion\n");
		refresh();
		addstr("4) Salir \n");
		refresh();
		scanw("%d",&option);
		clear();
		char nombre[25];
		int edad;
		char ciudad[25];
		if (option == 1) {
			clear();
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
				clear();
				addstr("Seleccione su escuadron: \n");
				refresh();
				stringstream ss;
				for (int i = 0; i < escuadrones.size(); i++) {
					ss<< i <<" : " << escuadrones.at(i)->toString() << "\n";
				}

				string menu = ss.str();
				addstr(menu.c_str());
				refresh();
				scanw("%d",&selectSquad);
				if (selectSquad >= escuadrones.size() || selectSquad<0)
				{
					addstr("No existe.");
					refresh();
				}else{
					clear();
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
							clear();
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

				}

				if (select == 2 ) {
					int dureza=0;
					int lanzas=0;

					addstr("¿Cuantos Coraza dura desea agregar?\n");
					refresh();
					scanw("%d",&repeat);
					while (repeat > 0 ) {
						clear();
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
						clear();
						addstr("Ingrese el nombre: \n");
						refresh();
						getstr(nombre);
						addstr("Ingrese la edad:\n");
						refresh();
						scanw("%d",&edad);
						addstr("Ingrese el nombre de la ciudad de origen\n");
						refresh();
						getstr( ciudad);
						addstr("Numero de victimas: \n");
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

		if (option == 3) {
			if (escuadrones.size() > 3) {
				int repeat = 0;
				vector<Squad*> frontal1;
				vector<Squad*> frontal2;
				Squad* back1;
				Squad* back2;
				int select1= 0;
				int select2= 0;
				clear();
				addstr("Se tienen 2 bandos,ambos con un escuadron al frente y otro en la retaguardia\n");
				refresh();

				stringstream ss;
				for (size_t i = 0; i < escuadrones.size(); i++) {
					ss<<i <<" : " << escuadrones.at(i)->toString() << "\n";
				}
				string menu = ss.str();
				addstr(menu.c_str());
				refresh();
						////////////////////////////////////////////////////////
				addstr("Bando 1: ¿Cuantos escuadrones desea agregar al frente?\n");
				refresh();
				scanw("%d",&repeat);
				for (int i = 0; i < repeat; i++) {
					addstr(menu.c_str());
					addstr("Bando 1: Seleccione el escuadron frontal: ");
					refresh();
					scanw("%d",&select1);
					frontal1.push_back(escuadrones.at(select1));
				}

				addstr("Bando 1: Seleccione el escuadron de retaguardia: ");
				refresh();
				scanw("%d",&select2);
				
				frontal1.push_back(escuadrones.at(select1));
				back1 = escuadrones.at(select2);
						///////////////////////////////////////////////////////
				addstr(menu.c_str());
				refresh();

				addstr("Bando 2:¿Cuantos escuadrones desea agregar al frente?\n");
				refresh();
				scanw("%d",&repeat);
				for (int i = 0; i < repeat; i++) {
					addstr(menu.c_str());
					refresh();
					addstr("Bando 2: Seleccione el escuadron frontal:");
					refresh();
					scanw("%d",&select1);
					frontal2.push_back(escuadrones.at(select1));
				}

				addstr("Bando 2: Seleccione el escuadron de retaguardia:");
				refresh();
				scanw("%d",&select2);
				back2 = escuadrones.at(select2);

				stringstream frontone ;
				stringstream fronttwo ;

				addstr("INICIO DE LA GUERRA!!!!\n");
				refresh();
				clear();
				while( back1 != NULL || back2!=  NULL){
					Squad* temp;
					Squad* aux;

					int ataque1= 0;
					int ataque2= 0;

					addstr("Bando 1: Seleccione ejercito de ataque\n");
					refresh();

					if (frontal1.size() > 0){
						for (size_t i = 0; i < frontal1.size(); i++) {
							frontone<<i <<" : " << frontal1.at(i)->toString() << "\n";
						}
						
						string army1 = frontone.str();
						addstr(army1.c_str());
						refresh();
						scanw("%d",&ataque1);
						temp = frontal1.at(ataque1);
					}else{
						temp = back1;
					}

					addstr("Bando 2: Eliga con quien defender\n");
					refresh();

					if (frontal2.size() > 0)
					{
						for (size_t i = 0; i < frontal2.size(); i++) {
							fronttwo << i <<" : " << frontal2.at(i)->toString() << "\n";
						}	

						string army2 = fronttwo.str();
						addstr(army2.c_str());
						refresh();
						scanw("%d",&ataque2);
						aux = frontal2.at(ataque2);

					}else{
						aux = back2;
					}

					if (temp->getTotalAttack() > aux->getTotalDef() * 10) {

						frontal2.erase(frontal2.begin() + ataque2);
						if(frontal2.size() < 1){
							back2 = NULL;
						}

					}else if (aux->getTotalAttack() > temp->getTotalDef() * 10 ){

						frontal1.erase(frontal1.begin() + ataque1);
						if(frontal1.size() < 1){
							back1 = NULL;
						}
					}
				}


				if (back1 != NULL)
				{
					addstr("Gano Bando 2\n");
					refresh();
				}
				if(back2!=  NULL){
					addstr("Gano Bando 1\n");
					refresh();
				}


			}else{
				addstr("Ocupa almenos 4 escuadrones para poder iniciar la simulación.\n");
				refresh();
				addstr("");
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
