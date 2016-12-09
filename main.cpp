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
				std::cout << "SIMULACIÓN : Guerras Punicas" << '\n';
				std::cout << "1) Agregar escuadrón" << '\n';
				std::cout << "2) Agregar soldado a escuadron" << '\n';
				std::cout << "3) Salir " << '\n';

				cin>>option;

				string nombre;
				string edad;
				string ciudad;

				if (option == 1) {
					std::cout << "Ingrese el nombre de su escuadron: " << '\n';
					cin>> nombre;
					escuadrones.push_back(new escuadron(nombre));
					std::cout << "Su escuadron ha sido agregado exitosamente" << '\n';
				}

				if (option == 2){
					int selectSquad=0;
					int select=0;
					int repeat=0;

					if (escuadrones.size()> 0) {
						std::cout << "Seleccione su escuadron: " << '\n';

							for (size_t i = 0; i < count; i++) {
								std::cout << i <<" : " << escuadrones.at(i)->toString() << '\n';
							}

						 cin>>selectSquad;

						 std::cout << "¿Qué desea agregar a su escuadron?" << '\n';
						 std::cout << "1) Arquero " << '\n';
						 std::cout << "2) Coraza Dura" << '\n';
						 std::cout << "3) Asesino Oculto " << '\n';

						 cin >> select;

						 if (select == 1 ) {
							 	int flechas=0;
							 	int presicion=0;
							 	std::cout << "¿Cuantos arqueros desea agregar?" << '\n';
								cin>>repeat;

								while (repeat > 0 ) {
									std::cout << "Ingrese el nombre: " << '\n';
									cin>> nombre;
									std::cout << "Ingrese la edad:" << '\n';
									cin>> edad;
									std::cout << "Ingrese el nombre de la ciudad de origen" << '\n';
									cin>> ciudad;
									std::cout << "Cantidad de flechas: " << '\n';
									cin>> flechas;
									std::cout << "Rango de presicion; " << '\n';
									cin>> presicion;
									escuadrones.at(selectSquad)->addSoldier(new Arquero(nombre,edad,ciudad,flechas,presicion));

									repeat--;
								}

						 }

						 if (select == 2 ) {
							 int dureza=0;
							 int lanzas=0;

							 std::cout << "¿Cuantos Coraza dura desea agregar?" << '\n';
							 cin>>repeat;

							 while (repeat > 0 ) {
								 std::cout << "Ingrese el nombre: " << '\n';
								 cin>> nombre;
								 std::cout << "Ingrese la edad:" << '\n';
								 cin>> edad;
								 std::cout << "Ingrese el nombre de la ciudad de origen" << '\n';
								 cin>> ciudad;

								 std::cout << "Nivel de dureza: " << '\n';
								 cin>> dureza;
								 std::cout << "numero de lanzas; " << '\n';
								 cin>> lanzas;

								 escuadrones.at(selectSquad)->addSoldier(new HardArmor(nombre,edad,ciudad,dureza,lanzas));

								 repeat--;
							 }

						 }

						 if (select == 3 ) {
							 int victimas=0;
							 int presencia=0;
							 std::cout << "¿Cuantos Asesinos Ocultos desea agregar?" << '\n';
							 cin>>repeat;

							 while (repeat > 0 ) {
								 std::cout << "Ingrese el nombre: " << '\n';
								 cin>> nombre;
								 std::cout << "Ingrese la edad:" << '\n';
								 cin>> edad;
								 std::cout << "Ingrese el nombre de la ciudad de origen" << '\n';
								 cin>> ciudad;
								 std::cout << "Numero de nictimas: " << '\n';
								 cin>> victimas;
								 std::cout << "Nivel de presencia; " << '\n';
								 cin>> presencia;
								 escuadrones.at(selectSquad)->addSoldier(new Assasin(nombre,edad,ciudad,victimas,presencia));
								 repeat--;
							 }
						 }
					}else{
						std::cout << "Almenos ocupa un escuadron al cual agregar soldados." << '\n';
					}



				}




			}



	return 0;
}
