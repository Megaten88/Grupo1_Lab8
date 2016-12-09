#include "Assassin.h"

Assassin::Assassin(){

}

Assassin::Assassin(string nombre, int edad, string ciudad, int kills, int presence){
	this->nombre = nombre;
	this->edad = edad;
	this->ciudad = ciudad;
	this->kills = kills;
	this->presence = presence;
}

int Assassin::getKills(){
	return kills;
}

void Assassin::setKills(int kills){
	this->kills = kills;
}

int Assassin::getPresence(){
	return presence;
}

void Assassin::setPresence(int presence){
	this->presence = presence;
}

double Assassin::efficiencyAttack(){
	return kills;

}

double Assassin::efficiencyDefense(){
	return presence * 10;
}

string Assassin::toString(){
	stringstream ss;
	ss<< "Nombre: " << name <<endl << "Edad: "<< age << endl << "Ciudad: " << city<<endl;
	ss<< "Cantidad de Asesinatos: " << kills << endl << "Capacidad de pasar desapercibido: " << presence << endl;
	
	return ss.str();
}


Assassin::~Assassin(){

}