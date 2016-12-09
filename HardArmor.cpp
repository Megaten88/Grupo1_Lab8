#include "HardArmor.h"

HardArmor::HardArmor(string nombre, int edad, string ciudad,int hardness, int lances): Soldier (nombre, edad, ciudad ){
	this->hardness = hardness;
	this->lances = lances;
}

int HardArmor::getHardness(){
	return hardness;
}
void HardArmor::setHardness(int hardness){
	this->hardness = hardness;
}

int HardArmor::getLances(){
	return lances;
}

void HardArmor::setLances(int lances){
	this->lances = lances;
}

HardArmor::~HardArmor(){

}

double HardArmor::efficiencyAttack(){
	return this->lances;
}


double HardArmor::efficiencyDefense(){
	return this->hardness;
}

string HardArmor::toString(){

}
