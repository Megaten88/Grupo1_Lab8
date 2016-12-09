#ifndef HARDARMOR_H
#define HARDARMOR_H

#include "Soldier.h"

class HardArmor : public Soldier
{
private:
	int hardness;
	int lances;
public:
	HardArmor(string,int,string, int, int);
	int getHardness();
	void setHardness(int);
	int getLances();
	void setLances(int);
	HardArmor();
	~HardArmor();
	
	double efficiencyAttack();
    double efficiencyDefense();


    string toString();
};


#endif