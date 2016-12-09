#include "Archer.h"

Archer::Archer(){

}

Archer::Archer(string nombre, int edad, string ciudad, int arrows, double presicion): Soldier (nombre, edad, ciudad ) {

	this->arrows = arrows;
	this->presicion = presicion;
}


int Archer::getArrows(){
	return arrows;
}

void Archer::setArrows(int arrows){
	this->arrows = arrows;
}

double Archer::getPresicion(){
	return presicion;
}

void Archer::setPresicion(double presicion){
	this->presicion=presicion;
}

Archer::~Archer(){

}

double Archer::efficiencyAttack(){
	return this->arrows * (this->presicion/1000);

}

double Archer::efficiencyDefense(){
	return 0;
}

string Archer::toString(){

}
