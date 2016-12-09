#include "Squad.h"
#include "Soldier.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Squad::Squad(string nombre){
	name = name;
	totalDef = 0;
	totalAttack = 0;
}
void Squad::addSoldier(Soldier* soldier){
	squad.push_back(soldier);
}
int Squad::getTotalDef(){
	return totalDef;
}
int Squad::getTotalAttack(){
	return totalAttack;
}
Squad::~Squad(){
	for (int i = 0; i < squad.size(); ++i){
	    squad.erase(squad.begin() + i);
	}
    squad.clear();
}
string Squad::toString(){
	stringstream ss;
	ss<<"Nombre del esquadrón: "<<name<<"\n------Soldados-------";
	if (squad.size() > 0)
	{
		for (int i = 0; i < squad.size(); ++i)
		{
			ss<<squad.at(i)-> getName()<<"\n";
		}
	}
	ss<<"Ataque total: "<<totalAttack<<"\tDefensa total: "<<totalDef<<"\n";
	return ss.str();
}