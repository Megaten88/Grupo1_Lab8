#include "Squad.h"
#include "Soldier.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Squad::Squad(string nombre){
	name = nombre;
	totalDef = 0;
	totalAttack = 0;
}
void Squad::addSoldier(Soldier* soldier){
	squad.push_back(soldier);
}
double Squad::getTotalDef(){
	totalDef = 0;
	if (squad.size()>0)
	{
		for (int i = 0; i < squad.size(); ++i)
		{
			totalDef+= squad.at(i)-> efficiencyDefense();
		}
		return totalDef;
	}else{
		return 0;
	}
}
double Squad::getTotalAttack(){
	totalAttack = 0;
	if (squad.size()>0)
	{
		for (int i = 0; i < squad.size(); ++i)
		{
			totalAttack+= squad.at(i)-> efficiencyAttack();
		}
		return totalAttack;
	}else{
		return 0;
	}
}
Squad::~Squad(){
	for (int i = 0; i < squad.size(); ++i){
	    squad.erase(squad.begin() + i);
	}
    squad.clear();
}
string Squad::toString(){
	stringstream ss;
	ss<<"Nombre del esquadrón: "<<name<<"\n------Soldados-------\n";
	if (squad.size() > 0)
	{
		for (int i = 0; i < squad.size(); ++i)
		{
			ss<<i<<") "<<squad.at(i)-> getName()<<"\n";
		}
	}
	ss<<"\nAtaque total: "<<getTotalAttack()<<"\tDefensa total: "<<getTotalDef()<<"\n";
	return ss.str();
}