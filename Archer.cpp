#include "Archer.h"

Archer::Archer(){

}

Archer::Archer(string nombre, int edad, string ciudad, int arrows, int presicion): Soldier (nombre, edad, ciudad ) {

	this->arrows = arrows;
	this->presicion = presicion;
}


int Archer::getArrows(){
	return arrows;
}

void Archer::setArrows(int arrows){
	this->arrows = arrows;
}

int Archer::getPresicion(){
	return presicion;
}

void Archer::setPresicion(int presicion){
	this->presicion=presicion;
}

Archer::~Archer(){

}

int Archer::efficiencyAttack(){
	return this->arrows * (this->presicion/1000);

}

int Archer::efficiencyDefense(){
	return 0;
}

string Archer::toString(){

	stringstream ss;
	ss<< "Nombre: " << name <<endl << "Edad: "<< age << endl << "Ciudad: " << city<<endl;
	ss<<"Cantidad de Flechas: "<<this->arrows<<endl<<"Presicion: "<< this->presicion << endl;
	return ss.str();
}
