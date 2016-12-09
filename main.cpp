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
	addstr("Goodbye");
	refresh();
	getch();
    endwin();




	int option = 0 ;

			while (option != 3) {
				cout << "SIMULACIÓN : Guerras Punicas" << '\n';
				cout << "1) Agregar escuadrón" << '\n';
				cout << "2) Agregar soldado a escuadron" << '\n';
				cout << "3) Salir " << '\n';

				cin>>option;

				string nombre;
				int edad;
				string ciudad;

				if (option == 1) {
					cout << "Ingrese el nombre de su escuadron: " << '\n';
					cin>> nombre;
					escuadrones.push_back(new Squad(nombre));
					cout << "Su escuadron ha sido agregado exitosamente" << '\n';
				}

				if (option == 2){
					int selectSquad=0;
					int select=0;
					int repeat=0;

					if (escuadrones.size()> 0) {
						cout << "Seleccione su escuadron: " << '\n';

							for (size_t i = 0; i < escuadrones.size(); i++) {
								cout << i <<" : " << escuadrones.at(i)->toString() << '\n';
							}

						 cin>>selectSquad;

						 cout << "¿Qué desea agregar a su escuadron?" << '\n';
						 cout << "1) Arquero " << '\n';
						 cout << "2) Coraza Dura" << '\n';
						 cout << "3) Asesino Oculto " << '\n';

						 cin >> select;

						 if (select == 1 ) {
							 	int flechas=0;
							 	int presicion=0;
							 	cout << "¿Cuantos arqueros desea agregar?" << '\n';
								cin>>repeat;

								while (repeat > 0 ) {
									cout << "Ingrese el nombre: " << '\n';
									cin>> nombre;
									cout << "Ingrese la edad:" << '\n';
									cin>> edad;
									cout << "Ingrese el nombre de la ciudad de origen" << '\n';
									cin>> ciudad;
									cout << "Cantidad de flechas: " << '\n';
									cin>> flechas;
									cout << "Rango de presicion; " << '\n';
									cin>> presicion;
									Archer* temp = new Archer(nombre,edad,ciudad,flechas,presicion);
									cout<< temp->efficiencyAttack();
									cout<<"FIn"<<endl;
									escuadrones.at(selectSquad)->addSoldier(new Archer(nombre,edad,ciudad,flechas,presicion));

									repeat--;
								}

						 }

						 if (select == 2 ) {
							 int dureza=0;
							 int lanzas=0;

							 cout << "¿Cuantos Coraza dura desea agregar?" << '\n';
							 cin>>repeat;

							 while (repeat > 0 ) {
								 cout << "Ingrese el nombre: " << '\n';
								 cin>> nombre;
								 cout << "Ingrese la edad:" << '\n';
								 cin>> edad;
								 cout << "Ingrese el nombre de la ciudad de origen" << '\n';
								 cin>> ciudad;

								 cout << "Nivel de dureza: " << '\n';
								 cin>> dureza;
								 cout << "numero de lanzas; " << '\n';
								 cin>> lanzas;

								 escuadrones.at(selectSquad)->addSoldier(new HardArmor(nombre,edad,ciudad,dureza,lanzas));

								 repeat--;
							 }

						 }

						 if (select == 3 ) {
							 int victimas=0;
							 int presencia=0;
							 cout << "¿Cuantos Asesinos Ocultos desea agregar?" << '\n';
							 cin>>repeat;

							 while (repeat > 0 ) {
								 cout << "Ingrese el nombre: " << '\n';
								 cin>> nombre;
								 cout << "Ingrese la edad:" << '\n';
								 cin>> edad;
								 cout << "Ingrese el nombre de la ciudad de origen" << '\n';
								 cin>> ciudad;
								 cout << "Numero de nictimas: " << '\n';
								 cin>> victimas;
								 cout << "Nivel de presencia; " << '\n';
								 cin>> presencia;
								 escuadrones.at(selectSquad)->addSoldier(new Assassin(nombre,edad,ciudad,victimas,presencia));
								 repeat--;
							 }
						 }
					}else{
						cout << "Almenos ocupa un escuadron al cual agregar soldados." << '\n';
					}



				}




			}

		for (int i = 0; i < escuadrones.size(); ++i){
	    	escuadrones.erase(escuadrones.begin() + i);
		}
    	escuadrones.clear();

	return 0;
}
